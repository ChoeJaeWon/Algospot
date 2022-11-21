// Algorithm: Divide & conquer
// Time Complexity: O(N)
// The number of Calculations: 1000

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <string>

using namespace std;

const int INF = 987654321;
int C;
string word;

void init() {

}

void input() {
    cin >> word;
}

void setup() {

}

string flip(int pos) {
    string quarterWords[4];

    if (word[pos] == 'x') {
        pos++;
        quarterWords[0] = flip(pos);
        for (int i = 1; i < 4; i++) {
            pos += quarterWords[i - 1].length();
            quarterWords[i] = flip(pos);
        }
        return "x" + quarterWords[2] + quarterWords[3] + quarterWords[0] + quarterWords[1];
    } else {
        string ret(1, word[pos]);
        return ret;
    }
}

void solve() {
    cout << flip(0) << endl;
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