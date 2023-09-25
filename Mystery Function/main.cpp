#include <iostream>

using namespace std;


unsigned long mystery(unsigned long n) {
    return n ^ (n >> 1);
}

unsigned long mysteryInv(unsigned long n) {
    unsigned long mask = n >> 1;
    while (mask != 0) {
        n = n ^ mask;
        mask = mask >> 1;
    }
    return n;
}

string nameOfMystery() {
    return "Gray code";
}


int main() {

    cout << mystery(6) << " 5" << endl;
    return 0;
}
