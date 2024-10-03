#include <iostream>
#include <string>

class Display {
    private:
        int name;

    public:
        // public에서 클래스 이름과 동일한 함수는 생성자
        Display(int name) {
            // 왜 this->name = name; 이렇게 써야하는지 이해가 안됨
            // 클래스 내부에서 클래스 변수를 가리키기 위해서는 this->name 이렇게 써야함
            this->name = name;
        }

        void display() {
            std::cout << "Name: " << name << std::endl;
        }
};

int main() {
    Display display(10);
    display.display();

    Display* displayPtr = new Display(20);
    displayPtr->display();
    delete displayPtr;
    return 0;
}

