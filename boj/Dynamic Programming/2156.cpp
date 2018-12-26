#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> wine;
vector<vector<int> > dp;

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        wine.push_back(a);
        vector<int> dv(3);
        dv[0] = dv[1] = dv[2] = 0;
        dp.push_back(dv);
    }
    dp[0][1] = wine[0];

    for (int i = 1; i < n; ++i) {
        dp[i][0] = *max_element(dp[i - 1].begin(), dp[i - 1].end());
        dp[i][1] = dp[i - 1][0] + wine[i];
        dp[i][2] = dp[i - 1][1] + wine[i];
    }

    printf("%d\n", *max_element(dp[n - 1].begin(), dp[n - 1].end()));
}