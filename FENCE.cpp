// Algorithm: Merge & Conquer
// Time Complexity: O(NlgN) # N: the number of fences
// The number of Calculations: 20000*lg(20000)

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
int N;
vector<int> fences;

void init() {
    fences.clear();
}

void input() {
    scanf("%d", &N);

    int temp;
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        fences.push_back(temp);
    }

}

void setup() {

}


int maxAreaOfFences(int start, int end) {
    if (end - start == 0) return fences[start];
    int mid = (start + end) / 2;
    int minH = fences[mid];
    int ret = 0;

    int s = mid;
    int e = mid;
    while (s != start || e != end) {
        if (s == start) {
            e++;
            minH = min(minH, fences[e]);
        } else if (e == end) {
            s--;
            minH = min(minH, fences[s]);
        } else {
            if (fences[s - 1] > fences[e + 1]) {
                s--;
                minH = min(minH, fences[s]);
            } else {
                e++;
                minH = min(minH, fences[e]);
            }
        }
        ret = max(ret, minH * (e - s + 1));
    }

    ret = max(ret, maxAreaOfFences(mid + 1, end));
    ret = max(ret, maxAreaOfFences(start, mid));

    return ret;

}

void solve() {
    printf("%d\n", maxAreaOfFences(0, fences.size() - 1));
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