#include <iostream>
#include "entity.h"
#include "repository.cpp"

int main() {
    Repository repo;

    Entity e0(0, "Entity 0");
    Entity e1(1, "Entity 1");
    Entity e2(2, "Entity 2");
    Entity e3(3, "Entity 3");

    std::vector<Entity> entityVector; 
    entityVector.push_back(e0);
    entityVector.push_back(e1);
    entityVector.push_back(e2);
    entityVector.push_back(e3);

    std::cout << "Инициализация энтити: " << std::endl;
    std::cout << e0 << std::endl;
    std::cout << e1 << std::endl;
    std::cout << e2 << std::endl;
    std::cout << e3 << std::endl;
    std::cout << "Энтити инициализированы" << std::endl;

    
    std::cout << "\nдобавление нового элемента: " << std::endl;
    for (const Entity& entity : entityVector) {
        std::cout << "   Добавление элемента: " << entity << std::endl;
        repo.save(entity);
        std::cout << "   Элемент добавлен: " << entity << std::endl;
    }

    std::cout << "\nпроход по списку с выводом на экран информационных частей элементов: " << std::endl;
    std::vector<Entity> all = repo.list();
    for (const Entity& entity : all) {
        std::cout << "   Найденный элемент элемента: " << entity << std::endl;
    }

    std::cout << "\nпоиск элемента с заданной информационной частью: " << std::endl;
    for (const Entity& entity : entityVector) {
        std::cout << "   Поиск элемента с id: " << entity.id << std::endl;
        std::cout << "   Найден элемент: " << repo.getById(entity.id) << std::endl;
    }

    std::cout << "\nудаление заданного элемента: " << std::endl;
    for (const Entity& entity : entityVector) {
        std::cout << "   Удаление элемента c id: " << std::endl;
        repo.deleteById(entity.id);
    }

    std::vector<Entity> allResults = repo.list();
    std::cout << "      Проверка размера хранилища, должна быть 0, фактический размер: " << allResults.size() << std::endl;

    return 0;
}