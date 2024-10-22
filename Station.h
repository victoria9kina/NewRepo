#pragma once
#include <string>

class Station {
public:
    int id;  // ���������� ������������� ��
    std::string name;  // �������� ��
    int totalWorkshops;  // ����� ���������� �����
    int activeWorkshops;  // ���������� �������� �����

    // ������������
    Station();
    Station(int id, const std::string& name, int totalWorkshops, int activeWorkshops);

    // ����������� ����� ��� �������� ��
    static Station CreateStation();

    // ����� ��� ����������� ���������� � ��
    void Display() const;

    // ����� ��� �������������� ��
    void Edit();

    // ������� ��� ������ ��
    static bool FilterByName(const Station& s, const std::string& searchName);
    static bool FilterByUnusedWorkshops(const Station& s, double percentage);
};
