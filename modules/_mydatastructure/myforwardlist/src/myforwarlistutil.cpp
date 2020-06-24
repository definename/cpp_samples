#include <iostream>
#include "myforwarlistutil.h"

namespace dsutil {

void fwd_list_create(FwdNode **first, int arr[], const int size) {
    FwdNode* last, *tmp = nullptr;
    *first = new FwdNode;
    (*first)->data_ = arr[0];
    (*first)->next_ = nullptr;
    last = *first;

    for (int i = 1; i < size; ++i) {
        tmp = new FwdNode;
        tmp->data_ = arr[i];
        tmp->next_ = nullptr;
        last->next_ = tmp;
        last = tmp;
    }
}

void fwd_list_display(const FwdNode* first) {
    while (first != nullptr) {
        std::cout << first->data_ << " ";
        first = first->next_;
    }
    std::cout << std::endl;
}

void fwd_list_display_recursive(const FwdNode* first) {
    if (first != nullptr) {
        std::cout << first->data_ << " ";
        fwd_list_display_recursive(first->next_);
    } else {
        std::cout << std::endl;
    }
}

std::size_t fwd_list_count(FwdNode* head) {
    std::size_t size = 0;
    while (head != nullptr) {
        head = head->next_;
        ++size;
    }
    return size;
}

}