#ifndef GUARD_Vec_h
#define GUARD_Vec_h

#include <algorithm>
#include <cstddef>
#include <memory>

template <class T> class Vec {
  public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    Vec() { create(); } // default constructor
    explicit Vec(size_type n, const T& val = T()) { create(n, val); }
    Vec(const Vec& v) { create(v.begin(), v.end()); }  // copy constructor
    ~Vec() { uncreate(); }

    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }

    size_type size() const { return avail - data;}

    Vec& operator=(const Vec&);

    iterator begin() { return data; }
    const_iterator begin() const { return data; }

    iterator end() { return avail; }
    const_iterator end() const { return avail; }

    void push_back(const T& val) {
      if (avail == limit)
        grow();
      unchecked_append(val);
    }

    void clear() { uncreate(); }

    iterator erase(iterator);

  private:
    iterator data;
    iterator avail;
    iterator limit;

    // facilities for memory allocation
    std::allocator<T> alloc;

    // allocate and initialize the underlying array
    void create();
    void create(size_type, const T&);
    void create(const_iterator, const_iterator);

    // destroy the elements in the array and free the memory
    void uncreate();

    // support functions for push_back
    void grow();
    void unchecked_append(const T&);
};

template <class T> Vec<T>& Vec<T>::operator=(const Vec& rhs) {
  // check for self-assignment
  if (&rhs != this) {
    // free the array in the left-hand side
    uncreate();

    // copy elements from the right-hand to the left-hand side
    create(rhs.begin(), rhs.end());
  }

  return *this;
}

template <class T> void Vec<T>::create() {
  data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& t) {
  data = avail = alloc.allocate(n);
  limit = data + n;

  std::uninitialized_fill(avail, limit, t);
  avail = limit;
}

template <class T> void Vec<T>::create(const_iterator b, const_iterator e) {
  data = alloc.allocate(e - b);
  avail = limit = std::uninitialized_copy(b, e, data);
}

template <class T> void Vec<T>::uncreate() {
  if (data) {
    // destroy (in reverse order)the elements that were constructed
    iterator it = avail;
    while (it != data)
      alloc.destroy(--it);

    // return all the space that was allocated
    alloc.deallocate(data, limit - data);
  }

  //reset pointers to indicate that the Vec is empty again
  data = avail = limit = 0;
}

template <class T> void Vec<T>::grow() {
  size_type new_size = std::max(ptrdiff_t(1), 2 * (limit -data));

  iterator temp_data = alloc.allocate(new_size);
  iterator temp_avail = std::uninitialized_copy(data, avail, temp_data);

  uncreate();

  // reset pointers to point to the newly allocated space
  data = temp_data;
  avail = temp_avail;
  limit = data + new_size;
}

template <class T> void Vec<T>::unchecked_append(const T& t) {
  alloc.construct(avail++, t);
}

template <class T> typename Vec<T>::iterator Vec<T>::erase(iterator it) {
  iterator next_it = it + 1;

  alloc.destroy(it);
  while (it + 1 != avail) {
    alloc.construct(it, *(it + 1));
    alloc.destroy(++it);
  }

  --avail;
  return next_it;
}

#endif
