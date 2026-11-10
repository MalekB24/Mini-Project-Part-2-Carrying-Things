#include "Item.h"

Item::Item():Name(""), Id(0){}

Item::Item(std::string ItemName, char ItemId): Name(ItemName), Id(ItemId) {}

std::string Item::getName() const{
    return Name;
}

char Item::getId() const{
    return Id;
}
