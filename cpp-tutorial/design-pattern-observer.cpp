#include "header.h"

// Observer 패턴
// 객체 사이의 1:N 종속성을 정의
// 한 객체 상태가 변하면, 종속된 다른 객체들에 통보가 가고 자동으로 수정이 발생


// Observer 인터페이스
class Observer {
    public:
        virtual void update(const std::string& message) = 0; // 메시지를 받을 메서드
};

// 구체적인 Observer 클래스 구현
class ConcreteObserver : public Observer {
    private:
        std::string name;

    public:
        // 생성자
        ConcreteObserver(const std::string& name) : name(name) {}

        // 알림을 받을 때 호출되는 메서드
        void update(const std::string& message) override {
            std::cout << "Observer " << name << " received message: " << message << std::endl;
        }
};

// Subject (관찰 대상)
class Subject {
    private:
        std::vector<Observer*> observers; // 관찰자 목록
        std::string message;

    public:
        // 관찰자 추가
        void addObserver(Observer* observer) {
            observers.push_back(observer);
        }

        // 관찰자 제거
        void removeObserver(Observer* observer) {
            observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
        }

        // 모든 관찰자에게 알림
        void notifyObservers() {
            for (Observer* observer : observers) {
                observer->update(message);
            }
        }

        // 상태 변경 시 메시지 설정 및 알림 전송
        void setMessage(const std::string& newMessage) {
            message = newMessage;
            notifyObservers(); // 상태가 변했을 때 관찰자들에게 알림
        }
};

int main() {
    Subject subject;

    // 구체적인 관찰자 생성
    ConcreteObserver observer1("Observer1");
    ConcreteObserver observer2("Observer2");

    // 관찰자를 Subject에 등록
    subject.addObserver(&observer1);
    subject.addObserver(&observer2);

    // 메시지 설정 -> 관찰자에게 알림 전송
    subject.setMessage("First Message");

    // Observer1 제거
    subject.removeObserver(&observer1);

    // 두 번째 메시지 설정 -> 남은 관찰자에게만 알림 전송
    subject.setMessage("Second Message");
    return 0;
}
