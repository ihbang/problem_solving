#include <cstdio>
#include <vector>
using namespace std;

vector<int> dp;

int tiling(int k) {
    if (dp[k] != -1)
        return dp[k];
    else {
        dp[k] = (tiling(k - 1) + 2 * tiling(k - 2)) % 10007;
        return dp[k];
    }
}

int main() {
    int n;

    scanf("%d", &n);
    dp.push_back(1);
    dp.push_back(3);
    for (int i = 2; i < n + 1; ++i) {
        dp.push_back(-1);
    }
    printf("%d\n", tiling(n - 1));
}