#include "header.h"

// Singleton 패턴
// new를 활용하여 heap에 할당하는 구현
// 멀티스레드에 안전하지 않아서, mutex같은 동기화 필요

class Cursor {
    private:
        Cursor() {}
        Cursor(const Cursor&) = delete;
        Cursor& operator=(const Cursor&) = delete;

        static std::mutex m;
        static Cursor* instance;

    public:
        static Cursor& getInstance() {
            std::lock_guard<std::mutex> g(m); // g의 생성자에서 Lock()
            if (instance == nullptr) {
                instance = new Cursor;
            }
            return *instance;
        }
};

Cursor* Cursor::instance = nullptr;
std::mutex Cursor::m;

int main() {
    Cursor& c1 = Cursor::getInstance();
    Cursor& c2 = Cursor::getInstance();
    return 0;
}