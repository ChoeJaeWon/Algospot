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
int C;
int N, L;
int partialSum[MAX_N + 1];

void input() {

}

void init() {
    scanf("%d %d", &N, &L);

    int temp;
    partialSum[0] = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &temp);
        partialSum[i] = temp + partialSum[i - 1];
    }
}

void setup() {

}

double solve() {
    double minVal = 9999;
    for (int i = 0; i <= N - L; i++) {
        for (int j = i + L; j <= N; j++) {
            minVal = min(minVal, double(partialSum[j] - partialSum[i]) / (j - i));
        }
    }
    return minVal;
}

int main() {
    scanf("%d", &C);
    while (C--) {
        init();
        input();
        setup();
        printf("%.12lf\n", solve());
    }
}