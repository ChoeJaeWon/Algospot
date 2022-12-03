// Algorithm: Dynamic Programming
// Time Complexity: O(N * 3^N)
// The number of Calculations: 3^9 * 2 * 9

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <map>

using namespace std;

const int INF = 987654321;
const int MAX_CASES = 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3 * 3;
int C;
vector<vector<int>> board;
int cache[MAX_CASES][3];
map<char, int> symbol;


void init() {
    for (int i = 0; i < MAX_CASES; i++)
        for (int j = 0; j < 3; j++)
            cache[i][j] = -2;
    board = vector<vector<int>>(3, vector<int>(3, -1));
    symbol['o'] = 1;
    symbol['x'] = -1;
    symbol['.'] = 0;
}

void input() {
    string temp;
    for (int i = 0; i < 3; i++) {
        cin >> temp;
        for (int j = 0; j < 3; j++)
            board[i][j] = symbol[temp[j]];
    }
}

void setup() {

}

bool isWin(vector<vector<int>> &boardTemp, int turn) {
    //horizontal
    int temp;
    for (int i = 0; i < 3; i++) {
        temp = boardTemp[i][0] + boardTemp[i][1] + boardTemp[i][2];
        if (temp == turn * 3)
            return true;
    }

    //vertical
    for (int i = 0; i < 3; i++) {
        temp = boardTemp[0][i] + boardTemp[1][i] + boardTemp[2][i];
        if (temp == turn * 3)
            return true;
    }

    //diagonal
    temp = boardTemp[0][0] + boardTemp[1][1] + boardTemp[2][2];
    if (temp == turn * 3)
        return true;

    temp = boardTemp[0][2] + boardTemp[1][1] + boardTemp[2][0];
    if (temp == turn * 3)
        return true;

    return false;
}

vector<vector<int>> intToVector(int boardTemp) {
    vector<vector<int>> ret(3, vector<int>(3));
    for (int i = 2; i >= 0; i--)
        for (int j = 2; j >= 0; j--) {
            if (boardTemp % 3 == 0)
                ret[i][j] = 0;
            else if (boardTemp % 3 == 1)
                ret[i][j] = -1;
            else if (boardTemp % 3 == 2)
                ret[i][j] = 1;
            boardTemp /= 3;
        }
    return ret;
}


int vectorToInt(vector<vector<int>> &boardTemp) {
    int ret = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            ret *= 3;
            if (boardTemp[i][j] == -1)
                ret += 1;
            else if (boardTemp[i][j] == 1)
                ret += 2;
        }
    return ret;
}

bool isFulled(vector<vector<int>> &boardTemp) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (boardTemp[i][j] == 0)
                return false;
    return true;
}

int whoWin(int boardState, int turn) {
    vector<vector<int>> boardVector = intToVector(boardState);
    if (isFulled(boardVector)) return 0;

    int &ret = cache[boardState][turn + 1];
    if (ret != -2) return ret;

    ret = -1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (boardVector[i][j] == 0) {
                boardVector[i][j] = turn;
                if (isWin(boardVector, turn))
                    return ret = 1;
                else
                    ret = max(ret, whoWin(vectorToInt(boardVector), turn * -1) * -1);
                boardVector[i][j] = 0;
            }
        }
    }

    return ret;
}

int whoIsTurn(vector<vector<int>> &boardTemp) {
    int ret = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            ret += boardTemp[i][j];
    return ret == 0 ? -1 : 1;
}

void solve() {
    int turn = whoIsTurn(board);
    int sol = whoWin(vectorToInt(board), turn);
    if (sol == 0)
        printf("TIE\n");
    else if ((sol == 1 && turn == -1) || (sol == -1 && turn == 1))
        printf("x\n");
    else if ((sol == -1 && turn == -1) || (sol == 1 && turn == 1))
        printf("o\n");
}

int main() {
    scanf("%d", &C);
    memset(cache, -1, sizeof(cache));
    while (C--) {
        init();
        input();
        setup();
        solve();
    }
}