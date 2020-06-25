#include <iostream>

#include "myforwardlist.h"
#include "myforwarlistutil.h"

#include <forward_list>


int main(int argc, char *argv[]) {
    int arr[] = { 1, 22, 33, 44, 55, 66, 77, 88, 99, 100 };

    // dsutil::FwdNode *head;
    // dsutil::fwd_list_create(&head, arr, 10);

    // dsutil::fwd_list_display(head);
    // dsutil::fwd_list_display_recursive(head);
    // std::cout << "list size:" << dsutil::fwd_list_count(head) << std::endl;
    // std::cout << "max is:" << dsutil::fwd_list_find_max(head) << std::endl;

    // dsutil::FwdNode* found = dsutil::fwd_list_search(head, 77);
    // std::cout << (found ? "found" : "not found") << std::endl;

    // std::forward_list<int*> ll;
    // ll.push_front(new int(1));
    // ll.push_front(new int(2));

    // std::forward_list<int*>::const_iterator it = ll.begin();
    // for (it; it != ll.end(); ++it) {
    //     std::cout << *(*it) << std::endl;
    // }

    // Template implementation
    dslist::ForwardList<int> l;
    l.push_front(1);
    l.push_front(2);

    dslist::ForwardList<int>::const_iterator it = l.begin();
    for (it; it != l.cend(); it++) {
        std::cout << *it << std::endl;
    }
    l.pop_front();

    return EXIT_SUCCESS;
}
