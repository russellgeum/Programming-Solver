#include <iostream>

struct Time {
    int h;
    int m;
    int s;
};

int totalSec1(Time t) {
    return 60 * 60 * t.h + 60 * t.m + 60 * t.s;
}

int totalSec2(Time *t) {
    return 60 * 60 * t->h + 60 * t->m + 60 * t->s;
}

int main() {
    Time t = {1, 22, 48};
    Time *a = &t;
    std::cout << totalSec1(t) << std::endl; // 변수를 넣어서 직접 연산
    std::cout << totalSec2(&t) << std::endl; // 포인터 변수 = 변수의 주소는 "->"
    std::cout << totalSec1(*a) << std::endl; // 포인터 변수를 넣어서 포인터가 주소의 값을 연산
}