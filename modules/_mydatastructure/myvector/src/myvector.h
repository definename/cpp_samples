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

    explicit Vector(const size_type size)
    : reserver_size_(size)
    , size_(0)
    , arr_(new T[reserver_size_]) {
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

    Vector<T>::size_type size() const {
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
                    (size_) * sizeof(T));
        delete [] arr_;
        arr_ = tmp;
    }

    private:
    size_type reserver_size_;
    size_type size_;
    T* arr_;
};

class VectorBoolProxy {
    public:
    VectorBoolProxy(unsigned char& byte_data, unsigned char bit_num)
    : byte_data_(byte_data)
    , mask_(1 << bit_num) {
    }

    operator bool() const {
        return byte_data_ & mask_;
    }

    VectorBoolProxy& operator=(const bool is_true) {
        if (is_true) {
            byte_data_ = byte_data_ | mask_;
        } else {
            byte_data_ = byte_data_ & (~mask_);
        }
        return *this;
    }

    private:
    unsigned char& byte_data_;
    unsigned char mask_;
};

template<>
class Vector<bool> {
    public:
    using size_type = std::size_t;

    explicit Vector(const size_type size)
    : reserver_size_(size)
    , arr_(new unsigned char[(reserver_size_ + 7) / 8]) {
    }

    ~Vector() {
        delete [] arr_;
    }

    bool operator[](const int i) const {
        const unsigned char byte_data = arr_[i / 8];
        const unsigned char bit_num = i % 8;
        const unsigned char mask = 1 << bit_num;
        return byte_data & mask;
    }

    VectorBoolProxy operator[](const int i) {
        unsigned char& byte_data = arr_[i / 8];
        const unsigned char bit_num = i % 8;
        return { byte_data, bit_num };
    }

    private:
    size_type reserver_size_;
    unsigned char* arr_;
};



}

#endif