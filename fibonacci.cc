#include <iostream>
#include <vector>

int recurFib(int n) {
    if (n < 2) {
        return n;
    } else {
        return recurFib(n - 1) + recurFib(n - 2);
    }
}

int dynFib(int n) {
    auto val = std::vector<int>(n);
    for (int i = 0; i <= n; ++i) {
        val.push_back(i);
    }
    if (n == 1 || n == 2) {
        return 1;
    } else {
        val[1] = 1;
        val[2] = 2;
        for (int i = 3; i <= n; ++i) {
            val[i] = val[i-1] + val[i-2];
        }
        return val[n-1];
    }
}

int main() {
    std::cout << recurFib(20) << std::endl;
    std::cout << dynFib(20) << std::endl;
    return 0;
}
