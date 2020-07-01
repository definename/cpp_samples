#ifndef MY_CIRCULAR_LIST_H
#define MY_CIRCULAR_LIST_H

namespace dscircular {

template<typename T>
struct CircularNode {
    using Self = CircularNode<T>;
    using value_type = T;

    CircularNode(const value_type& data) {
        data_ = data;
        next_ = nullptr;
    }

    value_type data_;
    Self* next_;
};

template<typename T>
class CircularList {
    public:
    using value_type = T;
    using NodeType = CircularNode<T>;

    public:
    CircularList()
    : head_(nullptr) {
    }

    private:
    NodeType* head_;
};

}

#endif