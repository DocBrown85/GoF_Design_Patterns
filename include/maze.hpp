#include "room.hpp"
#include <vector>

class Maze
{
public:
    Maze();

    void AddRoom(Room *);
    Room *RoomNo(int) const;

private:
    std::vector<Room *> _rooms;
};