#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
    #define MYDEBUG_NEW new( _NORMAL_BLOCK, __FILE__, __LINE__)
    #define new MYDEBUG_NEW
#endif

#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <chrono>
#include <intrin.h>
#include <random>

// http://www.cleverstudents.ru/systems/solving_systems_Gauss_method.html

using data_t = float;

/* C implementation *************************************************************************/

void do_print_results(const size_t& size, data_t** m, const data_t* v, const data_t* m_res) {
    if (size <= 10 && size <= 10) {
        for (int i = 0; i < size; ++i) {
            std::cout << "x" << i << "=" << m_res[i] << " ";
        }
        std::cout << std::endl;

        for (size_t i = 0; i < size; ++i) {
            float calc = 0;
            for (size_t j = 0; j < size; ++j) {
                calc += (m[i][j] * m_res[j]);
            }
            std::cout << i << " calc:" << std::setw(8) << calc << " origin:" << std::setw(8) << v[i] << std::endl;
        }
    }
}

void do_print_matrix(const size_t& size, data_t** m, data_t* v) {
    if (size <= 10) {
        const int setw_size = 6;
        const int setprecision_size = 2;
        for (size_t i = 0; i < size; ++i) {
            for (size_t j = 0; j < size; ++j) {
                std::cout << std::setw(setw_size) << std::setprecision(setprecision_size) << std::fixed << m[i][j] << " ";
            }
            std::cout << "= " << std::setw(setw_size) << std::setprecision(setprecision_size) << std::fixed << v[i] << std::endl;
        }
        std::cout << std::endl;
    }
}

void do_generate_random_matrix(const size_t& size, data_t** m, data_t* v) {

    unsigned int seed = static_cast<unsigned int>(std::time(nullptr));
    std::default_random_engine random_engine(seed);
    std::uniform_int_distribution<int> distribution(-9, 9);

    for (size_t i = 0; i < size; ++i) {
        v[i] = static_cast<float>(distribution(random_engine));
        for (size_t j = 0; j < size; ++j) {
            m[i][j] = static_cast<float>(distribution(random_engine));
        }
    }
}

data_t* do_gauss(const size_t size, data_t** m, data_t* v) {
    for (int i = 0, imax = size - 1; i < imax; ++i) {

        data_t max_x = abs(m[i][i]);
        int max_i = i;
        for (size_t moved_i = i + 1; moved_i < size; ++moved_i) {
            if (max_x < abs(m[moved_i][i])) {
                max_x = abs(m[moved_i][i]);
                max_i = moved_i;
            }
        }

        if (max_i != i) {
            data_t* tmp_x = m[i];
            m[i] = m[max_i];
            m[max_i] = tmp_x;

            data_t tmp_y = v[i];
            v[i] = v[max_i];
            v[max_i] = tmp_y;
        }

#pragma loop(hint_parallel(0))
#pragma loop(ivdep)
        for (int j = i + 1, jmax = size; j < jmax; ++j) {
            data_t a = -m[j][i] / m[i][i];

            data_t tmp_y = a * v[i];
            v[j] = v[j] + tmp_y;

            data_t* tmp_arr = new data_t[size];
            for (int t = 0, tmax = size; t < tmax; ++t) {
                data_t tmp_t = m[i][t] * a;
                tmp_arr[t] = tmp_t;
            }
            for (int t = 0, tmax = size; t < tmax; ++t) {
                data_t tmp_t = tmp_arr[t];
                m[j][t] = m[j][t] + tmp_t;
            }
            delete[] tmp_arr;
        }
        do_print_matrix(size, m, v);
    }

    data_t* m_res = new data_t[size];
    int* res_check = new int[size];
    for (int i = 0; i < size; ++i) {
        res_check[i] = 0;
    }
    for (int i = size - 1; i >= 0; --i) {
        data_t xi_res = v[i];
        for (int j = size - 1; j >= 0; --j) {
            if (m[i][j] != 0 && res_check[j] == 0) {
                m_res[j] = xi_res / m[i][j];
                res_check[j] = 1;
                break;
            }
            else if (res_check[j] != 0) {
                xi_res += -(m[i][j] * m_res[j]);
            }
        }
    }
    delete[] res_check;
    return m_res;
}

/* CPP implementation *************************************************************************/

using vector_t = std::vector<data_t>;
using matrix_t = std::vector<vector_t>;
using map_t = std::map<int, data_t>;

void do_print_results(const matrix_t& m, const vector_t& v, const map_t& m_res) {
    if (m.size() <= 10 && v.size() <= 10) {
        for (map_t::const_iterator it = m_res.begin(); it != m_res.end(); ++it) {
            std::cout << "x" << it->first << "=" << it->second << " ";
        }
        std::cout << std::endl;

        for (size_t i = 0; i < m.size(); ++i) {
            float calc = 0;
            for (size_t j = 0; j < m[i].size(); ++j) {
                calc += (m[i][j] * m_res.at(j));
            }
            std::cout << i << " calc:" << std::setw(8) << calc << " origin:" << std::setw(8) << v[i] << std::endl;
        }
    }
}

void do_print_matrix(const matrix_t& m, const vector_t& v) {
    if (m.size() <= 10 && v.size() <= 10) {
        const int setw_size = 6;
        const int setprecision_size = 2;
        for (size_t i = 0; i < m.size(); ++i) {
            for (size_t j = 0; j < m.size(); ++j) {
                std::cout << std::setw(setw_size) << std::setprecision(setprecision_size) << std::fixed << m[i][j] << " ";
            }
            std::cout << "= " << std::setw(setw_size) << std::setprecision(setprecision_size) << std::fixed << v[i] << std::endl;
        }
        std::cout << std::endl;
    }
}

void do_generate_random_matrix(const size_t& size, matrix_t& m, vector_t& v) {

    unsigned int seed = static_cast<unsigned int>(std::time(nullptr));
    std::default_random_engine random_engine(seed);
    std::uniform_int_distribution<int> distribution(-9, 9);

    for (size_t i = 0; i < size; ++i) {
        v[i] = static_cast<float>(distribution(random_engine));
        for (size_t j = 0; j < size; ++j) {
            m[i][j] = static_cast<float>(distribution(random_engine));
        }
    }
}

void do_gauss(matrix_t& m, vector_t& v, map_t& m_res) {
    for (int i = 0, imax = m.size() - 1; i < imax; ++i) {

        data_t max_x = abs(m[i][i]);
        int max_i = i;
        for (size_t moved_i = i + 1; moved_i < m.size(); ++moved_i) {
            if (max_x < abs(m[moved_i][i])) {
                max_x = abs(m[moved_i][i]);
                max_i = moved_i;
            }
        }

        if (max_i != i) {
            vector_t tmp_x = m[i];
            m[i] = m[max_i];
            m[max_i] = tmp_x;

            data_t tmp_y = v[i];
            v[i] = v[max_i];
            v[max_i] = tmp_y;
        }

#pragma loop(hint_parallel(0))
#pragma loop(ivdep)
        for (int j = i + 1, jmax = m.size(); j < jmax; ++j) {
            data_t a = -m[j][i] / m[i][i];

            data_t tmp_y = a * v[i];
            v[j] = v[j] + tmp_y;

            for (int t = 0, tmax = m[i].size(); t < tmax; ++t) {
                data_t tmp_t = m[i][t] * a;
                m[j][t] = m[j][t] + tmp_t;
            }
        }
        do_print_matrix(m, v);
    }

    for (int i = m.size() - 1; i >= 0; --i) {
        data_t xi_res = v[i];
        for (int j = m[i].size() - 1; j >= 0; --j) {
            if (m[i][j] != 0 && m_res.count(j) == 0) {
                m_res[j] = xi_res / m[i][j];
                break;
            }
            else if (m_res.count(j) != 0) {
                xi_res += -(m[i][j] * m_res.at(j));
            }
        }
    }
}

int main(const int argc, const char* argv[]) {
    int ret = EXIT_SUCCESS;
    try {
        int test_list[] = { 10};
/*        int test_list[] = { 10,100,1000,2000,3000,4000 };*/
        for (size_t i = 0; i < sizeof(test_list) / sizeof(test_list[0]); ++i) {
            size_t size = test_list[i];

            /* C implementation **********************************************/
            data_t** mm = new data_t*[size];
            data_t** mm_totest = new data_t*[size];
            for (int j = 0; j < size; ++j) {
                mm[j] = new data_t[size];
                mm_totest[j] = new data_t[size];
            }
            data_t* vv = new data_t[size];
            data_t* vv_totest = new data_t[size];

            do_generate_random_matrix(size, mm, vv);

            for (int j = 0; j < size; ++j) {
                vv_totest[j] = vv[j];
                for (int y = 0; y < size; ++y) {
                    mm_totest[j][y] = mm[j][y];
                }
            }
            do_print_matrix(size, mm, vv);

            std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
            
            data_t* mm_res = do_gauss(size, mm, vv);

            std::chrono::steady_clock::time_point stop = std::chrono::steady_clock::now();
            std::chrono::milliseconds dur = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
            std::cout << "milliseconds:" << std::setw(10) << dur.count() << " matrix size:" << std::setw(10) << size << std::endl;

            do_print_results(size, mm_totest, vv_totest, mm_res);

            for (int j = 0; j < size; ++j) {
                delete[] mm[j];
                delete[] mm_totest[j];
            }
            delete[] mm;
            delete[] mm_totest;
            delete[] vv;
            delete[] vv_totest;
            delete[] mm_res;

            /* CPP implementation **********************************************/

//             matrix_t m(size, vector_t(size, 0));
//             vector_t v(size, 0);
// 
//             do_generate_random_matrix(size, m, v);
//             do_print_matrix(m, v);
// 
//             matrix_t backup_m = m;
//             vector_t backup_v = v;
// 
//             std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
// 
//             std::map<int, float> m_res;
//             do_gauss(m, v, m_res);
// 
//             std::chrono::steady_clock::time_point stop = std::chrono::steady_clock::now();
//             std::chrono::milliseconds dur = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
//             std::cout << "milliseconds:" << std::setw(10) << dur.count() << " matrix size:" << std::setw(10) << size << std::endl;
// 
//             do_print_results(backup_m, backup_v, m_res);
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error occurred:" << e.what() << std::endl;
        ret = EXIT_FAILURE;
    }
    _CrtDumpMemoryLeaks();
    return ret;
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
