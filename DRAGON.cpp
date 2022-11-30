// Algorithm: Precalculate
// Time Complexity: O(M * N * logN) # N: the number of level, M: the length of sequence
// The number of Calculations: 50 * 50 * 7

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;

const long long INF = 9876543210;
const int MAX_N = 50;
int C;
int n, p, l;
long long preCal[MAX_N + 1];


void init() {

}

void input() {
    scanf("%d %d %d", &n, &p, &l);
}

void setup() {
    for (int i = 0; i <= 28; i++)
        preCal[i] = (1 << i) * 3 - 1;
    for (int i = 29; i <= MAX_N; i++)
        preCal[i] = INF;
}

char searchChar(int k, int level, string partial) {
    if (level == n) return partial[k];
    if (level == 0) return searchChar(k, 1, "FX+YF");

    string temp;
    if (k == preCal[n - level]) {
        return partial[2];
    } else if (k < preCal[n - level]) {
        partial[0] == 'F' ? temp = "FX+YF" : temp = "FX-YF";
        return searchChar(k, level + 1, temp);
    } else {
        partial[3] == 'F' ? temp = "FX+YF" : temp = "FX-YF";
        return searchChar(k - preCal[n - level] - 1, level + 1, temp);
    }
}

void solve() {
    for (int i = p; i < p + l; i++) {
        printf("%c", searchChar(i - 1, 0, "FX"));
    }
    printf("\n");
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