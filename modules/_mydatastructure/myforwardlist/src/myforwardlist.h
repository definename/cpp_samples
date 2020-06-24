#ifndef MYFORWARDLIST
#define MYFORWARDLIST

namespace dslist {

template<typename T>
struct FwdListNode {
    T data_;
    FwdListNode<T>* next_;
};

template<typename T>
class ForwardList {
    public:
    using NodeType = FwdListNode<T>*;
};

}

#endif