#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> v;

    scanf("%d", &n);
    v.resize(n);

    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);

    sort(v.begin(), v.end());

    for (auto k : v) {
        printf("%d\n", k);
    }
}