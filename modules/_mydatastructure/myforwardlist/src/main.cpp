#include <iostream>
#include "myforwardlist.h"

#include <forward_list>

int main(int argc, char *argv[]) {
    {
        std::forward_list<int> l = {1, 2, 2, 97, 99};

        std::forward_list<int> ll = {0, 10, 20};
        l.merge(ll);

        std::forward_list<int>::const_iterator it = l.begin();
        for (it; it != l.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

    }

    {
        // My template implementation
        dslist::ForwardList<int> l;
        l.push_front(99);
        l.push_front(97);
        l.push_front(2);
        l.push_front(2);
        l.push_front(1);

        dslist::ForwardList<int> other;
        other.push_front(20);
        other.push_front(10);
        other.push_front(0);

        // l.reverse();
        // l.unique();
        l.merge(other);

        dslist::ForwardList<int>::const_iterator it = l.begin();
        for (it; it != l.cend(); it++) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}
