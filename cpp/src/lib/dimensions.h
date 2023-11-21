#pragma once

#include "units.h"

struct Inclusion
{
    enum
    {
        Floor,
        Ceiling,
        Both,
        Neither,
    } inclusion;

    int mod();
};

class Dimensions
{
public:
    Dimensions();
    Dimensions(Unit length, Unit width, Unit height);

    Unit get_length();
    void set_length(Unit room_length);

    Unit get_width();
    void set_width(Unit room_width);

    Unit get_height();
    void set_height(Unit room_height);

    Unit volume();
    Unit surface_area(Inclusion include_options);

private:
    Unit length;
    Unit width;
    Unit height;
};