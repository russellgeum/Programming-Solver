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
        // rhs 주소값을 받아서 rhs의 len, strData를 새로운 인스턴스에 복사
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

        // 복사 대입 연산자
        // 기본적인 과정은 위와 같되, 새로운 생성자가 &rhs와 다르면 값 대입
        // 같다면 *this를 리턴
        String& operator=(const String& rhs) {
            if (this != &rhs) {
                len = rhs.len;
                delete[] strData;
                strData = new char[len+1];
                strcpy(strData, rhs.strData);
            }
            return *this;
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
    String s2("World");
    s2 = s1; // 치환시키는 것
    cout << s1.GetStrData() << endl;
    cout << s2.GetStrData() << endl;
}