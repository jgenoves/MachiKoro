//
// Created by Joshua Newton on 2019-03-13.
//

#ifndef CS205FINAL_GRAPHICS_H
#define CS205FINAL_GRAPHICS_H

#include <stdlib.h>
#include "Player.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Program initialization NOT OpenGL/GLUT dependent,
// as we haven't created a GLUT window yet
void init(void);

// Initialize OpenGL Graphics
void initGL(void);

//Draw text, takes rgb and xy with a message
void drawText24(string message, float r, float g, float b, double x, double y);
void drawText18(string message, float r, float g, float b, double x, double y);
void drawText10(string message, float r, float g, float b, double x, double y);

void drawMarket();

void drawPlayerInventory();

void drawPlayerButtons();

void displayStart();

void displayGame();

// Callback functions for GLUT */


// Draw the window - this is where all the GL actions are
void display(void);

// Trap and process alphanumeric keyboard events
void kbd(unsigned char key, int x, int y);

// Trap and process special keyboard events
void kbdS(int key, int x, int y);

// Handle "mouse cursor moved" events
void cursor(int x, int y);

// Calls itself after a specified time
void timer(int extra);

void resize(int width, int height);

// Handle mouse button pressed and released events
void mouse(int button, int state, int x, int y);

int graphicsPlay(int argc, char *argv[]);


#endif //CS205FINAL_GRAPHICS_H
