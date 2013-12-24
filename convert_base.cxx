#include <stack>
#include <cstdio>

void convert_base(int n, const int d) {
    std::stack<int> s;
    int e;

    while (n != 0) {
        e = n % d;
        s.push(e);
        n /= d;
    }

    while (!s.empty()) {
        e = s.top();
        s.pop();
        printf("%X", e);
    }
    puts("");
}

int main() {
    convert_base(4, 2);
}
