package main

func binary_search_recusive(array []int, begin int, end int, number int) int {
    if begin > end {
        return -1
    }
    middle := (begin + end) / 2
    if array[middle] == number {
        return middle
    } else if array[middle] > number {
        return binary_search_recusive(array, begin, middle, number)
    } else {
        return binary_search_recusive(array, middle, end, number)
    }
}

func binary_search_branch(array []int, number int) int {
    begin, end := 0, len(array)
    for {
        if begin > end {
            return -1
        }
        middle := (begin + end) / 2
        if array[middle] == number {
            return middle
        } else if array[middle] > number {
            end = middle
        } else {
            begin = middle
        }
    }
}

func main() {
    array := []int{0, 1, 2, 3, 4, 5}
    println(binary_search_recusive(array, 0, len(array), 3))
    println(binary_search_branch(array, 3))
}
