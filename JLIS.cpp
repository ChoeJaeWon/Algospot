// Algorithm: Dynamic Programming
// Time Complexity: O(NM(N+M)) # N: the length of A sequence, M: the length of B sequence
// The number of Calculations: 100*100*200

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;

const long long INF = 9876543210;
const int MAX_N = 100;
int C;
int n, m;
vector<long long> aSequence;
vector<long long> bSequence;
int cache[MAX_N + 1][MAX_N + 1];

void init() {
    aSequence.clear();
    bSequence.clear();
    memset(cache, -1, sizeof(cache));
}

void input() {
    scanf("%d %d", &n, &m);
    long long temp;
    aSequence.push_back(0);
    bSequence.push_back(0);
    for (int i; i < n; i++) {
        scanf("%lld", &temp);
        aSequence.push_back(temp);
    }
    for (int i; i < m; i++) {
        scanf("%lld", &temp);
        bSequence.push_back(temp);
    }
}

void setup() {

}

int lengthOfSubsequence(int a, int b, long long prevVal) {
    if (a == n && b == m) return 0;
    int &ret = cache[a][b];
    if (ret != -1) return ret;

    ret = 0;
    if (a < n) {
        for (int aNext = a + 1; aNext <= n; aNext++) {
            if (prevVal < aSequence[aNext])
                ret = max(ret, lengthOfSubsequence(aNext, b, aSequence[aNext]) + 1);
        }
    }
    if (b < m) {
        for (int bNext = b + 1; bNext <= m; bNext++) {
            if (prevVal < bSequence[bNext])
                ret = max(ret, lengthOfSubsequence(a, bNext, bSequence[bNext]) + 1);
        }
    }
    return ret;
}

void solve() {
    printf("%d\n", lengthOfSubsequence(0, 0, -INF));
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