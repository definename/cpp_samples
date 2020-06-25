#include <iostream>
#include "myvector.h"

using MyVector = dsvector::Vector<int>;

static void dump_vector(const MyVector& v) {
    MyVector::const_iterator it = v.begin();
    for (it; it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    MyVector v(10);
    v.push_back(1);
    v.push_back(88);

    v[0] = 99;
    std::cout << v[0] << std::endl;
    v.insert(v.begin(), 100);
    std::cout << v[0] << std::endl;

    for (int i = 0; i < 11; ++i) {
        v.push_back(i);
        v.insert(v.begin() + i, i);
    }

    dump_vector(v);

    return EXIT_SUCCESS;
}
