#include "Inventory.h"
#include <iostream>


Inventory::Inventory(): count(0), capacity (2){
    items = new Item[capacity];
}

Inventory::~Inventory(){
    delete[] items;
}

void Inventory::add(const Item& item){
    if ( count == capacity){
        int newCapacity = capacity * 2;
        Item* newItems = new Item[newCapacity];
        for(int i=0; i<count; i++){
            newItems[i] = items[i];
        }
        delete[] items;
        items = newItems;
        capacity = newCapacity;
    }
    items[count] = item;
    count++;
}

bool Inventory::contains(char id) const{
    for(int i =0; i<count ; i++){
        if(items[i].getId() == id){
            return true;
        }
    
    }
    return false;
}

bool Inventory::remove(char id){
    for(int i=0; i<count;i++){
        if(items[i].getId()==id){
            for(int j=i; j<count-1;j++){
                items[j] = items[j+1];
            }
            count--;
            return true;
        }
    }
    return false;
}

void Inventory::display() const{
    std::cout << "Inventory :"<< std::endl;
    for(int i = 0; i<count;i++){
        std::cout << "Item Name is : " << items[i].getName() << " , The Item ID is : " << items[i].getId() << std::endl;
    }
}