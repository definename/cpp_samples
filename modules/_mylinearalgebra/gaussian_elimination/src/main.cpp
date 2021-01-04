#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <chrono>
#include <intrin.h>

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
    for (int i = 0, imax = x.size() - 1; i < imax; ++i) {
#pragma loop(hint_parallel(0))
#pragma loop(ivdep)
        for (int j = i + 1, jmax = x.size(); j < jmax; ++j) {
            double a = -x[j][i] / x[i][i];
            if (size <= 10) {
                std::cout << "a=" << a << std::endl;
            }

            double tmp_y = a * y[i];
            y[j] = y[j] + tmp_y;

            for (int t = 0, tmax = static_cast<int>(x[i].size()); t < tmax; ++t) {
                double tmp_t = x[i][t] * a;
                x[j][t] = x[j][t] + tmp_t;
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

void check_avx_support(void) {
    bool avxSupported = false;

    // If Visual Studio 2010 SP1 or later
#if (_MSC_FULL_VER >= 160040219)
    // Checking for AVX requires 3 things:
    // 1) CPUID indicates that the OS uses XSAVE and XRSTORE
    //     instructions (allowing saving YMM registers on context
    //     switch)
    // 2) CPUID indicates support for AVX
    // 3) XGETBV indicates the AVX registers will be saved and
    //     restored on context switch
    //
    // Note that XGETBV is only available on 686 or later CPUs, so
    // the instruction needs to be conditionally run.
    int cpuInfo[4];
    __cpuid(cpuInfo, 1);

    bool osUsesXSAVE_XRSTORE = cpuInfo[2] & (1 << 27) || false;
    bool cpuAVXSuport = cpuInfo[2] & (1 << 28) || false;

    if (osUsesXSAVE_XRSTORE && cpuAVXSuport)
    {
        // Check if the OS will save the YMM registers
        unsigned long long xcrFeatureMask = _xgetbv(_XCR_XFEATURE_ENABLED_MASK);
        avxSupported = (xcrFeatureMask & 0x6) || false;
    }
#endif

    if (avxSupported)
    {
        printf("AVX is supported\n");
    }
    else
    {
        printf("AVX is NOT supported\n");
    }
}

int main(const int argc, const char* argv[]) {
    try {
        check_avx_support();

        std::vector<int> size_list({ 10,100,500,1000,2000,3000 });
        for (size_t size_index = 0; size_index < size_list.size(); ++size_index) {
            size_t size = size_list[size_index];
            std::vector<std::vector<double>> x(size, std::vector<double>(size, 0));
            std::vector<double> y(size, 0);

            generate_matrix_01(size, x, y);
            if (size <= 10) {
                dump(x, y);
            }

//             size_t size = 4;
//             std::vector<std::vector<double>> x = {
//                 {3,2,1,1},
//                 {1,-1,4,-1},
//                 {-2,-2,-3,1},
//                 {1,5,-1,2}
//             };
//             std::vector<double> y = { -2,-1,9,4 };
//             dump(x, y);

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
