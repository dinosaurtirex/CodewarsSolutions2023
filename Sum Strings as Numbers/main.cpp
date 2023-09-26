#include <string>

using namespace std;

string sum_strings(const string& a, const string& b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    string result = "";

    while (i >= 0 || j >= 0 || carry) {
        int num1 = (i >= 0) ? (a[i] - '0') : 0;
        int num2 = (j >= 0) ? (b[j] - '0') : 0;

        int sum = num1 + num2 + carry;
        carry = sum / 10;
        sum = sum % 10;

        result = to_string(sum) + result;

        i--;
        j--;
    }

    return result;
}