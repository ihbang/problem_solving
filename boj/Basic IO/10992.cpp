#include <cstdio>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i < n; ++i) {
        int j;
        for (j = 0; j < n - i; ++j)
            printf(" ");
        printf("*");
        for (j = n - i; j < n + i - 3; ++j)
            printf(" ");
        if (i != 1)
            printf("*");
        printf("\n");
    }
    for (int i = 0; i < 2 * n - 1; ++i)
        printf("*");
    printf("\n");
}