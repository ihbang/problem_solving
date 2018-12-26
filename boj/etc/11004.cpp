#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, k;
    vector<int> v;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        v.push_back(a);
    }
    nth_element(v.begin(), v.begin() + k - 1, v.end());
    printf("%d\n", v[k - 1]);
}