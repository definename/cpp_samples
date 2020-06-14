#include <iostream>

int main(int argc, char *argv[]) {
    const int size = 5;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = i * 2;
    }

    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }
    delete [] arr;
    return EXIT_SUCCESS;
}