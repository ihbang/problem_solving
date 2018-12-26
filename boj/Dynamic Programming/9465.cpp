#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > score;
vector<vector<int> > dp;

int max3(int a, int b, int c) {
    if (a > b) {
        if (a > c)
            return a;
        else
            return c;
    } else {
        if (b > c)
            return b;
        else
            return c;
    }
}

int sticker(int k, int l) {
    if (dp[k][l] != -1)
        return dp[k][l];
    else if (l == 0) {
        dp[k][l] = max3(sticker(k - 1, 0), sticker(k - 1, 1), sticker(k - 1, 2));
        return dp[k][l];
    } else if (l == 1) {
        dp[k][l] = max(sticker(k - 1, 0), sticker(k - 1, 2)) + score[k][0];
        return dp[k][l];
    } else {
        dp[k][l] = max(sticker(k - 1, 0), sticker(k - 1, 1)) + score[k][1];
        return dp[k][l];
    }
}

int main() {
    int t, n;

    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        int m;

        scanf("%d", &n);
        for (int j = 0; j < n; ++j) {
            int a;
            scanf("%d", &a);
            vector<int> sv(2);
            vector<int> dv(3);
            sv[0] = a;
            dv[0] = dv[1] = dv[2] = -1;
            score.push_back(sv);
            dp.push_back(dv);
        }
        for (int j = 0; j < n; ++j) {
            int a;
            scanf("%d", &a);
            score[j][1] = a;
        }
        dp[0][0] = 0;
        dp[0][1] = score[0][0];
        dp[0][2] = score[0][1];

        m = max3(sticker(n - 1, 0), sticker(n - 1, 1), sticker(n - 1, 2));
        printf("%d\n", m);

        score.clear();
        dp.clear();
    }
}