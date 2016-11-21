#include "cubelet.h"
#include <iostream>


cubelet::cubelet()  //default constructor
{
    colourX='-';
    colourY='-';
    colourZ='-';
}

cubelet::cubelet(char A, char B, char C)  //constructor with parameters
{
    colourX=A;
    colourY=B;
    colourZ=C;
}


cubelet::~cubelet() //destructor. Using cout only for debugging purposes
{
    //std::cout << "\nThe destructor has been called\n";
}


void cubelet::Charge_colour(char D, int axis)  //constructor with parameters
{
    if(axis==0){    //in case the rotation is in the axis X
        this->colourX=D;
    }
    else if (axis==1){  //in case the rotation is in the axis Y
        this->colourY=D;
    }
    else if (axis==2){  //in case the rotation is in the axis Z
        this->colourZ=D;
    }
    else{   //error detection since the axis should only be 0, 1 or 2
        std::cout << "\nError at Charge_colour when updating colour of " << axis << "\n";
    }
}


void cubelet::Rotate_cubelet(int axis)  //swaps colours of the cubelet in the 2 axis perpendicular to the one of rotation
{
    char temp='1';  //temp variable to storage the value of one of the colours and do not overwrite it and loose it.

    if(axis==0){    //in case the rotation is in the axis X
        temp = this->colourY;
        this->colourY = this->colourZ;
        this->colourZ = temp;
    }
    else if (axis==1){  //in case the rotation is in the axis Y
        temp = this->colourX;
        this->colourX = this->colourZ;
        this->colourZ = temp;
    }
    else if (axis==2){  //in case the rotation is in the axis Z
        temp = this->colourX;
        this->colourX = this->colourY;
        this->colourY = temp;
    }
    else{   //error detection since the axis should only be 0, 1 or 2
        std::cout << "\nError at Rotate_cubelet when rotating axis" << axis << "\n";
    }
}


char cubelet::Colour_cubelet(int axis)  //gives back the colour of the cubelet in the corresponding axis
{
    char colour = '2';

    if(axis==0){    //in case the rotation is in the axis X
        colour = this->colourX;
    }
    else if (axis==1){  //in case the rotation is in the axis Y
        colour = this->colourY;
    }
    else if (axis==2){  //in case the rotation is in the axis Z
        colour = this->colourZ;
    }
    else{   //error detection since the axis should only be 0, 1 or 2
        std::cout << "\nError at Colour_cubelet when returning colour of axis " << axis << "\n";
    }
    return colour;
}


void cubelet::Print_colours()
{
    std::cout << "\n Colours of the cubelet:\n"
                    "View in axis X:\t" << this->colourX
                    << "\nView in axis Y:\t" << this->colourY
                    << "\nView in axis Z:\t" << this->colourZ;
}
