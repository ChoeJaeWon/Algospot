// Algorithm: Dynamic Programming
// Time Complexity: O(N * 2^N) # N: the number of cities
// The number of Calculations: 2^15 * 15

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;

const double INF = 98765;
const int MAX_N = 15;
int C;
int N;
double cache[1 << MAX_N][MAX_N];
vector<vector<double>> adj;

void init() {
    memset(cache, -1, sizeof(cache));
}

void input() {
    scanf("%d", &N);

    adj = vector<vector<double>>(N, vector<double>(N, 0.0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%lf", &adj[i][j]);

}

void setup() {

}

double calMinDist(int visited, int presentCity) {
    double &ret = cache[visited][presentCity];
    if (visited == ((1 << N) - 1)) return 0;
    if (ret > -1.0e-7) return ret;

    ret = INF;
    for (int nextCity = 0; nextCity < N; nextCity++) {
        if (((1 << nextCity) & visited) == 0)
            ret = min(ret, adj[presentCity][nextCity] + calMinDist(visited | (1 << nextCity), nextCity));
    }
    return ret;

}

void solve() {

    double minDist = INF;
    for (int startCity = 0; startCity < N; startCity++) {
        minDist = min(minDist, calMinDist(1 << startCity, startCity));
    }
    printf("%.12lf\n", minDist);
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