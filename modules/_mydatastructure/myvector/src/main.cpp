#include <iostream>
#include "myvector.h"

using MyVector = dsvector::Vector<int>;
using MyVectorBool = dsvector::Vector<bool>;

static void dump_vector(const MyVector& v) {
    MyVector::const_iterator it = v.begin();
    for (it; it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    MyVector v(5);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    v[0] = 99;
    std::cout << v[0] << std::endl;

    v.insert(v.begin(), 100);
    std::cout << v[0] << std::endl;

    for (int i = 0; i < 11; ++i) {
        v.push_back(i);
    }

    dump_vector(v);

    MyVectorBool vb(2);
    vb[0] = false;
    vb[1] = true;
    std::cout << vb[1] << std::endl;
    return EXIT_SUCCESS;
}
