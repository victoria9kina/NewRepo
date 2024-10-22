#include "Station.h"
#include <vector>
#include <iostream>

// Конструктор по умолчанию
Station::Station() : id(0), name(""), totalWorkshops(0), activeWorkshops(0) {}

// Конструктор с параметрами
Station::Station(int id, const std::string& name, int totalWorkshops, int activeWorkshops)
    : id(id), name(name), totalWorkshops(totalWorkshops), activeWorkshops(activeWorkshops) {}

// Метод для создания КС
Station Station::CreateStation() {
    Station s;
    std::cout << "Enter station ID: ";
    std::cin >> s.id;
    std::cout << "Enter station name: ";
    std::cin >> s.name;
    std::cout << "Enter total workshops: ";
    std::cin >> s.totalWorkshops;
    std::cout << "Enter active workshops: ";
    std::cin >> s.activeWorkshops;
    return s;
}

// Метод для отображения информации о КС
void Station::Display() const {
    std::cout << "Station ID: " << id << ", Name: " << name
        << ", Total Workshops: " << totalWorkshops
        << ", Active Workshops: " << activeWorkshops << std::endl;
}

// Функция для редактирования КС
void EditStation(std::vector<Station>& stations) {
    int id;
    std::cout << "Enter Station ID to edit: ";
    std::cin >> id;

    for (auto& station : stations) {
        if (station.id == id) {
            station.Edit();
            break;
        }
    }
}

// Функция для удаления КС
void DeleteStation(std::vector<Station>& stations) {
    int id;
    std::cout << "Enter Station ID to delete: ";
    std::cin >> id;

    stations.erase(std::remove_if(stations.begin(), stations.end(), [id](const Station& station) {
        return station.id == id;
        }), stations.end());
}

// Фильтр по имени
bool Station::FilterByName(const Station& s, const std::string& searchName) {
    return s.name == searchName;
}

// Фильтр по проценту незадействованных цехов
bool Station::FilterByUnusedWorkshops(const Station& s, double percentage) {
    double unusedPercentage = (double)(s.totalWorkshops - s.activeWorkshops) / s.totalWorkshops * 100;
    return unusedPercentage >= percentage;
}
