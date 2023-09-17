#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <chrono>


using namespace std;


class Negabinary {
public:
    static string ToNegabinary(int i)
    {
        string result;
        if (i == 0) {
            result.push_back('0');
        }
        while (i != 0) {
            int remainder = i % (-2);
            i /= (-2);
            if (remainder < 0) {
                remainder += 2;
                i += 1;
            }
            result.insert(result.begin(), '0' + remainder);
        }
        return result;
    };

    static int ToInt(string s)
    {
        int result = 0;
        int power = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            result += (s[i] - '0') * power;
            power *= -2;
        }
        return result;
    };
};