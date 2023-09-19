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

class Mix
{
public:
    static string mix(const string& s1, const string& s2) {
        map<char, int> count1 = count_lowercase_letters(s1);
        map<char, int> count2 = count_lowercase_letters(s2);

        vector<string> differences;

        for (char c = 'a'; c <= 'z'; c++) {
            int freq1 = count1[c];
            int freq2 = count2[c];

            if (freq1 > 1 || freq2 > 1) {
                if (freq1 > freq2) {
                    differences.push_back("1:" + string(freq1, c));
                }
                else if (freq2 > freq1) {
                    differences.push_back("2:" + string(freq2, c));
                }
                else {
                    differences.push_back("=:" + string(freq1, c));
                }
            }
        }

        sort(differences.begin(), differences.end(), [](const string& a, const string& b) {
            if (a.length() != b.length()) {
                return a.length() > b.length();
            }
            return a < b;
            });

        return join(differences, "/");
    }
};

int main() {
    cout << fixed << setprecision(15);
    
    cout << "got: " << Mix::mix("Are they here", "yes, they are here") << " expected: 2:eeeee/2:yy/=:hh/=:rr" << endl;
    return 0;
}