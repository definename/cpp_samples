#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <chrono>
#include <intrin.h>
#include <random>

// http://www.cleverstudents.ru/systems/solving_systems_Gauss_method.html

void print_results(const std::vector<std::vector<float>>& x,
                   const std::vector<float>& y,
                   const std::map<int, float>& x_res) {
    if (x.size() <= 10 && y.size() <= 10) {
        std::map<int, float>::const_iterator it = x_res.begin();
        for (it; it != x_res.end(); ++it) {
            std::cout << "x" << it->first << "=" << it->second << " ";
        }
        std::cout << std::endl;

        for (int i = 0, imax = x.size(); i < imax; ++i) {
            float calc = 0;
            for (int j = 0, jmax = x[i].size(); j < jmax; ++j) {
                calc += (x[i][j] * x_res.at(j));
            }
            std::cout << i << " calc:" << std::setw(8) << calc << " origin:" << std::setw(8) << y[i] << std::endl;
        }
    }
}

void dump(const std::vector<std::vector<float>>& x,
          const std::vector<float>& y) {
    if (x.size() <= 10 && y.size() <= 10) {
        const int setw_size = 6;
        const int setprecision_size = 2;
        for (size_t i = 0; i < x.size(); ++i) {
            for (size_t j = 0; j < x.size(); ++j) {
                std::cout << std::setw(setw_size) << std::setprecision(setprecision_size) << std::fixed << x[i][j] << " ";
            }
            std::cout << "= " << std::setw(setw_size) << std::setprecision(setprecision_size) << std::fixed << y[i] << std::endl;
        }
        std::cout << std::endl;
    }
}

void generate_random_matrix(const size_t size,
                        std::vector<std::vector<float>>& x,
                        std::vector<float>& y) {

    unsigned int seed = static_cast<unsigned int>(std::time(nullptr));
    std::default_random_engine random_engine(seed);
    std::uniform_int_distribution<int> distribution(-9, 9);

    for (size_t i = 0; i < size; ++i) {
        y[i] = static_cast<float>(distribution(random_engine));
        for (size_t j = 0; j < size; ++j) {
            x[i][j] = static_cast<float>(distribution(random_engine));
        }
    }
}

void do_gauss(std::vector<std::vector<float>>& x,
              std::vector<float>& y,
              std::map<int, float>& x_res) {
    for (int i = 0, imax = x.size() - 1; i < imax; ++i) {

        float max_x = abs(x[i][i]);
        int max_i = i;
        for (int moved_i = i + 1, moved_imax = x.size(); moved_i < moved_imax; ++moved_i) {
            if (max_x < abs(x[moved_i][i])) {
                max_x = abs(x[moved_i][i]);
                max_i = moved_i;
            }
        }

        if (max_i != i) {
            std::vector<float> tmp_x = x[i];
            x[i] = x[max_i];
            x[max_i] = tmp_x;

            float tmp_y = y[i];
            y[i] = y[max_i];
            y[max_i] = tmp_y;
        }

#pragma loop(hint_parallel(0))
#pragma loop(ivdep)
        for (int j = i + 1, jmax = x.size(); j < jmax; ++j) {
            float a = -x[j][i] / x[i][i];

            float tmp_y = a * y[i];
            y[j] = y[j] + tmp_y;

            for (int t = 0, tmax = x[i].size(); t < tmax; ++t) {
                float tmp_t = x[i][t] * a;
                x[j][t] = x[j][t] + tmp_t;
            }
        }
        dump(x, y);
    }

    for (int i = x.size() - 1; i >= 0; --i) {
        float xi_res = y[i];
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
        for (size_t size_index = 0; size_index < 1; ++size_index) {
            size_t size = 10;
            std::vector<std::vector<float>> x(size, std::vector<float>(size, 0));
            std::vector<float> y(size, 0);

            generate_random_matrix(size, x, y);
            dump(x, y);

            std::vector < std::vector<float >> backup_x = x;
            std::vector<float> backup_y = y;

            std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

            std::map<int, float> x_res;
            do_gauss(x, y, x_res);

            std::chrono::steady_clock::time_point stop = std::chrono::steady_clock::now();
            std::chrono::milliseconds dur = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            std::cout << "milliseconds:" << dur.count() << " matrix size:" << size << std::endl;

            print_results(backup_x, backup_y, x_res);
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error occurred:" << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}















// #include <random>
// #include <iostream>
// using namespace std;
// // Вывод системы уравнений
// void sysout(double** a, double* y, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << a[i][j] << "*x" << j;
//             if (j < n - 1)
//                 cout << " + ";
//         }
//         cout << " = " << y[i] << endl;
//     }
//     return;
// }
// double* gauss(double** a, double* y, int n)
// {
//     double* x, max;
//     int k, index;
//     const double eps = 0.00001;  // точность
//     x = new double[n];
//     k = 0;
//     while (k < n)
//     {
//         // Поиск строки с максимальным a[i][k]
//         max = abs(a[k][k]);
//         index = k;
//         for (int i = k + 1; i < n; i++)
//         {
//             if (abs(a[i][k]) > max)
//             {
//                 max = abs(a[i][k]);
//                 index = i;
//             }
//         }
//         // Перестановка строк
//         if (max < eps)
//         {
//             // нет ненулевых диагональных элементов
//             cout << "Решение получить невозможно из-за нулевого столбца ";
//             cout << index << " матрицы A" << endl;
//             return 0;
//         }
//         for (int j = 0; j < n; j++)
//         {
//             double temp = a[k][j];
//             a[k][j] = a[index][j];
//             a[index][j] = temp;
//         }
//         double temp = y[k];
//         y[k] = y[index];
//         y[index] = temp;
//         // Нормализация уравнений
//         for (int i = k; i < n; i++)
//         {
//             double temp = a[i][k];
//             if (abs(temp) < eps) continue; // для нулевого коэффициента пропустить
//             for (int j = 0; j < n; j++)
//                 a[i][j] = a[i][j] / temp;
//             y[i] = y[i] / temp;
//             if (i == k)  continue; // уравнение не вычитать само из себя
//             for (int j = 0; j < n; j++)
//                 a[i][j] = a[i][j] - a[k][j];
//             y[i] = y[i] - y[k];
//         }
//         k++;
//     }
//     // обратная подстановка
//     for (k = n - 1; k >= 0; k--)
//     {
//         x[k] = y[k];
//         for (int i = 0; i < k; i++)
//             y[i] = y[i] - a[i][k] * x[k];
//     }
//     return x;
// }
// int main()
// {
//     double** a, * y, * x;
//     int n;
//     system("chcp 1251");
//     system("cls");
//     cout << "Введите количество уравнений: ";
//     cin >> n;
//     a = new double* [n];
//     y = new double[n];
// 
//     unsigned int seed = static_cast<unsigned int>(std::time(nullptr));
//     std::default_random_engine random_engine(seed);
//     std::uniform_int_distribution<int> distribution(-9, 9);
// 
//     for (int i = 0; i < n; i++) {
//         a[i] = new double[n];
//         for (int j = 0; j < n; j++) {
//             a[i][j] = distribution(random_engine);
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         y[i] = distribution(random_engine);
//     }
//     sysout(a, y, n);
//     x = gauss(a, y, n);
//     for (int i = 0; i < n; i++)
//         cout << "x[" << i << "]=" << x[i] << endl;
//     cin.get(); cin.get();
//     return 0;
// }
