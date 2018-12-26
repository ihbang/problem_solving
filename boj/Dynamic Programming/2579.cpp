#include <cstdio>
#include <vector>

using namespace std;

vector<int> stair;
vector<vector<int> > dp;

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        stair.push_back(a);
        vector<int> v(3);
        dp.push_back(v);
    }
    dp[0][0] = dp[0][2] = 0;
    dp[0][1] = stair[0];

    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = dp[i - 1][0] + stair[i];
        dp[i][2] = dp[i - 1][1] + stair[i];
    }

    printf("%d\n", max(dp[n - 1][1], dp[n - 1][2]));
}