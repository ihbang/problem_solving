#include <algorithm>
#include <cstdio>
#include <functional>
#include <vector>

using namespace std;

vector<int> dp(1);

int main() {
    int n;

    scanf("%d", &n);

    dp[0] = 1001;

    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        if (dp.back() > a)
            dp.push_back(a);
        else {
            vector<int>::iterator it = lower_bound(dp.begin(), dp.end(), a, greater<int>());
            *it = a;
        }
    }

    printf("%d\n", dp.size() - 1);
}