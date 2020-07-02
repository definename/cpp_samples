#include <iostream>

#include "mycircularlist.h"
#include <forward_list>

using MyCircularType = int;
using MyCircularList = dscircular::CircularList<MyCircularType>;
using MyCircularNode = MyCircularList::NodeType;

int length(MyCircularNode* head) {
    int count = 0;
    if (head) {
        ++count;
        MyCircularNode* tmp = head;
        while (tmp->next_ != head) {
            tmp = tmp->next_;
            ++count;
        }
    }
    return count;
}

void cleanup(MyCircularNode* head) {
    if (head) {
        MyCircularNode* tmp = head;
        do {
            MyCircularNode* to_delete = tmp;
            tmp = tmp->next_;
            delete to_delete;
        } while (tmp != head);
    } else {
        std::cout << "cleanup: list is empty" << std::endl;
    }
}

void display(MyCircularNode* head) {
    if (head) {
        MyCircularNode* tmp = head;
        do {
            std::cout << tmp->data_ << " ";
            tmp = tmp->next_;
        } while (tmp != head);
        std::cout << std::endl;
    } else {
        std::cout << "display: list is empty" << std::endl;
    }
}

void insert_before(MyCircularNode** head, const int pos, const MyCircularType& data) {
    if (pos >= 0 && pos < length(*head)) {
        MyCircularNode* to_insert = new MyCircularNode(data);
        MyCircularNode* tmp = *head;

        if (pos == 0) {
            to_insert->next_ = *head;
            while (tmp->next_ != *head) {
                tmp = tmp->next_;
            }
            tmp->next_ = to_insert;
            *head = to_insert;
        } else {
            int count = 0;
            while (count < pos - 1) {
                tmp = tmp->next_;
                ++count;
            }
            to_insert->next_ = tmp->next_;
            tmp->next_ = to_insert;
        }
    } else {
        std::cout << "insert_before: out of range" << std::endl;
    }
}

void remove_at(MyCircularNode** head, const int pos) {
    if (pos >= 0 && pos < length(*head)) {
        MyCircularNode* tmp = *head;
        if (pos == 0) {
            while(tmp->next_ != *head) {
                tmp = tmp->next_;
            }
            if (tmp == (*head)) {
                delete (*head);
                (*head) = nullptr;
            } else {
                tmp->next_ = (*head)->next_;
                delete *head;
                *head = tmp->next_;
            }
        } else {
            int count = 0;
            while (count < pos - 1) {
                tmp = tmp->next_;
                ++count;
            }
            MyCircularNode* to_delete = tmp->next_;
            tmp->next_ = tmp->next_->next_;
            delete to_delete;
        }
    } else {
        std::cout << "remote_at: out of range" << std::endl;
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

    std::cout << "list length:" << length(head) << std::endl;

    display(head);

    insert_before(&head, 0, 99);
    insert_before(&head, 3, 88);

    display(head);

    remove_at(&head, 3);
    remove_at(&head, 0);

    display(head);

    cleanup(head);

    return EXIT_SUCCESS;
}
