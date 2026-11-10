#ifndef ROOM_H
#define ROOM_H
class Room{
    private:
    int rows;
    int columns;
    char* map;

    public:
    Room(int rowCount, int columnCount);
    ~Room();
    bool isWall(int row, int column) const;
    void draw(int playerRow, int playerColumn) const;
    void placeItem (int row, int column, char itemId);
    char takeItem(int row, int column);
};


#endif