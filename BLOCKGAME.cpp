// Algorithm: Dynamic Programming
// Time Complexity: O(2^N * N) # N: the area of the board
// The number of Calculations: 2^25 * (16*6 + 4*2)

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int BOARD_SIZE = 5;
int C;
vector<string> board;
char cache[1 << (BOARD_SIZE * BOARD_SIZE)];
int blocks[6] = {25165824, 17301504, 25690112, 25427968, 17563648, 9175040};

void init() {
    board.clear();
}

void input() {
    string temp;
    for (int i = 0; i < BOARD_SIZE; i++) {
        cin >> temp;
        board.push_back(temp);
    }
}

void setup() {

}

int vectorToInt(vector<string> &boardTemp) {
    int ret = 0;
    for (int i = BOARD_SIZE - 1; i >= 0; i--) {
        for (int j = BOARD_SIZE - 1; j >= 0; j--) {
            ret *= 2;
            if (board[i][j] == '.')
                ret += 0;
            else
                ret += 1;
        }
    }
    return ret;
}

bool canPut(int boardTemp) {
    int block;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 6; k++) {
                block = blocks[k] >> (i * 5);
                block = block >> j;
                if ((boardTemp & block) == 0)
                    return true;
            }
        }
    }

    for (int j = 0; j < 4; j++) {
        block = blocks[0] >> (4 * 5);
        block = block >> j;
        if ((boardTemp & block) == 0)
            return true;
    }

    for (int i = 0; i < 4; i++) {
        block = blocks[1] >> (i * 5);
        block = block >> 4;
        if ((boardTemp & block) == 0)
            return true;
    }

    return false;
}

char canWin(int boardState) {
    char &ret = cache[boardState];
    if (ret != -1) return ret;
    if (!canPut(boardState)) return ret = 0;

    ret = 1;
    int block;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 6; k++) {
                block = blocks[k] >> (i * 5);
                block = block >> j;
                if ((boardState & block) == 0)
                    ret = min(ret, canWin(boardState | block));
            }
        }
    }

    for (int j = 0; j < 4; j++) {
        block = blocks[0] >> (4 * 5);
        block = block >> j;
        if ((boardState & block) == 0)
            ret = min(ret, canWin(boardState | block));
    }

    for (int i = 0; i < 4; i++) {
        block = blocks[1] >> (i * 5);
        block = block >> 4;
        if ((boardState & block) == 0)
            ret = min(ret, canWin(boardState | block));
    }

    ret = ret == 0 ? 1 : 0;
    return ret;
}

void solve() {
    if (canWin(vectorToInt(board)))
        printf("WINNING\n");
    else
        printf("LOSING\n");
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