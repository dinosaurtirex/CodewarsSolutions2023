#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;


void print_vector(std::vector<int> data)
{
    for (int i = 0; i < data.size(); i++) 
    {
        cout << data[i] << ",";
    }
    cout << endl;
}

bool is_in(vector<int>& data, unsigned int lookUpValue) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == lookUpValue) {
            return true;
        }
    }
    return false;
}

std::vector<int> tribonacci(std::vector<int> signature, int n)
{
    if (n < 3) {
        signature.resize(n);
    }
    for (unsigned int i = 3; i < n; i++) {
        signature.push_back(signature[i - 3] + signature[i - 2] + signature[i - 1]);
    }
    return signature;
}

int main()
{
    tribonacci({1,1,1,2,3}, 5);
    return 0;
}