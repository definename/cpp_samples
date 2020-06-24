#include <iostream>

#include "myforwardlist.h"
#include "myforwarlistutil.h"

#include <forward_list>


int main(int argc, char *argv[]) {
    int arr[] = { 1, 22, 33, 44, 55, 66, 77, 88, 99, 100 };

    dsutil::FwdNode *head;
    dsutil::fwd_list_create(&head, arr, 10);

    dsutil::fwd_list_display(head);
    dsutil::fwd_list_display_recursive(head);
    std::cout << "list size:" << dsutil::fwd_list_count(head) << std::endl;
    std::cout << "max is:" << dsutil::fwd_list_find_max(head) << std::endl;

    dsutil::FwdNode* found = dsutil::fwd_list_search(head, 77);
    std::cout << (found ? "found" : "not found") << std::endl;

    // Template implementation

    dslist::ForwardList<int> l;
    l.push_front(1);
    l.push_front(2);

    // Remove after iterator will be implemented
    l.fwd_list_display();

    return EXIT_SUCCESS;
}
