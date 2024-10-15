#include "header.h"

template<typename T, typename C>
class stack {
    private:
        // 포함이 제일 깔끔한 구현
        C c;

        // private 상속 vs 포함
        // private 상속은 가상함수 오버라이드 가능
        // 가상함수 오버라이드 불가능

    public:
        void push(const T& a) {
            c.push_back(a);
        }
        
        void pop() {
            c.pop_back();
        }

        T& top() {
            return c.back();
        }
};

int main() {
    stack<int, std::vector<int>> s1;
    stack<int, std::list<int>> s2;

    s1.push(10);
    s2.push(20);
    return 0;
}