#include <cstdio>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j < n - i)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }
}