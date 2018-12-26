#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<tuple<int, string> > v;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a;
        string b;
        tuple<int, string> t;

        cin >> a >> b;
        t = make_tuple(a, b);
        v.push_back(t);
    }

    stable_sort(v.begin(), v.end(),
                [](tuple<int, string> t1, tuple<int, string> t2) -> bool { return get<0>(t1) < get<0>(t2); });

    for (auto k : v) {
        cout << get<0>(k) << " " << get<1>(k) << '\n';
    }
}