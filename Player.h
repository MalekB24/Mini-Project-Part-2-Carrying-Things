#ifndef PLAYER_H
#define PLAYER_H

#include "Room.h"
#include "Inventory.h"

class Player {
private:
    int row;
    int column;
    Room* room;
    Inventory inventory;

public:
    Player(int startRow, int startColumn, Room& currentRoom);
    int getRow() const;
    int getColumn() const;
    void move(char key);
    void displayInventory() const;
};
#endif