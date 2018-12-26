#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> v(10000, 0);

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int k;

        scanf("%d", &k);
        v[k - 1]++;
    }

    for (int i = 0; i < 10000; ++i)
        for (int j = 0; j < v[i]; ++j)
            printf("%d\n", i + 1);
}