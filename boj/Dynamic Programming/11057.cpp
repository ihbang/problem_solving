#include <cstdio>
#include <numeric>
#include <vector>

using namespace std;

vector<vector<int> > dp;

int mySum(vector<int> v, int b, int e) {
    int sum = 0;

    for (int i = b; i <= e; ++i) {
        sum += v[i];
        sum %= 10007;
    }
    return sum;
}

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        vector<int> ele(10);
        dp.push_back(ele);
    }
    for (int i = 0; i < 10; ++i) {
        dp[0][i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            dp[i][j] = mySum(dp[i - 1], 0, j);
        }
    }
    printf("%d\n", mySum(dp[n - 1], 0, 9));
}