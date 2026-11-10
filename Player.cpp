#include "Player.h"
#include <string>

Player::Player(int startRow, int startColumn, Room& currentRoom)
    : row(startRow), column(startColumn), room(&currentRoom) {
}

int Player::getRow() const {
    return row;
}

int Player::getColumn() const {
    return column;
}

void Player::move(char key) {
    int nextRow = row;
    int nextColumn = column;

    switch (key) {
        case 'w':
            nextRow--;
            break;
        case 'a':
            nextColumn--;
            break;
        case 's':
            nextRow++;
            break;
        case 'd':
            nextColumn++;
            break;
        default:
            return;
    }

    // Stop before moving or collecting if the destination is a wall.
    if (room->isWall(nextRow, nextColumn)) {
        return;
    }

    row = nextRow;
    column = nextColumn;

    char itemId = room->takeItem(row, column);

    if (itemId != 0) {
        std::string itemName;

        switch (itemId) {
            case 'k':
                itemName = "key";
                break;
            case 'c':
                itemName = "coin";
                break;
            case 'm':
                itemName = "map";
                break;
            default:
                itemName = std::string(1, itemId);
                break;
        }

        inventory.add(Item(itemName, itemId));
    }
}

void Player::displayInventory() const {
    inventory.display();
}