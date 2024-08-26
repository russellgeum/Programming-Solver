// 복사생성자 이야기
#include <iostream>
#include <string.h>
using namespace std;

class String {
    private:
        char* strData;
        int len;

    public:
        String() {
            strData = NULL;
            len = 0;
        }

        // 문자열을 인자로 받는 생성자
        String(const char* str) {
            len = strlen(str);
            strData = new char[len+1];
            strcpy(strData, str);
        }

        // 복사 생성자
        // rhs 주소값을 받아서
        String(const String& rhs) {
            len = rhs.len;
            strData = new char[len+1];
            strcpy(strData, rhs.strData);
        }

        ~String() {
            if (strData) {
                delete[] strData;
            }
        }

        const char* GetStrData() const {
            if (strData) {
                return strData;
            }
            return "";
        }

        int Getlen() const {
            return len;
        }
};

int main() {
    String s1("Hello");
    String s2 = s1; // String s2(s1)과 같은 말

    cout << s1.GetStrData() << endl;
    cout << s2.GetStrData() << endl;
}