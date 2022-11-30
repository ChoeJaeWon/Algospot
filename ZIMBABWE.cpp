// Algorithm: Dynamic Programming
// Time Complexity: O(M* 2^N * N) # N: the number of digits, M: the max number of divisor
// The number of Calculations: 20 * 2^15 * 15 * 2

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int DIV = 1000000007;
const int MAX_M = 20;
const int MAX_DIGITS = (1 << 15) - 1;
int C;
int m, l;
vector<int> price;
int cache[MAX_M][MAX_DIGITS][2];


void init() {
    price.clear();
    memset(cache, -1, sizeof(cache));
}

void input() {
    string temp;
    cin >> temp;

    l = temp.size();
    for (int i = 0; i < temp.size(); i++)
        price.push_back(int(temp[i] - '0'));
    scanf("%d", &m);
}

void setup() {

}

int casesOfPrices(int prevRemain, int used, int isSmall) {
    if (used == (1 << l) - 1) {
        if (isSmall && prevRemain == 0)
            return 1;
        else
            return 0;
    }

    int &ret = cache[prevRemain][used][isSmall];
    if (ret != -1) return ret;
    ret = 0;

    vector<int> digits(10, 0);
    for (int i = 0; i < l; i++) {
        if ((used & (1 << i)) == 0 && digits[price[i]] == 0) {
            digits[price[i]] = 1;
            int nextRemain = (prevRemain * 10 + price[i]) % m;
            if (isSmall || price[i] < price[__builtin_popcount(used)])
                ret += casesOfPrices(nextRemain, used | (1 << i), 1);
            else if (price[i] == price[__builtin_popcount(used)])
                ret += casesOfPrices(nextRemain, used | (1 << i), 0);
            ret %= DIV;
        }
    }
    return ret;
}

void solve() {
    int sol = 0;

    vector<int> digits(10, 0);
    for (int i = 0; i < l; i++) {
        if (digits[price[i]] == 0) {
            digits[price[i]] = 1;
            if (price[0] > price[i])
                sol += casesOfPrices(price[i] % m, 1 << i, 1);
            else if (price[0] == price[i])
                sol += casesOfPrices(price[i] % m, 1 << i, 0);
        }
        sol %= DIV;
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