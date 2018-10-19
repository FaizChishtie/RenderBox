#ifndef SCREEN
#define SCREEN
#include <string>
#include <iostream>
#include "box.h"

struct Point2D;

// LINKEDBOX
class LinkedBox{
public:
    LinkedBox() = default;
    int size = 0;
    struct Node{ // internal linkedlist structure
        Box value;
        struct Node *next; // holds next and prev
        struct Node *previous;
    } *head;
    
    void insertNext(Box b){ // inserts the next open value in the linkedlist
        struct Node *p, *tmp;
        tmp = new(struct Node); // creates tmp based on if head or not
        tmp->value = b;
        tmp->next = NULL;
        if(size == 0){
            tmp->previous = NULL; // creates head
            head = tmp;
        }
        else{
            p = head; // iterates to next open spot
            while (p->next != NULL){
                p = p->next;
            }
            p->next = tmp; // assign
            tmp->previous = p;
        }
        size++;
    }
    
    void print(){ // prints linked list (for testing purposes)
        struct Node *p;
        p = head;
        while(p->next != NULL){
            std::cout << p->value.getColour() << ",";
            p = p->next;
        }
        std::cout << p->value.getColour() << std::endl;
    }
    
    int getSize(){
        return size;
    }
    
    bool isEmpty(){
        return size==0;
    }
    
    bool swapNext(int pos){ // swaps a given pos item with it's next
        if(pos < 0 || pos > size){ // if exceed size then break
            return false;
        }
        
        struct Node *p1, *p2;
        p1 = head;
        
        //Swapping algorithm
        for(int i = 0; i < pos; ++i){
            p1 = p1->next;
        }
        if(p1->next == NULL){
            return false;
        }
        p2 = p1->next;
        if(p1->previous == NULL){
            p2->previous = NULL;
            head = p2;
        }else{
            p2->previous = p1->previous;
            p1->previous->next = p2;
        }
        p1->previous = p2;
        if(p2->next == NULL){
            p1->next = NULL;
        }else{
            p1->next = p2->next;
            p2->next->previous = p1;
        }
        p2->next = p1;
        return true;
        
    }
    
    bool swapPrevious(int pos){
            if(pos < 0 || pos > size){
                return false;
            }
            struct Node *p1, *p2;
            p1 = head;
            for(int i = 0; i < pos; ++i){
                p1 = p1->next;
            }
            if(p1->previous == NULL){
                return false;
            }
            p2 = p1->previous;
            if(p1->next == NULL){ //END OF LL
                p2->next = NULL;
            }else{
                p2->next = p1->next;
                p1->next->previous = p2;
            }
            p1->next = p2;
            if(p2->previous == NULL){
                p1->previous = NULL;
                head = p1;
            }else{
                p1->previous = p2->previous;
                p2->previous->next = p1;
            }
            p2->previous = p1;
            return true;
        }
    
    Box* returnBoxes(){ // returns an array of boxes from linkedlist in order of insertion
        Box *b = new Box[size];
        if(isEmpty()){
            return NULL;
        }
        int count = 0;
        struct Node *p;
        p = new (struct Node);
        p = head;
        while(p != NULL){
            b[count] = p->value;
            p = p->next;
            ++count;
        }
        return b;
    }
    
    char* returnColours(){ // returns the colours of each box stored in linkedlist
        if(isEmpty()){
            return NULL;
        }
        char* c = new char[size];
        int count = 0;
        struct Node *p = head;
        while(p != NULL){
            c[count] = p->value.getColour();
            p = p->next;
            ++count;
        }
        return c;
    }
    
};

// SCREEN
class Screen{
    private:
        LinkedBox boxes;
        int width;
        int height;
        std::string *row;
    public:
        Screen(int w, int h);
        int add(Box b);
        bool reorder(int boxId, int orderChange);
        void draw();
        void printOrder();
        void setRow();
        void setStringSize();
        void setColour(const Box::Point2D& p, char c);
        int getWidth(){return width;};
        int getHeight(){return height;};
};
#endif
