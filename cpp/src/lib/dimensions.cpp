#include "dimensions.h"

Dimensions::Dimensions()
{
    set_length({0, {{"feet", 1}}});
    set_width({0, {{"feet", 1}}});
    set_height({0, {{"feet", 1}}});
}

Dimensions::Dimensions(Unit length, Unit width, Unit height)
{
    set_length(length);
    set_width(width);
    set_height(height);
}

Unit Dimensions::get_length()
{
    return length;
}

void Dimensions::set_length(Unit room_length)
{
    length = room_length;
}

Unit Dimensions::get_width()
{
    return width;
}

void Dimensions::set_width(Unit room_width)
{
    width = room_width;
}

Unit Dimensions::get_height()
{
    return height;
}

void Dimensions::set_height(Unit room_height)
{
    height = room_height;
}

Unit Dimensions::volume()
{
    return length * width * height;
}

Unit Dimensions::surface_area(Inclusion include_options)
{
    Unit floor_ceiling_area = length * width;
    Unit wall_hw_area = height * width;
    Unit wall_hl_area = height * length;

    return 2.0f * wall_hl_area + 2.0f * wall_hw_area + (float)inclusion_modifier(include_options) * floor_ceiling_area;
}

int Dimensions::inclusion_modifier(Inclusion inclusion)
{
    switch (inclusion)
    {
    case Floor:
        return 1;
    case Ceiling:
        return 1;
    case Both:
        return 2;
    case Neither:
        return 0;
    }
}
