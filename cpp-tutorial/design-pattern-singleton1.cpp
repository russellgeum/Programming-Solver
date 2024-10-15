#include "header.h"

// Singleton 패턴
// 장점
// 객체를 오직 하나임을 보장하며, 어디에서든 동일한 방법으로 접근
// 규칙 1: 외부에서는 객체를 생성할 수 없어야 한다.
// 규칙 2: 1개의 객체를 만들어서 반환하는 static 멤버함수
// 규칙 3: 복사 생성자, 대입 생성자를 사용할 수 없어야 한다.
// 단점
// 전역변수와 유사하고, 멀티 스레드간의 접근 문제, 재사용성 감소
// Meyer의 싱글톤: 처음 객체를 호출할 때 초기화 -> 사용하지 않으면 생성자 호출 안함
// 멀티 스레드 환경에서 Cursor는 오직 1개를 보장

class Cursor {
    private:
        Cursor() {
            std::cout << "Start  Cursor()" << std::endl;
            // std::this_thread::sleep_for(std::literals::3s);
            std::cout << "Finish Cursor()" << std::endl;
        }
        Cursor(const Cursor&) = delete;
        Cursor& operator=(const Cursor&) = delete;

    public:
        static Cursor& getInstance() {
            std::cout << "Start  getInstance" << std::endl;
            static Cursor instance;
            std::cout << "Finish getInstance" << std::endl;
            return instance;
        }
};

int main() {
    std::cout << "main" << std::endl;

    // // 지연된 초기화
    // Cursor& c1 = Cursor::getInstance();
    std::thread t1(&Cursor::getInstance);
    std::thread t2(&Cursor::getInstance);
    t1.join();
    t2.join();
    return 0;
}