#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item {
    private:
        std::string Name;
        char Id;
    public:
        Item();
        Item(std::string ItemName, char ItemId);
        std::string getName() const;
        char getId() const;
};

#endif 