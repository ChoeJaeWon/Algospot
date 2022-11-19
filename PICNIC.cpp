// Algorithm: Dynamic Programming
// Time Complexity: 2^N # N: the number of people
// The number of Calculations: 2^10

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int C;
int n, m;
int cache[1 << 10];
vector<vector<int>> adj;

void init() {
    memset(cache, -1, sizeof(cache));
}

void input() {
    scanf("%d %d", &n, &m);

    int t1, t2;
    adj = vector<vector<int>>(n, vector<int>());
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &t1, &t2);
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }
}

void setup() {

}

int NumberOfCasesToGo(int satisfied) {
    int &ret = cache[satisfied];

    if (ret != -1) return ret;
    if (satisfied == ((1 << n) - 1)) return 1;

    int pos = 0;
    while ((satisfied & (1 << pos)) != 0) pos++;

    ret = 0;
    for (int i = 0; i < adj[pos].size(); i++) {
        int frend = adj[pos][i];
        if ((satisfied & (1 << frend)) == 0)
            ret += NumberOfCasesToGo(satisfied | ((1 << pos) + (1 << frend)));
    }
    return ret;
}

void solve() {
    printf("%d\n", NumberOfCasesToGo(0));
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