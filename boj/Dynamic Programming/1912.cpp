#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> dp;

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        dp.push_back(a);

        if (i == 0)
            continue;
        else if (dp[i - 1] > 0)
            dp[i] = dp[i - 1] + dp[i];
    }

    printf("%d\n", *max_element(dp.begin(), dp.end()));
}