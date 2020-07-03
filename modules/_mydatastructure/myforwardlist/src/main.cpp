#include <iostream>
#include "myforwardlist.h"
#include "findloop.h"

using MyForwarListType = int;
using MyForwarList = dslist::ForwardList<MyForwarListType>;

#include <forward_list>

int main(int argc, char *argv[]) {

    find_loop_in_linked_list();

    {
        MyForwarList l;

        if (l.empty()) {
            std::cout << "empty" << std::endl;
        }

        l.push_front(99);
        l.push_front(97);
        l.push_front(2);
        l.push_front(2);
        l.push_front(1);

        MyForwarList other;
        other.push_front(20);
        other.push_front(10);
        other.push_front(2);
        other.push_front(0);

        // l.reverse();
        // l.unique();
        l.merge(other);

        MyForwarList::const_iterator it = l.cbegin();
        for (it; it != l.cend(); it++) {
            std::cout << *it << "; ";
        }
        std::cout << std::endl;
    }



    {
        // std::forward_list<int> l = {1, 2, 2, 97, 99};
        // std::forward_list<int> l;
        // std::forward_list<int> other = {0, 10, 20};
        // l.merge(other);

        // std::forward_list<int>::const_iterator it = l.begin();
        // for (it; it != l.end(); ++it) {
        //     std::cout << *it << " ";
        // }
        // std::cout << std::endl;

        // std::forward_list<int>::const_iterator it_other = other.begin();
        // for (it_other; it_other != other.end(); ++it_other) {
        //     std::cout << *it << " ";
        // }
        // std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
