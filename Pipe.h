#pragma once
#include <string>

class Pipe {
public:
    int id;  // Уникальный идентификатор трубы
    std::string name;  // Название трубы
    bool inRepair;  // Признак "в ремонте"

    // Конструкторы
    Pipe();
    Pipe(int id, const std::string& name, bool inRepair);

    // Статический метод для создания трубы
    static Pipe CreatePipe();

    // Метод для отображения информации о трубе
    void Display() const;

    // Метод для редактирования трубы
    void Edit();

    // Фильтры для поиска труб
    static bool FilterByName(const Pipe& p, const std::string& searchName);
    static bool FilterByRepair(const Pipe& p, bool repairStatus);
};
