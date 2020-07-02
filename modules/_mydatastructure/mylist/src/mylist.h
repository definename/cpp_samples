#ifndef MY_LIST_H
#define MY_LIST_H

namespace dslist {

template<typename T>
struct ListNode {
    using value_type = T;
    using _self = ListNode<value_type>;

    ListNode(const value_type& value, _self* prev, _self* next)
    : value_(value)
    , prev_(prev)
    , next_(next) {
    }

    value_type value_;
    _self* prev_;
    _self* next_;
};

template<typename T>
class List {
    public:
    using value_type = T;
    using NodeType = ListNode<value_type>;
    using size_type = std::size_t;

    public:
    List()
    : node_(nullptr)
    , size_(0) {
    }

    void push_back(const value_type& value) {
        NodeType* node = new NodeType(value, node_, nullptr);
        if (node_ == nullptr) {
            node_ = node;
        } else {
            node_->next_ = node;
        }
        ++size_;
    }

    size_type size() const {
        return size_;
    }

    private:
    NodeType* node_;
    size_type size_;
};

}

#endif