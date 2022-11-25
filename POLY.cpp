// Algorithm: Dynamic Programming
// Time Complexity: O(N^3) # N: the number of blocks
// The number of Calculations: 100*100*100

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int DIV = 10000000;
const int MAX_N = 100;
int C;
int n;
int cache[MAX_N + 1][MAX_N + 1];

void init() {
    memset(cache, -1, sizeof(cache));
}

void input() {
    scanf("%d", &n);
}

void setup() {

}

int cntCases(int leftBlocks, int prevBlocks) {
    if (leftBlocks == 0) return 1;

    int &ret = cache[leftBlocks][prevBlocks];
    if (ret != -1) return ret;

    ret = 0;
    for (int nextBlocks = leftBlocks; nextBlocks > 0; nextBlocks--) {
        if (prevBlocks != 0)
            ret = ret + (prevBlocks + nextBlocks - 1) * cntCases(leftBlocks - nextBlocks, nextBlocks);
        else
            ret = ret + cntCases(leftBlocks - nextBlocks, nextBlocks);
        ret %= DIV;
    }

    return ret;
}

void solve() {
    printf("%d\n", cntCases(n, 0));
}

int main() {
    scanf("%d", &C);
    init();
    while (C--) {
        input();
        setup();
        solve();
    }
}