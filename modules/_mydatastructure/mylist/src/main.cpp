#include <iostream>
#include "mylist.h"
#include <list>

using MyListType = int;
using MyList = dslist::List<MyListType>;

int main(int argc, char *argv[]) {
    MyList l;
    l.push_back(11);
    l.push_back(12);
    l.push_back(14);

    MyList::iterator it = l.begin();
    for (it; it != l.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    {
        // TODO: Implement
        std::list<int> ll;
        ll.push_back(11);
        ll.push_back(12);
        ll.push_back(14);

        std::list<int>::iterator itt = ll.end();
        --itt;
        std::cout << *itt << std::endl;
    }

    return EXIT_SUCCESS;
}
