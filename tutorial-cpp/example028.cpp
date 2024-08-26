#include <iostream>
using namespace std;

class Ice {
    public:
        Ice() { cout << "Ice()" << endl; }
        ~Ice() { cout << "~Ice()" << endl; }
};

class Pat {
    public:
        Pat() { cout << "Pat()" << endl; }
        ~Pat() { cout << "~Pat()" << endl; }
};

class Bingsoo {
    public:
        Bingsoo() { cout << "Bingsoo()" << endl; }
        ~Bingsoo() { cout << "~Bingsoo()" << endl; }

    private:
        Ice ice;
};

class PatBingsoo : public Bingsoo {
    public:
        PatBingsoo() { cout << "PatBingsoo()" << endl; }
        ~PatBingsoo() { cout << "~PatBingsoo()" << endl; }

    private:
        Pat pat;
};

int main() {
    cout << "===== 1 =====" << endl;
    // 1. Binsoo - Ice가 먼저 실행
    // 2. Ice에서 Bingsoo가 그 다음 실행
    // 3. private: Pat pat;의 class Pat이 그 다음 실행
    // 4. PatBingsoo가 실행
    PatBingsoo* p = new PatBingsoo;
    cout << "===== 2 =====" << endl;
    delete p;
    cout << "===== 3 =====" << endl;
}