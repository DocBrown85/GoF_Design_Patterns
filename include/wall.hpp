#include "map_site.hpp";

class Wall : public MapSite
{
public:
    Wall();
    virtual void Enter();
};