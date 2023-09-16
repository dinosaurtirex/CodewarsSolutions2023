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

unsigned int how_often(vector<int> data, unsigned int lookUpValue) {
    unsigned int total = 0;
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == lookUpValue)
            total += 1;
    }
    return total;
}

unsigned int get_score(unsigned int frequency, unsigned int value) {
    unsigned int score = 0;

    if (value == 1) {
        if (frequency >= 3) {
            score += 1000;
            frequency -= 3;
        }
        score += frequency * 100;
    }
    else if (value == 5) {
        if (frequency >= 3) {
            score += 500;
            frequency -= 3;
        }
        score += frequency * 50;
    }
    else if (frequency >= 3) {
        score += value * 100;
    }

    return score;
}

int score(const std::vector<int>& dice) {
    unsigned int score = 0;
    vector<int> uniqueValues = {};
    for (const auto value : dice) {
        if (!is_in(uniqueValues, value))
            uniqueValues.push_back(value);
    }
    for (const auto value : uniqueValues) {
        score += get_score(
            how_often(dice, value),
            value
        );
    }
    return score;
}

int main()
{
    cout << score({ 1, 1, 1, 1, 3 }) << " " << 1100 << endl;
    cout << score({ 1, 1, 1, 3, 3 }) << " " << 1000 << endl;
    cout << score({ 6, 6, 4, 1, 1 }) << " " << 200 << endl;
    cout << score({ 1, 1, 1, 3, 3 }) << " " << 1000 << endl;
    cout << score({ 2, 3, 4, 1, 4 }) << " " << 100 << endl;
    return 0;
}