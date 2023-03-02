//
// Created by ryanz on 3/1/2023.
//

#ifndef LEETCODE_PAIR_H
#define LEETCODE_PAIR_H



template <typename T>
class Pair {
    T inc;
    T exc;
public:
    Pair() : inc(0), exc(0) {}
    Pair(T inc, T exc) : inc(inc), exc(exc) {}
    T getInc() {
        return inc;
    }
    T getExc() {
        return exc;
    }

    void setInc(T inc_) {
        this->inc = inc_;
    }
    void setExc(T exc_) {
        this->exc = exc_;
    }
};

#endif //LEETCODE_PAIR_H
