// C++ 11 이상에서 가능한 멀티스레딩 예제

#include <iostream>
#include <thread>

void func1() {
    for (int i = 0; i < 10; i++) {
        std::cout << "Thread 1 is running" << std::endl;
    }
}

void func2() {
    for (int i = 0; i < 10; i++) {
        std::cout << "Thread 2 is running" << std::endl;
    }
}

void func3() {
    for (int i = 0; i < 10; i++) {
        std::cout << "Thread 3 is running" << std::endl;
    }
}

int main() {
    std::thread t1(func1);
    std::thread t2(func2);
    std::thread t3(func3);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}