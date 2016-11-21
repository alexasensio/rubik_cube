# rubik_cube
A simple implementation of the data structure of a Rubik's cube in C++. Written using Code::Blocks.

Features:

-The game starts with a solved cube and allows the user all the possible movements.

-It also checks if the cube has been solved after each movement.

Drawbacks: No 3D representation since it only uses the console to display, so the only implemented way to visually check the state of the cube is with a view in 2D of the cube unrolled. Also no colour implemented in the visualizations since the intention was to make it OS independent.

Future steps:

-The present state of the API works with a 3x3x3 cube but the dimesions can be changed easily inside the code to do a 4x4x4 or NxNxN cube. Most functions would work. The only thing that would need to change is the way the 2D unrolled view is printed in console and also to upgrade the options in the menu in order to allow for rotations in the added layers of the cube.

-No solver implemented at all.
