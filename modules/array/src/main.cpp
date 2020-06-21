#include <iostream>

void create_1d_array_dynamic(void) {
    const int size = 5;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }

    int *test_arr_ptr = arr;
    std::cout << "1d access via ptr arr[2]:" << *(test_arr_ptr + 2) << std::endl;
    std::cout << "1d access via ptr arr[1]:" << *(++test_arr_ptr) << std::endl;

    std::cout << "1d array dynamic:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete [] arr;
}

void create_2d_array_static_row_dynamic_column(void) {
    const int row = 3;
    int* a[row];
    const int col = 4;
    a[0] = new int[col];
    a[1] = new int[col];
    a[2] = new int[col];
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            a[r][c] = c * 10;
        }
    }
    std::cout << "2d array static+heap:" << std::endl;
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            std::cout << a[r][c] << " ";
        }
        std::cout << std::endl;
    }

    for (int r = 0; r < row; ++r) {
        delete [] a[r];
    }
}

void create_2darray_dymanic_row_dynamic_column(void) {
    int **a;
    const int row = 3;
    a = new int*[row];

    const int col = 4;
    for (int r = 0; r < row; ++r) {
        a[r] = new int[col];
    }

    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            a[r][c] = c + 11;
        }
    }

    std::cout << "2d array heap:" << std::endl;
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
            std::cout << a[r][c] <<  " ";
        }
        std::cout << std::endl;
    }

    for (int r = 0; r < row; ++r) {
        delete [] a[r];
    }
    delete [] a;
}

int main(int argc, char *argv[]) {
    create_1d_array_dynamic();
    create_2d_array_static_row_dynamic_column();
    create_2darray_dymanic_row_dynamic_column();

    return EXIT_SUCCESS;
}