// Algorithm: Dynamic Programming
// Time Complexity: O(NW) # N: the number of items, W: the limitation of the weight
// The number of Calculations: 2*100*1000

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX_N = 100;
const int MAX_W = 1000;
int C;
int N, W;
vector<pair<int, int>> items;
vector<string> names;
int cache[MAX_N + 1][MAX_W + 1];
vector<int> selectedItems;


void init() {
    memset(cache, -1, sizeof(cache));
    items.clear();
    selectedItems.clear();
    names.clear();
}

void input() {
    scanf("%d %d", &N, &W);

    int V, P;
    string name;
    for (int i = 0; i < N; i++) {
        cin >> name;
        scanf("%d %d", &V, &P);
        names.push_back(name);
        items.push_back(make_pair(V, P));
    }
}

void setup() {

}

int maxPreference(int curItem, int leftVolume) {
    if (curItem == N) return 0;

    int &ret = cache[curItem][leftVolume];
    if (ret != -1) return ret;

    ret = 0;

    int select = 0;
    if (leftVolume - items[curItem].first >= 0)
        select = maxPreference(curItem + 1, leftVolume - items[curItem].first) + items[curItem].second;
    ret = max(select, maxPreference(curItem + 1, leftVolume));

    return ret;
}

void reconstruct(int curItem, int leftVolume) {
    if (curItem == N - 1) {
        if (leftVolume >= items[curItem].first) selectedItems.push_back(curItem);
        return;
    }
    if (cache[curItem][leftVolume] == cache[curItem + 1][leftVolume]) {
        reconstruct(curItem + 1, leftVolume);
    } else {
        selectedItems.push_back(curItem);
        reconstruct(curItem + 1, leftVolume - items[curItem].first);
    }

}

void solve() {
    int maxValue = maxPreference(0, W);
    reconstruct(0, W);
    printf("%d %d\n", maxValue, (int) selectedItems.size());
    for (int i = 0; i < selectedItems.size(); i++) {
        cout << names[selectedItems[i]] << endl;
    }
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