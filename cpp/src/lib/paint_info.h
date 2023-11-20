#pragma once

#include "units.h"

class PaintInfo
{
public:
    PaintInfo();
    PaintInfo(Unit price_per_gallon, int coats_needed);

    int get_coats_needed();
    void set_coats_needed(int coats_needed_to_cover);

    Unit get_price_per_gallon();
    void set_price_per_gallon(Unit price);

private:
    Unit price_per_gallon;
    int coats_needed;
};