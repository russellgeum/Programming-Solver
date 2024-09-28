#include <cstdio>
#include <thread>
#include <vector>
#include <iostream>

// 스레드에서 실행할 함수
// vector<int>::iterator의 의미
// vector<int> 타입의 데이터를 가리키는 반복자
// 반복자는 벡터의 요소를 가리키는 포인터와 같은 개념
// 따라서 start와 end는 벡터의 시작과 끝을 가리키는 반복자
void worker(std::vector<int>::iterator start, std::vector<int>::iterator end, int* result) {
    int sum = 0;
    // 반복자를 사용하여 벡터의 요소를 모두 더함
    for (auto itr = start; itr < end; itr++) {
        // 왜 반복자는 포인터인가?
        // 포인터는 메모리 주소를 가리키는 변수
        // 반복자는 벡터의 요소를 가리키는 변수
        // 따라서 반복자는 포인터와 같은 개념

        // sum에 저장되는 값은 벡터의 요소를 모두 더한 값
        sum += *itr;
    }
    // 왜 결과값이 포인터인가?
    // 포인터는 메모리 주소를 가리키는 변수
    // 따라서 결과값은 메모리 주소를 가리키는 변수
    *result = sum;

    // 이 줄의 의미
    // 현재 스레드의 ID를 가져오는 함수
    // 스레드의 ID는 스레드를 구분하는 유일한 식별자
    // 이를 통해 스레드의 작업 상태를 확인하거나 스레드를 제어할 수 있음
    std::thread::id thid_id = std::this_thread::get_id();
    
    std::cout << "쓰레드 " << thid_id << "에서 " << *start << "부터 " << *(end-1) << "까지 계산한 결과 : " << sum << std::endl;
}

int main() {
    std::vector<int> data(1000);
    // 벡터의 요소를 0부터 999까지 초기화
    for (int i = 0; i < 1000; i++) {
        data[i] = i;
    }

    // 각 스레드에서 계산된 부분합을 저장하는 벡터
    std::vector<int> partial_sum(4);
    // 스레드를 저장할 벡터
    std::vector<std::thread> workers;

    // 데이터를 4개의 스레드로 나누어 계산
    for (int i = 0; i < 4; i++) {
        workers.push_back(std::thread(worker, data.begin() + i * 250, data.begin() + (i+1) * 250, &partial_sum[i]));
    }

    // 각 스레드의 작업이 끝날 때까지 기다림
    for (int i = 0; i< 4; i++) {
        workers[i].join();
    }

    // 각 스레드의 부분합을 모두 더함
    int total_sum = 0;
    for (int i = 0; i < 4; i++) {
        total_sum += partial_sum[i];
    }

    std::cout << "전체 합 : " << total_sum << std::endl;
    return 0;
}