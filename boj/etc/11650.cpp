#include <algorithm>
#include <cstdio>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<tuple<int, int> > v;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int a, b;
        tuple<int, int> t;

        scanf("%d %d", &a, &b);
        t = make_tuple(a, b);
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    for (auto k : v) {
        printf("%d %d\n", get<0>(k), get<1>(k));
    }
}