#include <cstdio>
#include <unordered_map>

using namespace std;

int main() {
    int n, m = 0;
    long long answer = INT64_MAX;
    unordered_map<long long, int> cnt;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        long long k;
        scanf("%lld", &k);
        cnt[k]++;
    }
    for (auto it = cnt.begin(); it != cnt.end(); ++it) {
        if (m < it->second) {
            m = it->second;
            answer = it->first;
        } else if (m == it->second && answer > it->first)
            answer = it->first;
    }
    printf("%lld\n", answer);
}