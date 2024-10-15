#include <header.h>

// Subject 인터페이스 (공통 인터페이스)
class Subject {
    public:
        virtual void Request() = 0;  // const 제거
        virtual ~Subject() = default;
};

// RealSubject (실제 객체)
class RealSubject : public Subject {
    public:
        RealSubject() {
            // 무거운 초기화 작업을 가정
            std::cout << "RealSubject: 객체가 생성되었습니다.\n";
        }

        void Request() override {
            std::cout << "RealSubject: 요청 처리 중...\n";
        }
};

// Proxy (대리 객체)
class Proxy : public Subject {
    private:
        RealSubject* real_subject_;  // 실제 객체를 포인터로 저장

    public:
        Proxy() : real_subject_(nullptr) {}

        ~Proxy() {
            delete real_subject_;
        }

        void Request() override {  // const 제거
            if (real_subject_ == nullptr) {
                real_subject_ = new RealSubject();  // 실제 객체를 처음 요청할 때 생성
            }
            std::cout << "Proxy: 요청을 실제 객체로 전달합니다.\n";
            real_subject_->Request();  // 실제 객체에 요청 전달
        }
};

// 클라이언트 코드
void ClientCode(Subject& subject) {  // const 제거
    subject.Request();
}

int main() {
    std::cout << "클라이언트: 프록시 객체로 작업을 처리합니다.\n";
    Proxy proxy;
    ClientCode(proxy);

    return 0;
}
