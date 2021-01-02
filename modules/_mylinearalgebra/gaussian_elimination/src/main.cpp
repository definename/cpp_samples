#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

// http://www.cleverstudents.ru/systems/solving_systems_Gauss_method.html
// https://prog-cpp.ru/gauss/

void dump(const std::vector<std::vector<double>>& x, const std::vector<double>& y) {
    const int setw_size = 10;
    for (size_t i = 0; i < x.size(); ++i) {
        for (size_t j = 0; j < x.size(); ++j) {
            std::cout << std::setw(setw_size) << x[i][j] << " ";
        }
        std::cout << "= " << std::setw(setw_size) << y[i] << std::endl;
    }
}

int main(const int argc, const char* argv[]) {
    std::vector<std::vector<double>> x = {
        {3,2,1,1},
        {1,-1,4,-1},
        {-2,-2,-3,1},
        {1,5,-1,2}
//         {2,4,1},
//         {5,2,1},
//         {2,3,4},
    };
    std::vector<double> y = 
        { -2,-1,9,4 }
//        { 36, 47, 37 }
    ;

    dump(x, y);

    for (size_t i = 0; i < x.size() - 1; ++i) {
        for (size_t j = i+1; j < x.size(); ++j) {
            double a = -x[j][i] / x[i][i];
            std::cout << "a=" << a << std::endl;

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
        dump(x, y);
    }

    std::map<int, double> x_res;
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

    std::map<int, double>::const_iterator it = x_res.begin();
    for (it; it != x_res.end(); ++it) {
        std::cout << "x"<<it->first + 1 << "=" << it->second << " ";
    }

    return EXIT_SUCCESS;
}
