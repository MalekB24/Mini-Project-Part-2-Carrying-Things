#include "Room.h"
#include <iostream>

Room::Room(int rowCount, int columnCount)
    : rows(rowCount), columns(columnCount) {

    map = new char[rows * columns];

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            bool outsideWall =
                r == 0 || r == rows - 1 ||
                c == 0 || c == columns - 1;

            // Leave row 1 and column 1 open for the player.
            bool insideWall =
                r > 1 && c > 1 &&
                r % 2 == 0 && c % 3 == 0;

            if (outsideWall || insideWall) {
                map[r * columns + c] = '#';
            } else {
                map[r * columns + c] = ' ';
            }
        }
    }
}

Room::~Room() {
    delete[] map;
}

bool Room::isWall(int row, int column) const {
    // Check bounds before accessing the array.
    if (row < 0 || row >= rows ||
        column < 0 || column >= columns) {
        return true;
    }

    return map[row * columns + column] == '#';
}

void Room::draw(int playerRow, int playerColumn) const {
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            if (r == playerRow && c == playerColumn) {
                std::cout << '@';
            } else {
                std::cout << map[r * columns + c];
            }
        }

        std::cout << '\n';
    }
}

void Room::placeItem(int row, int column, char itemId) {
    // Stop if the position is outside the map.
    if (row < 0 || row >= rows ||
        column < 0 || column >= columns) {
        return;
    }

    int index = row * columns + column;

    // Place the item only on an empty space.
    if (map[index] == ' ') {
        map[index] = itemId;
    }
}

char Room::takeItem(int row, int column) {
    if (row < 0 || row >= rows ||
        column < 0 || column >= columns) {
        return 0;
    }

    int index = row * columns + column;
    if(map[index] >= 'a' && map[index] <= 'z'){
        char itemId = map[index];
        map[index] = ' ';
        return itemId;
    }else{
        return 0;
    }
}