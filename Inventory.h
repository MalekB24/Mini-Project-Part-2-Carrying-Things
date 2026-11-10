#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"

class Inventory {
private:
    Item* items;
    int count;
    int capacity;

public:
    Inventory();
    ~Inventory();

    void add(const Item& item);
    bool remove(char id);
    bool contains(char id) const;
    void display() const;

    Inventory(const Inventory&) = delete;
    Inventory& operator=(const Inventory&) = delete;
};

#endif