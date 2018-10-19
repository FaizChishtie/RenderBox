#include "screen.h"


Screen::Screen(int w, int h){
    width = w; //screen constructor
    height = h;
    row = new std::string[h]; // with pointer
}

int Screen::add(Box b){ // uses linkedlist methods
    boxes.insertNext(b);
    return 0;
}

bool Screen::reorder(int boxId, int orderChange){
    int count = 0;
    if (boxId < orderChange){ // swaps based on the values to move
        int iterations = orderChange - boxId;
        while(count < iterations){
            boxes.swapNext(boxId);
            ++boxId;
            ++count;
        }
    } else if (boxId > orderChange){
        int iterations = boxId - orderChange;
        while (count < iterations){
            boxes.swapPrevious(boxId);
            --boxId;
            ++count;
        }
    }
    return true;
}

void Screen::draw(){
    setStringSize(); // sets blank string before insertion
    setRow(); // sets the value of row based on set colour
    for(int i = 0; i < height; ++i){
        std::cout << row[i] << std::endl;
    }
}

void Screen::setRow(){
    Box *b = boxes.returnBoxes(); // returns an array of boxes from linkedlist
    int i = 0;
    while(i < boxes.getSize()){
        b[i].draw(*this); // draws box based on linkedlist position
        ++i;
    }
}

void Screen::setStringSize(){
    for(int i = 0; i < height; ++i){
        for(int j = 0; j < width; ++j){
            row[i] += " "; // sets blank string
        }
    }
}

void Screen::printOrder(){
    char *c = boxes.returnColours(); // returns colours of boxes from linkedlist
    for(int i = 0; i < boxes.getSize(); ++i){
        if( i == boxes.getSize()-1){
            std::cout << c[i];
            break;
        }
        std::cout << c[i] << " - ";
    }
    std::cout << std::endl;
}

void Screen::setColour(const Box::Point2D& p, char c){
    int width_pos = p.d_x;
    int height_pos = p.d_y;
    if(!(width_pos >= width || height_pos >= height)){ // checks if greater than set width and height
        row[height_pos][width_pos] = c; // sets row using string indexing
    }
}
