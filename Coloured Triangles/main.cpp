#include <iostream>
#include <vector>
#include <string>

using namespace std;


bool is_in(const string& data, char lookUpValue) {
    for (auto value : data) {
        if (value == lookUpValue)
            return true;
    }
    return false;
}


char getNextChar(const string& doublechar) {
    const vector<char> defaultCharSet = {'R','G','B'};
    if (doublechar[0] == doublechar[1])
        return doublechar[0];
    for (auto schar : defaultCharSet) {
        if (!is_in(doublechar, schar)) {
            return schar;
        }
    }
}


string triangle(string row)
{
    if (row.size() == 1)
        return row;
    string rowCopy = row;
    for (size_t j = 0; j < (row.size() - 1); j++) {
        string nextLine = "";
        for (size_t i = 1; i < rowCopy.size(); i++) {
            char nextChar = getNextChar({
                rowCopy[i - 1],
                rowCopy[i]
            });
            nextLine.push_back(nextChar);
        };
        rowCopy = nextLine;
        if (nextLine.size() == 1)
            return nextLine;
    }
}