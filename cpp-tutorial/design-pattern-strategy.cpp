// 변하는 것을 가상함수로 분리
// 변하지 않는 내부에 변하는 것을 가상함수로 분리한다.
// 인터페이스를 먼저 만들고, 구현 클래스에서 약한 결합으로 다양한 구현 사용
#include "header.h"

// 결제 전략 인터페이스 (Strategy Interface)
class PaymentStrategy {
public:
    virtual ~PaymentStrategy() = default;
    virtual void pay(int amount) const = 0; // 순수 가상 함수
};

// 신용 카드 결제 (Concrete Strategy 1)
class CreditCardPayment : public PaymentStrategy {
private:
    std::string cardNumber;
public:
    CreditCardPayment(const std::string& number) : cardNumber(number) {}

    void pay(int amount) const override {
        std::cout << "신용 카드로 " << amount << "원을 결제합니다. 카드 번호: " << cardNumber << std::endl;
    }
};

// PayPal 결제 (Concrete Strategy 2)
class PayPalPayment : public PaymentStrategy {
private:
    std::string email;
public:
    PayPalPayment(const std::string& emailAddress) : email(emailAddress) {}

    void pay(int amount) const override {
        std::cout << "PayPal 계정 " << email << "을(를) 사용하여 " << amount << "원을 결제합니다." << std::endl;
    }
};

// 현금 결제 (Concrete Strategy 3)
class CashPayment : public PaymentStrategy {
public:
    void pay(int amount) const override {
        std::cout << "현금으로 " << amount << "원을 결제합니다." << std::endl;
    }
};

// 결제 처리 클래스 (Context)
class ShoppingCart {
private:
    std::unique_ptr<PaymentStrategy> paymentStrategy; // 현재 사용 중인 결제 전략

public:
    // 결제 전략 설정
    void setPaymentStrategy(std::unique_ptr<PaymentStrategy> strategy) {
        paymentStrategy = std::move(strategy);
    }

    // 결제 실행 메서드
    void checkout(int amount) const {
        if (paymentStrategy) { // 결제 전략이 설정되어 있는지 확인
            paymentStrategy->pay(amount);
        } else {
            std::cout << "결제 전략이 설정되지 않았습니다." << std::endl;
        }
    }
};

int main() {
    ShoppingCart cart;

    int amount = 50000; // 결제할 금액

    // 신용 카드 결제 사용
    cart.setPaymentStrategy(std::make_unique<CreditCardPayment>("1234-5678-9012-3456"));
    cart.checkout(amount);

    // PayPal 결제 사용
    cart.setPaymentStrategy(std::make_unique<PayPalPayment>("user@example.com"));
    cart.checkout(amount);

    // 현금 결제 사용
    cart.setPaymentStrategy(std::make_unique<CashPayment>());
    cart.checkout(amount);

    return 0;
}
