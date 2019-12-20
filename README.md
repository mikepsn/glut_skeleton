# glut_skeleton
Skeleton code for an OpenGL GLUT application.

This was first written in February 2001

# Compiling on Raspbery Pi

I tried to compile this simpme (old) OpenGL program on a Raspberry Pi 2 (Model B) running Raspian (Jesse).

The Pi supports OpenGL ES - this on the other hand is written in very old OpenGL with GLUT. 
GLUT or freeglut isn't installed out of the box but can be installed using:

    sudo apt-get install freeglut3-dev g++
    
This allowed the program to compile and run. 

# On Linux

Make sure you have the glut library installed. I believe the correct one is freeglut.
On Kubuntu you can do the following:

    sudo apt-cache search freeglut

    sudo apt-get install freeglut3-dev

Type the following to see what freeglut3-dev has installed:

    dpkg -L freeglut3-dev