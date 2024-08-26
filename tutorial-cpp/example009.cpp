#include <iostream>
using namespace std;

struct TV {
    private:
        bool powerOn;
        int channel;
        int volume;

    public:
        void on() {
            powerOn = true;
        }
        void off() {
            powerOn = false;
        }

        void setChannel(int chn) {
            if (chn >= 1 && chn <= 999) {
                channel = chn;
            }
        }
        int getChannel() {
            return channel;
        }

        void setVolume(int vol) {
            if (vol >= 0 && vol <= 100) {
                volume = vol;
            }
        }
        int getVolume() {
            return volume;
        }
};

int main() {
    TV mytv;

    mytv.on();
    mytv.setChannel(10);
    mytv.setVolume(50);

    cout << "Get Channel " << mytv.getChannel() << endl;
    cout << "Get Volume " << mytv.getVolume() << endl;
}