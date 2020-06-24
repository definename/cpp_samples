#ifndef MYFORWARDLIST
#define MYFORWARDLIST

namespace dslist {

template<typename T>
struct FwdListNode {
    using Self = FwdListNode<T>;

    FwdListNode(const T& data = T(), Self* next = nullptr) {
        data_ = data;
        next_ = next;
    }

    T data_;
    Self* next_;
};

template<typename T>
class ForwardList {
    public:
    using NodeType = FwdListNode<T>;

    ForwardList() {
        head_ = nullptr;
    }

    void push_front(const T& val) {
        head_ = new NodeType(val, head_);
    }

    // Remove after iterator will be implemented
    void fwd_list_display(void) {
        NodeType* node = head_;
        while (node != nullptr) {
            std::cout << node->data_ << " ";
            node = node->next_;
        }
        std::cout << std::endl;
    }

    private:
    NodeType* head_;
};

}

#endif