// Algorithm: Dynamic Programming
// Time Complexity: O(N^2) # N: the width of the board
// The number of Calculations: 100^2

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX_N = 100;
int C;
int N;
vector<vector<int>> board;
int cache[MAX_N][MAX_N];

void init() {
    memset(cache, -1, sizeof(cache));
}

void input() {
    scanf("%d", &N);
    board = vector<vector<int>>(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &board[i][j]);

}

void setup() {

}

bool canReachToGoal(int y, int x) {
    int &ret = cache[y][x];
    if (ret != -1) return ret;
    if (y == N - 1 && x == N - 1) return true;

    ret = false;
    if (y + board[y][x] < N) ret |= canReachToGoal(y + board[y][x], x);
    if (x + board[y][x] < N) ret |= canReachToGoal(y, x + board[y][x]);

    return ret;
}

void solve() {
    if (canReachToGoal(0, 0)) printf("YES\n");
    else printf("NO\n");
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