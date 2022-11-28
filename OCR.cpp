// Algorithm: Dynamic Programming
// Time Complexity: O(N * M^2)
// The number of Calculations: 100*500*500

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <memory.h>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX_M = 500;
const int MAX_N = 100;
int C;
int m, q;
int n;
vector<int> sentence;

string words[MAX_M];
double initProp[MAX_M];
double joinProp[MAX_M][MAX_M];
double posProp[MAX_M][MAX_M];

double propCache[MAX_M][MAX_N];
int posCache[MAX_M][MAX_N];


void input() {
    scanf("%d %d", &m, &q);

    for (int i = 0; i < m; i++)
        cin >> words[i];

    for (int i = 0; i < m; i++) {
        scanf("%lf", &initProp[i]);
        initProp[i] = log(initProp[i]);
    }


    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) {
            scanf("%lf", &joinProp[i][j]);
            joinProp[i][j] = log(joinProp[i][j]);
        }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) {
            scanf("%lf", &posProp[i][j]);
            posProp[i][j] = log(posProp[i][j]);
        }

}

void setup() {

}


void init() {
    memset(propCache, 0, sizeof(propCache));
    memset(posCache, -1, sizeof(posCache));
    sentence.clear();
}

double maxProp(int prevWord, int pos) {
    if (pos == n) return 0;

    int &ch = posCache[prevWord][pos];
    double &ret = propCache[prevWord][pos];
    if (ch != -1) return ret;


    ret = maxProp(0, pos + 1) + joinProp[prevWord][0] + posProp[0][sentence[pos]];
    posCache[prevWord][pos] = 0;
    for (int i = 1; i < m; i++) {
        double temp = maxProp(i, pos + 1) + joinProp[prevWord][i] + posProp[i][sentence[pos]];
        if (ret < temp) {
            ret = temp;
            posCache[prevWord][pos] = i;
        }
    }

    return ret;
}

void reconstruct(int prevWord, int pos) {
    if (pos == n) {
        cout << endl;
        return;
    }
    int wordPos = posCache[prevWord][pos];
    cout << words[wordPos] << " ";
    reconstruct(wordPos, pos + 1);

}

void solve() {

    for (int curQ = 0; curQ < q; curQ++) {
        init();
        scanf("%d", &n);

        string temp;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            for (int j = 0; j < m; j++) {
                if (temp == words[j]) {
                    sentence.push_back(j);
                    break;
                }
            }
        }
        int initPos = 0;
        double ret = maxProp(0, 1) + initProp[0] + posProp[0][sentence[0]];
        for (int i = 1; i < m; i++) {
            double temp = maxProp(i, 1) + initProp[i] + posProp[i][sentence[0]];
            if (ret < temp) {
                ret = temp;
                initPos = i;
            }
        }
        posCache[0][0] = initPos;
        reconstruct(0, 0);
    }


}

int main() {
    input();
    setup();
    solve();

}