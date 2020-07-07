#include <iostream>
#include <cassert>
#include "findlistmiddle.h"
#include "forwardlistutil.h"

void find_middle_element_in_forward_list(void) {
    IntNode* head = new IntNode(0);
    IntNode* tail = head;
    for (int i = 1; i < 10; ++i) {
        tail = add_node<IntNode>(&tail->_next, i);
    }

    IntNode* slow = head;
    IntNode* fast = slow;
    while (fast) {
        fast = fast->_next;
        if (fast) {
            fast = fast->_next;
            if (fast) {
                slow = slow->_next;
            }
        }
    }
    std::cout << "Middle element:" << slow->_value << std::endl;
    assert(slow->_value == 4);

    while (head) {
        IntNode* tmp = head;
        head = head->_next;
        delete tmp;
    }
}