#include <iostream>
#include <vector>
#include <string>

struct Laptop {
    std::string brand;
    std::string cpu_model;
    bool gaming;
};

void laptopChars(Laptop* laptop) {
    std::cout << "Введите фирму: ";
    std::cin >> laptop->brand;

    std::cout << "Введите модель процессора: ";
    std::cin >> laptop->cpu_model;

    std::cout << "Игровой? (1 - Да, 0 - Нет): ";
    int gamingInput;
    std::cin >> gamingInput;
    laptop->gaming = gamingInput;
}

void printLaptop(const Laptop& laptop) {
    std::cout << "Фирма: " << laptop.brand << "\n";
    std::cout << "Процессор: " << laptop.cpu_model << "\n";
    std::cout << "Игровой: " << (laptop.gaming ? "Да" : "Нет") << "\n";
}


void createLaptopVector(std::vector<Laptop>& laptops) {
    Laptop newLaptop;
    laptopChars(&newLaptop);
    laptops.push_back(newLaptop);
}

int main() {
    std::vector<Laptop> laptops;
    int choice;

    while (true) {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить ноутбук\n";
        std::cout << "2. Показать все ноутбуки\n";
        std::cout << "3. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                createLaptopVector(laptops);
                break;
            case 2:
                if (laptops.empty()) {
                    std::cout << "Список пуст.\n";
                } else {
                    for (size_t i = 0; i < laptops.size(); ++i) {
                        std::cout << "\nНоутбук #" << i + 1 << ":\n";
                        printLaptop(laptops[i]);
                    }
                }
                break;
            case 3:
                std::cout << "Выход из программы.\n";
                return 0;
            default:
                std::cout << "Некорректный ввод. Попробуйте снова.\n";
        }
    }
}

Laptop l1, l2;
