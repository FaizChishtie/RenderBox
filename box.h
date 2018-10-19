#ifndef BOX
#define BOX
class Screen;

class Box{
    
    public:
    struct Point2D{ // internal struct
        int d_x;
        int d_y;
    };
        Box() = default;
        Box(Point2D l_l, int width, int height, char c);
        void draw(Screen& s);
        void set(Point2D l_l, int width, int height, char c);
        char getColour(){return colour;};
    private:
        Point2D lower_left;
        Point2D upper_right;
        char colour;
};
#endif
