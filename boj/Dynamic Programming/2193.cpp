#include <cstdio>
#include <vector>

using namespace std;

vector<vector<long long> > dp;

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        vector<long long> ele(2);
        dp.push_back(ele);
    }
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
    printf("%lld\n", dp[n - 1][0] + dp[n - 1][1]);
}