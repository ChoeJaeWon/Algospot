// Algorithm: Dynamic Programming
// Time Complexity: O(D * N^2)
// The number of Calculations: 100 * 50 * 50

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
const int MAX_D = 100;
int C;
int n, d, p, t;
vector<vector<int>> adj;
vector<int> villages;
double cache[MAX_N][MAX_D + 1];

void init() {
    villages.clear();
    memset(cache, -1, sizeof(cache));
}

void input() {
    scanf("%d %d %d", &n, &d, &p);

    int temp;
    adj = vector<vector<int>>(n, vector<int>());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &temp);
            if (temp) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &temp);
        villages.push_back(temp);
    }
}

double calProp(int curPos, int leftDays) {
    if (leftDays == 0 && curPos == p) return 1;
    if (leftDays == 0 && curPos != p) return 0;

    double &ret = cache[curPos][leftDays];
    if (ret > -0.5) return ret;

    ret = 0.0;
    for (int i = 0, nextPos = adj[curPos][i]; i < adj[curPos].size(); i++, nextPos = adj[curPos][i]) {
        ret += calProp(nextPos, leftDays - 1) / adj[nextPos].size();
    }
    return ret;
}

void setup() {

}

void solve() {
    for (int i = 0; i < villages.size(); i++) {
        printf("%.8lf ", calProp(villages[i], d));
    }
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