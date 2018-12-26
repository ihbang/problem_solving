#include <cstdio>
#include <vector>

using namespace std;

vector<long long> dp(5);

int main() {
    int t, n;

    scanf("%d", &t);

    for (int i = 0; i < t; ++i) {
        dp[0] = dp[1] = dp[2] = 1;
        dp[3] = dp[4] = 2;
        scanf("%d", &n);

        if (n <= dp.size())
            printf("%lld\n", dp[n - 1]);
        else {
            for (int j = dp.size(); j < n; ++j) {
                dp.push_back(dp[j - 1] + dp[j - 5]);
            }
            printf("%lld\n", dp[n - 1]);
        }
    }
}