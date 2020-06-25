#ifndef FINDLOOP_H
#define FINDLOOP_H

#include <iostream>
#include "myforwardlist.h"

using LoopList = dslist::FwdListNode<int>;

LoopList* add_node(LoopList** head, const int data) {
    *head = new LoopList(data);
    (*head)->data_ = data;
    (*head)->next_ = nullptr;
    return (*head);
}

void find_loop_in_linked_list(void) {
    bool is_loop = false;

    // Create loop
    auto head = new LoopList(1);
    auto tail = add_node(&head->next_, 1);
    for (int i = tail->data_; i < 10; ++i) {
        tail = add_node(&tail->next_, i);
    }
    tail->next_ = head;

    // Find loop
    auto slow = head;
    auto fast = slow->next_;
    while (fast != nullptr) {
        fast = fast->next_;
        if (slow == fast) {
            is_loop = true;
            break;
        }
        fast = fast->next_;
        slow = slow->next_;
    }

    if (is_loop) {
        std::cout << "Loop detected at:" << slow->data_ << std::endl;
    } else {
        std::cout << "No loop detected" << std::endl;
    }

    // Break loop
    tail->next_ = nullptr;
    // Clean up loop
    LoopList* tmp = nullptr;
    while (head) {
        tmp = head;
        head = head->next_;
        delete tmp;
    }
}

#endif