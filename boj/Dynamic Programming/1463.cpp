#include <cstdio>
#include <vector>
using namespace std;

vector<int> dp;

int makeOne(int k) {
    if (dp[k] != -1)
        return dp[k];
    else {
        int d1 = makeOne(k / 3) + (k % 3) + 1;
        int d2 = makeOne(k / 2) + (k % 2) + 1;
        return d1 < d2 ? d1 : d2;
    }
}

int main() {
    int n;

    scanf("%d", &n);
    dp.push_back(0);
    dp.push_back(0);
    for (int i = 2; i < n + 1; ++i) {
        dp.push_back(-1);
    }
    printf("%d\n", makeOne(n));
}