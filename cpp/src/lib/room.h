#include "dimensions.h"
#include "paint_info.h"

struct RoomInfo
{
    Dimensions dimensions;
    PaintInfo info;
};

class Room
{
public:
    Room();
    Room(RoomInfo room_info);

    Dimensions get_dimensions();
    void set_dimensions(Dimensions dimensions);

    PaintInfo get_paint_info();
    void set_paint_info(PaintInfo paint_info);

    float get_hours();
    float get_gallons();
    float get_total_price();

private:
    Dimensions dims;
    PaintInfo info;
};