// Algorithm: Dynamic Programming
// Time Complexity: O(N) # N: the width of the rectangle
// The number of Calculations: 100

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int DIV = 1000000007;
const int MAX_n = 100;
int C;
int n;
int cache[MAX_n + 1];


void init() {
    memset(cache, -1, sizeof(cache));
    cache[1] = 1;
    cache[2] = 2;
}

int countCases(int nCur) {
    int &ret = cache[nCur];
    if (ret != -1) return ret;

    ret = 0;
    ret = countCases(nCur - 1) + countCases(nCur - 2);
    ret %= DIV;

    return ret;
}

void setup() {
    countCases(100);
}


void input() {
    scanf("%d", &n);
}


void solve() {
    printf("%d\n", cache[n]);
}

int main() {
    scanf("%d", &C);
    init();
    setup();
    while (C--) {
        input();
        solve();
    }
}