#include <cstdio>
#include <numeric>
#include <vector>

using namespace std;

vector<vector<int> > dp;

int main() {
    int n;
    int sum = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        vector<int> ele(10);
        dp.push_back(ele);
    }
    dp[0][0] = 0;
    for (int i = 1; i < 10; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (j == 0)
                dp[i][j] = dp[i - 1][1];
            else if (j == 9)
                dp[i][j] = dp[i - 1][8];
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
    }
    for (int i = 0; i < 10; ++i) {
        sum += dp[n - 1][i];
        sum %= 1000000000;
    }
    printf("%d\n", sum);
}