#include "Pipe.h"
#include <iostream>
#include <vector> 

// Конструктор по умолчанию
Pipe::Pipe() : id(0), name(""), inRepair(false) {}

// Конструктор с параметрами
Pipe::Pipe(int id, const std::string& name, bool inRepair)
    : id(id), name(name), inRepair(inRepair) {}

// Метод для создания трубы
Pipe Pipe::CreatePipe() {
    Pipe p;
    std::cout << "Enter pipe ID: ";
    std::cin >> p.id;
    std::cout << "Enter pipe name: ";
    std::cin >> p.name;
    std::cout << "Is pipe in repair? (1 for yes, 0 for no): ";
    std::cin >> p.inRepair;
    return p;
}

// Метод для отображения информации о трубе
void Pipe::Display() const {
    std::cout << "Pipe ID: " << id << ", Name: " << name
        << ", In repair: " << (inRepair ? "Yes" : "No") << std::endl;
}

/
void EditPipe(std::vector<Pipe>&pipes) {
    int id;
    std::cout << "Enter Pipe ID to edit: ";
    std::cin >> id;

    for (auto& pipe : pipes) {
        if (pipe.id == id) {
            std::cout << "Enter new length: ";
            std::cin >> pipe.length;
            std::cout << "Is the pipe in repair (1 - yes, 0 - no): ";
            std::cin >> pipe.inRepair;
            return;
        }
    }
    std::cout << "Pipe not found." << std::endl;
}

// Функция для удаления трубы
void DeletePipe(std::vector<Pipe>& pipes) {
    int id;
    std::cout << "Enter Pipe ID to delete: ";
    std::cin >> id;

    pipes.erase(std::remove_if(pipes.begin(), pipes.end(), [id](const Pipe& pipe) {
        return pipe.id == id;
        }), pipes.end());
}

// Фильтр по имени
bool Pipe::FilterByName(const Pipe& p, const std::string& searchName) {
    return p.name == searchName;
}

// Фильтр по признаку "в ремонте"
bool Pipe::FilterByRepair(const Pipe& p, bool repairStatus) {
    return p.inRepair == repairStatus;
}
