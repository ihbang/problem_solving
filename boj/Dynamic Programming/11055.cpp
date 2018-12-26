#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> seq;
vector<int> dp;

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        seq.push_back(a);
        dp.push_back(a);
    }
    dp[0] = seq[0];

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (seq[i] > seq[j])
                dp[i] = max(dp[i], dp[j] + seq[i]);
        }
    }

    printf("%d\n", *max_element(dp.begin(), dp.end()));
}