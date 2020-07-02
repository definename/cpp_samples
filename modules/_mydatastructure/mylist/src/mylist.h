#ifndef MY_LIST_H
#define MY_LIST_H

namespace dslist {

template<typename T>
struct ListNode {
    using value_type = T;
    using Self = ListNode<value_type>;

    ListNode(const value_type& value, Self* prev, Self* next)
    : value_(value)
    , prev_(prev)
    , next_(next) {
    }

    value_type value_;
    Self* prev_;
    Self* next_;
};

template<typename T>
struct ListIterator {
    using NodeType = ListNode<T>;

    using value_type = T;
    using reference = T&;
    using Self = ListIterator<value_type>;

    ListIterator(NodeType* node)
    : node_(node) {
    }

    reference operator*() {
        return node_->value_;
    }

    Self& operator++() {
        node_ = node_->next_;
        return *this;
    }

    Self operator++(int) {
        Self tmp = *this;
        node_ = node_->next_;
        return tmp;
    }

    bool operator==(const Self& it) {
        return node_ == it.node_;
    }

    bool operator!=(const Self& it) {
        return node_ != it.node_;
    }

    private:
    NodeType* node_;
};

template<typename T>
class List {
    public:
    using NodeType = ListNode<T>;

    using value_type = T;
    using size_type = std::size_t;
    using iterator = ListIterator<value_type>;

    public:
    List()
    : node_(nullptr)
    , tail_(nullptr)
    , size_(0) {
    }

    void push_back(const value_type& value) {
        NodeType* node = new NodeType(value, nullptr, nullptr);
        if (node_ == nullptr) {
            node_ = node;
            tail_ = node_;
        } else {
            node->next_ = nullptr;
            node->prev_ = tail_;
            tail_->next_ = node;
            tail_= node;
        }
        ++size_;
    }

    size_type size() const {
        return size_;
    }

    iterator begin() {
        return iterator(node_);
    }

    iterator end() {
        return iterator(nullptr);
    }

    private:
    NodeType* node_;
    NodeType* tail_;
    size_type size_;
};

}

#endif