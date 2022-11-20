// Algorithm: Exhaustive Search
// Time Complexity: O(4^N) # N: the number of clocks
// The number of Calculations: 4^10

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX_C = 16;
const int MAX_B = 10;
int C;
int cl[MAX_C];
vector<vector<int>> button({vector<int>({0, 1, 2}),
                            vector<int>({3, 7, 9, 11}),
                            vector<int>({4, 10, 14, 15}),
                            vector<int>({0, 4, 5, 6, 7}),
                            vector<int>({6, 7, 8, 10, 12}),
                            vector<int>({0, 2, 14, 15}),
                            vector<int>({3, 14, 15}),
                            vector<int>({4, 5, 7, 14, 15}),
                            vector<int>({1, 2, 3, 4, 5}),
                            vector<int>({3, 4, 5, 9, 13})});

void init() {
    memset(cl, 0, sizeof(cl));
}

void input() {
    for (int i = 0; i < MAX_C; i++) {
        scanf("%d", &cl[i]);
        cl[i] %= 12;
    }
}

void setup() {

}

bool isAll12() {
    for (int i = 0; i < MAX_C; i++)
        if (cl[i] != 0) return false;
    return true;
}

void clickButton(int cur, int clickNum) {
    for (int i = 0; i < button[cur].size(); i++)
        cl[button[cur][i]] = (cl[button[cur][i]] + 3 * clickNum) % 12;
}


void unclickButton(int cur, int clickNum) {
    for (int i = 0; i < button[cur].size(); i++)
        cl[button[cur][i]] = (cl[button[cur][i]] + 12 - 3 * clickNum) % 12;

}

int calMinNumberOfClick(int cur) {
    if (cur == MAX_B) {
        if (isAll12()) return 0;
        else
            return INF;
    }

    int ret = INF;
    for (int i = 0; i < 4; i++) {
        clickButton(cur, i);
        ret = min(ret, i + calMinNumberOfClick(cur + 1));
        unclickButton(cur, i);
    }
    return ret;
}

void solve() {
    int ret = calMinNumberOfClick(0);

    if (ret >= INF) printf("-1\n");
    else printf("%d\n", ret);
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