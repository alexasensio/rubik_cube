#ifndef CUBELET_H
#define CUBELET_H


class cubelet
{
    private:
        char colourX,colourY,colourZ;

    //protected:

    public:
        cubelet();  //constructor by default
        cubelet(char A, char B, char C);    //constructor with all the parameters
        ~cubelet(); //destructor
        void Charge_colour(char D, int axis);    //modifies colour parameter in only one of the axis. Used to initialize cube
        void Rotate_cubelet(int axis);   //rotates the colours of each cubelet according to the axis of rotation
        char Colour_cubelet(int axis);  //gives back the colour of the cubelet in the corresponding axis
        void Print_colours();   //prints in console the 3 colours storage in the cubelet in order X, Y , Z
};

#endif // CUBELET_H
