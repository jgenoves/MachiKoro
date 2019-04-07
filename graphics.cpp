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
    int currentPlayerIndex = 0;
    vector<Player> players;
    int numOfPlayers = 0;
    bool gameOver = false;
    int dice1Roll = 0;
    int dice2Roll = 0;
    int diceSum = 0;
    bool diceRolled = false;
    bool gameBegin = true;
    bool cardPhase = false;

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

void drawText(string message, float r, float g, float b, double x, double y){
    glColor3f(r, g, b);
    glRasterPos2d(x, y);
    for (int i = 0; i < message.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
}

void displayStart(){

    startButton.draw();
    string message = "Start Game";
    drawText(message, 1, 1, 1, startButton.getX() + 25, startButton.getY() + 45);

    exitButton.draw();
    message = "Exit Game";
    drawText(message, 1, 1, 1, exitButton.getX() + 25, exitButton.getY() + 45);


}

void displayGame(){
    mainMenuButton.draw();
    string message = "Main Menu";
    drawText(message, 1, 1, 1, mainMenuButton.getX() + 25, mainMenuButton.getY() + 45);

    wheatFieldButton.draw();
    message = "Wheat Field";
    drawText(message, 1, 1, 1, wheatFieldButton.getX() + 10, wheatFieldButton.getY() + 20);

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


    if(Game.gameBegin){
        Player player1 = Player(3);
        Player player2 = Player(3);


        shared_ptr<WheatField> wheat_field_card = make_shared<WheatField>(
              WheatField()
        );

        wheat_field_card->setName(WHEAT_FIELD_NAME);
        wheat_field_card->setCost(WHEAT_FIELD_COST);
        wheat_field_card->setActivation(WHEAT_FIELD_RANGE);
        wheat_field_card->setCardType(WHEAT_FIELD_TYPE);
        wheat_field_card->setDescription(WHEAT_FIELD_DESCRIPTION);
        wheat_field_card->setCardSymbol(WHEAT_FIELD_SYMBOL);

        shared_ptr<Bakery> bakery_card = make_shared<Bakery>(
                Bakery()
        );

        bakery_card->setName(BAKERY_NAME);
        bakery_card->setCost(BAKERY_COST);
        bakery_card->setActivation(BAKERY_RANGE);
        bakery_card->setCardType(BAKERY_TYPE);
        bakery_card->setDescription(BAKERY_DESCRIPTION);
        bakery_card->setCardSymbol(BAKERY_SYMBOL);

        Game.players.push_back(player1);
        Game.players.push_back(player2);

        Game.numOfPlayers = Game.players.size();

        for(Player player : Game.players){
            player.addEstablishment(wheat_field_card);
            player.addEstablishment(bakery_card);
        }

        Game.currentPlayer = player1;

        Game.gameBegin = false;
    }

    if(turnPhase == roll){
        rollDieButton.draw();
        string dieMessage = "Roll";
        drawText(dieMessage, 0, 0, 0, rollDieButton.getX() + 10, rollDieButton.getY() + 20);
        if(Game.diceRolled){
            turnPhase = distribution;
            Game.diceRolled = false;
        }
    }
    else if (turnPhase == distribution){

        rollDieButton.draw();
        drawText(to_string(Game.dice1Roll), 0, 0, 0, rollDieButton.getX() + 30, rollDieButton.getY() + 35);

        Game.cardPhase = true;

        while(Game.cardPhase){

            bool redPhase = true;

            while(redPhase){
                for(int i = 0; i < Game.numOfPlayers - 1; ++i){
                    switch(Game.numOfPlayers){
                        case(2):
                            Player player;
                            switch(Game.currentPlayerIndex){
                                case(0):
                                    player = Game.players[1];
                                    for(shared_ptr<Card> card : player.getEstablishments()){
                                        if(card->getCardColor() == r && card->getActivationMin() <= Game.diceSum <= card->getActivationMax()){
                                            card->activate(player, Game.players, Game.currentPlayer );
                                        }
                                    }
                                    break;
                                case(1):
                                    player = Game.players[0];
                                    for(shared_ptr<Card> card : player.getEstablishments()){
                                        if(card->getCardColor() == r && card->getActivationMin() <= Game.diceSum <= card->getActivationMax()){
                                            card->activate(player, Game.players, Game.currentPlayer );
                                        }
                                    }

                                    break;
                            }
                            break;
                        }

                    }
                }
            }


            for(Player player : Game.players){
                for(shared_ptr<Card> card : player.getEstablishments()){
                    if((card->getCardColor() == g || card->getCardColor() == b) && card->getActivationMin() <= Game.diceSum <= card->getActivationMax()){
                        card->activate(player, Game.players, Game.currentPlayer );
                    }
                }
            }

            for(Player player : Game.players){
                for(shared_ptr<Card> card : player.getEstablishments()){
                    if(card->getCardColor() == p && card->getActivationMin() <= Game.diceSum <= card->getActivationMax()){
                        card->activate(player, Game.players, Game.currentPlayer );
                    }
                }
            }

            Game.cardPhase = false;
        }


        Game.dice1Roll = 0;
        Game.dice2Roll = 0;
        Game.diceSum = 0;

        turnPhase = buy;

    } else if(turnPhase = buy){

        turnPhase = endturn;

    }else if(turnPhase == endturn){

        //This needs to be implemented based upon how many players are playing the game, current set up for two players.
        if(Game.players.size() == 2 && Game.currentPlayerIndex == 1){
            Game.currentPlayer = Game.players[0];
        }else {
            Game.currentPlayer = Game.players[Game.currentPlayerIndex + 1];
        }

        turnPhase = roll;

    }


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
        displayStart();
    }
    if (screen == game){
       displayGame();

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
        else if (rollDieButton.isOverlapping(x,y) && button == GLUT_LEFT_BUTTON && state == GLUT_UP && Game.diceRolled == false){
            Game.dice1Roll = rand() % (6 - 1 + 1) + 1;
            Game.diceRolled = true;
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

