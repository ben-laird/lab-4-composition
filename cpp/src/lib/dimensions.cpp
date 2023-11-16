#include "dimensions.h"

Dimensions::Dimensions()
{
    set_length(0);
    set_width(0);
    set_height(0);
}

Dimensions::Dimensions(float length, float width, float height)
{
    set_length(length);
    set_width(width);
    set_height(height);
}

float Dimensions::get_length()
{
    return length;
}

void Dimensions::set_length(float room_length)
{
    length = room_length;
}

float Dimensions::get_width()
{
    return width;
}

void Dimensions::set_width(float room_width)
{
    width = room_width;
}

float Dimensions::get_height()
{
    return height;
}

void Dimensions::set_height(float room_height)
{
    height = room_height;
}

float Dimensions::volume()
{
    return length * width * height;
}

float Dimensions::surface_area(Inclusion include_options)
{
    float floor_ceiling_area = length * width;
    float wall_hw_area = height * width;
    float wall_hl_area = height * length;

    return 2 * wall_hl_area + 2 * wall_hw_area + inclusion_modifier(include_options) * floor_ceiling_area;
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
