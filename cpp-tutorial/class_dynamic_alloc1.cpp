#include <iostream>
#include <string>
using namespace std;

// 동적 할당
class Image {
    public:
        // 연산자 
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
        // 포인터 변수
        Image* image;

    public:
        ImageMessage(int sendTime, string sendName, Image* image) {
            this->sendTime = sendTime;
            this->sendName = sendName;
            this->image = image;
        }

        int GetSendTime() const { return sendTime; }
        string GetSendName() const { return sendName; }
        Image* GetImage() const { return image; }
};


int main() {
    Image* dogImage = new Image; // 이미지 객체를 미리 만든다.
    TextMessage* hello = new TextMessage(10, "두들", "안녕");
    // 만들어 둔 객체의 포인터를 생성자의 인수로 집어 넣는다.
    // dogImage는 Image* dogImage = new Image
    ImageMessage* dog = new ImageMessage(20, "두들", dogImage);

    cout << "보낸 시간 : " << hello->GetSendTime() << endl;
    cout << "보낸 사람 : " << hello->GetSendName() << endl;
    cout << "     내용 : " << hello->GetText() << endl;
    cout << endl;

    cout << "보낸 시간 : " << hello->GetSendTime() << endl;
    cout << "보낸 사람 : " << hello->GetSendName() << endl;
    cout << "     내용 : " << (string)* dog->GetImage() << endl;

    delete dogImage;
    delete hello;
    delete dog;
}