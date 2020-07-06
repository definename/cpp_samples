#include <iostream>
#include "mylist.h"

#include <list>
#include <algorithm>
#include <cassert>

using MyListType = int;
using MyList = dslist::List<MyListType>;

void dump(MyList& l) {
    for (MyList::const_iterator it = l.cbegin(); it != l.cend(); ++it) {
        std::cout << *it << "-";
    }
    std::cout << std::endl;
}

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

    // Inline with stl algorithms
    auto found = std::find(l.begin(), l.end(), 11);
    if (found == l.end()) {
        std::cout << "not found" << std::endl;
    } else {
        std::cout << "found:" << *found << std::endl;
    }

    // Insert
    std::cout << "inserted at:" << *l.insert(found, 10) << std::endl;
    dump(l);

    // Push front
    l.push_front(2);
    l.push_front(1);
    dump(l);

    // Erase at position
    std::cout << "removed before:" << *l.erase(l.begin()) << std::endl;
    assert(l.erase(l.end()) == l.end());
    dump(l);

    // Pop back
    l.pop_back();
    dump(l);

    // Pop front
    l.pop_front();
    dump(l);

    // Reverse
    l.reverse();
    dump(l);

    return EXIT_SUCCESS;
}
