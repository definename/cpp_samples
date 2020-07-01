#include <iostream>

#include "mycircularlist.h"
#include <forward_list>

using MyCircularType = int;
using MyCircularList = dscircular::CircularList<MyCircularType>;
using MyCircularNode = MyCircularList::NodeType;

MyCircularNode* add_node(MyCircularNode** node, const MyCircularType& data) {
    (*node) = new MyCircularNode(data);
    return (*node);
}

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

    MyCircularNode* head = nullptr;
    MyCircularNode* tail = add_node(&head, 0);
    tail = add_node(&tail->next_, 1);
    tail = add_node(&tail->next_, 2);
    tail = add_node(&tail->next_, 3);
    tail = add_node(&tail->next_, 4);
    tail->next_ = head;

    display(head);
    cleanup(head);

    return EXIT_SUCCESS;
}
