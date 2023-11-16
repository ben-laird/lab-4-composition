#include "utils.hpp"

#include "room.h"

Room::Room()
{
    set_dimensions(Dimensions());
    set_paint_info(PaintInfo());
}

Room::Room(RoomInfo room_info)
{
    set_dimensions(room_info.dimensions);
    set_paint_info(room_info.info);
}

Dimensions Room::get_dimensions()
{
    return dims;
}

void Room::set_dimensions(Dimensions dimensions)
{
    dims = dimensions;
}

PaintInfo Room::get_paint_info()
{
    return info;
}

void Room::set_paint_info(PaintInfo paint_info)
{
    info = paint_info;
}

float Room::get_hours()
{
    throw Todo();
    return 0.0f;
}

float Room::get_gallons()
{
    throw Todo();
    return 0.0f;
}

float Room::get_total_price()
{
    throw Todo();
    return 0.0f;
}
