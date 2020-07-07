#include <iostream>
#include "findlistloop.h"
#include "forwardlistutil.h"

void find_loop_in_linked_list(void) {
    bool is_loop = false;

    // Create loop
    auto head = new IntNode(1);
    IntNode* tail = head;
    for (int i = 1; i < 11; ++i) {
        tail = add_node(&tail->_next, i);
    }
    tail->_next = head;

    // Find loop
    auto slow = head;
    auto fast = slow->_next;
    while (fast != nullptr && fast->_next != nullptr) {
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
        IntNode* tmp = head;
        do {
            IntNode* to_delete = tmp;
            tmp = tmp->_next;
            delete to_delete;
        } while(tmp != head);
    } else {
        std::cout << "No loop detected" << std::endl;
        while (head != nullptr) {
            IntNode* tmp = head;
            head = head->_next;
            delete tmp;
        }
    }
}