// Algorithm: Dynamic Programming
// Time Complexity: O(N) # N: the width of the rectangle
// The number of Calculations: 100+2*100

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
const int MAX_N = 100;
int C;
int n;
int totalCases[MAX_N + 1];
int symCases[MAX_N + 1];

void init() {
    memset(totalCases, -1, sizeof(totalCases));
    memset(symCases, -1, sizeof(symCases));
}

int calTotalCases(int width) {
    int &ret = totalCases[width];
    if (ret != -1) return ret;

    ret = calTotalCases(width - 1) + calTotalCases(width - 2);
    ret %= DIV;

    return ret;
}

int calSymCases(int width) {
    int &ret = symCases[width];
    if (ret != -1) return ret;

    ret = calSymCases(width - 2) + calSymCases(width - 4);
    ret %= DIV;

    return ret;
}

void setup() {
    totalCases[1] = 1, totalCases[2] = 2;
    symCases[1] = 1, symCases[2] = 2, symCases[3] = 1, symCases[4] = 3;

    calTotalCases(100);
    calSymCases(100);
    calSymCases(99);
}

void input() {
    scanf("%d", &n);
}


void solve() {
    printf("%d\n", (DIV + totalCases[n] - symCases[n]) % DIV);

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