// Algorithm: Dynamic Programming & Partial Summation
// Time Complexity: O(N^2 * S) # N: the length of sequence, S: the number of used numbers
// The number of Calculations: 100^2 * 10

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX_n = 100;
const int MAX_s = 10;
int C;
int n, s;
vector<int> sequence;
int cache[MAX_n][MAX_s];
int partialSum[MAX_n + 1];

void init() {
    memset(cache, -1, sizeof(cache));
    sequence.clear();
    partialSum[0] = 0;
}

void input() {
    scanf("%d %d", &n, &s);
    int temp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        sequence.push_back(temp);
    }
}

void setup() {
    sort(sequence.begin(), sequence.end());
    for (int i = 0; i < n; i++) {
        partialSum[i + 1] = partialSum[i] + sequence[i];
    }
}

int ErrorValue(int a, int b) {
    int ret = 0;
    int avg = int(round(double(partialSum[b + 1] - partialSum[a]) / (b - a + 1)));
    for (int i = a; i <= b; i++)
        ret += (sequence[i] - avg) * (sequence[i] - avg);
    return ret;
}

int minimizeErrorValue(int nCur, int sCur) {
    if (nCur == n) return 0;
    if (sCur == s - 1) return ErrorValue(nCur, n - 1);

    int &ret = cache[nCur][sCur];
    if (ret != -1) return ret;

    ret = INF;
    for (int nNext = nCur + 1; nNext <= n; nNext++)
        ret = min(ret, minimizeErrorValue(nNext, sCur + 1) + ErrorValue(nCur, nNext - 1));

    return ret;
}
// 1 1 2 2 2 2 3 3 3 3

void solve() {
    printf("%d\n", minimizeErrorValue(0, 0));
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