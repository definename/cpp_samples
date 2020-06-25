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
struct FwdListIterator {
    using Self = FwdListIterator<T>;
    using NodeType = FwdListNode<T>;

    using value_type = T;
    using reference = T&;
    using pointer = NodeType*;

    explicit FwdListIterator(NodeType* node = nullptr) {
        node_ = node;
    }

    reference operator*() const {
        return node_->data_;
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

    bool operator==(const Self& it) const {
        return node_ == it.node_;
    }

    bool operator!=(const Self& it) const {
        return node_ != it.node_;
    }

    NodeType* node_;
};

template<typename T>
struct FwdListConstIterator {
    using Self = FwdListConstIterator<T>;
    using NodeType = const FwdListNode<T>;
    using iterator = FwdListIterator<T>;

    using value_type = T;
    using reference = const T&;

    explicit FwdListConstIterator(const NodeType* node = nullptr) {
        node_ = node;
    }

    FwdListConstIterator(const iterator& it) {
        node_ = it.node_;
    }

    reference operator*() const {
        return node_->data_;
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

    bool operator==(const Self& it) const {
        return node_ == it.node_;
    }

    bool operator!=(const Self& it) const {
        return node_ != it.node_;
    }

    NodeType* node_;
};

template<typename T>
class ForwardList {
    public:
    using value_type = T;
    using iterator = FwdListIterator<T>;
    using const_iterator = FwdListConstIterator<T>;

    private:
    using NodeType = FwdListNode<T>;

    public:
    ForwardList() {
        head_ = nullptr;
    }

    void push_front(const T& val) {
        head_ = new NodeType(val, head_);
    }

    iterator begin() {
        return iterator(head_);
    }

    const_iterator cbegin() const {
        return const_iterator(head_);
    }

    iterator end() {
        return iterator(nullptr);
    }

    const_iterator cend() const {
        return const_iterator(nullptr);
    }

    private:
    NodeType* head_;
};

}

#endif