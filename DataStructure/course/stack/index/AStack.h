#ifndef ASTACK
#define ASTACK
#include <cstddef>
#define Rank int
#include <vector>
template <class T> class AStack {
public:
  Rank size();
  void push();
  void pop();
  void top();

private:

};
#endif