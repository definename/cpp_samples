 #define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#ifdef _DEBUG
    #define MYDEBUG_NEW new( _NORMAL_BLOCK, __FILE__, __LINE__)
    #define new MYDEBUG_NEW
#endif

#include <iostream>
#include <map>
#include <iomanip>
#include <chrono>
#include <random>
#include <intrin.h>

using data_t = float;

bool do_test_avx_support() {
    bool avxSupported = false;
#if (_MSC_FULL_VER >= 160040219)
    int cpuInfo[4];
    __cpuid(cpuInfo, 1);

    bool osUsesXSAVE_XRSTORE = cpuInfo[2] & (1 << 27) || false;
    bool cpuAVXSuport = cpuInfo[2] & (1 << 28) || false;

    if (osUsesXSAVE_XRSTORE && cpuAVXSuport) {
        unsigned long long xcrFeatureMask = _xgetbv(_XCR_XFEATURE_ENABLED_MASK);
        avxSupported = (xcrFeatureMask & 0x6) || false;
    }
#endif
    return avxSupported;
}

void do_print_results(const size_t& size, data_t** m, const data_t* v, const data_t* m_res) {
    if (size <= 10) {
        for (size_t i = 0; i < size; ++i) {
            std::cout << "x" << i << "=" << m_res[i] << " ";
        }
        std::cout << std::endl;

        for (size_t i = 0; i < size; ++i) {
            data_t calc = 0;
            for (size_t j = 0; j < size; ++j) {
                calc += (m[i][j] * m_res[j]);
            }
            std::cout << i << " calc:" << std::setw(8) << calc
                << " origin:" << std::setw(8) << v[i] << std::endl;
        }
    }
}

void do_print_matrix(const size_t& size, data_t** m, data_t* v) {
    if (size <= 10) {
        const int setw_size = 6;
        const int setprecision_size = 2;
        for (size_t i = 0; i < size; ++i) {
            for (size_t j = 0; j < size; ++j) {
                std::cout << std::setw(setw_size) << 
                    std::setprecision(setprecision_size) << std::fixed << m[i][j] << " ";
            }
            std::cout << "= " << std::setw(setw_size) <<
                std::setprecision(setprecision_size) << std::fixed << v[i] << std::endl;
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

data_t* do_gauss(const int& size, data_t** m, data_t* v) {
    for (int i = 0, imax = size - 1; i < imax; ++i) {

        data_t max_x = abs(m[i][i]);
        int max_i = i;
        for (int moved_i = i + 1; moved_i < size; ++moved_i) {
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

int main(const int argc, const char* argv[]) {
    int ret = EXIT_SUCCESS;
    try {
        std::cout << (do_test_avx_support() ? "AVX support OK" : "AVX support NOK") << std::endl;

        int test_list[] = { 10,100,1000,2000,3000,4000 };
        for (size_t i = 0; i < sizeof(test_list) / sizeof(test_list[0]); ++i) {
            size_t size = test_list[i];

            data_t** mm = new data_t*[size];
            data_t** mm_totest = new data_t*[size];
            for (size_t j = 0; j < size; ++j) {
                mm[j] = new data_t[size];
                mm_totest[j] = new data_t[size];
            }
            data_t* vv = new data_t[size];
            data_t* vv_totest = new data_t[size];

            do_generate_random_matrix(size, mm, vv);

            for (size_t j = 0; j < size; ++j) {
                vv_totest[j] = vv[j];
                for (size_t y = 0; y < size; ++y) {
                    mm_totest[j][y] = mm[j][y];
                }
            }
            do_print_matrix(size, mm, vv);

            std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
            
            data_t* mm_res = do_gauss(size, mm, vv);

            std::chrono::steady_clock::time_point stop = std::chrono::steady_clock::now();
            std::chrono::microseconds dur = std::chrono::duration_cast<
                std::chrono::microseconds>(stop - start);
            std::cout << "microseconds:" << std::setw(10) << dur.count()
                << " matrix size:" << std::setw(10) << size << std::endl;

            do_print_results(size, mm_totest, vv_totest, mm_res);

            for (size_t j = 0; j < size; ++j) {
                delete[] mm[j];
                delete[] mm_totest[j];
            }
            delete[] mm;
            delete[] mm_totest;
            delete[] vv;
            delete[] vv_totest;
            delete[] mm_res;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error:" << e.what() << std::endl;
        ret = EXIT_FAILURE;
    }
    _CrtDumpMemoryLeaks();
    return ret;
}
