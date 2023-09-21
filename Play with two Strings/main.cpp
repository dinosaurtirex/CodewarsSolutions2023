#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <bitset>
#include <locale>
#include <cctype>
#include <chrono>
#include <map>
#include <algorithm>

using namespace std;

const vector<char> alphabet = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
};

const vector<char> alphabetlowercase = {
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


void print_map(const map<char, unsigned int>& data) {
    for (char el : alphabetlowercase) {
        if (data.find(el) != data.end()) {
            cout << el << " : " << data.at(el) << endl;
        }
    }
}


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

map<char, int> count_lowercase_letters(const string& s) {
    map<char, int> letter_count;
    for (char c : s) {
        if (islower(c)) {
            letter_count[c]++;
        }
    }
    return letter_count;
}


string join(const vector<string>& strings, const string& delimiter) {
    if (strings.empty()) {
        return "";
    }

    string result = strings[0];
    for (size_t i = 1; i < strings.size(); i++) {
        result += delimiter + strings[i];
    }

    return result;
}


int countCharacter(const string& str, char c) {
    int count = 0;
    char lowerC = tolower(c);
    for (char ch : str) {
        if (tolower(ch) == lowerC) {
            count++;
        }
    }
    return count;
}

char swapCase(char c) {
    if (islower(c)) {
        return toupper(c);
    }
    else if (isupper(c)) {
        return tolower(c);
    }
    else {
        return c; 
    }
}


string work_on_strings(const string& a, const string& b) {
    string bLower;
    string aLower;
    string newA;
    string newB;
    for (auto schar : b) 
        bLower += tolower(schar);
    for (auto schar : a) 
        aLower += tolower(schar);
    for (char letter : a) {
        if (countCharacter(bLower, letter) % 2 == 0) {
            newA += letter;
        }
        else {
            newA += swapCase(letter);
        }
    }
    for (char letter : b) {
        if (countCharacter(aLower, letter) % 2 == 0) {
            newB += letter;
        }
        else {
            newB += swapCase(letter);
        }
    }
    return newA + newB;
}


int main() {
    cout << fixed << setprecision(15);
    
    cout << "got: " << work_on_strings("abcdeFgtrzw", "defgGgfhjkwqe") << " abcDeFGtrzWDEFGgGFhjkWqE" << endl;
    return 0;
}