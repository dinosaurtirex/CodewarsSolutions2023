#include <iostream>
#include <string>
#include <vector>


using namespace std;


string multiply(string a, string b) {
    if (a == "0" || b == "0")
        return "0";
    a.erase(0, min(a.find_first_not_of('0'), a.size() - 1));
    b.erase(0, min(b.find_first_not_of('0'), a.size() - 1));
    int m = a.length();
    int n = b.length();
    vector<int> result(m + n, 0);
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    string finResult;
    for (int i : result) {
        finResult += to_string(i);
    }
    finResult.erase(0, min(finResult.find_first_not_of('0'), finResult.size() - 1));
    return finResult;
}




int main() {
    cout << multiply("2", "3") << " 6" << endl;
    //cout << multiply("58608473622772837728372827", "7586374672263726736374") << " : 444625839871840560024489175424316205566214109298" << endl;
    return 0;
}