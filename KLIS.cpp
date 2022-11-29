// Algorithm: Dynamic Programming
// Time Complexity: O(N^2 * logN) # N: the length of sequence
// The number of Calculations: 2*500*500 + 500*500*8

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;

const long long INF = 9876543210;
const int MAX_N = 500;
int C;
int N;
long long K;
vector<int> sequence;
int lengthCache[MAX_N + 1];
long long casesCache[MAX_N + 1];
vector<vector<pair<int, int>>> adj;

void init() {
    memset(lengthCache, -1, sizeof(lengthCache));
    memset(casesCache, -1, sizeof(casesCache));
    sequence.clear();
    adj.clear();
}

void input() {
    scanf("%d %lld", &N, &K);

    int temp;
    sequence.push_back(0);
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        sequence.push_back(temp);
    }
}

int calMaxLength(int pos) {

    int &ret = lengthCache[pos];
    if (ret != -1) return ret;

    ret = 1;
    for (int nextPos = pos + 1; nextPos <= N; nextPos++) {
        if (sequence[pos] < sequence[nextPos])
            ret = max(ret, calMaxLength(nextPos) + 1);
    }
    return ret;
}

void setup() {
    calMaxLength(0);
    adj = vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>());
}

long long reconstruct(int pos) {
    long long &ret = casesCache[pos];
    if (ret != -1) return ret;

    ret = 0;
    for (int nextPos = pos + 1; nextPos <= N; nextPos++) {
        if (sequence[pos] < sequence[nextPos] && lengthCache[pos] - 1 == lengthCache[nextPos]) {
            ret += reconstruct(nextPos);
            adj[pos].push_back(make_pair(sequence[nextPos], nextPos));
            if (ret > INF) ret = INF;
        }
    }

    if (ret == 0) ret = 1;
    return ret;
}

void findKthSequence(int pos) {
    for (int nextPosIdx = 0; nextPosIdx < adj[pos].size(); nextPosIdx++) {
        long long temp = casesCache[adj[pos][nextPosIdx].second];
        if (K <= temp) {
            printf("%d ", adj[pos][nextPosIdx].first);
            findKthSequence(adj[pos][nextPosIdx].second);
            break;
        } else {
            K -= temp;
        }
    }
}

void solve() {
    reconstruct(0);
    for (int i = 0; i <= N; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    printf("%d\n", lengthCache[0] - 1);
    findKthSequence(0);
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