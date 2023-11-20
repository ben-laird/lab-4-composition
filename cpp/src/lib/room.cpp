#include "errors.h"

#include "room.h"

const Unit GALLONS_PER_HOUR = {2, {{"gallons", 1}, {"hours", -1}}};

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

Unit Room::get_hours(Inclusion inclusion)
{
    return get_gallons(inclusion) * GALLONS_PER_HOUR;
}

Unit Room::get_gallons(Inclusion inclusion)
{
    return get_dimensions().surface_area(inclusion) * get_paint_info().get_coats_needed();
}

Unit Room::get_total_price(Inclusion inclusion)
{
    return get_gallons(inclusion) * get_paint_info().get_price_per_gallon();
}
