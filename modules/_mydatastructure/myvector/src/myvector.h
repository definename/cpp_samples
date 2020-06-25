#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <cstring>

namespace dsvector {

template<typename T>
class Vector {
    public:
    using iterator = T*;
    using const_iterator = const T*;
    using reference = T&;
    using const_reference = const T&;
    using size_type = std::size_t;

    Vector(const size_type reserver_size) {
        reserver_size_ = reserver_size;
        arr_ = new T[reserver_size_];
        size_ = 0;
    }

    ~Vector() {
        delete [] arr_;
    }

    void push_back(const T& val) {
        if (reserver_size_ == size_) {
            reserver_size_ *= 2;
            reallocate();
        }

        arr_[size_] = val;
        ++size_;
    }

    void pop_back() {
        --size_;
    }

    Vector<T>::reference operator[](const int i) {
        return arr_[i];
    }

    Vector<T>::const_reference operator[](const int i) const {
        return arr_[i];
    }

    Vector<T>::iterator insert(Vector<T>::iterator it, const T& val) {
        const size_type index = it - arr_;
        if (reserver_size_ == size_) {
            reserver_size_ *= 2;
            reallocate();
        }

        iterator actual_it = arr_ + index;
        std::memmove(reinterpret_cast<void*>(actual_it + 1),
                     reinterpret_cast<void*>(actual_it),
                     (size_ - index) * sizeof(T));
        *actual_it = val;
        ++size_;
    }

    int size() const {
        return size_;
    }

    Vector<T>::iterator begin() {
        return arr_;
    }

    Vector<T>::const_iterator begin() const {
        return arr_;
    }

    Vector<T>::iterator end() {
        return arr_ + size_;
    }

    Vector<T>::const_iterator end() const {
        return arr_ + size_;
    }

    private:
    void reallocate() {
        T* tmp = new T[reserver_size_];
        std::memcpy(reinterpret_cast<void*>(tmp),
                    reinterpret_cast<void*>(arr_),
                    reserver_size_ * sizeof(T));
        delete [] arr_;
        arr_ = tmp;
    }

    private:
    T* arr_;
    size_type size_;
    size_type reserver_size_;
    
};

}

#endif