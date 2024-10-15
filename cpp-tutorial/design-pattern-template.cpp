#include "header.h"

// Abstract Class
class Cooking {
    public:
        // Template Method
        void cookDish() {
            prepareIngredients();
            cook();
            serve();
        }

    protected:
        // Abstract methods to be implemented by subclasses
        virtual void prepareIngredients() = 0;
        virtual void cook() = 0;
        
        // Concrete method
        void serve() {
            std::cout << "Dish is served!" << std::endl;
        }
};

// Concrete Class 1
class Pasta : public Cooking {
    protected:
        void prepareIngredients() override {
            std::cout << "Preparing pasta, tomatoes, and cheese." << std::endl;
        }

        void cook() override {
            std::cout << "Cooking the pasta and making the sauce." << std::endl;
        }
};

// Concrete Class 2
class Steak : public Cooking {
    protected:
        void prepareIngredients() override {
            std::cout << "Preparing steak, salt, pepper, and garlic." << std::endl;
        }

        void cook() override {
            std::cout << "Grilling the steak to perfection." << std::endl;
        }
};

int main() {
    Cooking* pastaDish = new Pasta();
    Cooking* steakDish = new Steak();

    std::cout << "Making Pasta:" << std::endl;
    pastaDish->cookDish();

    std::cout << "\nMaking Steak:" << std::endl;
    steakDish->cookDish();

    delete pastaDish;
    delete steakDish;

    return 0;
}
