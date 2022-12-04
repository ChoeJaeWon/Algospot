// Algorithm: Huffman Code
// Time Complexity: O(N^2 * logN) # N: the number of strings
// The number of Calculations: 100^2 * 7

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
vector<int> strLen;

void init() {
    strLen.clear();
}

void input() {
    scanf("%d", &n);
    int temp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        strLen.push_back(temp);
    }
}

void setup() {

}

void solve() {
    n = n - 1;
    int sol = 0;
    int sum;
    while (n--) {
        std::sort(strLen.begin(), strLen.end());
        sum = strLen[0] + strLen[1];
        sol = sol + sum;
        strLen.erase(strLen.begin(), strLen.begin() + 2);
        strLen.push_back(sum);
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