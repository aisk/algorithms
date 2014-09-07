#include <cstdio>

void hanoi(int n, char x, char y, char z) {
    if (n == 1) {
        printf("%d from %c to %c\n", n, x, z);
        return;
    } else {
        hanoi(n - 1, x, z, y);
        printf("%d from %c to %c\n", n, x, z);
        hanoi(n - 1, y, x, z);
    }
}

int main() {
    int n;
    n = 3;
    hanoi(n, 'A', 'B', 'C');

    return 0;
}
