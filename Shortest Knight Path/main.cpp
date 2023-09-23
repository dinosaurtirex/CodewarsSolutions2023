#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

unsigned int convertToChessInt(char value) {
    char convertedValue = tolower(value);
    switch (convertedValue) {
    case 'a':
        return 1;
    case 'b':
        return 2;
    case 'c':
        return 3;
    case 'd':
        return 4;
    case 'e':
        return 5;
    case 'f':
        return 6;
    case 'g':
        return 7;
    case 'h':
        return 8;
    }
    return 500;
}

vector<pair<int, int>> showKnightPossibleMoves(pair<int, int> currentPosition) {
    int x = currentPosition.first;
    int y = currentPosition.second;
    vector<int> dx = { 2, 1, -1, -2, -2, -1, 1, 2 };
    vector<int> dy = { 1, 2, 2, 1, -1, -2, -2, -1 };
    vector<pair<int, int>> possible_moves;
    for (int i = 0; i < 8; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (1 <= new_x && new_x <= 8 && 1 <= new_y && new_y <= 8) {
            possible_moves.push_back(pair<int, int>(new_x, new_y));
        }
    }
    return possible_moves;
}

int find_distance(pair<int, int> x, pair<int, int> y) {
    return abs(x.first - y.first) + abs(x.second - y.second);
}

int knight(string start, string finish) {
    unsigned int start_x = convertToChessInt(start[0]);
    int start_y = start[1] - '0';
    unsigned int finish_x = convertToChessInt(finish[0]);
    int finish_y = finish[1] - '0';

    pair<int, int> start_position(start_x, start_y);
    pair<int, int> finish_position(finish_x, finish_y);

    vector<vector<int>> distance(9, vector<int>(9, INT_MAX));
    queue<pair<int, int>> q;

    distance[start_x][start_y] = 0;
    q.push(start_position);

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        vector<pair<int, int>> moves = showKnightPossibleMoves(current);

        for (auto move : moves) {
            if (distance[move.first][move.second] == INT_MAX) {
                distance[move.first][move.second] = distance[current.first][current.second] + 1;
                q.push(move);
            }
        }
    }

    if (distance[finish_x][finish_y] == INT_MAX) {
        cout << "Конь не может достичь цели." << endl;
        return -1;
    }

    return distance[finish_x][finish_y];
}

int main() {
    int moves = knight("a1", "c1");
    if (moves != -1) {
        cout << "Минимальное количество ходов: " << moves << endl;
    }
    return 0;
}
