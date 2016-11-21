//LIBRARIES
#include <iostream>
#include <string>
# include "cubelet.h"

using namespace std;

//VARIABLES
const int side_length = 3;

//FUNCTIONS DECLARATIONS
void Initialize_cube (cubelet (*)[side_length][side_length]);
void print_explanation (void);
void print_cube (cubelet (*)[side_length][side_length]);
int print_menu(void);
void rotate_cube_X (cubelet (*)[side_length][side_length], int, bool);
void rotate_cube_Y (cubelet (*)[side_length][side_length], int, bool);
void rotate_cube_Z (cubelet (*)[side_length][side_length], int, bool);
bool solved_test (cubelet(*)[side_length][side_length]);


//MAIN FUNCTION
int main() //no need to explicitly do the "return 0" at the end of main function since compiler does it by default for us
{
    cout << "Welcome to Rubik's cube!\n";
    print_explanation();    //prints explanation to understand the next view of the cube

    cubelet cube[side_length][side_length][side_length];    //initializes the Rubik's cube and storage in an array of cubelets called "cube"

    Initialize_cube(cube);  //fills the created Rubik's cube with the initial position (we start always with the solved cube)

    cout << "Initial Rubik's cube position (solved) is:\n";
    print_cube(cube);   //displays and unrolled view of the cube in its initial state.


    while (true){   //infinite loop to let the user choose the movements on the cube or exit
        switch(print_menu()){   //The user chooses one group of actions from these list.
            case 0: return 0; //finish the program going out of the while and back to the main. Also destructors clean data.
            case 1: rotate_cube_X(cube,0,true); print_cube(cube); solved_test(cube); break;     //rotates face Front clockwise and display the result
            case 2: rotate_cube_X(cube,2,false); print_cube(cube); solved_test(cube); break;    //rotates face Back clockwise and display the result
            case 3: rotate_cube_Y(cube,0,true); print_cube(cube); solved_test(cube); break;     //rotates face Up clockwise and display the result
            case 4: rotate_cube_Y(cube,2,false); print_cube(cube); solved_test(cube); break;    //rotates face Down clockwise and display the result
            case 5: rotate_cube_Z(cube,0,true); print_cube(cube); solved_test(cube); break;     //rotates face Left clockwise and display the result
            case 6: rotate_cube_Z(cube,2,false); print_cube(cube); solved_test(cube); break;    //rotates face Right clockwise and display the result
            case 7: rotate_cube_X(cube,1,true); print_cube(cube); solved_test(cube); break;     //rotates layer Standing clockwise and display the result
            case 8: rotate_cube_Y(cube,1,true); print_cube(cube); solved_test(cube); break;     //rotates layer Equator clockwise and display the result
            case 9: rotate_cube_Z(cube,1,true); print_cube(cube); solved_test(cube); break;     //rotates layer Middle clockwise and display the result
            case 11: rotate_cube_X(cube,0,false); print_cube(cube); solved_test(cube); break;   //rotates face Front counterclockwise and display the result
            case 12: rotate_cube_X(cube,2,true); print_cube(cube); solved_test(cube); break;    //rotates face Back counterclockwise and display the result
            case 13: rotate_cube_Y(cube,0,false); print_cube(cube); solved_test(cube); break;   //rotates face Up counterclockwise and display the result
            case 14: rotate_cube_Y(cube,2,true); print_cube(cube); solved_test(cube); break;    //rotates face Down counterclockwise and display the result
            case 15: rotate_cube_Z(cube,0,false); print_cube(cube); solved_test(cube); break;   //rotates face Left counterclockwise and display the result
            case 16: rotate_cube_Z(cube,2,true); print_cube(cube); solved_test(cube); break;    //rotates face Right counterclockwise and display the result
            case 17: rotate_cube_X(cube,1,false); print_cube(cube); solved_test(cube); break;   //rotates layer Standing counterclockwise and display the result
            case 18: rotate_cube_Y(cube,1,false); print_cube(cube); solved_test(cube); break;   //rotates layer Equator counterclockwise and display the result
            case 19: rotate_cube_Z(cube,1,false); print_cube(cube); solved_test(cube); break;   //rotates layer Middle counterclockwise and display the result
            case 20: print_explanation();; break;
        }
    }

}

//FUNCTIONS DEFINITIONS

void Initialize_cube (cubelet (*cube)[side_length][side_length])
{
/*  -Task: fills a 3D array of cubelets of the corresponding colours in each axis to get a solved cube
    -Arguments: the 3D array of cubelets or cube
    -Return: Return the array filled by reference*/
    for (int i = 0 ; i < side_length ; i++){
        for (int j = 0 ; j < side_length ; j++){
            for (int k = 0 ; k < side_length ; k++){
                if(i==0){
                    cube[i][j][k].Charge_colour('R',0);
                }
                else if (i==side_length-1){
                    cube[i][j][k].Charge_colour('O',0);
                }

                if(j==0){
                    cube[i][j][k].Charge_colour('W',1);
                }
                else if (j==side_length-1){
                    cube[i][j][k].Charge_colour('Y',1);
                }

                if(k==0){
                    cube[i][j][k].Charge_colour('G',2);
                }
                else if (k==side_length-1){
                    cube[i][j][k].Charge_colour('B',2);
                }
            }
        }
    }
}


void print_explanation (void)
{
/*  -Task: print an scheme of the unrolled flat view of the Rubik's cube
    -Arguments: none
    -Return: none*/
    cout << "\nExplanation of the unrolled flat view:\n";
    cout << "      " << char(218) << char(196)  << char(196)  << char(196)  << char(196)  << char(196)  << char(191)  << "\n";
    cout << "      " << char(179) << "     " << char(179) << "\n";
    cout << "      " << char(179) << " Up  " << char(179) << "\n";
    cout << "      " << char(179) << "     " << char(179) << "\n";
    cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(197) << char(196) << char(196) << char(196) << char(196) << char(196) << char(197) << char(196) << char(196) << char(196) << char(196) << char (196) << char(194) << char(196) << char(196) << char(196) << char(196) << char (196) << char(191) << "\n";
    cout << char(179) << "     " << char(179) << "     " << char(179) <<  "     " << char(179) << "     " << char(179) << "\n";
    cout << char(179) << "Left " << char(179) << "Front" << char(179) <<  "Right" << char(179) << "Back " << char(179) << "\n";
    cout << char(179) << "     " << char(179) << "     " << char(179) <<  "     " << char(179) << "     " << char(179) << "\n";
    cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(197) << char(196) << char(196) << char(196) << char(196) << char(196) << char(197) << char(196) << char(196) << char (196) << char(196) << char(196) << char(193) << char(196) << char(196) << char (196) << char(196) << char(196) << char(217) << "\n";
    cout << "      " << char(179) << "     " << char(179) << "\n";
    cout << "      " << char(179) << "Down " << char(179) << "\n";
    cout << "      " << char(179) << "     " << char(179) << "\n";
    cout << "      " << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(217)  << "\n\n" ;
    cout << "In each of this faces there is going to be n*n elements of 6 different colours.\n"
            "The colours are represented by these characters:\n"
                "\tR: Red\n"
                "\tO: Orange\n"
                "\tW: White\n"
                "\tY: Yellow\n"
                "\tG: Green\n"
                "\tB: Blue\n\n";
}


void print_cube (cubelet (*cube)[side_length][side_length])
{
/*  -Task: print an unrolled flat view of the Rubik's cube
    -Arguments: the cube at its present state
    -Return: none*/
    if(side_length==3){
        cout << "\nView of the cube when unrolled flat:\n";
        cout << "      " << char(218) << char(196)  << char(196)  << char(196)  << char(196)  << char(196)  << char(191)  << "\n";
        cout << "      " << char(179) << cube[2][0][0].Colour_cubelet(1) << ' ' << cube[2][0][1].Colour_cubelet(1) << ' ' << cube[2][0][2].Colour_cubelet(1) << char(179) << "\n";
        cout << "      " << char(179) << cube[1][0][0].Colour_cubelet(1) << ' ' << cube[1][0][1].Colour_cubelet(1) << ' ' << cube[1][0][2].Colour_cubelet(1) << char(179) << "\n";
        cout << "      " << char(179) << cube[0][0][0].Colour_cubelet(1) << ' ' << cube[0][0][1].Colour_cubelet(1) << ' ' << cube[0][0][2].Colour_cubelet(1) << char(179) << "\n";
        cout << char(218) << char(196) << char(196) << char(196) << char(196) << char(196) << char(197) << char(196) << char(196) << char(196) << char(196) << char(196) << char(197) << char(196) << char(196) << char(196) << char(196) << char (196) << char(194) << char(196) << char(196) << char(196) << char(196) << char (196) << char(191) << "\n";
        cout << char(179) << cube[2][0][0].Colour_cubelet(2) << ' ' << cube[1][0][0].Colour_cubelet(2) << ' ' << cube[0][0][0].Colour_cubelet(2) << char(179) << cube[0][0][0].Colour_cubelet(0) << ' ' << cube[0][0][1].Colour_cubelet(0) << ' ' << cube[0][0][2].Colour_cubelet(0) << char(179) <<  cube[0][0][2].Colour_cubelet(2) << ' ' << cube[1][0][2].Colour_cubelet(2) << ' ' << cube[2][0][2].Colour_cubelet(2) << char(179) << cube[2][0][2].Colour_cubelet(0) << ' ' << cube[2][0][1].Colour_cubelet(0) << ' ' << cube[2][0][0].Colour_cubelet(0) << char(179) << "\n";
        cout << char(179) << cube[2][1][0].Colour_cubelet(2) << ' ' << cube[1][1][0].Colour_cubelet(2) << ' ' << cube[0][1][0].Colour_cubelet(2) << char(179) << cube[0][1][0].Colour_cubelet(0) << ' ' << cube[0][1][1].Colour_cubelet(0) << ' ' << cube[0][1][2].Colour_cubelet(0) << char(179) <<  cube[0][1][2].Colour_cubelet(2) << ' ' << cube[1][1][2].Colour_cubelet(2) << ' ' << cube[2][1][2].Colour_cubelet(2) << char(179) << cube[2][1][2].Colour_cubelet(0) << ' ' << cube[2][1][1].Colour_cubelet(0) << ' ' << cube[2][1][0].Colour_cubelet(0) << char(179) << "\n";
        cout << char(179) << cube[2][2][0].Colour_cubelet(2) << ' ' << cube[1][2][0].Colour_cubelet(2) << ' ' << cube[0][2][0].Colour_cubelet(2) << char(179) << cube[0][2][0].Colour_cubelet(0) << ' ' << cube[0][2][1].Colour_cubelet(0) << ' ' << cube[0][2][2].Colour_cubelet(0) << char(179) <<  cube[0][2][2].Colour_cubelet(2) << ' ' << cube[1][2][2].Colour_cubelet(2) << ' ' << cube[2][2][2].Colour_cubelet(2) << char(179) << cube[2][2][2].Colour_cubelet(0) << ' ' << cube[2][2][1].Colour_cubelet(0) << ' ' << cube[2][2][0].Colour_cubelet(0) << char(179) << "\n";
        cout << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(197) << char(196) << char(196) << char(196) << char(196) << char(196) << char(197) << char(196) << char(196) << char (196) << char(196) << char(196) << char(193) << char(196) << char(196) << char (196) << char(196) << char(196) << char(217) << "\n";
        cout << "      " << char(179) << cube[0][2][0].Colour_cubelet(1) << ' ' << cube[0][2][1].Colour_cubelet(1) << ' ' << cube[0][2][2].Colour_cubelet(1) << char(179) << "\n";
        cout << "      " << char(179) << cube[1][2][0].Colour_cubelet(1) << ' ' << cube[1][2][1].Colour_cubelet(1) << ' ' << cube[1][2][2].Colour_cubelet(1) << char(179) << "\n";
        cout << "      " << char(179) << cube[2][2][0].Colour_cubelet(1) << ' ' << cube[2][2][1].Colour_cubelet(1) << ' ' << cube[2][2][2].Colour_cubelet(1) << char(179) << "\n";
        cout << "      " << char(192) << char(196) << char(196) << char(196) << char(196) << char(196) << char(217)  << "\n";
    }
    else{
        cout << "View for other cubes that are not 3x3x3 not implemented yet";
    }
}


int print_menu(void)
{
/*  -Task: function that prints the options and wait for the user to choose the next step to do
    -Arguments: none
    -Return: integer with the chosen option*/
	int a = 0;
	do{
		cout << "** Menu. Choose valid number from these options: **\n"
                "\t0.  EXIT\n"
                "\t1.  F:  Turn Front face clockwise\n"
                "\t2.  B:  Turn Back face clockwise\n"
                "\t3.  U:  Turn Up face clockwise\n"
                "\t4.  D:  Turn Down face clockwise\n"
                "\t5.  L:  Turn Left face clockwise\n"
                "\t6.  R:  Turn Right face clockwise\n"
                "\t7.  S:  Turn Standing layer (between F and B) clockwise (viewed from F)\n"
                "\t8.  E:  Turn Equator layer (between U and D) clockwise (viewed from U)\n"
                "\t9.  M:  Turn Middle layer (between L and R) clockwise (viewed from L)\n"
                "\t11. F': Turn Front face counterclockwise\n"
                "\t12. B': Turn Back face counterclockwise\n"
                "\t13. U': Turn Up face counterclockwise\n"
                "\t14. D': Turn Down face counterclockwise\n"
                "\t15. L': Turn Left face counterclockwise\n"
                "\t16. R': Turn Right face counterclockwise\n"
                "\t17. S': Turn Standing layer counterclockwise (viewed from F)\n"
                "\t18. E': Turn Equator layer counterclockwise (viewed from U)\n"
                "\t19. M': Turn Middle layer counterclockwise (viewed from L)\n"
                "\t20. Print explanation of the unrolled flat view.\n"
                "Option you choose?:\t";
		cin >> a;
	}while ( a<0 || a>20 || a==10 );
	return a;
}


void rotate_cube_X (cubelet (*cube)[side_length][side_length], int A, bool clockwise)
{
/*  -Task: rotates any layer perpendicular to axis X (Front, Standing, or Back) clockwise or counterclockwise
    -Arguments:
        -cube to rotate (by ref)
        -layer to rotate: 0 (Front), 1 (Standing), or 2 (Back)
        -rotate clockwise or counterclocwise (clockwise: bool = true)
    -Return: none. Directly change matrix cube by reference.
    Take in special account that the clockwise / counterclockwise orientation
    corresponds to an absolute point of view of axis X looking at Front,
    so if we want to rotate face Back clockwise (when looking at B directly),
    it is in fact a counterclockwise rotation regarding absolute axis X */
    int B,C;
    cubelet side_temp [side_length][side_length];
    if(clockwise==true){     // clockwise rotation and storage into a temp 2D array.
       for (B=0;B<side_length;B++){
            for (C=0;C<side_length;C++){
                side_temp [B][C] = cube[A][side_length-1-C][B];
                side_temp [B][C].Rotate_cubelet(0);
            }
        }
    }
    else{   // counterclockwise rotation and storage into a temp 2D array.
        for (B=0;B<side_length;B++){
            for (C=0;C<side_length;C++){
                side_temp [B][C] = cube[A][C][side_length-1-B];
                side_temp [B][C].Rotate_cubelet(0);
            }
        }

    }
    for (B=0;B<side_length;B++){    //load results storage in temp 2D array into the corresponding layer of the cube
            for (C=0;C<side_length;C++){
                cube[A][B][C] = side_temp [B][C];
            }
    }
}


void rotate_cube_Y (cubelet (*cube)[side_length][side_length], int B, bool clockwise)
{
/*  -Task: rotates any layer perpendicular to axis Y (Up, Equator, or Down) clockwise or counterclockwise
    -Arguments:
        -cube to rotate (by ref)
        -layer to rotate: 0 (Up), 1 (Equator), or 2 (Down)
        -rotate clockwise or counterclocwise (clockwise: bool = true)
    -Return: none. Directly change matrix cube by reference.
    Take in special account that the clockwise / counterclockwise orientation
    corresponds to an absolute point of view of axis Y looking at Up,
    so if we want to rotate face Down clockwise (when looking at D directly),
    it is in fact a counterclockwise rotation regarding absolute axis Y */
    int A,C;
    cubelet side_temp [side_length][side_length];
    if(clockwise==true){     // clockwise rotation and storage into a temp 2D array.
       for (A=0;A<side_length;A++){
            for (C=0;C<side_length;C++){
                side_temp [A][C] = cube[C][B][side_length-1-A];
                side_temp [A][C].Rotate_cubelet(1);
            }
        }
    }
    else{   // counterclockwise rotation and storage into a temp 2D array.
        for (A=0;A<side_length;A++){
            for (C=0;C<side_length;C++){
                side_temp [A][C] = cube[side_length-1-C][B][A];
                side_temp [A][C].Rotate_cubelet(1);
            }
        }

    }
    for (A=0;A<side_length;A++){    //load results storage in temp 2D array into the corresponding layer of the cube
            for (C=0;C<side_length;C++){
                cube[A][B][C] = side_temp [A][C];
            }
    }
}


void rotate_cube_Z (cubelet (*cube)[side_length][side_length], int C, bool clockwise)
{
/*  -Task: rotates any layer perpendicular to axis Z (Left, Middle, or Right) clockwise or counterclockwise
    -Arguments:
        -cube to rotate (by ref)
        -layer to rotate: 0 (Up), 1 (Equator), or 2 (Down)
        -rotate clockwise or counterclocwise (clockwise: bool = true)
    -Return: none. Directly change matrix cube by reference.
    Take in special account that the clockwise / counterclockwise orientation
    corresponds to an absolute point of view of axis Z looking at face Left,
    so if we want to rotate face Right clockwise (when looking at B directly),
    it is in fact a counterclockwise rotation regarding absolute axis Z */
    int A,B;
    cubelet side_temp [side_length][side_length];
    if(clockwise==true){    // clockwise rotation and storage into a temp 2D array.
        for (A=0;A<side_length;A++){
            for (B=0;B<side_length;B++){
                side_temp [A][B] = cube[side_length-1-B][A][C];
                side_temp [A][B].Rotate_cubelet(2);
            }
        }
    }
    else{   // counterclockwise rotation and storage into a temp 2D array.
        for (A=0;A<side_length;A++){
            for (B=0;B<side_length;B++){
                side_temp [A][B] = cube[B][side_length-1-A][C];
                side_temp [A][B].Rotate_cubelet(2);
            }
        }
    }
    for (A=0;A<side_length;A++){    //load results storage in temp 2D array into the corresponding layer of the cube
            for (B=0;B<side_length;B++){
                cube[A][B][C] = side_temp [A][B];
            }
    }
}


bool solved_test (cubelet (*cube)[side_length][side_length])
{
/*  -Task: check if the Rubik's cube has been solved
    -Arguments: present state of the cube, by ref.
    -Return: boolean with true if the cube is solved or false if not*/

    bool solved=true;
    int i,j,k,C;


    //Axis X: Checking the Front and Back faces to see if all elements in each face has the same colour.
    C=0;    //to check the first element of each cubelet which is where the X axis colour is storaged.
    for (i = 0 ; i < side_length ; i+=side_length-1){   //checks 1st and last face perpendicular to axis X.
        for (j = 0 ; j < side_length ; j++){
            for (k = 0 ; k < side_length ; k++){
               if (cube[i][j][k].Colour_cubelet(C) != cube[i][0][0].Colour_cubelet(C)){ //compares colour of each item with the one at [0][0] of that face
                    solved = false;     //the colour is not the same then boolean to FALSE and break
                    break;
               }
            }
            if (solved == false){   //allows to leave the loop earlier in case the "not solved" status has been achieved already.
                break;
            }
        }
        if (solved == false){   //allows to leave the loop earlier in case the "not solved" status has been achieved already.
                break;
            }
    }


    //Axis Y: Checking the Up and Down faces to see if all elements in each face has the same colour.
    if(solved){ //to avoid running this code in case previous faces has already proven that is not solved
        C=1;    //to check the first element of each cubelet which is where the Y axis colour is storaged.
        for (j = 0 ; j < side_length ; j+=side_length-1){   //checks 1st and last face perpendicular to axis Y.
            for (i = 0 ; i < side_length ; i++){
                for (k = 0 ; k < side_length ; k++){
                   if (cube[i][j][k].Colour_cubelet(C) != cube[0][j][0].Colour_cubelet(C)){ //compares colour of each item with the one at [i][0][0] of that face
                        solved = false;     //the colour is not the same then boolean to FALSE and break
                        break;
                   }
                }
                if (solved == false){   //allows to leave the loop earlier in case the "not solved" status has been achieved already.
                    break;
                }
            }
            if (solved == false){   //allows to leave the loop earlier in case the "not solved" status has been achieved already.
                    break;
                }
        }
    }


    //Axis Z: Checking the Left and Right faces to see if all elements in each face has the same colour.
    if(solved){  //to avoid running this code in case previous faces has already proven that is not solved
        C=2;    //to check the first element of each cubelet which is where the Z axis colour is storaged.
        for (k = 0 ; k < side_length ; k+=side_length-1){   //checks 1st and last face perpendicular to axis Z.
            for (i = 0 ; i < side_length ; i++){
                for (j = 0 ; j < side_length ; j++){
                   if (cube[i][j][k].Colour_cubelet(C) != cube[0][0][k].Colour_cubelet(C)){ //compares colour of each item with the one at [0][0][k] of that face
                        solved = false;     //the colour is not the same then boolean to FALSE and break
                        break;
                   }
                }
                if (solved == false){   //allows to leave the loop earlier in case the "not solved" status has been achieved already.
                    break;
                }
            }
            if (solved == false){   //allows to leave the loop earlier in case the "not solved" status has been achieved already.
                    break;
                }
        }
    }

    if(solved){
        cout << "\t---Cube is SOLVED---\n\n";
    }
    else{
        cout << "\t---The cube is still unsolved---\n\n";
    }
    return solved;
}
