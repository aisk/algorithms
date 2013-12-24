package main

import "fmt"

func hanoi(n int, x string, y string, z string) {
    if n == 1 {
        fmt.Printf("%d from %s to %s\n", n, x, z)
        return
    } else {
        hanoi(n - 1, x, z, y);
        fmt.Printf("%d from %s to %s\n", n, x, z)
        hanoi(n - 1, y, x, z);
    }
}

func main() {
    n := 3
    hanoi(n, "A", "B", "C")
}
