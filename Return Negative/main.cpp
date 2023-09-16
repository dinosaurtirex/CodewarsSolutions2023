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

int makeNegative(int num)
{
    int res = 0;
    if (num == 0)
        return 0;
    if (num > 0)
        return -num;
    return num;
}

int main()
{
    makeNegative(873);
    makeNegative(0);
    makeNegative(-8);
    return 0;
}