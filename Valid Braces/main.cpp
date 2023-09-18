#include <string>
#include <vector>
#include <iostream>
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


bool valid_braces(string braces) {
    vector<char> stack;
    for (char currentChar : braces) {
        if (is_in(openStates, currentChar)) {
            stack.push_back(currentChar);
        }
        else if (is_in(closingStates, currentChar)) {
            if (stack.empty() || openAndCloseStates.at(stack.back()) != currentChar) {
                return false;
            }
            stack.pop_back();
        }
    }
    return stack.empty();
}

int main()
{
    cout << valid_braces("(){}[]") << " " << 1 << endl;
    cout << valid_braces("([{}])") << " " << 1 << endl;
    cout << valid_braces("()") << " " << 1 << endl;
    cout << valid_braces("[(])") << " " << 0 << endl;
    return 0;
}