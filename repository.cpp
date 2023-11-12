#include <iostream>
#include "entity.h"
#include <map>

class Repository {
    std::map<int, Entity> storage;
public:
    Repository() {}

    // добавление нового элемента
    void save(Entity v) {
        storage.insert(std::make_pair(v.id, v));
    }

    // проход по списку с выводом на экран информационных частей элементов
    std::vector<Entity> list() const {
        std::vector<Entity> values;

        for (const std::pair<int, Entity>& pair : storage) {
            values.push_back(pair.second);
        }

        return values;
    }

    // поиск элемента с заданной информационной частью
    Entity getById(int id) const {
        return storage.at(id);
    }

    // удаление заданного элемента.
    void deleteById(int id) {
        storage.erase(id);
    }
};