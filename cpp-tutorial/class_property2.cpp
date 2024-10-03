// 클래스 상속 응용 예제
#include <iostream>
#include <string>
using namespace std;

class Image {
    public:
        operator string() {
            return "사진";
        }
};

class TextMessage {
    private:
        int sendTime;
        string sendName;
        string text;
    
    public:
        // 생성자
        TextMessage(int sendTime, string sendName, string text) {
            this->sendTime = sendTime;
            this->sendName = sendName;
            this->text = text;
        }

        int GetSendTime() const {
            return sendTime;
        }

        string GetSendName() const {
            return sendName;
        }

        string GetText() const {
            return text;
        }
};

class ImageMessage {
    private:
        int sendTime;
        string sendName;
        Image* image;

    public:
        ImageMessage(int sendTime, string sendName, Image* image) {
            this->sendTime = sendTime;
            this->sendName = sendName;
            this->image = image;
        }

        int GetSendTime() const {
            return sendTime;
        }

        string GetSendName() const {
            return sendName;
        }

        Image* GetImage() const {
            return image;
        }
};

int main() {
    Image* dogImage = new Image; // Image 객체를 미리 만듬
    TextMessage* hello = new TextMessage(10, "두들", "안녕"); // TextMessage 객체를 미리 만듬

    // 만들어둔 객체의 포인터를 생성자의 인수로 삽입
    ImageMessage* dog = new ImageMessage(20, "두들", dogImage);
    
    // 객체의 포인터 요소를 ->으로 접근
    cout << "보낸 시간 : " << hello->GetSendTime() << endl;
    cout << "보낸 사람 : " << hello->GetSendName() << endl;
    cout << "내용 : " << hello->GetText() << endl;
    cout << endl;

    // 객체의 포인터 요소를 -> 으로 접근
    cout << "보낸 시간 : " << dog->GetSendTime() << endl;
    cout << "보낸 사람 : " << dog->GetSendName() << endl;
    // (string)은 강제 형변환?
    cout << "시간 : " << (string)*dog->GetImage() << endl;
}