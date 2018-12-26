#include <cstdio>
#include <vector>
using namespace std;

vector<int> dp;

int tiling(int k) {
    if (dp[k] != -1)
        return dp[k];
    else {
        dp[k] = (tiling(k - 1) + tiling(k - 2) + tiling(k - 3)) % 10007;
        return dp[k];
    }
}

int main() {
    int t;

    scanf("%d", &t);
    dp.push_back(1);
    dp.push_back(2);
    dp.push_back(4);
    for (int i = 2; i < 11; ++i) {
        dp.push_back(-1);
    }
    for (int i = 0; i < t; ++i) {
        int n;
        scanf("%d", &n);
        printf("%d\n", tiling(n - 1));
    }
}