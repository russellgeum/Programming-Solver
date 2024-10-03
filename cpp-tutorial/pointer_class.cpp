#include <iostream>
#include <string>
using namespace std;

class Image {
    public:
        operator string() {
            return "사진";
        }
};

class Message {
    private:
        int sendTime;
        string sendName;

    public:
        Message(int sendTime, string sendName) {
            this->sendTime = sendTime;
            this->sendName = sendName;
        }
        virtual ~Message() {}  // 가상 소멸자

        int GetSendTime() const { return sendTime; }
        string GetSendName() const { return sendName; }
        virtual string GetContent() const { return ""; }
};

// 메세지 클래스 상속
class TextMessage : public Message {
    private:
        string text;

    public:
        TextMessage(int sendtime, string sendname, string text) : Message(sendtime, sendname) {
            this->text = text;
        }
        
        // 오버라이딩
        string GetContent() const { return text; } 
};


// 메세지 클래스 상속
class ImageMessage : public Message {
    private:
        Image* image;

    public:
        ImageMessage(int sendtime, string sendname, Image* image) : Message(sendtime, sendname) {
            this->image = image;
        }

        // 오버라이딩
        string GetContent() const {
            return (string)* image;
        }
};


// 포인터 변수의 주소값을 받음
void printMessage1(const Message& m) {
    cout << "보낸 시간 : " << m.GetSendTime() << endl;
    cout << "보낸 사람 : " << m.GetSendName() << endl;
    cout << "내용 : " << m.GetContent() << endl;
    cout << endl;
};


// 포인터 변수를 받음
void printMessage2(const Message* m) {
    cout << "보낸 시간 : " << m->GetSendTime() << endl;
    cout << "보낸 사람 : " << m->GetSendName() << endl;
    cout << "내용 : " << m->GetContent() << endl;
    cout << endl;
};


int main() {
    Image* dogImage = new Image;
    Message* messages[] = {
        new TextMessage(10, "두들", "안녕"),
        new ImageMessage(20, "두들", dogImage),
        new TextMessage(30, "두들", "잘가")};

    // 범위 기반 반복문
    // messages가 포인터 배열이므로 원소 역시 포인터
    for (Message* m : messages) {
        printMessage1(*m);
        printMessage2(m);
    }

    // 배열의 각 칸마다 동적 할당된 객체를 가리키고 있으므로 각각 해제
    for (Message* m : messages) {
        delete m;
    }
}