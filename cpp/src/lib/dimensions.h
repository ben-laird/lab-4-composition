enum Inclusion
{
    Floor,
    Ceiling,
    Both,
    Neither,
};

class Dimensions
{
public:
    Dimensions();
    Dimensions(float length, float width, float height);

    float get_length();
    void set_length(float room_length);

    float get_width();
    void set_width(float room_width);

    float get_height();
    void set_height(float room_height);

    float volume();
    float surface_area(Inclusion include_options);

private:
    float length;
    float width;
    float height;

    int inclusion_modifier(Inclusion inclusion);
};