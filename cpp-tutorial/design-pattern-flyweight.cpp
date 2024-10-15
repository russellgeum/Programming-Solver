#include <iostream>
#include <unordered_map>
#include <string>

// Flyweight 클래스 (공유될 상태를 가진 클래스)
class Character {
public:
    virtual void render(int x, int y) = 0;  // 외부 상태는 좌표(x, y)로 표현
};

// 구체적인 Flyweight 클래스
class Soldier : public Character {
private:
    std::string unitType;

public:
    Soldier() {
        unitType = "Soldier";
    }

    void render(int x, int y) override {
        std::cout << "Rendering a " << unitType << " at (" << x << ", " << y << ")\n";
    }
};

// Flyweight Factory 클래스 (Flyweight 객체를 관리)
class CharacterFactory {
private:
    std::unordered_map<std::string, Character*> characters;

public:
    ~CharacterFactory() {
        for (auto& pair : characters) {
            delete pair.second;
        }
    }

    Character* getCharacter(const std::string& type) {
        if (characters.find(type) == characters.end()) {
            if (type == "Soldier") {
                characters[type] = new Soldier();
            }
            // 다른 캐릭터 타입도 필요하면 추가 가능
        }
        return characters[type];
    }
};

// Client Code
int main() {
    CharacterFactory factory;

    // 캐릭터들을 생성하고 위치를 설정
    Character* soldier1 = factory.getCharacter("Soldier");
    soldier1->render(10, 20);

    Character* soldier2 = factory.getCharacter("Soldier");
    soldier2->render(30, 40);

    Character* soldier3 = factory.getCharacter("Soldier");
    soldier3->render(50, 60);

    return 0;
}
