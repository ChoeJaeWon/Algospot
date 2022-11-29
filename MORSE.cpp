// Algorithm:
// Time Complexity:
// The number of Calculations:

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int DIV = 1000000001;
const int MAX_MN = 100;
int C;
int n, m, k;
int cache[MAX_MN + 1][MAX_MN + 1];

void init() {
    memset(cache, -1, sizeof(cache));
}

void input() {
    scanf("%d %d %d", &n, &m, &k);
}

int calCases(int circle, int bar) {
    int &ret = cache[circle][bar];
    if (circle == 0 || bar == 0) return ret = 1;

    if (ret != -1) return ret;
    ret = calCases(circle - 1, bar) + calCases(circle, bar - 1);

    if (ret >= DIV) ret = DIV;

    return ret;
}

void setup() {
    calCases(100, 100);
}

string reconstruct(int circle, int bar) {
    if (circle == 0 && bar == 0) return "";

    string ret = "";
    if (circle == 0) {
        while (bar--) ret += "-";
        return ret;
    }
    if (bar == 0) {
        while (circle--) ret += "o";
        return ret;
    }

    if (k <= cache[circle][bar - 1]) {
        return "-" + reconstruct(circle, bar - 1);
    } else {
        k -= cache[circle][bar - 1];
        return "o" + reconstruct(circle - 1, bar);
    }
}

void solve() {
    cout << reconstruct(n, m) << endl;
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