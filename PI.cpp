// Algorithm: Dynamic Programming
// Time Complexity: O(N) # N: the length of the sequence
// The number of Calculations: 10000 * 3 * 18

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX_LEN = 10000;
int C;
string number;
int cache[MAX_LEN];

void init() {
    memset(cache, -1, sizeof(cache));
}

void input() {
    cin >> number;
}

void setup() {

}

// 여기 수정....
int calScore(string str) {
    vector<int> sub;
    for (int i = 1; i < str.size(); i++)
        sub.push_back(str[i] - str[i - 1]);

    int i;
    for (i = 0; i < sub.size(); i++)
        if (sub[i] != 0)
            break;
    if (i == sub.size()) return 1;

    for (i = 1; i < sub.size(); i++){
        if (sub[i] == sub[i - 1] && sub[i] == 1) continue;
        else break;
    }
    if (i == sub.size()) return 2;

    for (i = 1; i < sub.size(); i++){
        if (sub[i] == sub[i - 1] && sub[i] == -1)
            continue;
        else break;
    }
    if (i == sub.size()) return 2;

    for (i = 1; i < sub.size(); i++)
        if (sub[i] != -sub[i-1])
            break;
    if (i == sub.size()) return 4;

    for (i = 1; i < sub.size(); i++)
        if (sub[i - 1] != sub[i])
            break;
    if (i == sub.size()) return 5;

    return 10;
}

int calTotalScore(int pos) {
    if (pos == number.size()) return 0;
    if (pos > number.size()) return INF;
    int &ret = cache[pos];
    if (ret != -1) return ret;

    ret = INF;
    for (int nextPos = pos + 3; nextPos <= pos + 5 && nextPos <= number.size(); nextPos++) {
        ret = min(ret, calTotalScore(nextPos) + calScore(number.substr(pos, nextPos - pos)));

    }
    return ret;
}

void solve() {
    printf("%d\n", calTotalScore(0));
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