// Algorithm: Exhaustive Search
// Time Complexity: ...
// The number of Calculations: 4^(50/3)

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int axisy[4][2] = {{0, 1},
                   {0, 1},
                   {1, 1},
                   {1, 1}};
int axisx[4][2] = {{1, 0},
                   {1, 1},
                   {0, 1},
                   {0, -1}};
int C;
int H, W;
vector<string> board;

void init() {
    board.clear();
}

void input() {
    scanf("%d %d", &H, &W);

    string temp;
    for (int i = 0; i < H; i++) {
        cin >> temp;
        board.push_back(temp);
    }
}


void setup() {

}

bool canPut(int y, int x, int i) {
    for (int j = 0; j < 2; j++) {
        int dy = y + axisy[i][j];
        int dx = x + axisx[i][j];
        if (dy < 0 || dy >= H || dx < 0 || dx >= W || board[dy][dx] == '#') return false;
    }
    return true;
}

void AddToBoard(int y, int x, int i) {
    \
    board[y][x] = '#';
    for (int j = 0; j < 2; j++) {
        int dy = y + axisy[i][j];
        int dx = x + axisx[i][j];
        board[dy][dx] = '#';
    }
}

void removeFromBoard(int y, int x, int i) {
    board[y][x] = '.';
    for (int j = 0; j < 2; j++) {
        int dy = y + axisy[i][j];
        int dx = x + axisx[i][j];
        board[dy][dx] = '.';
    }
}


int countCases(int y, int x) {
    if (x == W) return countCases(y + 1, 0);
    if (y == H) return 1;
    if (board[y][x] == '#') return countCases(y, x + 1);

    int ret = 0;
    for (int i = 0; i < 4; i++) {
        if (canPut(y, x, i)) {
            AddToBoard(y, x, i);
            ret += countCases(y, x + 1);
            removeFromBoard(y, x, i);
        }
    }
    return ret;
}

void solve() {
    printf("%d\n", countCases(0, 0));
}

int main() {
    scanf("%d", &C);
    while (C--) {
        init();
        input();
        setup();
        solve();

    }
}