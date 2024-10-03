#include <iostream>
#include <vector>
#include <thread>
#include <cstdio>

void worker(std::vector<int>::iterator start, std::vector<int>::iterator end, int* result) {

    int sum = 0;
    for (auto itr = start; itr < end; itr++) {
        sum += *itr;
    }
    *result = sum;

    // 스레드의 ID를 구한다.
    std::thread::id this_id = std::this_thread::get_id();
    std::cout << "Thread " << this_id << " is running" << std::endl;
}

int main() {
    std::vector<int> data(10000);
    for (int i = 0; i < 10000; i++) {
        data[i] = i;
    }

    // 각 스레드에서 계산된 부분 합들을 저장하는 벡터
    std::vector<int> partial_sums(4);
    for (int i = 0; i < 4; i++) {
        // 벡터 출력
        std::cout << "partial_sums[" << i << "] = " << partial_sums[i] << std::endl;
    }

    // 각 스레드를 생성하고 실행
    std::thread t1(worker, data.begin(), data.begin() + 2500, &partial_sums[0]);
    std::thread t2(worker, data.begin() + 2500, data.begin() + 5000, &partial_sums[1]);
    std::thread t3(worker, data.begin() + 5000, data.begin() + 7500, &partial_sums[2]);
    std::thread t4(worker, data.begin() + 7500, data.end(), &partial_sums[3]);

    // 각 스레드가 종료될 때까지 대기
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}