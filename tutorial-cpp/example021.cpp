#include <iostream>
#include <string.h>
using namespace std;

class String {
    private:
        char* strData; // 문자열 포인터 변수
        int len; // 문자열 길이

    public:
        // 생성자 1
        String() {
            strData = NULL;
            len = 0;
        }

        // 생성자 2: 문자열을 입력받아서 len, strData 얻음
        String(const char* str) {
            len = strlen(str);
            strData = new char[len+1];
            strcpy(strData, str);
        }

        // 소멸자
        ~String() {
            if (strData) {
                delete[] strData;
            }
        }

        const char* GetStrData() const {
            if (strData) {
                return strData;
            }

            return " ";
        }

        int GetLen() const {
            return len;
        }
};


int main() {
    String s1;
    String s2("Hello");

    cout << s1.GetLen() << endl;
    cout << s1.GetStrData() << endl;
    cout << s2.GetLen() << endl;
    cout << s2.GetStrData() << endl;
}