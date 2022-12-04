// Algorithm: Greed Algorithm
// Time Complexity: O(N * logN) # N: the number of member
// The number of Calculations: 100*9 + 100

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
int n;
vector<int> russians;
vector<int> koreans;

void init() {
    russians.clear();
    koreans.clear();
}

void input() {
    scanf("%d", &n);

    int temp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        russians.push_back(temp);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        koreans.push_back(temp);
    }
}

void setup() {
    std::sort(russians.begin(), russians.end());
    std::sort(koreans.begin(), koreans.end());
}

void solve() {
    int curR = 0;
    int sol = 0;
    for (int curK = 0; curK < n; curK++) {
        if (koreans[curK] >= russians[curR]) {
            sol++;
            curR++;
        }
    }
    printf("%d\n", sol);
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