#include <iostream>

#include "mycircularlist.h"
#include <forward_list>

using MyCircularType = int;
using MyCircularList = dscircular::CircularList<MyCircularType>;
using MyCircularNode = MyCircularList::NodeType;

void cleanup(MyCircularNode* head) {
    MyCircularNode* tmp = head;
    do {
        MyCircularNode* to_delete = tmp;
        tmp = tmp->next_;
        delete to_delete;
    } while (tmp != head);
}

void display(MyCircularNode* head) {
    MyCircularNode* tmp = head;
    do {
        std::cout << tmp->data_ << " ";
        tmp = tmp->next_;
    } while (tmp != head);
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    MyCircularList l;

    MyCircularNode* head = new MyCircularNode(0);
    head->next_ = head;

    MyCircularNode* tail = head;
    for (int i = 1; i < 10; ++i) {
        tail->next_ = new MyCircularNode(i);
        tail->next_->next_ = head;
        tail = tail->next_;
    }

    display(head);
    cleanup(head);

    return EXIT_SUCCESS;
}
