//
// Created by Joshua Newton on 2019-03-13.
//
// Co-Creator: Jordan Genovese

#include "graphics.h"
#include "graphicsConstants.h"
#include "Image.h"


GLdouble width, height;
int wd;

Image i("cardTwo.BMP");

//Function Declarations

void init() {
    width = WIDTH;
    height = HEIGHT;

    initializeGame(2);

    for(shared_ptr<Card> card : Game.currentPlayer.getEstablishments()){
        cout << card->getName() << endl;
    }
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void drawText24(string message, float r, float g, float b, double x, double y){
    glColor3f(r, g, b);
    glRasterPos2d(x, y);
    for (int i = 0; i < message.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
}


void drawText18(string message, float r, float g, float b, double x, double y){
    glColor3f(r, g, b);
    glRasterPos2d(x, y);
    for (int i = 0; i < message.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i]);
    }
}

void drawText10(string message, float r, float g, float b, double x, double y){
    glColor3f(r, g, b);
    glRasterPos2d(x, y);
    for (int i = 0; i < message.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, message[i]);
    }
}

void drawMarket(){

    wheatFieldButton.draw();
    string message = "Wheat Field";
    drawText24(message, 1, 1, 1, wheatFieldButton.getX() + 10, wheatFieldButton.getY() + 30);

    ranchButton.draw();
    message = "Ranch";
    drawText24(message, 1, 1, 1, ranchButton.getX() + 10, ranchButton.getY() + 30);

    bakeryButton.draw();
    message = "Bakery";
    drawText24(message, 1, 1, 1, bakeryButton.getX() + 10, bakeryButton.getY() + 30);

    cafeButton.draw();
    message = "Cafe";
    drawText24(message, 1, 1, 1, cafeButton.getX() + 10, cafeButton.getY() + 30);

    convenienceStoreButton.draw();
    message = "Convenience Store";
    drawText24(message, 1, 1, 1, convenienceStoreButton.getX() + 10, convenienceStoreButton.getY() + 30);

    forestButton.draw();
    message = "Forest";
    drawText24(message, 1, 1, 1, forestButton.getX() + 10, forestButton.getY() + 30);

    tvStationButton.draw();
    message = "TV Station";
    drawText24(message, 1, 1, 1, tvStationButton.getX() + 10, tvStationButton.getY() + 30);

    stadiumButton.draw();
    message = "Stadium";
    drawText24(message, 1, 1, 1, stadiumButton.getX() + 10, stadiumButton.getY() + 30);

    bussinessCenterButton.draw();
    message = "Bussiness Center";
    drawText24(message, 1, 1, 1, bussinessCenterButton.getX() + 10, bussinessCenterButton.getY() + 30);

    cheeseFactoryButton.draw();
    message = "Cheese Factory";
    drawText24(message, 1, 1, 1, cheeseFactoryButton.getX() + 10, cheeseFactoryButton.getY() + 30);

    furnitureFactoryButton.draw();
    message = "Furniture Factory";
    drawText24(message, 1, 1, 1, furnitureFactoryButton.getX() + 10, furnitureFactoryButton.getY() + 30);

    mineButton.draw();
    message = "Mine";
    drawText24(message, 1, 1, 1, mineButton.getX() + 10, mineButton.getY() + 30);

    familyRestaurantButton.draw();
    message = "Family Restaurant";
    drawText24(message, 1, 1, 1, familyRestaurantButton.getX() + 10, familyRestaurantButton.getY() + 30);

    appleOrchardButton.draw();
    message = "Apple Orchard";
    drawText24(message, 1, 1, 1, appleOrchardButton.getX() + 10, appleOrchardButton.getY() + 30);

    fruitAndVegetableMarketButton.draw();
    message = "Fruit and Vegetable Market";
    drawText24(message, 1, 1, 1, fruitAndVegetableMarketButton.getX() + 10, fruitAndVegetableMarketButton.getY() + 30);

}

void drawPlayerInventory(){
    moneySlot.draw();
    string message = "Money";
    drawText18(message, 1, 1, 1, moneySlot.getX() + 10, moneySlot.getY() + 20);
    message = to_string(Game.currentPlayer.getMoney());
    drawText18(message, 1, 1, 1, moneySlot.getX() + (moneySlot.getBase() - 30), moneySlot.getY() + 20);

    wheatFieldSlot.draw();
    message = "Wheat Field";
    drawText18(message, 1, 1, 1, wheatFieldSlot.getX() + 10, wheatFieldSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(WHEAT_FIELD_NAME));
    drawText18(message, 1, 1, 1, wheatFieldSlot.getX() + (wheatFieldSlot.getBase() - 30), wheatFieldSlot.getY() + 20);

    ranchSlot.draw();
    message = "Ranch";
    drawText18(message, 1, 1, 1, ranchSlot.getX() + 10, ranchSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(RANCH_NAME));
    drawText18(message, 1, 1, 1, ranchSlot.getX() + (ranchSlot.getBase() - 30), ranchSlot.getY() + 20);

    bakerySlot.draw();
    message = "Bakery";
    drawText18(message, 1, 1, 1, bakerySlot.getX() + 10, bakerySlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(BAKERY_NAME));
    drawText18(message, 1, 1, 1, bakerySlot.getX() + (bakerySlot.getBase() - 30), bakerySlot.getY() + 20);

    cafeSlot.draw();
    message = "Cafe";
    drawText18(message, 1, 1, 1, cafeSlot.getX() + 10, cafeSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(CAFE_NAME));
    drawText18(message, 1, 1, 1, cafeSlot.getX() + (cafeSlot.getBase() - 30), cafeSlot.getY() + 20);

    convenienceStoreSlot.draw();
    message = "Convenience Store";
    drawText18(message, 1, 1, 1, convenienceStoreSlot.getX() + 10, convenienceStoreSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(CONVENIENCE_STORE_NAME));
    drawText18(message, 1, 1, 1, convenienceStoreSlot.getX() + (convenienceStoreSlot.getBase() - 30), convenienceStoreSlot.getY() + 20);

    forestSlot.draw();
    message = "Forest";
    drawText18(message, 1, 1, 1, forestSlot.getX() + 10, forestSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(FOREST_NAME));
    drawText18(message, 1, 1, 1, forestSlot.getX() + (forestSlot.getBase() - 30), forestSlot.getY() + 20);

    tvStationSlot.draw();
    message = "TV Station";
    drawText18(message, 1, 1, 1, tvStationSlot.getX() + 10, tvStationSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(TV_STATION_NAME));
    drawText18(message, 1, 1, 1, tvStationSlot.getX() + (tvStationSlot.getBase() - 30), tvStationSlot.getY() + 20);

    stadiumSlot.draw();
    message = "Stadium";
    drawText18(message, 1, 1, 1, stadiumSlot.getX() + 10, stadiumSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(STADIUM_NAME));
    drawText18(message, 1, 1, 1, stadiumSlot.getX() + (stadiumSlot.getBase() - 30), stadiumSlot.getY() + 20);

    bussinessCenterSlot.draw();
    message = "Bussiness Center";
    drawText18(message, 1, 1, 1, bussinessCenterSlot.getX() + 10, bussinessCenterSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(BUSSINESS_CENTER_NAME));
    drawText18(message, 1, 1, 1, bussinessCenterSlot.getX() + (bussinessCenterSlot.getBase() - 30), bussinessCenterSlot.getY() + 20);

    cheeseFactorySlot.draw();
    message = "Cheese Factory";
    drawText18(message, 1, 1, 1, cheeseFactorySlot.getX() + 10, cheeseFactorySlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(CHEESE_FACTORY_NAME));
    drawText18(message, 1, 1, 1, cheeseFactorySlot.getX() + (cheeseFactorySlot.getBase() - 30), cheeseFactorySlot.getY() + 20);

    furnitureFactorySlot.draw();
    message = "Furniture Factory";
    drawText18(message, 1, 1, 1, furnitureFactorySlot.getX() + 10, furnitureFactorySlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(FURNITURE_FACTORY_NAME));
    drawText18(message, 1, 1, 1, furnitureFactorySlot.getX() + (furnitureFactorySlot.getBase() - 30), furnitureFactorySlot.getY() + 20);

    mineSlot.draw();
    message = "Mine";
    drawText18(message, 1, 1, 1, mineSlot.getX() + 10, mineSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(MINE_NAME));
    drawText18(message, 1, 1, 1, mineSlot.getX() + (mineSlot.getBase() - 30), mineSlot.getY() + 20);

    familyRestaurantSlot.draw();
    message = "Family Restaurant";
    drawText18(message, 1, 1, 1, familyRestaurantSlot.getX() + 10, familyRestaurantSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(FAMILY_RESTAURANT_NAME));
    drawText18(message, 1, 1, 1, familyRestaurantSlot.getX() + (familyRestaurantSlot.getBase() - 30), familyRestaurantSlot.getY() + 20);

    appleOrchardSlot.draw();
    message = "Apple Orchard";
    drawText18(message, 1, 1, 1, appleOrchardSlot.getX() + 10, appleOrchardSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(APPLE_ORCHARD_NAME));
    drawText18(message, 1, 1, 1, appleOrchardSlot.getX() + (appleOrchardSlot.getBase() - 30), appleOrchardSlot.getY() + 20);

    fruitAndVegetableMarketSlot.draw();
    message = "Fruit and Vegetable Market";
    drawText18(message, 1, 1, 1, fruitAndVegetableMarketSlot.getX() + 10, fruitAndVegetableMarketSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(FRUIT_AND_VEGETABLE_MARKET_NAME));
    drawText18(message, 1, 1, 1, fruitAndVegetableMarketSlot.getX() + (fruitAndVegetableMarketSlot.getBase() - 30), fruitAndVegetableMarketSlot.getY() + 20);

    trainStationSlot.draw();
    message = "Train Station";
    drawText18(message, 1, 1, 1, trainStationSlot.getX() + 10, trainStationSlot.getY() + 20);

    shoppingMallSlot.draw();
    message = "Shopping Mall";
    drawText18(message, 1, 1, 1, shoppingMallSlot.getX() + 10, shoppingMallSlot.getY() + 20);

    amusementParkSlot.draw();
    message = "Amusement Park";
    drawText18(message, 1, 1, 1, amusementParkSlot.getX() + 10, amusementParkSlot.getY() + 20);

    radioTowerSlot.draw();
    message = "Radio Tower";
    drawText18(message, 1, 1, 1, radioTowerSlot.getX() + 10, radioTowerSlot.getY() + 20);

}

void drawPlayerButtons(){

    player1button.draw();
    string message = "Player 1";
    drawText24(message, 1, 1, 1, player1button.getX() + 25, player1button.getY() + 45);

    player2button.draw();
    message = "Player 2";
    drawText24(message, 1, 1, 1, player2button.getX() + 25, player2button.getY() + 45);

}


void displayStart(){

    startButton.draw();
    string message = "Start Game";
    drawText24(message, 1, 1, 1, startButton.getX() + 25, startButton.getY() + 45);

    exitButton.draw();
    message = "Exit Game";
    drawText24(message, 1, 1, 1, exitButton.getX() + 25, exitButton.getY() + 45);


}

void displayGame(){


    mainMenuButton.draw();
    string message = "Main Menu";
    drawText24(message, 1, 1, 1, mainMenuButton.getX() + 25, mainMenuButton.getY() + 45);

    drawMarket();
    rollDieButton.draw();
    drawPlayerInventory();
    drawPlayerButtons();

    if(Game.turnPhase == roll){

        //TODO implement pre roll (2 die roll) and post roll (reroll)
        rollDieButton.draw();
        string dieMessage = "Roll";
        drawText24(dieMessage, 0, 0, 0, rollDieButton.getX() + 10, rollDieButton.getY() + 20);
        if(Game.diceRolled){
            Game.turnPhase = distribution;
            Game.diceRolled = false;
        }
    }else if (Game.turnPhase == distribution){


        drawText24(to_string(Game.dice1Roll), 0, 0, 0, rollDieButton.getX() + 30, rollDieButton.getY() + 35);


        //Red/restaurant cards need to be activated in a counter clockwise fashion. This implementation does that for 2 players right now
        //Perhaps there is a more efficient way to do this.
        switch (Game.numOfPlayers) {

            //Case 1: 2 player game
            case (2):
                Player player;
                switch (Game.currentPlayerIndex) {

                    //Activate red cards for player2 on player1's roll
                    case (0):
                        player = Game.players[1];
                        for (shared_ptr<Card> card : player.getEstablishments()) {
                            if (card->getCardType() == restaurant && card->getActivationMin() <= Game.diceSum <= card->getActivationMax()) {
                                card->activate(player, Game.players, Game.currentPlayer);
                            }
                        }
                        break;

                    //Activate red cards for player1 on player2's roll
                    case (1):
                        player = Game.players[0];
                        for (shared_ptr<Card> card : player.getEstablishments()) {
                            if (card->getCardType() == restaurant && card->getActivationMin() <= Game.diceSum <= card->getActivationMax()) {
                                card->activate(player, Game.players, Game.currentPlayer);
                            }
                        }

                        break;
                }
                break;


        }


        //Activate all blue/primaryIndustry cards across the board
        for (Player player : Game.players) {
            for (shared_ptr<Card> card : player.getEstablishments()) {
                if (card->getCardType() == primaryIndustry && card->getActivationMin() <= Game.diceSum <= card->getActivationMax()) {
                    card->activate(player, Game.players, Game.currentPlayer);
                }
            }
        }


        //Activate currentPlayers green/secondary industry cards and purple/majorEstablishment cards
        for (shared_ptr<Card> card : Game.currentPlayer.getEstablishments()) {
            if ((card->getCardType() == majorEstablishment || card->getCardType() == secondaryIndustry) && card->getActivationMin() <= Game.diceSum <= card->getActivationMax()) {
                card->activate(Game.currentPlayer, Game.players, Game.currentPlayer);
            }
        }



        Game.turnPhase = buy;

    } else if(Game.turnPhase == buy){

        drawText24(to_string(Game.dice1Roll), 0, 0, 0, rollDieButton.getX() + 30, rollDieButton.getY() + 35);


        //TODO implement buying of cards

        if(Game.boughtCard) {
            cout << "card bought" << endl;
            Game.turnPhase = endturn;
            Game.boughtCard = false;
        }

    }else if(Game.turnPhase == endturn){

        cout << "end turn phase" << endl;

        //This needs to be implemented based upon how many players are playing the game, current set up for two players.
        if(Game.numOfPlayers == 2 && Game.currentPlayerIndex == 1){
            Game.currentPlayer = Game.players[0];
            Game.currentPlayerIndex = 0;
        }else {
            Game.currentPlayer = Game.players[Game.currentPlayerIndex + 1];
            Game.currentPlayerIndex++;

        }


        //Reset dice roll and dice sum values
        Game.dice1Roll = 0;
        Game.dice2Roll = 0;
        Game.diceSum = 0;

        Game.turnPhase = roll;

    }


}


void initializePlayers(int numOfPlayers){

    Player player1 = Player(3);
    Player player2 = Player(3);


    Game.players.push_back(player1);
    Game.players.push_back(player2);

    Game.numOfPlayers = numOfPlayers;


    for(Player player : Game.players){
        player.addEstablishment(make_shared<WheatField>(WheatField(WHEAT_FIELD_DESCRIPTION, WHEAT_FIELD_COST, WHEAT_FIELD_RANGE, WHEAT_FIELD_TYPE, blueCardRectangle, WHEAT_FIELD_NAME, WHEAT_FIELD_SYMBOL)));
        player.addEstablishment(make_shared<Bakery>(Bakery(BAKERY_DESCRIPTION, BAKERY_COST, BAKERY_RANGE, BAKERY_TYPE, greenCardRectangle, BAKERY_NAME, BAKERY_SYMBOL)));
    }

    Game.currentPlayer = player1;


}

void initializeGame(int numOfPlayers){

    initializePlayers(numOfPlayers);

    Game.gameBegin = false;

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

    i.draw();

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
//    cout << x << "," << y << "\n";

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

        if (wheatFieldButton.isOverlapping(x,y)){
            wheatFieldButton.setFill(CARD_BUTTON_HOVER_COLOR);
        }
        else {
            wheatFieldButton.setFill(BLUE_CARD_COLOR);
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
        else if (rollDieButton.isOverlapping(x,y) && button == GLUT_LEFT_BUTTON && state == GLUT_UP && !Game.diceRolled && Game.turnPhase == roll){
            Game.dice1Roll = rand() % (6 - 1 + 1) + 1;
            Game.diceRolled = true;
        }
        else if(wheatFieldButton.isOverlapping(x, y) && button == GLUT_LEFT_BUTTON && state == GLUT_UP && !Game.boughtCard && numOfWheatField != 0 && Game.turnPhase == buy){

            Game.currentPlayer.addEstablishment(make_shared<WheatField>(WheatField(WHEAT_FIELD_DESCRIPTION, WHEAT_FIELD_COST, WHEAT_FIELD_RANGE, WHEAT_FIELD_TYPE, blueCardRectangle, WHEAT_FIELD_NAME, WHEAT_FIELD_SYMBOL)));
            numOfWheatField--;
            Game.boughtCard = true;
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

void resize(int width, int height){
    glutReshapeWindow(WIDTH, HEIGHT);
    glutPostRedisplay();
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

    glutReshapeFunc(resize);

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

