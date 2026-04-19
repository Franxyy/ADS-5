// Copyright 2025 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int pr(char c) {
  if (c == '+' || c == '-') return 1;
  if (c == '*' || c == '/') return 2;
  return 0;
}

std::string infx2pstfx(const std::string& inf) {
  TStack<char, 100> stack;
  std::string result;
    for (int i = 0; i < inf.length(); i++) {
      char c = inf[i];
      if (c >= '0' && c <= '9') {
        result = result + c;
        if (i == inf.length() - 1) {
          result = result + ' ';
        } else if (inf[i+1] < '0' || inf[i+1] > '9') {
          result = result + ' ';
        }
      }
      if (c == '(') {
        stack.push(c);
      }
      if (c == ')') {
        while (stack.top() != '(') {
          result = result + stack.pop();
          result = result + ' ';
        }
        stack.pop();
      }
      if (c == '+' || c == '-' || c == '*' || c == '/') {
        while (stack.isEmpty() == false) {
          if (stack.top() == '(') break;
            if (pr(stack.top()) < pr(c)) break;
              result = result + stack.pop();
              result = result + ' ';
        }
        stack.push(c);
      }
    }
    while (stack.isEmpty() == false) {
      result = result + stack.pop();
      result = result + ' ';
    }
    return result;
}

int eval(const std::string& pref) {
  TStack<int, 100> stack;
  for (int i = 0; i < pref.length(); i++) {
    char c = pref[i];
    if (c == ' ') {
    } else if (c >= '0' && c <= '9') {
      int num = 0;
      while (pref[i] >= '0' && pref[i] <= '9') {
        num = num * 10;
        num = num + (pref[i] - '0');
        i = i + 1;
      }
      i = i - 1;
      stack.push(num);
    } else {
      int b = stack.pop();
      int a = stack.pop();
      if (c == '+') stack.push(a + b);
      if (c == '-') stack.push(a - b);
      if (c == '*') stack.push(a * b);
      if (c == '/') stack.push(a / b);
    }
  }
  return stack.pop();
}
