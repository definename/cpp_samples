#ifndef MY_FORWARD_LIST_H
#define MY_FORWARD_LIST_H

#define USE_FAST_ALGORITM 1

namespace dslist {

template<typename T>
struct FwdListNode {
    using self = FwdListNode<T>;
    using value_type = T;

    FwdListNode(const value_type& value = T(), self* next = nullptr)
    : _value(value)
    , _next(next) {
    }

    value_type _value;
    self* _next;
};

template<typename T>
struct FwdListIterator {
    using value_type = T;
    using self = FwdListIterator<value_type>;
    using node_type = FwdListNode<value_type>;
    using reference = value_type&;

    explicit FwdListIterator(node_type* node)
    : _node(node) {
    }

    reference operator*() const {
        return _node->_value;
    }

    self& operator++() {
        _node = _node->_next;
        return *this;
    }

    self operator++(int) {
        self tmp = *this;
        _node = _node->_next;
        return tmp;
    }

    bool operator==(const self& it) const {
        return _node == it._node;
    }

    bool operator!=(const self& it) const {
        return _node != it._node;
    }

    node_type* _node;
};

template<typename T>
struct FwdListConstIterator {
    using value_type = T;
    using node_type = const FwdListNode<value_type>;
    using reference = const value_type&;
    using self = FwdListConstIterator<value_type>;
    using iterator = FwdListIterator<value_type>;

    explicit FwdListConstIterator(const node_type* node)
    : _node(node) {
    }

    FwdListConstIterator(const iterator& it)
    : _node(it._node) {
    }

    reference operator*() const {
        return _node->_value;
    }

    self& operator++() {
        _node = _node->_next;
        return *this;
    }

    self operator++(int) {
        self tmp = *this;
        _node = _node->_next;
        return tmp;
    }

    bool operator==(const self& it) const {
        return _node == it._node;
    }

    bool operator!=(const self& it) const {
        return _node != it._node;
    }

    const node_type* _node;
};

template<typename T>
class ForwardList {
    public:
    using value_type = T;
    using node_type = FwdListNode<value_type>;
    using iterator = FwdListIterator<value_type>;
    using const_iterator = FwdListConstIterator<value_type>;

    public:
    ForwardList()
    : _head(nullptr) {
    }

    ~ForwardList() {
        clear();
    }

    bool empty() const {
        return begin() == end();
    }

    void push_front(const T& val) {
        _head = new node_type(val, _head);
    }

    void pop_front() {
        if (_head) {
            node_type* tmp = _head;
            _head = _head->_next;
            delete tmp;
        }
    }

    void clear() {
        node_type* tmp = nullptr;
        while (!empty()) {
            tmp = _head;
            _head = _head->_next;
            delete tmp;
        }
    }

    iterator begin() {
        return iterator(_head);
    }

    const_iterator begin() const {
        return const_iterator(_head);
    }

    iterator end() {
        return iterator(nullptr);
    }

    const_iterator end() const {
        return const_iterator(nullptr);
    }

    const_iterator cbegin() const {
        return const_iterator(_head);
    }

    const_iterator cend() const {
        return const_iterator(nullptr);
    }

    void unique() {
        if (_head) {
            node_type* node_prev = _head;
            node_type* node_next = _head->_next;

            while (node_next) {
                if (node_prev->_value == node_next->_value) {
                    node_prev->_next = node_next->_next;
                    delete node_next;
                    node_next = node_prev->_next;
                } else {
                    node_prev = node_next;
                    node_next = node_next->_next;
                }
            }
        }
    }

    void reverse() {
        node_type* head = _head;
        node_type* mid = nullptr, *tail = nullptr;

        while (head) {
            tail = mid;
            mid = head;
            head = head->_next;

            mid->_next = tail;
        }
        _head = mid;
    }

    void merge(ForwardList& other) {
#if USE_FAST_ALGORITM
        merge_bigO_n_plus_m(other);
#else
        merge_bigO_n_square(other);
#endif
    }

private:
    void merge_bigO_n_plus_m(ForwardList& other) {
        if (!_head) {
            _head = other._head;
            other._head = nullptr;
            return;
        }

        if (other._head) {
            node_type* third = nullptr;
            node_type* last = nullptr;

            node_type* first = _head;
            node_type* second = other._head;

            if (first->_value < second->_value) {
                third = last = first;
                first = first->_next;
            } else {
                third = last = second;
                second = second->_next;
            }
            last->_next = nullptr;

            while (first != nullptr && second != nullptr) {
                if (first->_value < second->_value) {
                    last->_next = first;
                    last = first;
                    first = first->_next;
                } else {
                    last->_next = second;
                    last = second;
                    second = second->_next;
                }
                last->_next = nullptr;
            }

            if (first != nullptr) {
                last->_next = first;
            } else {
                last->_next = second;
            }

            _head = third;
            other._head = nullptr;
        }
    }

    void merge_bigO_n_square(ForwardList& other) {
        if (!_head) {
            _head = other._head;
            other._head = nullptr;
            return;
        }

        while (other._head != nullptr) {
            node_type* insert = other._head;
            other._head = other._head->_next;

            node_type* dst_prev = nullptr;
            node_type* dst_next = _head;
            while (dst_next && insert->_value > dst_next->_value) {
                dst_prev = dst_next;
                dst_next = dst_next->_next;
            }

            if (dst_next && dst_prev) {
                insert->_next = dst_next;
                dst_prev->_next = insert;
            } else if (dst_next) {
                insert->_next = dst_next;
                _head = insert;
            } else {
                insert->_next = nullptr;
                dst_prev->_next = insert;
            }
        }
    }

    private:
    node_type* _head;
};

}

#endif