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


string spinWords(const string& str)
{
    string spinnedString = "";
    const vector<string> words = splitEngStringToWords(str);
    for (auto word : words) {
        if (word.size() >= 5) {
            if (spinnedString.size() > 0) {
                spinnedString += " ";
                spinnedString += reverseString(word);
            }
            else {
                spinnedString += reverseString(word);
            }
        }
        else {
            if (spinnedString.size() > 0) {
                spinnedString += " ";
                spinnedString += word;
            }
            else {
                spinnedString += word;
            }
        }
    }
    return spinnedString;
}

int main()
{
    cout << spinWords("Welcome") << endl;
    cout << spinWords("CodeWars") << endl;
    cout << spinWords("to") << endl;
    cout << spinWords("Hey fellow warriors") << endl;
    return 0;
}