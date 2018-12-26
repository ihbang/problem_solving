#include <cstdio>
using namespace std;

int main() {
    int N, a;
    int sum = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%1d", &a);
        sum += a;
    }
    printf("%d\n", sum);
}