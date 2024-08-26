// 호출 가능 객체
#include <iostream>
using namespace std;

class Equal {
    private:
        int value;
    public: 
        Equal(int value) : value(value) {}
        bool operator()(int x) const {
            return x == value;
        }
};

int main() {
    Equal eq(10);
    cout << eq(12) << endl;
    cout << eq(10) << endl;
    return 0;
}