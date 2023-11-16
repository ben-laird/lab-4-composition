class PaintInfo
{
public:
    PaintInfo();
    PaintInfo(float price_per_gallon, int coats_needed);

    int get_coats_needed();
    void set_coats_needed(int coats_needed_to_cover);

    float get_price_per_gallon();
    void set_price_per_gallon(float price);

private:
    float price_per_gallon;
    int coats_needed;
};