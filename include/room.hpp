#include "map_site.hpp";

class Room : public MapSite
{
public:
    Room(int roomNo);

    MapSite *GetSide(Direction) const;
    void SetSide(Direction, MapSite *);

    virtual void Enter();

private:
    MapSite *_sides[4];
    int _roomNumber;
};