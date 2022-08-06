#include <iostream>

using namespace std;

template<class T>
class Vector {

    static const int init_size = 20;
    T *A;
    int len;
    int tail;

public:

    Vector(): A{new T[init_size]}, len{init_size}, tail{0} {}

    T& operator[](int idx) {
        return A[idx];
    }

    void push_back(T elem) {
        if (tail == len) {
            // resize
            T *old_A = A;
            A = new T[len*2];
            memcpy(A,old_A,len*sizeof(T));
            len *= 2;
        }
        A[tail++] = elem;
    }

    T& pop_back() {
        T ret_val = nullptr;
        if (tail > 0) {
            ret_val = A[--tail];
            A[tail] = nullptr;
        }
        return ret_val;
    }
};