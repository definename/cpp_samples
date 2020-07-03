#ifndef MY_LIST_H
#define MY_LIST_H

namespace dslist {

template<typename T>
struct ListNode {
    using value_type = T;
    using self = ListNode<value_type>;

    ListNode(const value_type& value = T(), self* prev = nullptr, self* next = nullptr)
    : _value(value)
    , _prev(prev)
    , _next(next) {
    }

    value_type _value;
    self* _prev;
    self* _next;
};

template<typename T>
struct ListIterator {
    using value_type = T;
    using node_type = ListNode<value_type>;
    using reference = value_type&;
    using self = ListIterator<value_type>;

    ListIterator(node_type* node)
    : _node(node) {
    }

    reference operator*() {
        return _node->_value;
    }

    self& operator++() {
        if (_node->_next != nullptr) {
            _node = _node->_next;
        }
        return *this;
    }

    self operator++(int) {
        self tmp = *this;
        if (_node->_next != nullptr) {
            _node = _node->_next;
        }
        return tmp;
    }

    self& operator--() {
        if (_node->_prev != nullptr) {
            _node = _node->_prev;
        }
        return *this;
    }

    self operator--(int) {
        self tmp = *this;
        if (_node->_prev != nullptr) {
            _node = _node->_prev;
        }
        return tmp;
    }

    bool operator==(const self& it) {
        return _node == it._node;
    }

    bool operator!=(const self& it) {
        return _node != it._node;
    }

    private:
    node_type* _node;
};

template<typename T>
class List {
    public:
    using value_type = T;
    using node_type = ListNode<value_type>;
    using size_type = std::size_t;
    using iterator = ListIterator<value_type>;

    public:
    List()
    : _size(0) {
        _head = new node_type();
        _tail = new node_type();

        _head->_next = _tail;
        _tail->_prev = _head;
    }

    void push_back(const value_type& value) {
        node_type* new_node = new node_type(value);

        new_node->_prev = _tail->_prev;
        new_node->_next = _tail;

        _tail->_prev->_next = new_node;
        _tail->_prev = new_node;

        ++_size;
    }

    size_type size() const {
        return _size;
    }

    iterator begin() {
        return iterator(_head->_next);
    }

    iterator end() {
        return iterator(_tail);
    }

    private:
    node_type* _head;
    node_type* _tail;
    size_type _size;
};

}

#endif