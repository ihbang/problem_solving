#include <cstdio>
#include <vector>

using namespace std;

vector<int> dp;

int main() {
    int n;

    scanf("%d", &n);

    if (n % 2 == 1)
        printf("0\n");
    else {
        dp.push_back(1);
        dp.push_back(3);
        for (int i = 2; i <= n / 2; ++i) {
            int k = 0;
            k += 3 * dp[i - 1];
            for (int j = 2; j <= i; ++j) {
                k += 2 * dp[i - j];
            }
            dp.push_back(k);
        }
        printf("%d\n", dp[n / 2]);
    }
}