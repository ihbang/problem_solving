#include <algorithm>
#include <cstdio>
#include <functional>
#include <vector>

using namespace std;

vector<int> seq;
vector<int> inc;
vector<int> dec;

int main() {
    int n, result;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        seq.push_back(a);
        inc.push_back(1);
        dec.push_back(1);

        for (int j = 0; j < i; ++j) {
            if (seq[j] < seq[i])
                inc[i] = max(inc[i], inc[j] + 1);
        }
    }
    result = inc[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (seq[j] < seq[i])
                dec[i] = max(dec[i], dec[j] + 1);
        }
        if (result < inc[i] + dec[i] - 1)
            result = inc[i] + dec[i] - 1;
    }
    printf("%d\n", result);
}