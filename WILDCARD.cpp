// Algorithm: Dynamic Programming
// Time Complexity: O(NMK) # N: the length of the expression, M: the length of the word, K: the number of words;
// The number of Calculations: 100*100*50;

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
int C;
int N;
string expression;
vector<string> words;
int cache[MAX_N][MAX_N];

void init() {
    words.clear();
}

void input() {
    cin >> expression;
    scanf("%d", &N);

    string temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        words.push_back(temp);
    }
}

void setup() {
    sort(words.begin(), words.end());
}

int isMatched(int expressionPos, int wordPos, const string &word) {
    if (wordPos == word.size() && expressionPos == expression.size()) return true;
    if (expressionPos == expression.size()) return false;
    if (wordPos == word.size()) {
        if(expression[expressionPos] == '*')
            return isMatched(expressionPos+1, wordPos, word);
        else
            return false;
    }

    int &ret = cache[expressionPos][wordPos];
    if (ret != -1) return ret;

    ret = 0;
    if (expression[expressionPos] == '*') {
        for (int nextWordPos = wordPos; nextWordPos <= word.size(); nextWordPos++) {
            ret |= isMatched(expressionPos + 1, nextWordPos, word);
        }
    } else if (expression[expressionPos] == '?' || expression[expressionPos] == word[wordPos]) {
        ret |= isMatched(expressionPos + 1, wordPos + 1, word);
    }
    return ret;
}

void solve() {
    for (int i = 0; i < words.size(); i++) {
        memset(cache, -1, sizeof(cache));
        if (isMatched(0, 0, words[i])) cout << words[i] << endl;
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