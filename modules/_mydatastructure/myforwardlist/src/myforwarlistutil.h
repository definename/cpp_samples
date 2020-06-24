#ifndef MYFORWARDLISTUTIL
#define MYFORWARDLISTUTIL

#include "myforwardlist.h"

namespace dsutil {

using FwdNode = dslist::FwdListNode<int>;

void fwd_list_create(FwdNode **head, int arr[], const int size);
void fwd_list_display(const FwdNode* head);
void fwd_list_display_recursive(const FwdNode* head);
std::size_t fwd_list_count(FwdNode* head);
int fwd_list_find_max(const FwdNode* head);
FwdNode* fwd_list_search(FwdNode* head, const int key);

}

#endif