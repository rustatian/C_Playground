//
// Created by valery on 11/18/19.
//
#include <list>
#include <mutex>
#include <algorithm>
#include <fstream>

std::list<int> some_list;
std::mutex some_mutex;

void add_to_list(int new_value) {
    std::scoped_lock<std::mutex> guard(some_mutex);
    some_list.push_back(new_value);
    // ~guard destructor here
}

bool list_contains(int value_to_find) {
    std::scoped_lock<std::mutex> guard(some_mutex);
    return std::find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
}

#include <stdio.h>

void update(int *a,int *b) {
    int tempA = (*a);
    int tempB = (*b);

    (*a) = tempA + tempB;
    (*b) = tempA - tempB;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
