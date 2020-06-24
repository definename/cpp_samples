#ifndef MYFORWARDLISTUTIL
#define MYFORWARDLISTUTIL

#include "myforwardlist.h"

namespace dsutil {

using FwdNode = dslist::FwdListNode<int>;

void fwd_list_create(FwdNode **first, int arr[], const int size);
void fwd_list_display(const FwdNode* first);
void fwd_list_display_recursive(const FwdNode* first);
std::size_t fwd_list_count(FwdNode* head);

}

#endif