//
// Created by ryanz on 2/3/2023.
//
#include <iostream>
using namespace std;

class IsPrime {
public:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};

//// parse command line argument and call isPrime
//int main(int argc, char *argv[]) {
//    int n = atoi(argv[1]);
//    bool result = IsPrime().isPrime(n);
//    if (result) {
//        cout << n << " is prime" << endl;
//    } else {
//        cout << n << " is not prime" << endl;
//    }
//}
