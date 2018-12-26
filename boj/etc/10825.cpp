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
    vector<tuple<string, int, int, int> > v;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        string name;
        int kor, eng, math;
        tuple<string, int, int, int> t;

        cin >> name >> kor >> eng >> math;
        t = make_tuple(name, kor, eng, math);
        v.push_back(t);
    }

    sort(v.begin(), v.end());
    stable_sort(v.begin(), v.end(),
                [](tuple<string, int, int, int> t1, tuple<string, int, int, int> t2) -> bool { return get<3>(t1) > get<3>(t2); });
    stable_sort(v.begin(), v.end(),
                [](tuple<string, int, int, int> t1, tuple<string, int, int, int> t2) -> bool { return get<2>(t1) < get<2>(t2); });
    stable_sort(v.begin(), v.end(),
                [](tuple<string, int, int, int> t1, tuple<string, int, int, int> t2) -> bool { return get<1>(t1) > get<1>(t2); });

    for (auto k : v) {
        cout << get<0>(k) << '\n';
    }
}