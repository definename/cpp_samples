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

void insert_before(MyCircularNode* head, const int pos, const MyCircularType& data) {
    MyCircularNode* to_insert = new MyCircularNode(data);
    MyCircularNode* tail = head;

    if (pos == 0) {
        to_insert->next_ = head;
        while (tail->next_ != head) {
            tail = tail->next_;
        }
        tail->next_ = to_insert;
    } else {
        int count = 0;
        while (count < pos - 1) {
            tail = tail->next_;
            ++count;
        }
        to_insert->next_ = tail->next_;
        tail->next_ = to_insert;
    }
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

    insert_before(head, 3, 99);
    insert_before(head, 0, 88);

    display(head);

    cleanup(head);

    return EXIT_SUCCESS;
}
