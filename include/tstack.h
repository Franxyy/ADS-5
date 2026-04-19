// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int kSize>
class TStack {
 private:
  T elements[kSize];
  int count;
 public:
  TStack() {
    count = 0;
  }
  bool isEmpty() {
    return count == 0;
  }
  bool isFull() {
    return count == kSize;
  }
  void push(T value) {
    if (!isFull()) {
      elements[count] = value;
      count = count + 1;
    }
  }
  T pop() {
    if (!isEmpty()) {
      count = count - 1;
      return elements[count];
    }
    return T();
  }
  T top() {
    if (!isEmpty()) {
      return elements[count - 1];
    }
    return T();
  }
};

#endif  // INCLUDE_TSTACK_H_
