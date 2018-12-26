#include <cstdio>
#include <vector>

using namespace std;

vector<int> dp;

int myfunc(int k) {
    if (dp[k] != -1)
        return dp[k];
    else {
        int m = 100001;
        for (int i = 1; i * i <= k; ++i) {
            int tmp = myfunc(k - i * i);
            if (m > tmp + 1)
                m = tmp + 1;
        }
        dp[k] = m;
        return m;
    }
}

int main() {
    int n;

    scanf("%d", &n);

    dp.push_back(0);
    for (int i = 1; i < n + 1; ++i) {
        dp.push_back(-1);
    }

    printf("%d\n", myfunc(n));
}