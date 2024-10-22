#pragma once
#include <string>

class Pipe {
public:
    int id;  // ���������� ������������� �����
    std::string name;  // �������� �����
    bool inRepair;  // ������� "� �������"

    // ������������
    Pipe();
    Pipe(int id, const std::string& name, bool inRepair);

    // ����������� ����� ��� �������� �����
    static Pipe CreatePipe();

    // ����� ��� ����������� ���������� � �����
    void Display() const;

    // ����� ��� �������������� �����
    void Edit();

    // ������� ��� ������ ����
    static bool FilterByName(const Pipe& p, const std::string& searchName);
    static bool FilterByRepair(const Pipe& p, bool repairStatus);
};
