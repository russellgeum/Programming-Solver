#include "header.h"

// 싱글톤 객체를 생성하는 기반 클래스
// CRTP 원리

template<typename T>
class Singleton {
    private:
        Singleton(const Singleton&) = delete;
        Singleton& opreator=(const Singleton&) = delete;
        static std::mutex m;
        static T* instance;
    protected:
        Singleton() {}
    public:
        static T& getInstance() {
            std::lock_guard<std::mutex> g(m);
            if (instance == nullptr) {
                instance = new T;
            }
            return *instance
        }
};

template<typename T> T* Singleton<T>::instance = nullptr;
template<typename T> std::mutex Singleton<T>::m;

// 파생 클래스에서 템플릿 인자로 객체 이름을 명시
class Mouse : public Singleton<Mouse> {

};

int main() {
    Mouse& c1 = Mouse::getInstance();
    return 0;
}