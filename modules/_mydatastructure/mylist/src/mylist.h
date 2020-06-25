#ifndef MY_LIST_H
#define MY_LIST_H

namespace dslist {

template<typename T>
struct ListNode {
    T data_;
    ListNode<T>* next_;
};

}

#endif