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

    ~ForwardList() {
        clear();
    }

    void push_front(const T& val) {
        head_ = new NodeType(val, head_);
    }

    void pop_front() {
        if (head_) {
            NodeType* tmp = head_;
            head_ = head_->next_;
            delete tmp;
        }
    }

    void clear() {
        NodeType* tmp = nullptr;
        while (head_) {
            tmp = head_;
            head_ = head_->next_;
            delete tmp;
        }
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

    void unique() {
        if (head_) {
            NodeType* node_prev = head_;
            NodeType* node_next = head_->next_;

            while (node_next) {
                if (node_prev->data_ == node_next->data_) {
                    node_prev->next_ = node_next->next_;
                    delete node_next;
                    node_next = node_prev->next_;
                } else {
                    node_prev = node_next;
                    node_next = node_next->next_;
                }
            }
        }
    }

    void reverse() {
        NodeType* head = head_;
        NodeType* mid = nullptr, *tail = nullptr;

        while (head) {
            tail = mid;
            mid = head;
            head = head->next_;

            mid->next_ = tail;
        }
        head_ = mid;
    }

    private:
    NodeType* head_;
};

}

#endif