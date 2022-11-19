// Algorithm: Dynamic Programming
// Time Complexity: O(W*H*N) #board size, length of word
// The number of Calculations: 5*5*10

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int diry[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dirx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int C;
int N;
int cache[5][5][10];
vector<string> board;
vector<string> words;

void init() {
    board = vector<string>(5, "");
    words.clear();
}

void input() {
    for (int i = 0; i < 5; i++)
        cin >> board[i];

    scanf("%d", &N);
    string temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        words.push_back(temp);
    }
}


void setup() {

}

int isMatch(int y, int x, int pos, string word) {
    int &ret = cache[y][x][pos];
    if (ret != -1) return ret;
    if (board[y][x] != word[pos]) return ret = 0;
    if (pos == word.size() - 1) return ret = 1;

    ret = 0;
    for (int i = 0; i < 8; i++) {
        int dy = y + diry[i];
        int dx = x + dirx[i];
        if (dx >= 0 && dx < 5 && dy >= 0 && dy < 5) {
            ret |= isMatch(dy, dx, pos + 1, word);
        }
    }

    return ret;
}

void solve() {
    for (int i = 0; i < N; i++) {
        int ret = 0;
        memset(cache, -1, sizeof(cache));
        for (int y = 0; y < 5; y++)
            for (int x = 0; x < 5; x++)
                ret |= isMatch(y, x, 0, words[i]);
        if (ret)
            cout << words[i] << " YES" << endl;
        else
            cout << words[i] << " NO" << endl;
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

