#pragma once
#include <string>

class Station {
public:
    int id;  // Уникальный идентификатор КС
    std::string name;  // Название КС
    int totalWorkshops;  // Общее количество цехов
    int activeWorkshops;  // Количество активных цехов

    // Конструкторы
    Station();
    Station(int id, const std::string& name, int totalWorkshops, int activeWorkshops);

    // Статический метод для создания КС
    static Station CreateStation();

    // Метод для отображения информации о КС
    void Display() const;

    // Метод для редактирования КС
    void Edit();

    // Фильтры для поиска КС
    static bool FilterByName(const Station& s, const std::string& searchName);
    static bool FilterByUnusedWorkshops(const Station& s, double percentage);
};
