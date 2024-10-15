#include "header.h"

// 객체에 동적으로 서비스를 추가
// 원래 클래스와 기능 추가 클래스의 공통의 인터페이스를 정의
// 기본 커피 인터페이스
class Coffee {
public:
    virtual ~Coffee() = default;
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
};

// 기본 커피 구현
class SimpleCoffee : public Coffee {
public:
    std::string getDescription() const override {
        return "Simple Coffee";
    }

    double cost() const override {
        return 2.0;
    }
};

// 데코레이터 기본 클래스
class CoffeeDecorator : public Coffee {
protected:
    std::shared_ptr<Coffee> coffee; // 기본 커피 객체를 포함

public:
    CoffeeDecorator(std::shared_ptr<Coffee> coffee) : coffee(coffee) {}
    
    std::string getDescription() const override {
        return coffee->getDescription();
    }

    double cost() const override {
        return coffee->cost();
    }
};

// 우유를 추가하는 데코레이터
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(coffee) {}

    std::string getDescription() const override {
        return coffee->getDescription() + ", Milk";
    }

    double cost() const override {
        return coffee->cost() + 0.5;
    }
};

// 설탕을 추가하는 데코레이터
class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(std::shared_ptr<Coffee> coffee) : CoffeeDecorator(coffee) {}

    std::string getDescription() const override {
        return coffee->getDescription() + ", Sugar";
    }

    double cost() const override {
        return coffee->cost() + 0.2;
    }
};

int main() {
    // 기본 커피 객체 생성
    std::shared_ptr<Coffee> myCoffee = std::make_shared<SimpleCoffee>();
    std::cout << myCoffee->getDescription() << " $" << myCoffee->cost() << std::endl;

    // 우유 추가
    myCoffee = std::make_shared<MilkDecorator>(myCoffee);
    std::cout << myCoffee->getDescription() << " $" << myCoffee->cost() << std::endl;

    // 설탕 추가
    myCoffee = std::make_shared<SugarDecorator>(myCoffee);
    std::cout << myCoffee->getDescription() << " $" << myCoffee->cost() << std::endl;

    return 0;
}