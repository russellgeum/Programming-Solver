#include <header.h>

// Facade
// 서브 시스템을 사용하기 쉽게 하는 포괄적 개념의 인터페이스


class TCPServer {
    private:
        // 네트워크 객체
        // 소켓 객체
    public:
        void start(const char* ip, short port) {
            // IP 주소 객체
            // 바인드
            // 듣기
            // 수용
        }
};


int main() {
    TCPServer server;

    return 0;
}