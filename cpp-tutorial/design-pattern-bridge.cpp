#include <header.h>

// Bridge
// 구현이 업데이트되면 사용자 코드도 모두 변경
// 사용자와 상관없이 구현만 독립적으로 구현 가능?


// Implementor 인터페이스 (구현부)
class DrawingAPI {
public:
    virtual void DrawCircle(double x, double y, double radius) const = 0;
    virtual ~DrawingAPI() = default;
};

// ConcreteImplementorA (구체적 구현 1)
class DrawingAPI1 : public DrawingAPI {
public:
    void DrawCircle(double x, double y, double radius) const override {
        std::cout << "API1: (" << x << ", " << y << "), 반지름: " << radius << std::endl;
    }
};

// ConcreteImplementorB (구체적 구현 2)
class DrawingAPI2 : public DrawingAPI {
public:
    void DrawCircle(double x, double y, double radius) const override {
        std::cout << "API2: (" << x << ", " << y << "), 반지름: " << radius << std::endl;
    }
};

// Abstraction (추상부)
class Shape {
protected:
    const DrawingAPI& drawingAPI;  // Implementor와 연결
    Shape(const DrawingAPI& drawingAPI) : drawingAPI(drawingAPI) {}
public:
    virtual void Draw() const = 0;        // 추상화된 메서드
    virtual void ResizeByPercentage(double pct) = 0;
    virtual ~Shape() = default;
};

// RefinedAbstraction (구체적 추상 클래스 - 원을 그리기 위한 구현)
class CircleShape : public Shape {
private:
    double x, y, radius;
public:
    CircleShape(double x, double y, double radius, const DrawingAPI& drawingAPI)
        : Shape(drawingAPI), x(x), y(y), radius(radius) {}

    // Shape의 구체적인 구현
    void Draw() const override {
        drawingAPI.DrawCircle(x, y, radius);  // Implementor 객체 사용
    }

    void ResizeByPercentage(double pct) override {
        radius *= (1.0 + pct / 100.0);
    }
};

// 클라이언트 코드
int main() {
    CircleShape circle1(1, 2, 3, DrawingAPI1());  // API1을 사용하는 원
    CircleShape circle2(5, 7, 11, DrawingAPI2()); // API2를 사용하는 원

    circle1.Draw();
    circle2.Draw();

    circle1.ResizeByPercentage(10);  // 반지름 10% 증가
    circle1.Draw();

    return 0;
}
