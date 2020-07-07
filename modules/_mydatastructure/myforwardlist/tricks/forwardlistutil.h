#ifndef FORWARD_LIST_UTIL_H
#define FORWARD_LIST_UTIL_H

#include "myforwardlist.h"

using IntNode = dslist::FwdListNode<int>;

template<typename T>
T* add_node(T** head, const int data) {
    *head = new T(data);
    (*head)->_value = data;
    (*head)->_next = nullptr;
    return (*head);
}

#endif