#include <iostream>
#include "mylist.h"
#include <list>

using MyListType = int;
using MyList = dslist::List<MyListType>;

int main(int argc, char *argv[]) {
    MyList l;
    l.push_back(1);
    std::cout << l.size() << std::endl;

    return EXIT_SUCCESS;
}
