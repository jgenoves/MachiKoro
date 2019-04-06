//
// Created by Joshua Newton on 2019-03-13.
//
// Co-Creator: Jordan Genovese

#include "graphics.h"
#include "graphicsConstants.h"

GLdouble width, height;
int wd;

struct GameData {
    Player currentPlayer;
    vector<Player> players;
    bool gameOver = false;
    int dice1Roll = 0;
    int dice2Roll = 0;

}Game;

void init() {
    width = WIDTH;
    height = HEIGHT;

}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    /*
     * Draw here
     */

    if (screen == start){

        startButton.draw();
        string message = "Start Game";
        glColor3f(1, 1, 1);
        glRasterPos2i(startButton.getX() + 25, startButton.getY() + 45);
        for (int i = 0; i < message.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
        }

        exitButton.draw();
        message = "Exit Game";
        glColor3f(1, 1, 1);
        glRasterPos2i(exitButton.getX() + 25, exitButton.getY() + 45);
        for (int i = 0; i < message.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
        }
    }
    if (screen == game){
        mainMenuButton.draw();
        string message = "Main Menu";
        glColor3f(1, 1, 1);
        glRasterPos2i(mainMenuButton.getX() + 25, mainMenuButton.getY() + 45);
        for (int i = 0; i < message.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
        }

        wheatFieldButton.draw();
        message = "Wheat Field";
        glColor3f(1, 1, 1);
        glRasterPos2i(wheatFieldButton.getX() + 10, wheatFieldButton.getY() + 20);
        for (int i = 0; i < message.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
        }

        ranchButton.draw();
        bakeryButton.draw();
        cafeButton.draw();
        convenienceStoreButton.draw();
        forestButton.draw();
        tvStationButton.draw();
        stadiumButton.draw();
        bussinessCenterButton.draw();
        cheeseFactoryButton.draw();
        furnitureFactoryButton.draw();
        mineButton.draw();
        familyRestaurantButton.draw();
        appleOrchardButton.draw();
        fruitAndVegetableMarketButton.draw();

        rollDieButton.draw();
        string dieMessage = "Roll";
        glColor3f(1, 1, 1);
        glRasterPos2i(rollDieButton.getX() + 10, rollDieButton.getY() + 20);
        for (int i = 0; i < dieMessage.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, dieMessage[i]);
        }

        Player player1 = Player(3);
        Player player2 = Player(3);

        Game.currentPlayer = player1;

    }
    if (screen == endGame){
        // Draw stuff
    }
    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    glutPostRedisplay();

    return;
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:

            break;
        case GLUT_KEY_LEFT:

            break;
        case GLUT_KEY_RIGHT:

            break;
        case GLUT_KEY_UP:

            break;
    }

    glutPostRedisplay();

    return;
}

void cursor(int x, int y) {
    if (screen == start){
        if (startButton.isOverlapping(x,y)){
            startButton.setFill(BUTTON_HOVER_COLOR);
        }
        else {
            startButton.setFill(BUTTON_COLOR);
        }
        if (exitButton.isOverlapping(x,y)){
            exitButton.setFill(BUTTON_HOVER_COLOR);
        }
        else {
            exitButton.setFill(BUTTON_COLOR);
        }
    }
    else if (screen == game){
        if (mainMenuButton.isOverlapping(x,y)){
            mainMenuButton.setFill(BUTTON_HOVER_COLOR);
        }
        else {
            mainMenuButton.setFill(BUTTON_COLOR);
        }

        if (rollDieButton.isOverlapping(x,y)){
            rollDieButton.setFill(ROLL_BUTTON_HOVER);
        }
        else {
            rollDieButton.setFill(ROLL_BUTTON_COLOR);
        }
    }
    else if (screen == endGame){

    }

    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {

    if (screen == start){
        if (startButton.isOverlapping(x,y) && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            screen = game;
        }
        else if (exitButton.isOverlapping(x,y) && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            glutDestroyWindow(wd);
            exit(0);
        }

    }
    else if (screen == game){
        if (mainMenuButton.isOverlapping(x,y) && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            screen = start;
        }
        else if (rollDieButton.isOverlapping(x,y) && button == GLUT_LEFT_BUTTON && state == GLUT_UP){

            Game.dice1Roll = rand() % (6 - 1 + 1) + 1;
            string dieMessage;

            if(Game.dice1Roll == 1){
                string dieMessage = "1";
            }
            else if(Game.dice1Roll == 2){
                string dieMessage = "2";
            }
            else if(Game.dice1Roll == 3){
                string dieMessage = "3";
            }
            else if(Game.dice1Roll == 4){
                string dieMessage = "4";
            }
            else if(Game.dice1Roll == 5){
                string dieMessage = "5";
            }
            else if(Game.dice1Roll == 6){
                string dieMessage = "6";
            }

            glColor3f(0, 0, 0);
            glRasterPos2i(rollDieButton.getX() + 10, rollDieButton.getY() + 20);
            for (int i = 0; i < dieMessage.length(); ++i) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, dieMessage[i]);
            }

            glutPostRedisplay();

        }
    }
    else if (screen == endGame){

    }

    glutPostRedisplay();
}

void timer(int extra) {

    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}

/* Main function: GLUT runs as a console application starting at main()  */
int graphicsPlay(int argc, char** argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(0, 0); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Machi Koro" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}

