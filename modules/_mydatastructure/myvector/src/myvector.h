namespace datastruct {

template<typename T>
class Vector {
    public:
    using iterator = T*;
    using const_iterator = const T*;
    using reference = T&;
    using const_reference = const T&;

    Vector(const int length) {
        arr_ = new T[length];
        length_ = length;
        size_ = 0;
    }

    ~Vector() {
        delete [] arr_;
    }

    void push_back(const T& val) {
        // TODO: Realloc if needed!
        arr_[size_] = val;
        ++size_;
    }

    void pop_bach() {
        --size_;
    }

    Vector<T>::reference operator[](const int i) {
        return arr_[i];
    }

    Vector<T>::const_reference operator[](const int i) const {
        return arr_[i];
    }

    Vector<T>::iterator insert(Vector<T>::iterator it, const T& val) {
        // TODO: Realloc if needed!
        Vector<T>::iterator end = it + size_ + 1;
        while(it != end) {
            *end = *(end - 1);
            end--;
        }
        *it = val;
        size_++;
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
    T* arr_;
    int size_;
    int length_;
};

}