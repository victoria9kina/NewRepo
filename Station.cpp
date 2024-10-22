#include "Station.h"
#include <vector>
#include <iostream>

// ����������� �� ���������
Station::Station() : id(0), name(""), totalWorkshops(0), activeWorkshops(0) {}

// ����������� � �����������
Station::Station(int id, const std::string& name, int totalWorkshops, int activeWorkshops)
    : id(id), name(name), totalWorkshops(totalWorkshops), activeWorkshops(activeWorkshops) {}

// ����� ��� �������� ��
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

// ����� ��� ����������� ���������� � ��
void Station::Display() const {
    std::cout << "Station ID: " << id << ", Name: " << name
        << ", Total Workshops: " << totalWorkshops
        << ", Active Workshops: " << activeWorkshops << std::endl;
}

// ������� ��� �������������� ��
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

// ������� ��� �������� ��
void DeleteStation(std::vector<Station>& stations) {
    int id;
    std::cout << "Enter Station ID to delete: ";
    std::cin >> id;

    stations.erase(std::remove_if(stations.begin(), stations.end(), [id](const Station& station) {
        return station.id == id;
        }), stations.end());
}

// ������ �� �����
bool Station::FilterByName(const Station& s, const std::string& searchName) {
    return s.name == searchName;
}

// ������ �� �������� ����������������� �����
bool Station::FilterByUnusedWorkshops(const Station& s, double percentage) {
    double unusedPercentage = (double)(s.totalWorkshops - s.activeWorkshops) / s.totalWorkshops * 100;
    return unusedPercentage >= percentage;
}
