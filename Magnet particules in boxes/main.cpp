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

class Magnets {
public:

    static double custom_pow(double base, int exponent) {
        if (exponent == 0) {
            return 1.0;
        }

        double result = 1.0;

        for (int i = 0; i < abs(exponent); i++) {
            result *= base;
        }

        if (exponent < 0) {
            return 1.0 / result;
        }

        return result;
    }


    static double v(double k, double n) {
        double r = custom_pow(k * custom_pow(n + 1.0, 2 * k), -1.0);
        return r;
    };

    static double doubles(int K, int N) {
        double result = 0.0;
        for (int k = 1; k <= K; k++) {
            for (int n = 1; n <= N; n++) {
                result += v(k, n);
            }
        }
        return result;
    }
};


int main() {
    cout << fixed << setprecision(15);
    cout << "got: " << Magnets::doubles(1, 10) << " expected: 0.5580321939764581, ";
    cout << "equal: " << approx_equal(Magnets::doubles(1, 10), 0.5580321939764581) << endl;

    cout << "got: " << Magnets::doubles(10, 1000) << " expected: 0.6921486500921933, ";
    cout << "equal: " << approx_equal(Magnets::doubles(10, 1000), 0.6921486500921933) << endl;

    cout << "got: " << Magnets::doubles(10, 10000) << " expected: 0.6930471674194457, ";
    cout << "equal: " << approx_equal(Magnets::doubles(10, 10000), 0.6930471674194457) << endl;

    cout << "got: " << Magnets::doubles(20, 10000) << " expected: 0.6930471955575918, ";
    cout << "equal: " << approx_equal(Magnets::doubles(20, 10000), 0.6930471955575918) << endl;

    return 0;
}