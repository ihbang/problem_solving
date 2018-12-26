#include <cstdio>
#include <numeric>
#include <vector>

using namespace std;

vector<vector<int> > dp(1);

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n + 1; ++i) {
        dp[0].push_back(1);
    }

    for (int i = 1; i < k; ++i) {
        vector<int> v(n + 1);
        v[0] = 1;
        for (int j = 1; j < n + 1; ++j) {
            v[j] = (v[j - 1] + dp[i - 1][j]) % 1000000000;
        }
        dp.push_back(v);
    }
    printf("%d\n", dp[k - 1][n] % 1000000000);
}