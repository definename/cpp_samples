#ifndef FINDLOOP_H
#define FINDLOOP_H

#include <iostream>
#include "myforwardlist.h"

using LoopList = dslist::FwdListNode<int>;

LoopList* add_node(LoopList** head, const int data) {
    *head = new LoopList(data);
    (*head)->_value = data;
    (*head)->_next = nullptr;
    return (*head);
}

void find_loop_in_linked_list(void) {
    bool is_loop = false;

    // Create loop
    auto head = new LoopList(1);
    auto tail = add_node(&head->_next, 1);
    for (int i = tail->_value; i < 10; ++i) {
        tail = add_node(&tail->_next, i);
    }
    tail->_next = head;

    // Find loop
    auto slow = head;
    auto fast = slow->_next;
    while (fast != nullptr) {
        fast = fast->_next;
        if (slow == fast) {
            is_loop = true;
            break;
        }
        fast = fast->_next;
        slow = slow->_next;
    }

    if (is_loop) {
        std::cout << "Loop detected at:" << slow->_value << std::endl;
    } else {
        std::cout << "No loop detected" << std::endl;
    }

    // Clean up
    LoopList* tmp = head;
    do {
        LoopList* to_delete = tmp;
        tmp = tmp->_next;
        delete to_delete;
    } while(tmp != head);
}

#endif