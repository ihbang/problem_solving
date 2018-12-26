#include <cstdio>
using namespace std;

int main() {
    int n, k;
    int min, max;
    min = 1000001;
    max = -1000001;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        if (k < min) min = k;
        if (k > max) max = k;
    }
    printf("%d %d\n", min, max);
}