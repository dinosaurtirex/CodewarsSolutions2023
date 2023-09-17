#include <string>
#include <iostream>
#include <chrono>
using namespace std;

// Степени числа 3
const int powersOfThree[12] = { 1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147 };

// Преобразование символа в целое число, используя ASCII
int charToInt(char c)
{
    switch (static_cast<int>(c))
    {
    case 82: return 0; // R
    case 71: return 1; // G
    case 66: return 2; // B
    }
    return -1;
}

// Преобразование целого числа в символ
char intToChar(int i)
{
    switch (i)
    {
    case 0: return 'R';
    case 1: return 'G';
    case 2: return 'B';
    }
    return 'A';
}

char triangle(const string& input)
{
    string currentResult = input;
    string currentLine = input;

    while (currentLine.size() > 1)
    {
        currentResult.clear();
        int n = currentLine.length() - 1;
        int nearestPower = 1;
        for (int powerIndex = 0; powerIndex < 12; ++powerIndex)
        {
            if (n >= powersOfThree[powerIndex]) nearestPower = powersOfThree[powerIndex];
            else break;
        }

        int sizeOfArray = (n - nearestPower + 1);
        for (int position = 0; position < sizeOfArray; ++position)
            currentResult.push_back(intToChar((2 * (charToInt(currentLine[position]) + charToInt(currentLine[n - position]))) % 3));
        currentLine = currentResult;
    }

    return currentResult[0];
}


int main()
{
    cout << triangle({ "B" }) << " : B" << endl;
    cout << triangle({ "GB" }) << " : R" << endl;
    cout << triangle({ "RRR" }) << " : R" << endl;
    cout << triangle({ "RBRGBRBGGRRRBGBBBGG" }) << " : G" << endl;
    auto start = chrono::high_resolution_clock::now();
    cout << "Start build huge triangle" << endl;
    string hugeTriangle = "";
    for (size_t i = 0; i < 100000; i++)
    {
        hugeTriangle += "RBRGBRBGGRRRBGBBBGG";
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Huge triangle build is took: " << duration.count()<< endl;
    cout << "start calculating huge triangle" << endl;
    auto startTime = chrono::high_resolution_clock::now();
    cout << triangle(hugeTriangle) << " : G" << endl;
    auto endTime = chrono::high_resolution_clock::now();
    chrono::duration<double> newDuration = endTime - startTime;
    cout << "Huge triangle calculate is took: " << newDuration.count() << endl;
    return 0;
}