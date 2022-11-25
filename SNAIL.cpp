// Algorithm: Dynamic Programming
// Time Complexity: O(MN) # M: the length of days, N: the depth of the well
// The number of Calculations: 1000*1000

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX_N = 1000;
const int MAX_M = 1000;
int C;
int n, m;
double prop[MAX_N][MAX_M];

void init() {
    memset(prop, -1, sizeof(prop));
}

void input() {
    scanf("%d %d", &n, &m);
}

void setup() {

}

double calProp(int depth, int day) {
    if (depth >= n) return 1;
    if (day == m) return 0;

    double &ret = prop[depth][day];
    if (ret > -0.5) return ret;

    ret = 0.0;
    ret = calProp(depth + 1, day + 1) * 0.25 + calProp(depth + 2, day + 1) * 0.75;

    return ret;
}

void solve() {
    printf("%.12lf\n", calProp(0, 0));
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