#include "Pipe.h"
#include <iostream>
#include <vector> 

// ����������� �� ���������
Pipe::Pipe() : id(0), name(""), inRepair(false) {}

// ����������� � �����������
Pipe::Pipe(int id, const std::string& name, bool inRepair)
    : id(id), name(name), inRepair(inRepair) {}

// ����� ��� �������� �����
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

// ����� ��� ����������� ���������� � �����
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

// ������� ��� �������� �����
void DeletePipe(std::vector<Pipe>& pipes) {
    int id;
    std::cout << "Enter Pipe ID to delete: ";
    std::cin >> id;

    pipes.erase(std::remove_if(pipes.begin(), pipes.end(), [id](const Pipe& pipe) {
        return pipe.id == id;
        }), pipes.end());
}

// ������ �� �����
bool Pipe::FilterByName(const Pipe& p, const std::string& searchName) {
    return p.name == searchName;
}

// ������ �� �������� "� �������"
bool Pipe::FilterByRepair(const Pipe& p, bool repairStatus) {
    return p.inRepair == repairStatus;
}
