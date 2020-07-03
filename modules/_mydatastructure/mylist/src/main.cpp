#include <iostream>
#include "mylist.h"
#include <list>

using MyListType = int;
using MyList = dslist::List<MyListType>;

int main(int argc, char *argv[]) {
    MyList l;

    if (l.begin() == l.end()) {
        std::cout << "equal" << std::endl;
    }

    l.push_back(11);
    l.push_back(12);
    l.push_back(14);

    // Iterator
    for (MyList::iterator it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Bidirection iterator
    MyList::iterator it = l.end();
    for (it; it != l.begin(); it--) {
        if (it != l.end()) {
            std::cout << *it << " ";
        }
    }
    std::cout << *it << std::endl;

    // Const iterator
    for (MyList::const_iterator it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Const iterator(cbegin)
    for (MyList::const_iterator it = l.cbegin(); it != l.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
