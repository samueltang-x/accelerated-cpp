#include "Vec.h"
#include <algorithm>

using std::max;

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
      alloc.destroy(it--);

    // return all the space that was allocated
    alloc.deallocate(data, limit - data);
  }

  //reset pointers to indicate that the Vec is empty again
  data = avail = limit = 0;
}

template <class T> void Vec<T>::grow() {
  size_type new_size = max(ptrdiff_t(1), size() * 2);

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
