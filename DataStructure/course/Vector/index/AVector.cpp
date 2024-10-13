#include "./AVector.h"
// default construct
template <class T> AVector<T>::AVector() {
  this->_capacity = default_capacity;
  this->size() = 0;
  this->_arr = new T[_capacity];
}
// construct with size
template <class T> AVector<T>::AVector(const Rank &s) {
  this->_capacity = s * 2;
  this->size() = s;
  this->_arr = new T[_capacity];
}
// copy construct
template <class T> AVector<T>::AVector(AVector<T> const &v) {
  copy(v._arr, 0, v._size);
}
template <class T> AVector<T>::AVector(T const *v, Rank lo, Rank hi) {
  copy(v, lo, hi);
}
template <class T> AVector<T>::AVector(AVector<T> const &v, Rank lo, Rank hi) {
  copy(v._arr, lo, hi);
}

// default disconstruct
template <class T> AVector<T>::~AVector() { delete[] _arr; }

// expand
template <class T> void AVector<T>::expand() {
  if (_size < _capacity) // _size < _capacity,is not nessesary to expand
    return;
  T *old = this->_arr;
  copy(old, 0, _capacity);
  delete[] old;
}
// copy
// =========================>
// assign space in copy,prevent memory address access error
// make sure this->-arr is empty pointer when call method copy!
// copy is not just move value from one to another,it make new memory segment.
// <========================
template <class T> void AVector<T>::copy(T const *A, Rank lo, Rank hi) {
  this->_arr = new T[_capacity = (lo - hi) * 2];
  for (Rank i = lo; i < hi; i++) {
    this->_arr[i] = A[i];
    this->_size++;
  }
}
// ############INFOMATION################
template <class T> bool AVector<T>::empty() { return _size == 0; }
template <class T> Rank AVector<T>::size() { return _size; }
// ############OPERATION#################
template <class T> T &AVector<T>::operator[](Rank r) { return _arr[r]; }
template <class T> Rank AVector<T>::insert(const Rank &r, const T &e) {
  expand(); // in here,I see the intelligent of programmer.
  // function expand means that when _size is equal to _capacity,it expand.Not
  // over so the bounder situation is clear.
  for (Rank i = _size; i >= r; i--) {
    _arr[i] = _arr[i - 1];
  }
  _arr[r] = e;
  _size++;
  return r;
}
template <class T> Rank AVector<T>::remove(Rank lo, Rank hi) {
  if (lo == hi)
    return 0;
  Rank distance = hi - lo;
  for (Rank i = lo; i < hi; i++) {
    _arr[i] = _arr[i + distance];
  }
  _size -= distance;
  return distance;
}
template <class T> T &AVector<T>::remove(const Rank &r) { remove(r, r + 1); }