#include "header.h"

// Composite 패턴
// 부분과 전체의 계층을 표현하기 위해 복합 객체를 트리 구조로 만든다.
// 새로운 메뉴 추가하거나 메뉴의 구조를 변경하는 것이 쉽다.
// 타입 안정성 vs 일관성

class BaseMenu {
    private:
        std::string title;
    public:
        BaseMenu(const std::string& title) : title(title) {}
        
        virtual ~BaseMenu() {}

        std::string get_title() const {
            return title;
        }

        void set_title(const std::string& s) {
            title = s;
        }
        
        virtual void command() = 0;
};


class MenuItem : public BaseMenu {
    private:
        int id;
    
    public:
        // 초기화 리스트에서 this-> 제거
        MenuItem(const std::string& title, int id) : BaseMenu(title), id(id) {}

        void command() {
            std::cout << get_title() << " 메뉴 선택" << std::endl;
        }
};


class PopupMenu : public BaseMenu {
    private:
        std::vector<MenuItem*> v;
    public:
        PopupMenu(const std::string& title) : BaseMenu(title) {}

        void add_menu(MenuItem* m) { 
            v.push_back(m); 
        }

        void command() {
            while (1) {
                system("cls");
                std::size_t sz = v.size();
                std::size_t i = 0;
                for (BaseMenu* p : v) {
                    std::cout << ++i << ". " << p->get_title() << std::endl;
                }
                std::cout << i+1 << ". 종료" << std::endl;
                std::cout << "메뉴를 선택해 주세요. >> ";

                int cmd;
                std::cin >> cmd;

                if (cmd == sz+1) {
                    break;
                }
                if (cmd < 1 || cmd > sz+1) {
                    continue;
                }
                // command()를 호출하는데, BaseMenu에 구현되지 않음
                v[cmd-1]->command();
            }
        }
};


int main() {
    PopupMenu* root = new PopupMenu("오늘의 메뉴");
    root->add_menu(new MenuItem("김밥", 11));
    root->add_menu(new MenuItem("라면", 12));
    root->add_menu(new MenuItem("우동", 13));
    root->command();

    // 객체를 만들고,
    // 객체 간 관계를 설정하고,
    // 객체 간 메시지를 주고 받는 과정
    return 0;
}