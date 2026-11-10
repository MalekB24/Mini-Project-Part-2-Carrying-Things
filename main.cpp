#include <iostream>
#include "Room.h"
#include "Player.h"

int main() {
    int rows = 0;
    int columns = 0;

    std::cout << "Enter number of rows: ";
    if (!(std::cin >> rows)) {
        std::cout << "Invalid input. Enter a whole number.\n";
        return 1;
    }

    std::cout << "Enter number of columns: ";
    if (!(std::cin >> columns)) {
        std::cout << "Invalid input. Enter a whole number.\n";
        return 1;
    }

    // These limits ensure room for interior walls and
    // keep the terminal map and allocation manageable.
    if (rows < 5 || columns < 5 ||
        rows > 100 || columns > 100) {
        std::cout << "Rows and columns must be between 5 and 100.\n";
        return 1;
    }

    Room room(rows, columns);
    // Place items in the room.
    room.placeItem(1, 2, 'k');
    room.placeItem(1, 3, 'c');
    room.placeItem(2, 1, 'm');

    // Create the player.
    Player player(1, 1, room);

    std::cout << "\nControls:\n"
              << "w = up\n"
              << "a = left\n"
              << "s = down\n"
              << "d = right\n"
              << "q = quit\n"
              << "Press Enter after each key.\n";

    room.draw(player.getRow(), player.getColumn());

    char key;

    while (true) {
        std::cout << "\nEnter move: ";

        if (!(std::cin >> key)) {
            break;
        }

        if (key == 'q') {
            break;
        }

        player.move(key);
        room.draw(player.getRow(), player.getColumn());
        player.displayInventory();
        room.draw(player.getRow(), player.getColumn());
    }

    std::cout << "Goodbye!\n";
    return 0;
}