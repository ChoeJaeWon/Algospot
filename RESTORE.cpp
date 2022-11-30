// Algorithm: Dynamic Programming
// Time Complexity: O(2^N * N^2) # N: the number of data
// The number of Calculations: 2^15 * 15 * 15

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX_K = 15;
int C;
int k;

vector<string> words;
int cache[1 << MAX_K][MAX_K];
int overlap[MAX_K][MAX_K];


void init() {
    words.clear();
    memset(cache, -1, sizeof(cache));
    memset(overlap, -1, sizeof(overlap));
}

void input() {
    scanf("%d", &k);

    string temp;
    for (int i = 0; i < k; i++) {
        cin >> temp;
        words.push_back(temp);
    }
}

int calOverlap(int a, int b) {
    int as = words[a].size(), bs = words[b].size();
    int len = min(as, bs);

    for (int i = len - 1; i > 0; i--) {
        if (words[a].substr(as - i) == words[b].substr(0, i))
            return i;
    }
    return 0;
}


void setup() {
    int included[MAX_K];
    memset(included, 0, sizeof(included));

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            if (i != j && words[i].find(words[j]) != string::npos)
                included[j] = 1;

    vector<string> newWords;
    for (int i = 0; i < k; i++)
        if (included[i] == 0)
            newWords.push_back(words[i]);
    words = newWords;
    k = newWords.size();

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            if (i != j)
                overlap[i][j] = calOverlap(i, j);
}

int calShortestLen(int used, int lastWord) {
    int &ret = cache[used][lastWord];
    if (used == (1 << k) - 1) return ret = 0;

    if (ret != -1) return ret;

    ret = INF;
    for (int nextWord = 0; nextWord < k; nextWord++) {
        if ((used & (1 << nextWord)) == 0) {
            int added = int(words[nextWord].size()) - overlap[lastWord][nextWord];
            ret = min(ret, calShortestLen(used | (1 << nextWord), nextWord) + added);
        }
    }
    return ret;
}

string reconstruct(int used, int lastWord) {
    if (used == (1 << k) - 1) return "";

    for (int nextWord = 0; nextWord < k; nextWord++) {
        int seletedVal = cache[used][lastWord] - words[nextWord].size() + overlap[lastWord][nextWord];
        if ((used & (1 << nextWord)) == 0 && cache[used | (1 << nextWord)][nextWord] == seletedVal)
            return words[nextWord].substr(overlap[lastWord][nextWord]) + reconstruct(used | (1 << nextWord), nextWord);

    }
}

void solve() {
    int sol = INF;
    int startWord = 0;
    for (int initWord = 0; initWord < k; initWord++) {
        int val = calShortestLen(1 << initWord, initWord) + int(words[initWord].size());
        if (sol > val) {
            sol = val;
            startWord = initWord;
        }
    }
    cout << words[startWord] + reconstruct(1 << startWord, startWord) << endl;
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