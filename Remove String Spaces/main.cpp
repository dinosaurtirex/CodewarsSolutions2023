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

std::string no_space(const std::string& x)
{   
    std::string removedSpaceBars = "";
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == ' ') {
            continue;
        }
        removedSpaceBars += x[i];
    }
    return removedSpaceBars;
}

int main()
{
    no_space("HELLO   *F** G G  GG G* ");
    return 0;
}