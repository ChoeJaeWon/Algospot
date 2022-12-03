// Algorithm: Dynamic Programming
// Time Complexity: O(N^2)
// The number of Calculations: 50^2 * 2

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX_N = 50;
const int TURN = 2;
int C;
int n;
int board[MAX_N];
int cache[MAX_N][MAX_N][TURN];

void init() {
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_N; j++)
            for (int k = 0; k < 2; k++)
                cache[i][j][k] = INF;
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &board[i]);
}

void setup() {

}

int scoreDifference(int left, int right, int turn) {
    if (right == left - 1) return 0;

    int &ret = cache[left][right][turn];
    if (ret != INF) return ret;

    ret = board[left] - scoreDifference(left + 1, right, !turn);
    ret = max(ret, board[right] - scoreDifference(left, right - 1, !turn));
    if (right - left >= 1) {
        ret = max(ret, -scoreDifference(left + 2, right, !turn));
        ret = max(ret, -scoreDifference(left, right - 2, !turn));
    }
    return ret;
}

void solve() {
    printf("%d\n", scoreDifference(0, n - 1, 0));
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