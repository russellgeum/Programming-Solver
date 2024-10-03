#include <iostream>
#include <vector>

// 백준 1292번
// 문제 링크: https://www.acmicpc.net/problem/1094


int main() {
    int X;
    std::cin >> X;

    int stick = 64;
    int count = 0;

    while (X>0) {
        // 현재 막대가 X보다 크면, 절반으로 자름
        if (stick > X) {
            stick /= 2;
        }
        // 현재 막대가 X보다 작으면, 막대를 합쳐서 목표 길이로 만듬
        // 목표 길이 X에서 잘개 쪼갠 stick을 빼가며 count ++
        // X가 0보다 작아지면 while문 빠져나오기
        else {
            X -= stick;
            count++;
        }
    }

    std::cout << count << std::endl;
    return 0;
}