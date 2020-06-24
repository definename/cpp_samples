#include <iostream>
#include "mylist.h"

using MyList = datastruct::ListNode<int>;

static MyList* add(MyList** l, const int data) {
    *l = new MyList;
    (*l)->val_ = data;
    (*l)->next_ = nullptr;
    return (*l);
}

static void dump_list(MyList* head) {
    if (head == nullptr) {
        std::cout << "empty" << std::endl;
        return;
    }

    MyList* it = head;
    while (it != nullptr) {
        std::cout << it->val_ << " ";
        it = it->next_;
    }
    std::cout << std::endl;
}

void merge_two_sorted_linked_lists(void) {
    MyList* node = nullptr;

    MyList* dst = nullptr;
    node = add(&dst, 1);
    node = add(&node->next_, 3);
    node = add(&node->next_, 5);
    dump_list(dst);

    MyList* src = nullptr;
    node = add(&src, 2);
    node = add(&node->next_, 4);
    node = add(&node->next_, 6);
    dump_list(src);

    // Merge two sorted linked lists
    while (src != nullptr) {
        MyList* insert = src;
        src = src->next_;

        MyList* dst_prev = nullptr;
        MyList* dst_next = dst;
        while (dst_next && insert->val_ > dst_next->val_) {
            dst_prev = dst_next;
            dst_next = dst_next->next_;
        }

        if (dst_next && dst_prev) {
            dst_prev->next_ = insert;
            insert->next_ = dst_next;
        } else if (dst_next) {
            insert->next_ = dst_next;
            dst = insert;
        } else {
            dst_prev->next_ = insert;
            insert->next_ = nullptr;
        }
    }

    dump_list(dst);
    dump_list(src);
}

void find_loop_in_linked_list(void) {
    MyList* head = nullptr;
    MyList* node = add(&head, 1);
    node = add(&node->next_, 3);
    node = add(&node->next_, 5);
    // Create loop
    node->next_ = head;

    MyList* slow = head;
    MyList* fast = head->next_;
    while (fast != nullptr) {
        fast = fast->next_;

        if (slow == fast) {
            std::cout << "loop found:"
            << slow << ":" <<  slow->val_ << " "
            << fast << ":" << fast->val_ << std::endl;
            break;
        }
        fast = fast->next_;
        slow = slow->next_;
    }
}
int main(int argc, char *argv[]) {

    merge_two_sorted_linked_lists();
    find_loop_in_linked_list();

    return EXIT_SUCCESS;
}
