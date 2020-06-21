#include <iostream>
#include "myvector.h"

using MyVector = datastruct::Vector<int>;

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
    v.push_back(2);

    v[0] = 99;
    std::cout << v[0] << std::endl;
    v.insert(v.begin(), 100);
    std::cout << v[0] << std::endl;

    dump_vector(v);

    return EXIT_SUCCESS;
}
