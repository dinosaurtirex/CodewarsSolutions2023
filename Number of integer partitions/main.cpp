#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <locale>
#include <chrono>
#include <map>

using namespace std;

const vector<char> alphabet = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

const vector<char> closingStates = {
    ']', ')', '}'
};

const vector<char> openStates = {
    '[', '(', '{'
};

const map<char, char> openAndCloseStates = {
    {'(', ')'},
    {'{', '}'},
    {'[', ']'}
};

const locale loc;

void print_vector(const vector<string> data)
{
    if (data.size() <= 0) {
        return;
    }
    for (auto i : data) {
        cout << i << " ";
    }
    cout << endl;
}

bool is_in(const vector<char> data, const char lookUpValue) {
    for (auto value : data) {
        if (value == lookUpValue)
            return true;
    }
    return false;
}

vector<string> splitEngStringToWords(const string& str) 
{
    vector<string> words = {};
    string tempWord = "";
    for (auto schar : str) {
        if (is_in(alphabet, schar)) {
            tempWord += schar;
        }
        else {
            string wordcopy = tempWord;
            words.push_back(wordcopy);
            tempWord = "";
        }
    }
    words.push_back(tempWord);
    return words;
}

string reverseString(const string& str) {
    string reversed = "";
    for (int i = str.size(); i != -1; i--) {
        reversed += str[i];
    }
    return reversed;
}

bool approx_equal(double a, double b, double tolerance = 1e-9) {
    return abs(a - b) < tolerance;
}



uint32_t partitions(uint32_t n) {
    vector<int> partitionCounts(n + 1, 0);
    partitionCounts[0] = 1;
    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = i; j <= n; ++j) {
            partitionCounts[j] += partitionCounts[j - i];
        }
    }
    return partitionCounts[n];
}


int main() {
    cout << fixed << setprecision(15);
    

    cout << partitions(1) << " 1" << endl;
    cout << partitions(5) << " 7" << endl;
    cout << partitions(10) << " 42" << endl;
    cout << partitions(100) << " 1958" << endl;
    
    return 0;
}