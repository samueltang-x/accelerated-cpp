template <class T> class Vec {
  public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    Vec() { create(); };
    explicit Vec(size_type n, const T& val = T()) { create(n, val); }

    size_type size() const { return limit - data;}

    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }
  private:
    iterator data;
    iterator limit;
}
