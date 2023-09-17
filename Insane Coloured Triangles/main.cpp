#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <map>
#include <fstream>
#include <string>

using namespace std;


void print_vector(vector<int> data)
{
    for (int i = 0; i < data.size(); i++) 
    {
        cout << data[i] << ",";
    }
    cout << endl;
}

unsigned int how_often(vector<int> data, unsigned int lookUpValue) {
    unsigned int total = 0;
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == lookUpValue)
            total += 1;
    }
    return total;
}


bool is_in(const string& data, char lookUpValue) {
    for (auto value : data) {
        if (value == lookUpValue)
            return true;
    }
    return false;
}


char getNextChar(const string& doublechar) {
    const vector<char> defaultCharSet = {'R','G','B'};
    if (doublechar[0] == doublechar[1])
        return doublechar[0];
    for (auto schar : defaultCharSet) {
        if (!is_in(doublechar, schar)) {
            return schar;
        }
    }
}


// Function to convert a number to base 3 and return the number of digits
unsigned convertToBase3(unsigned n, unsigned max, vector<unsigned>& output) {
    unsigned i = 0;
    while (i < max && n > 0) {
        output[i] = n % 3;
        n /= 3;
        i++;
    }
    return i;
}

// Function to calculate the binomial coefficient for n < 3
unsigned binomialCoefficientMax2(unsigned n, unsigned k) {
    if (n < k)
        return 0;
    switch (n) {
    case 0:
    case 1:
        return 1;
    case 2:
        return 1 + (k == 1);
    default:
        return 0;
    }
}

// Function to apply Lucas's theorem for p = 3
unsigned lucasTheorem3(unsigned lenN, const vector<unsigned>& digitsN,
    unsigned lenK, const vector<unsigned>& digitsK) {
    unsigned product = 1;
    for (unsigned i = 0; i < lenN; i++) {
        unsigned n_i = digitsN[i];
        unsigned k_i = (i < lenK) ? digitsK[i] : 0;
        product = (product * binomialCoefficientMax2(n_i, k_i)) % 3;
    }
    return product % 3;
}

// Function to convert from 012 to RGB
char intToChar(int i) {
    switch (i) {
    case 0: return 'R';
    case 1: return 'G';
    case 2: return 'B';
    default:
        return '\0';
    }
}

// Function to convert from RGB to 012
unsigned charToInt(char c) {
    switch (c) {
    case 'R': return 0;
    case 'G': return 1;
    case 'B': return 2;
    default:
        return 3;
    }
}

char triangle(const string& userInput) {
    const char* input = userInput.c_str();
    unsigned sum = 0;
    const int n = userInput.length();

    vector<unsigned> digitsN(11);
    unsigned lenN = convertToBase3(n - 1, 11, digitsN);

    for (unsigned km1 = 0; km1 < n; km1++) {
        vector<unsigned> digitsK(11);
        unsigned lenK = convertToBase3(km1, 11, digitsK);

        unsigned Cnk_mod3 = lucasTheorem3(lenN, digitsN, lenK, digitsK);
        sum = (sum + Cnk_mod3 * charToInt(input[km1])) % 3;
    }

    int sign = (n % 2) * 2 - 1;
    int sum_mod3 = (3 + (sign * (int)(sum % 3))) % 3;
    return intToChar(sum_mod3);
}


int main()
{
    cout << triangle({ "B" }) << " : B" << endl;
    cout << triangle({ "GB" }) << " : R" << endl;
    cout << triangle({ "RRR" }) << " : R" << endl;
    cout << triangle({ "RBRGBRBGGRRRBGBBBGG" }) << " : G" << endl;
    auto start = chrono::high_resolution_clock::now();
    cout << "Start build huge triangle" << endl;
    string hugeTriangle = "";
    for (size_t i = 0; i < 100000; i++)
    {
        hugeTriangle += "RBRGBRBGGRRRBGBBBGG";
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Huge triangle build is took: " << duration.count()<< endl;
    cout << "start calculating huge triangle" << endl;
    auto startTime = chrono::high_resolution_clock::now();
    cout << triangle(hugeTriangle) << " : G" << endl;
    auto endTime = chrono::high_resolution_clock::now();
    chrono::duration<double> newDuration = endTime - startTime;
    cout << "Huge triangle calculate is took: " << newDuration.count() << endl;
    return 0;
}