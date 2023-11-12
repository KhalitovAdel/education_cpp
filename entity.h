#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>

struct Entity {
    int id;
    std::string name;

    Entity(int id, const std::string& name) : id(id), name(name) {}
};

// Для удобства печати в консоль
std::ostream& operator<<(std::ostream& os, const Entity& entity) {
    os << "ID: " << entity.id << ", Name: " << entity.name;
    return os;
}

#endif
