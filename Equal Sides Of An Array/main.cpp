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

int find_even_index(const vector <int> numbers) {
    for (unsigned int i = 0; i < numbers.size(); i++)
    {
        int leftSideSum = 0;
        for (unsigned j = 0; j < i; j++)
        {
            leftSideSum += numbers[j];
        }
        int rightSideSum = 0;
        for (unsigned j = i+1; j < numbers.size(); j++)
        {
            rightSideSum += numbers[j];
        }
        if (leftSideSum == rightSideSum)
            return i;
    }
    return -1;
}

int main()
{
    find_even_index({1,1,1,2,3,4,5,6,7,1,1});
    return 0;
}