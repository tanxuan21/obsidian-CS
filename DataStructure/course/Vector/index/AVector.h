#ifndef AVECTOR
#define AVECTOR
#define default_capacity 2
#define Rank int

template <class T> class AVector {
public:
  // construct
  AVector();
  AVector(const Rank &s);
  ~AVector();
  // copy construct
  AVector(T const *A, Rank lo, Rank hi);          // copy from arr
  AVector(AVector<T> const &v);                   // copy hole vector
  AVector(AVector<T> const &v, Rank lo, Rank hi); // copy from vector
  Rank size();                                    // 元素总数
  bool empty();                                   // 是否为空                       // 获取秩r的元素
  Rank insert(const Rank &r, const T &e);         // 在秩r后插入元素e
  T& remove(const Rank &r);
  Rank remove(const Rank lo,const Rank hi);
  Rank disordered();
  Rank find();
  Rank dedup();
  Rank traverse();

  T &operator[](Rank r);
  const T &operator[](Rank r) const;

private:
  Rank _size;                              // 向量规模
  Rank _capacity;                          // 物理容量
  T *_arr;                                 // 物理数组指针
  void expand();                           // expand physical arr
  void copy(T const *A, Rank lo, Rank hi); // copy physical arr
};
#endif