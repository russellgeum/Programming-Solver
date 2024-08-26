#include <iostream>
#include <string>
using namespace std;

class Item {
    private:
        int num;
        string name;
    public:
        // 생성자의 다양한 스타일
        Item() { }
        // 인자를 받아서 생성하는 다양한 스타일
        Item(int num) : num(num) { }
        Item(string name) : name(name) { }
        Item(int num, string name) : num(num), name(name) { }

        operator int() const {
            cout << "Item::operator int()" << endl;
            return num;
        }
        operator string() const {
            cout << "Item::operator string()" << endl;
            return name;
        }
};

int main() {
    Item i1(1, "Stone");
    int inum = i1;      // int inum = (int)i1;
    string iname = i1;  // string iname = (string)i1;

    cout << inum << endl;
    cout << iname << endl;
}