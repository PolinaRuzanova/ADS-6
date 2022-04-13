// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
    T arr[100];
    int first, last;

 public:
     TPQueue() : first(0), last(0) {}
    void push(T x) {
            int per = last++;
            while ((--per >= first) && (arr[per % size].prior < x.prior)) {
                arr[(per + 1) % size] = arr[per % size];
            }
            arr[(per + 1) % size] = x;
        }
    T pop() {
        return arr[(first++) % size];
    } 
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
