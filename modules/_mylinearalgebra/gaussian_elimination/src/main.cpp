#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <chrono>

// http://www.cleverstudents.ru/systems/solving_systems_Gauss_method.html

void dump(const std::vector<std::vector<double>>& x,
          const std::vector<double>& y) {
    const int setw_size = 2;
    for (size_t i = 0; i < x.size(); ++i) {
        for (size_t j = 0; j < x.size(); ++j) {
            std::cout << std::setw(setw_size) << x[i][j] << " ";
        }
        std::cout << "= " << std::setw(setw_size) << y[i] << std::endl;
    }
}

void generate_matrix_01(const size_t size,
                        std::vector<std::vector<double>>& x,
                        std::vector<double>& y) {
    for (size_t i = 0; i < size; ++i) {
        y.at(i) = static_cast<int>(i) + 1;
        for (size_t j = 0; j < size; ++j) {
            if (j <= i) {
                x.at(i).at(j) = 1;
            }
            else {
                x.at(i).at(j) = 0;
            }
        }
    }
}

void solve_gauss(const size_t& size, std::vector<std::vector<double>>& x,
                std::vector<double>& y,
                std::map<int, double>& x_res) {
    for (size_t i = 0; i < x.size() - 1; ++i) {
        for (size_t j = i + 1; j < x.size(); ++j) {
            double a = -x[j][i] / x[i][i];
            if (size <= 10) {
                std::cout << "a=" << a << std::endl;
            }

            double tmp_y = a * y[i];
            y[j] = y[j] + tmp_y;

            std::vector<double> tmp_x;
            for (size_t t = 0; t < x[i].size(); ++t) {
                tmp_x.push_back(x[i][t] * a);
            }

            for (size_t t = 0; t < tmp_x.size(); ++t) {
                x[j][t] = x[j][t] + tmp_x[t];
            }
        }
        if (size <= 10) {
            dump(x, y);
        }
    }

    for (int i = x.size() - 1; i >= 0; --i) {
        double xi_res = y[i];
        for (int j = x[i].size() - 1; j >= 0; --j) {
            if (x[i][j] != 0 && x_res.count(j) == 0) {
                x_res[j] = xi_res / x[i][j];
                break;
            }
            else if (x_res.count(j) != 0) {
                xi_res += -(x[i][j] * x_res.at(j));
            }
        }
    }
}

int main(const int argc, const char* argv[]) {
    try {
        std::vector<int> size_list({ 10,100,500,1000,2000,3000 });
        for (size_t size_index = 0; size_index < size_list.size(); ++size_index) {
            size_t size = size_list[size_index];
            std::vector<std::vector<double>> x(size, std::vector<double>(size, 0));
            std::vector<double> y(size, 0);

            generate_matrix_01(size, x, y);
            if (size <= 10) {
                dump(x, y);
            }

            std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

            std::map<int, double> x_res;
            solve_gauss(size, x, y, x_res);

            std::chrono::steady_clock::time_point stop = std::chrono::steady_clock::now();
            std::cout << "Time difference milliseconds:" << std::chrono::duration_cast<
                std::chrono::milliseconds>(stop - start).count() << " size:" << size << std::endl;

            if (size <= 10) {
                std::map<int, double>::const_iterator it = x_res.begin();
                for (it; it != x_res.end(); ++it) {
                    std::cout << "x" << it->first + 1 << "=" << it->second << " ";
                }
                std::cout << std::endl;
            }
        }
        std::cout << "Done!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error occurred:" << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
