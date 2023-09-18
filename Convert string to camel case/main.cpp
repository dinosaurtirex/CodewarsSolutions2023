#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <locale>
#include <chrono>


using namespace std;


const vector<char> alphabet = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

const locale loc;

bool is_in(const vector<char> data, char lookUpValue) {
    for (auto value : data) {
        if (value == lookUpValue)
            return true;
    }
    return false;
}


std::string to_camel_case(string text) {
    string finalString = "";
    bool do_next_big = false;
    for (auto schar : text) {
        if (is_in(alphabet, schar)) {
            if (do_next_big) {
                finalString += toupper(schar, loc);
                do_next_big = false;
            }
            else {
                finalString += schar;
            }
        }
        else {
            do_next_big = true; 
            continue;
        }
    }
    return finalString;
}


int main()
{
    cout << to_camel_case("") << endl;
    cout << to_camel_case("the_stealth_warrior") << endl;
    return 0;
}