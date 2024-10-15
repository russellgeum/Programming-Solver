#include "header.h"

// 인터페이스를 클라이언트가 기대하는 인터페이스로 변환

class Korean220V {
    private:
    public:
        virtual ~Korean220V();
        virtual void connect220V() = 0;
};

class American110V {
    private:
    public: 
        void connect110V() {
            std::cout << "110 볼트 연결" << std::endl;
        }
};

class PowerAdapter : public Korean220V {
    private:
    American110V* americanDevice;
    
    public:
        PowerAdapter(American110V* device) : americanDevice(device) {}

        // 220 볼트 요구에 맞추어, 110 볼트 전력을 변환
        void connect220V() override {
            std::cout << "110 볼트를 220 볼트로 변환" << std::endl;
            americanDevice->connect110V();
        }
};

int main() {
    // 110볼트 전력 공급 장치
    American110V* americanDevice = new American110V();

    // 어댑터를 통해 110볼트 전력을 220볼트로 변환하여 사용
    Korean220V* koreanDevice = new PowerAdapter(americanDevice);

    // 한국 전자제품 연결
    koreanDevice->connect220V();

    delete americanDevice;
    delete koreanDevice;

    return 0;
}

