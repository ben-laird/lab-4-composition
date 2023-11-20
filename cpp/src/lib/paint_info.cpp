#include "paint_info.h"

PaintInfo::PaintInfo()
{
    set_price_per_gallon({0, {{"dollars", 1}, {"gallon", -1}}});
    set_coats_needed(0);
}

PaintInfo::PaintInfo(Unit price_per_gallon, int coats_needed)
{
    set_price_per_gallon(price_per_gallon);
    set_coats_needed(coats_needed);
}

int PaintInfo::get_coats_needed()
{
    return coats_needed;
}

void PaintInfo::set_coats_needed(int coats_needed_to_cover)
{
    coats_needed = coats_needed_to_cover;
}

Unit PaintInfo::get_price_per_gallon()
{
    return price_per_gallon;
}

void PaintInfo::set_price_per_gallon(Unit price)
{
    price_per_gallon = price;
}