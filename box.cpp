#include "box.h"
#include "screen.h"

Box::Box(Point2D l_l, int w, int h, char c){ // BOX CONSTRUCTOR
    lower_left = l_l;
    upper_right.d_x = lower_left.d_x + w; // Creates upper right
    upper_right.d_y = lower_left.d_y + h;
    colour = c;
}
        
void Box::draw(Screen& s){ //sets all values of box to certain colour
    int w_difference = s.getWidth() - upper_right.d_x; //checks if box fits in screen
    int h_difference = s.getHeight() - upper_right.d_y;
    
    int w_on = 0;
    int h_on = 0;
    
    if(w_difference < 0){ // if any of these are negative, box doesn't fit screen, readjust by difference
        w_on = 1;
    }
    if(h_difference < 0){
        h_on = 1;
    }
    
    for(int i = 0; i < (upper_right.d_x - lower_left.d_x); ++i){
        for(int j = 0; j < (upper_right.d_y - lower_left.d_y); ++j){
            const Point2D &tmp{lower_left.d_x + i + w_on*w_difference, lower_left.d_y + j + h_on*h_difference}; // new const point to send to screen
            s.Screen::setColour(tmp, colour); // colours with tmp
            
        }
    }
    
}

void Box::set(Point2D l_l, int w, int h, char c){
    lower_left = l_l;
    upper_right.d_x = lower_left.d_x + w;
    upper_right.d_y = lower_left.d_y + h;
    colour = c;
    
}
