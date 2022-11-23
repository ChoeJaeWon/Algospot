// Algorithm: Dynamic Programming
// Time Complexity: O(N^2) # the length of Number
// The number of Calculations: 500 * 500

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX_N = 500;
int C;
int N;
vector<int> arr;
int cache[MAX_N + 1];

void init() {
    arr.clear();
    memset(cache, -1, sizeof(cache));
}

void input() {
    scanf("%d", &N);

    int temp;
    arr.push_back(0);
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        arr.push_back(temp);
    }
}

void setup() {

}

int sizeOfSubsequence(int pos) {
    if (pos == arr.size()) return 0;

    int &ret = cache[pos];
    if (ret != -1) return ret;

    ret = 0;
    for (int nextPos = pos + 1; nextPos <= N; nextPos++) {
        if (arr[pos] < arr[nextPos])
            ret = max(ret, sizeOfSubsequence(nextPos) + 1);
    }
    return ret;
}

void solve() {
    printf("%d\n", sizeOfSubsequence(0));
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