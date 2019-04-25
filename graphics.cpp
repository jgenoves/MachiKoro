//
// Created by Joshua Newton on 2019-03-13.
//
// Co-Creator: Jordan Genovese

#include "graphics.h"
#include "graphicsConstants.h"
#include <thread>
#include <chrono>
#include "Image.h"


GLdouble width, height;
int wd;

Image* cardImage = &wheatFieldFile;
//Function Declarations

void init() {
//    Player player3(50);
//    Player player4(80);
//
//    player3.addEstablishment(make_shared<WheatField>(WheatField(WHEAT_FIELD_DESCRIPTION, WHEAT_FIELD_COST, WHEAT_FIELD_RANGE, WHEAT_FIELD_TYPE, blueCardRectangle, WHEAT_FIELD_NAME, WHEAT_FIELD_SYMBOL)));
//    player3.addEstablishment(make_shared<Bakery>(Bakery(BAKERY_DESCRIPTION, BAKERY_COST, BAKERY_RANGE, BAKERY_TYPE, greenCardRectangle, BAKERY_NAME, BAKERY_SYMBOL)));
//
//    player4.addEstablishment(make_shared<WheatField>(WheatField(WHEAT_FIELD_DESCRIPTION, WHEAT_FIELD_COST, WHEAT_FIELD_RANGE, WHEAT_FIELD_TYPE, blueCardRectangle, WHEAT_FIELD_NAME, WHEAT_FIELD_SYMBOL)));
//    player4.addEstablishment(make_shared<Bakery>(Bakery(BAKERY_DESCRIPTION, BAKERY_COST, BAKERY_RANGE, BAKERY_TYPE, greenCardRectangle, BAKERY_NAME, BAKERY_SYMBOL)));
//
//    vector<Player> somePlayers;
//    somePlayers.push_back(player3);
//    somePlayers.push_back(player4);
//
//    player3.getEstablishments()[0]->activate(player3, somePlayers, player3);
//    cout << "Player 3 Money: " << player3.getMoney() << "\n";

//    cout << "wheat field min: " << WHEAT_FIELD_RANGE.minimum << "\n";
    width = WIDTH;
    height = HEIGHT;

    // Example of working inventory
    Player player1 = Player(STARTING_MONEY);
    Player player2 = Player(STARTING_MONEY);


    Game.players.push_back(player1);
    Game.players.push_back(player2);

    Game.players[0].setHuman(true);
    Game.players[1].setHuman(false);

    Game.players[0].addEstablishment(make_shared<WheatField>(WheatField(WHEAT_FIELD_DESCRIPTION, WHEAT_FIELD_COST, WHEAT_FIELD_RANGE, WHEAT_FIELD_TYPE, blueCardRectangle, WHEAT_FIELD_NAME, WHEAT_FIELD_SYMBOL)));
    Game.players[0].addEstablishment(make_shared<Bakery>(Bakery(BAKERY_DESCRIPTION, BAKERY_COST, BAKERY_RANGE, BAKERY_TYPE, greenCardRectangle, BAKERY_NAME, BAKERY_SYMBOL)));

    Game.players[1].addEstablishment(make_shared<WheatField>(WheatField(WHEAT_FIELD_DESCRIPTION, WHEAT_FIELD_COST, WHEAT_FIELD_RANGE, WHEAT_FIELD_TYPE, blueCardRectangle, WHEAT_FIELD_NAME, WHEAT_FIELD_SYMBOL)));
    Game.players[1].addEstablishment(make_shared<Bakery>(Bakery(BAKERY_DESCRIPTION, BAKERY_COST, BAKERY_RANGE, BAKERY_TYPE, greenCardRectangle, BAKERY_NAME, BAKERY_SYMBOL)));

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

void resetGame(){
    for (int i = 0; i < Game.players.size(); i++){
        Game.players[i].getEstablishments().clear();
    }
    Game.players.clear();

    bool human = true;
    Player player1 = Player(STARTING_MONEY, human);
    Player player2 = Player(STARTING_MONEY, human);

    Game.players.push_back(player1);
    Game.players.push_back(player2);

    Game.players[0].addEstablishment(make_shared<WheatField>(WheatField(WHEAT_FIELD_DESCRIPTION, WHEAT_FIELD_COST, WHEAT_FIELD_RANGE, WHEAT_FIELD_TYPE, blueCardRectangle, WHEAT_FIELD_NAME, WHEAT_FIELD_SYMBOL)));
    Game.players[0].addEstablishment(make_shared<Bakery>(Bakery(BAKERY_DESCRIPTION, BAKERY_COST, BAKERY_RANGE, BAKERY_TYPE, greenCardRectangle, BAKERY_NAME, BAKERY_SYMBOL)));

    Game.players[1].addEstablishment(make_shared<WheatField>(WheatField(WHEAT_FIELD_DESCRIPTION, WHEAT_FIELD_COST, WHEAT_FIELD_RANGE, WHEAT_FIELD_TYPE, blueCardRectangle, WHEAT_FIELD_NAME, WHEAT_FIELD_SYMBOL)));
    Game.players[1].addEstablishment(make_shared<Bakery>(Bakery(BAKERY_DESCRIPTION, BAKERY_COST, BAKERY_RANGE, BAKERY_TYPE, greenCardRectangle, BAKERY_NAME, BAKERY_SYMBOL)));

    Game.currentPlayerIndex = 0;
    Game.focusedPlayerIndex = 0;
    Game.numOfPlayers = 2;
    Game.gameOver = false;
    Game.dice1Roll = 0;
    Game.dice2Roll = 0;
    Game.diceSum = 0;
    Game.diceRolled = false;
    Game.turnPhase = roll;
    Game.boughtCard = false;
    Game.skipRadioTower = false;
    Game.skipBusinessCenter = true;
    Game.skipTVStation = true;
    Game.businessCenterUsed = false;
    Game.tvStationUsed = false;

    numOfWheatField = 6;
    numOfRanch = 6;
    numOfForest = 6;
    numOfMine = 6;
    numOfAppleOrchard = 6;
    numOfBakery = 6;
    numOfConvenienceStore = 6;
    numOfCheeseFactory = 6;
    numOfFurnitureFactory = 6;
    numOfFruitandVeggieMarket = 6;
    numOfCafe = 6;
    numOfFamilyRestaurant = 6;
    numOfStadium = 2;
    numOfTVStation = 2;
    numOfBusinessCenter = 2;
}

void moveCards(string card1Name, string card2Name, int player1Index, int player2Index) {
//    Game.players[0].addEstablishment(make_shared<FruitAndVegetableMarket>(FruitAndVegetableMarket(FRUIT_AND_VEGETABLE_MARKET_DESCRIPTION, FRUIT_AND_VEGETABLE_MARKET_COST, FRUIT_AND_VEGETABLE_MARKET_RANGE, FRUIT_AND_VEGETABLE_MARKET_TYPE, greenCardRectangle, FRUIT_AND_VEGETABLE_MARKET_NAME, FRUIT_AND_VEGETABLE_MARKET_SYMBOL)));
//    Game.players[0].addEstablishment(make_shared<FruitAndVegetableMarket>(FruitAndVegetableMarket(FRUIT_AND_VEGETABLE_MARKET_DESCRIPTION, FRUIT_AND_VEGETABLE_MARKET_COST, FRUIT_AND_VEGETABLE_MARKET_RANGE, FRUIT_AND_VEGETABLE_MARKET_TYPE, greenCardRectangle, FRUIT_AND_VEGETABLE_MARKET_NAME, FRUIT_AND_VEGETABLE_MARKET_SYMBOL)));
//    Game.players[0].addEstablishment(make_shared<FruitAndVegetableMarket>(FruitAndVegetableMarket(FRUIT_AND_VEGETABLE_MARKET_DESCRIPTION, FRUIT_AND_VEGETABLE_MARKET_COST, FRUIT_AND_VEGETABLE_MARKET_RANGE, FRUIT_AND_VEGETABLE_MARKET_TYPE, greenCardRectangle, FRUIT_AND_VEGETABLE_MARKET_NAME, FRUIT_AND_VEGETABLE_MARKET_SYMBOL)));
//    Game.players[1].addEstablishment(make_shared<FruitAndVegetableMarket>(FruitAndVegetableMarket(FRUIT_AND_VEGETABLE_MARKET_DESCRIPTION, FRUIT_AND_VEGETABLE_MARKET_COST, FRUIT_AND_VEGETABLE_MARKET_RANGE, FRUIT_AND_VEGETABLE_MARKET_TYPE, greenCardRectangle, FRUIT_AND_VEGETABLE_MARKET_NAME, FRUIT_AND_VEGETABLE_MARKET_SYMBOL)));
//    Game.players[1].addEstablishment(make_shared<FruitAndVegetableMarket>(FruitAndVegetableMarket(FRUIT_AND_VEGETABLE_MARKET_DESCRIPTION, FRUIT_AND_VEGETABLE_MARKET_COST, FRUIT_AND_VEGETABLE_MARKET_RANGE, FRUIT_AND_VEGETABLE_MARKET_TYPE, greenCardRectangle, FRUIT_AND_VEGETABLE_MARKET_NAME, FRUIT_AND_VEGETABLE_MARKET_SYMBOL)));
//    Game.players[1].addEstablishment(make_shared<FruitAndVegetableMarket>(FruitAndVegetableMarket(FRUIT_AND_VEGETABLE_MARKET_DESCRIPTION, FRUIT_AND_VEGETABLE_MARKET_COST, FRUIT_AND_VEGETABLE_MARKET_RANGE, FRUIT_AND_VEGETABLE_MARKET_TYPE, greenCardRectangle, FRUIT_AND_VEGETABLE_MARKET_NAME, FRUIT_AND_VEGETABLE_MARKET_SYMBOL)));


    Game.players[player1Index].removeCard(card1Name);
    Game.players[player2Index].removeCard(card2Name);

    // Give currentPlayer the other player's card
    if (card2Name == WHEAT_FIELD_NAME){
        Game.players[player1Index].addEstablishment(make_shared<WheatField>(WheatField(WHEAT_FIELD_DESCRIPTION, WHEAT_FIELD_COST, WHEAT_FIELD_RANGE, WHEAT_FIELD_TYPE, blueCardRectangle, WHEAT_FIELD_NAME, WHEAT_FIELD_SYMBOL)));

    }
    else if(card2Name == BAKERY_NAME){
        Game.players[player1Index].addEstablishment(make_shared<Bakery>(Bakery(BAKERY_DESCRIPTION, BAKERY_COST, BAKERY_RANGE, BAKERY_TYPE, greenCardRectangle, BAKERY_NAME, BAKERY_SYMBOL)));

    }
    else if(card2Name == RANCH_NAME){
        Game.players[player1Index].addEstablishment(make_shared<Ranch>(Ranch(RANCH_DESCRIPTION, RANCH_COST, RANCH_RANGE, RANCH_TYPE, blueCardRectangle, RANCH_NAME, RANCH_SYMBOL)));

    }
    else if(card2Name == CAFE_NAME){
        Game.players[player1Index].addEstablishment(make_shared<Cafe>(Cafe(CAFE_DESCRIPTION, CAFE_COST, CAFE_RANGE, CAFE_TYPE, redCardRectangle, CAFE_NAME, CAFE_SYMBOL)));

    }
    else if(card2Name == CONVENIENCE_STORE_NAME){
        Game.players[player1Index].addEstablishment(make_shared<ConvenienceStore>(ConvenienceStore(CONVENIENCE_STORE_DESCRIPTION, CONVENIENCE_STORE_COST, CONVENIENCE_STORE_RANGE, CONVENIENCE_STORE_TYPE, greenCardRectangle, CONVENIENCE_STORE_NAME, CONVENIENCE_STORE_SYMBOL)));

    }
    else if(card2Name == FOREST_NAME){
        Game.players[player1Index].addEstablishment(make_shared<Forest>(Forest(FOREST_DESCRIPTION, FOREST_COST, FOREST_RANGE, FOREST_TYPE, blueCardRectangle, FOREST_NAME, FOREST_SYMBOL)));

    }
    else if(card2Name == CHEESE_FACTORY_NAME){
        Game.players[player1Index].addEstablishment(make_shared<CheeseFactory>(CheeseFactory(CHEESE_FACTORY_DESCRIPTION, CHEESE_FACTORY_COST, CHEESE_FACTORY_RANGE, CHEESE_FACTORY_TYPE, greenCardRectangle, CHEESE_FACTORY_NAME, CHEESE_FACTORY_SYMBOL)));

    }
    else if(card2Name == FURNITURE_FACTORY_NAME){
        Game.players[player1Index].addEstablishment(make_shared<FurnitureFactory>(FurnitureFactory(FURNITURE_FACTORY_DESCRIPTION, FURNITURE_FACTORY_COST, FURNITURE_FACTORY_RANGE, FURNITURE_FACTORY_TYPE, greenCardRectangle, FURNITURE_FACTORY_NAME, FURNITURE_FACTORY_SYMBOL)));

    }
    else if(card2Name == MINE_NAME){
        Game.players[player1Index].addEstablishment(make_shared<Mine>(Mine(MINE_DESCRIPTION, MINE_COST, MINE_RANGE, MINE_TYPE, blueCardRectangle, MINE_NAME, MINE_SYMBOL)));

    }
    else if(card2Name == FAMILY_RESTAURANT_NAME){
        Game.players[player1Index].addEstablishment(make_shared<FamilyRestaurant>(FamilyRestaurant(FAMILY_RESTAURANT_DESCRIPTION, FAMILY_RESTAURANT_COST, FAMILY_RESTAURANT_RANGE, FAMILY_RESTAURANT_TYPE, redCardRectangle, FAMILY_RESTAURANT_NAME, FAMILY_RESTAURANT_SYMBOL)));

    }
    else if(card2Name == APPLE_ORCHARD_NAME){
        Game.players[player1Index].addEstablishment(make_shared<AppleOrchard>(AppleOrchard(APPLE_ORCHARD_DESCRIPTION, APPLE_ORCHARD_COST, APPLE_ORCHARD_RANGE, APPLE_ORCHARD_TYPE, blueCardRectangle, APPLE_ORCHARD_NAME, APPLE_ORCHARD_SYMBOL)));

    }
    else if(card2Name == FRUIT_AND_VEGETABLE_MARKET_NAME){
        Game.players[player1Index].addEstablishment(make_shared<FruitAndVegetableMarket>(FruitAndVegetableMarket(FRUIT_AND_VEGETABLE_MARKET_DESCRIPTION, FRUIT_AND_VEGETABLE_MARKET_COST, FRUIT_AND_VEGETABLE_MARKET_RANGE, FRUIT_AND_VEGETABLE_MARKET_TYPE, greenCardRectangle, FRUIT_AND_VEGETABLE_MARKET_NAME, FRUIT_AND_VEGETABLE_MARKET_SYMBOL)));
    }

    // Give other player the currentPlayer's card
    if (card1Name == WHEAT_FIELD_NAME){
        Game.players[player2Index].addEstablishment(make_shared<WheatField>(WheatField(WHEAT_FIELD_DESCRIPTION, WHEAT_FIELD_COST, WHEAT_FIELD_RANGE, WHEAT_FIELD_TYPE, blueCardRectangle, WHEAT_FIELD_NAME, WHEAT_FIELD_SYMBOL)));

    }
    else if(card1Name == BAKERY_NAME){
        Game.players[player2Index].addEstablishment(make_shared<Bakery>(Bakery(BAKERY_DESCRIPTION, BAKERY_COST, BAKERY_RANGE, BAKERY_TYPE, greenCardRectangle, BAKERY_NAME, BAKERY_SYMBOL)));

    }
    else if(card1Name == RANCH_NAME){
        Game.players[player2Index].addEstablishment(make_shared<Ranch>(Ranch(RANCH_DESCRIPTION, RANCH_COST, RANCH_RANGE, RANCH_TYPE, blueCardRectangle, RANCH_NAME, RANCH_SYMBOL)));

    }
    else if(card1Name == CAFE_NAME){
        Game.players[player2Index].addEstablishment(make_shared<Cafe>(Cafe(CAFE_DESCRIPTION, CAFE_COST, CAFE_RANGE, CAFE_TYPE, redCardRectangle, CAFE_NAME, CAFE_SYMBOL)));

    }
    else if(card1Name == CONVENIENCE_STORE_NAME){
        Game.players[player2Index].addEstablishment(make_shared<ConvenienceStore>(ConvenienceStore(CONVENIENCE_STORE_DESCRIPTION, CONVENIENCE_STORE_COST, CONVENIENCE_STORE_RANGE, CONVENIENCE_STORE_TYPE, greenCardRectangle, CONVENIENCE_STORE_NAME, CONVENIENCE_STORE_SYMBOL)));

    }
    else if(card1Name == FOREST_NAME){
        Game.players[player2Index].addEstablishment(make_shared<Forest>(Forest(FOREST_DESCRIPTION, FOREST_COST, FOREST_RANGE, FOREST_TYPE, blueCardRectangle, FOREST_NAME, FOREST_SYMBOL)));

    }
    else if(card1Name == CHEESE_FACTORY_NAME){
        Game.players[player2Index].addEstablishment(make_shared<CheeseFactory>(CheeseFactory(CHEESE_FACTORY_DESCRIPTION, CHEESE_FACTORY_COST, CHEESE_FACTORY_RANGE, CHEESE_FACTORY_TYPE, greenCardRectangle, CHEESE_FACTORY_NAME, CHEESE_FACTORY_SYMBOL)));

    }
    else if(card1Name == FURNITURE_FACTORY_NAME){
        Game.players[player2Index].addEstablishment(make_shared<FurnitureFactory>(FurnitureFactory(FURNITURE_FACTORY_DESCRIPTION, FURNITURE_FACTORY_COST, FURNITURE_FACTORY_RANGE, FURNITURE_FACTORY_TYPE, greenCardRectangle, FURNITURE_FACTORY_NAME, FURNITURE_FACTORY_SYMBOL)));

    }
    else if(card1Name == MINE_NAME){
        Game.players[player2Index].addEstablishment(make_shared<Mine>(Mine(MINE_DESCRIPTION, MINE_COST, MINE_RANGE, MINE_TYPE, blueCardRectangle, MINE_NAME, MINE_SYMBOL)));

    }
    else if(card1Name == FAMILY_RESTAURANT_NAME){
        Game.players[player2Index].addEstablishment(make_shared<FamilyRestaurant>(FamilyRestaurant(FAMILY_RESTAURANT_DESCRIPTION, FAMILY_RESTAURANT_COST, FAMILY_RESTAURANT_RANGE, FAMILY_RESTAURANT_TYPE, redCardRectangle, FAMILY_RESTAURANT_NAME, FAMILY_RESTAURANT_SYMBOL)));

    }
    else if(card1Name == APPLE_ORCHARD_NAME){
        Game.players[player2Index].addEstablishment(make_shared<AppleOrchard>(AppleOrchard(APPLE_ORCHARD_DESCRIPTION, APPLE_ORCHARD_COST, APPLE_ORCHARD_RANGE, APPLE_ORCHARD_TYPE, blueCardRectangle, APPLE_ORCHARD_NAME, APPLE_ORCHARD_SYMBOL)));

    }
    else if(card1Name == FRUIT_AND_VEGETABLE_MARKET_NAME){
        Game.players[player2Index].addEstablishment(make_shared<FruitAndVegetableMarket>(FruitAndVegetableMarket(FRUIT_AND_VEGETABLE_MARKET_DESCRIPTION, FRUIT_AND_VEGETABLE_MARKET_COST, FRUIT_AND_VEGETABLE_MARKET_RANGE, FRUIT_AND_VEGETABLE_MARKET_TYPE, greenCardRectangle, FRUIT_AND_VEGETABLE_MARKET_NAME, FRUIT_AND_VEGETABLE_MARKET_SYMBOL)));
    }

}

void drawMarket(){
    string message = "";
    if (numOfWheatField > 0) {
        wheatFieldButton.draw();
        message = "Wheat";
        drawText18(message, 1, 1, 1, wheatFieldButton.getX() + 5, wheatFieldButton.getY() + 30);
        message = "Field";
        drawText18(message, 1, 1, 1, wheatFieldButton.getX() + 5, wheatFieldButton.getY() + 60);
    }
    if (numOfRanch > 0) {
        ranchButton.draw();
        message = "Ranch";
        drawText18(message, 1, 1, 1, ranchButton.getX() + 5, ranchButton.getY() + 30);
    }
    if (numOfBakery > 0) {
        bakeryButton.draw();
        message = "Bakery";
        drawText18(message, 1, 1, 1, bakeryButton.getX() + 5, bakeryButton.getY() + 30);
    }
    if (numOfCafe > 0) {
        cafeButton.draw();
        message = "Cafe";
        drawText18(message, 1, 1, 1, cafeButton.getX() + 5, cafeButton.getY() + 30);
    }
    if (numOfConvenienceStore > 0) {
        convenienceStoreButton.draw();
        message = "Convenience";
        drawText18(message, 1, 1, 1, convenienceStoreButton.getX() + 5, convenienceStoreButton.getY() + 30);
        message = "Store";
        drawText18(message, 1, 1, 1, convenienceStoreButton.getX() + 5, convenienceStoreButton.getY() + 60);
    }
    if (numOfForest > 0) {
        forestButton.draw();
        message = "Forest";
        drawText18(message, 1, 1, 1, forestButton.getX() + 5, forestButton.getY() + 30);
    }
    if (numOfTVStation > 0) {
        tvStationButton.draw();
        message = "TV";
        drawText18(message, 1, 1, 1, tvStationButton.getX() + 5, tvStationButton.getY() + 30);
        message = "Station";
        drawText18(message, 1, 1, 1, tvStationButton.getX() + 5, tvStationButton.getY() + 60);
    }
    if (numOfStadium > 0) {
        stadiumButton.draw();
        message = "Stadium";
        drawText18(message, 1, 1, 1, stadiumButton.getX() + 5, stadiumButton.getY() + 30);
    }
    if (numOfBusinessCenter > 0) {
        businessCenterButton.draw();
        message = "Business";
        drawText18(message, 1, 1, 1, businessCenterButton.getX() + 5, businessCenterButton.getY() + 30);
        message = "Center";
        drawText18(message, 1, 1, 1, businessCenterButton.getX() + 5, businessCenterButton.getY() + 60);
    }
    if (numOfCheeseFactory > 0) {
        cheeseFactoryButton.draw();
        message = "Cheese";
        drawText18(message, 1, 1, 1, cheeseFactoryButton.getX() + 5, cheeseFactoryButton.getY() + 30);
        message = "Factory";
        drawText18(message, 1, 1, 1, cheeseFactoryButton.getX() + 5, cheeseFactoryButton.getY() + 60);
    }
    if (numOfFurnitureFactory > 0) {
        furnitureFactoryButton.draw();
        message = "Furniture";
        drawText18(message, 1, 1, 1, furnitureFactoryButton.getX() + 5, furnitureFactoryButton.getY() + 30);
        message = "Factory";
        drawText18(message, 1, 1, 1, furnitureFactoryButton.getX() + 5, furnitureFactoryButton.getY() + 60);
    }
    if (numOfMine > 0) {
        mineButton.draw();
        message = "Mine";
        drawText18(message, 1, 1, 1, mineButton.getX() + 5, mineButton.getY() + 30);
    }
    if (numOfFamilyRestaurant > 0) {
        familyRestaurantButton.draw();
        message = "Family";
        drawText18(message, 1, 1, 1, familyRestaurantButton.getX() + 5, familyRestaurantButton.getY() + 30);
        message = "Restaurant";
        drawText18(message, 1, 1, 1, familyRestaurantButton.getX() + 5, familyRestaurantButton.getY() + 60);
    }
    if (numOfAppleOrchard > 0) {
        appleOrchardButton.draw();
        message = "Apple";
        drawText18(message, 1, 1, 1, appleOrchardButton.getX() + 5, appleOrchardButton.getY() + 30);
        message = "Orchard";
        drawText18(message, 1, 1, 1, appleOrchardButton.getX() + 5, appleOrchardButton.getY() + 60);
    }
    if (numOfFruitandVeggieMarket > 0) {
        fruitAndVegetableMarketButton.draw();
        message = "Fruit and";
        drawText18(message, 1, 1, 1, fruitAndVegetableMarketButton.getX() + 5,
                   fruitAndVegetableMarketButton.getY() + 30);
        message = "Vegetable";
        drawText18(message, 1, 1, 1, fruitAndVegetableMarketButton.getX() + 5,
                   fruitAndVegetableMarketButton.getY() + 60);
        message = "Market";
        drawText18(message, 1, 1, 1, fruitAndVegetableMarketButton.getX() + 5,
                   fruitAndVegetableMarketButton.getY() + 90);
    }
}

void drawPlayerInventory(){
    labelSlot.draw();
    string message = "Inventory for Player: ";
    drawText18(message, 1, 1, 1, labelSlot.getX() + 10, labelSlot.getY() + 20);
    message = to_string(Game.focusedPlayerIndex + 1);
    drawText18(message, 1, 1, 1, labelSlot.getX() + (labelSlot.getBase() - 30), labelSlot.getY() + 20);

    moneySlot.draw();
    message = "Money";
    drawText18(message, 1, 1, 1, moneySlot.getX() + 10, moneySlot.getY() + 20);
    message = to_string(Game.players[Game.focusedPlayerIndex].getMoney());
    drawText18(message, 1, 1, 1, moneySlot.getX() + (moneySlot.getBase() - 30), moneySlot.getY() + 20);

    wheatFieldSlot.draw();
    message = "Wheat Field";
    drawText18(message, 1, 1, 1, wheatFieldSlot.getX() + 10, wheatFieldSlot.getY() + 20);
    message = to_string(Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(WHEAT_FIELD_NAME));
    drawText18(message, 1, 1, 1, wheatFieldSlot.getX() + (wheatFieldSlot.getBase() - 30), wheatFieldSlot.getY() + 20);

    ranchSlot.draw();
    message = "Ranch";
    drawText18(message, 1, 1, 1, ranchSlot.getX() + 10, ranchSlot.getY() + 20);
    message = to_string(Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(RANCH_NAME));
    drawText18(message, 1, 1, 1, ranchSlot.getX() + (ranchSlot.getBase() - 30), ranchSlot.getY() + 20);

    bakerySlot.draw();
    message = "Bakery";
    drawText18(message, 1, 1, 1, bakerySlot.getX() + 10, bakerySlot.getY() + 20);
    message = to_string(Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(BAKERY_NAME));
    drawText18(message, 1, 1, 1, bakerySlot.getX() + (bakerySlot.getBase() - 30), bakerySlot.getY() + 20);

    cafeSlot.draw();
    message = "Cafe";
    drawText18(message, 1, 1, 1, cafeSlot.getX() + 10, cafeSlot.getY() + 20);
    message = to_string(Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(CAFE_NAME));
    drawText18(message, 1, 1, 1, cafeSlot.getX() + (cafeSlot.getBase() - 30), cafeSlot.getY() + 20);

    convenienceStoreSlot.draw();
    message = "Convenience Store";
    drawText18(message, 1, 1, 1, convenienceStoreSlot.getX() + 10, convenienceStoreSlot.getY() + 20);
    message = to_string(Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(CONVENIENCE_STORE_NAME));
    drawText18(message, 1, 1, 1, convenienceStoreSlot.getX() + (convenienceStoreSlot.getBase() - 30), convenienceStoreSlot.getY() + 20);

    forestSlot.draw();
    message = "Forest";
    drawText18(message, 1, 1, 1, forestSlot.getX() + 10, forestSlot.getY() + 20);
    message = to_string(Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(FOREST_NAME));
    drawText18(message, 1, 1, 1, forestSlot.getX() + (forestSlot.getBase() - 30), forestSlot.getY() + 20);

    tvStationSlot.draw();
    message = "TV Station";
    drawText18(message, 1, 1, 1, tvStationSlot.getX() + 10, tvStationSlot.getY() + 20);
    message = to_string(Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(TV_STATION_NAME));
    drawText18(message, 1, 1, 1, tvStationSlot.getX() + (tvStationSlot.getBase() - 30), tvStationSlot.getY() + 20);

    stadiumSlot.draw();
    message = "Stadium";
    drawText18(message, 1, 1, 1, stadiumSlot.getX() + 10, stadiumSlot.getY() + 20);
    message = to_string(Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(STADIUM_NAME));
    drawText18(message, 1, 1, 1, stadiumSlot.getX() + (stadiumSlot.getBase() - 30), stadiumSlot.getY() + 20);

    businessCenterSlot.draw();
    message = "Business Center";
    drawText18(message, 1, 1, 1, businessCenterSlot.getX() + 10, businessCenterSlot.getY() + 20);
    message = to_string(Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(BUSINESS_CENTER_NAME));
    drawText18(message, 1, 1, 1, businessCenterSlot.getX() + (businessCenterSlot.getBase() - 30), businessCenterSlot.getY() + 20);

    cheeseFactorySlot.draw();
    message = "Cheese Factory";
    drawText18(message, 1, 1, 1, cheeseFactorySlot.getX() + 10, cheeseFactorySlot.getY() + 20);
    message = to_string(Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(CHEESE_FACTORY_NAME));
    drawText18(message, 1, 1, 1, cheeseFactorySlot.getX() + (cheeseFactorySlot.getBase() - 30), cheeseFactorySlot.getY() + 20);

    furnitureFactorySlot.draw();
    message = "Furniture Factory";
    drawText18(message, 1, 1, 1, furnitureFactorySlot.getX() + 10, furnitureFactorySlot.getY() + 20);
    message = to_string(Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(FURNITURE_FACTORY_NAME));
    drawText18(message, 1, 1, 1, furnitureFactorySlot.getX() + (furnitureFactorySlot.getBase() - 30), furnitureFactorySlot.getY() + 20);

    mineSlot.draw();
    message = "Mine";
    drawText18(message, 1, 1, 1, mineSlot.getX() + 10, mineSlot.getY() + 20);
    message = to_string(Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(MINE_NAME));
    drawText18(message, 1, 1, 1, mineSlot.getX() + (mineSlot.getBase() - 30), mineSlot.getY() + 20);

    familyRestaurantSlot.draw();
    message = "Family Restaurant";
    drawText18(message, 1, 1, 1, familyRestaurantSlot.getX() + 10, familyRestaurantSlot.getY() + 20);
    message = to_string(Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(FAMILY_RESTAURANT_NAME));
    drawText18(message, 1, 1, 1, familyRestaurantSlot.getX() + (familyRestaurantSlot.getBase() - 30), familyRestaurantSlot.getY() + 20);

    appleOrchardSlot.draw();
    message = "Apple Orchard";
    drawText18(message, 1, 1, 1, appleOrchardSlot.getX() + 10, appleOrchardSlot.getY() + 20);
    message = to_string(Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(APPLE_ORCHARD_NAME));
    drawText18(message, 1, 1, 1, appleOrchardSlot.getX() + (appleOrchardSlot.getBase() - 30), appleOrchardSlot.getY() + 20);

    fruitAndVegetableMarketSlot.draw();
    message = "Fruit and Vegetable Market";
    drawText18(message, 1, 1, 1, fruitAndVegetableMarketSlot.getX() + 10, fruitAndVegetableMarketSlot.getY() + 20);
    message = to_string(Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(FRUIT_AND_VEGETABLE_MARKET_NAME));
    drawText18(message, 1, 1, 1, fruitAndVegetableMarketSlot.getX() + (fruitAndVegetableMarketSlot.getBase() - 30), fruitAndVegetableMarketSlot.getY() + 20);

    if(Game.players[Game.focusedPlayerIndex].getTrainStationBool()){
        trainStationSlot.setFill(LANDMARK_CARD_OWNED_COLOR);
        trainStationSlot.draw();
    }
    else{
        trainStationSlot.setFill(LANDMARK_CARD_COLOR);
        trainStationSlot.draw();
    }
    message = "Train Station";
    drawText18(message, 1, 1, 1, trainStationSlot.getX() + 10, trainStationSlot.getY() + 20);

    if(Game.players[Game.focusedPlayerIndex].getShoppingMallBool()){
        shoppingMallSlot.setFill(LANDMARK_CARD_OWNED_COLOR);
        shoppingMallSlot.draw();
    }
    else{
        shoppingMallSlot.setFill(LANDMARK_CARD_COLOR);
        shoppingMallSlot.draw();
    }
    message = "Shopping Mall";
    drawText18(message, 1, 1, 1, shoppingMallSlot.getX() + 10, shoppingMallSlot.getY() + 20);

    if(Game.players[Game.focusedPlayerIndex].getAmusementParkBool()){
        amusementParkSlot.setFill(LANDMARK_CARD_OWNED_COLOR);
        amusementParkSlot.draw();
    }
    else{
        amusementParkSlot.setFill(LANDMARK_CARD_COLOR);
        amusementParkSlot.draw();
    }
    message = "Amusement Park";
    drawText18(message, 1, 1, 1, amusementParkSlot.getX() + 10, amusementParkSlot.getY() + 20);

    if(Game.players[Game.focusedPlayerIndex].getRadioTowerBool()){
        radioTowerSlot.setFill(LANDMARK_CARD_OWNED_COLOR);
        radioTowerSlot.draw();
    }
    else{
        radioTowerSlot.setFill(LANDMARK_CARD_COLOR);
        radioTowerSlot.draw();
    }
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
    cardImage->draw();
    mainMenuButton.draw();
    string message = "Main Menu";
    drawText24(message, 1, 1, 1, mainMenuButton.getX() + 25, mainMenuButton.getY() + 45);

    message = "Player " + to_string(Game.currentPlayerIndex + 1) + "'s turn";
    drawText24(message, 1, 1, 1, 400, 40);

    switch (Game.turnPhase){
        case (roll):
            message = "Phase: Roll";
            drawText24(message, 1, 1, 1, 600, 40);
            break;
        case (postRoll):
            message = "Phase: Post Roll";
            drawText24(message, 1, 1, 1, 600, 40);
            break;
        case (radioTower):
            message = "Phase: RadioTower";
            drawText24(message, 1, 1, 1, 600, 40);
            break;
        case(distribution):
            message = "Phase: Distribution";
            drawText24(message, 1, 1, 1, 600, 40);
            break;
        case(buy):
            message = "Phase: Buy";
            drawText24(message, 1, 1, 1, 600, 40);
            break;
        case(endturn):
            message = "Phase: End Turn";
            drawText24(message, 1, 1, 1, 600, 40);
            break;
        case(businessCenter):
            message = "Phase: Business Center";
            drawText24(message, 1, 1, 1, 600, 40);
            break;
        case(tvStation):
            message = "Phase: TV Station";
            drawText24(message, 1, 1, 1, 600, 40);
            break;
    }


    drawMarket();
    rollDieButton.draw();
    roll2diceButton.draw();
    rerollButton.draw();
    message = "Reroll Dice";
    drawText24(message, 1, 1, 1, rerollButton.getX() + 25, rerollButton.getY() + 45);
    keepRollButton.draw();
    message = "Keep Roll";
    drawText24(message, 1, 1, 1, keepRollButton.getX() + 25, keepRollButton.getY() + 45);
    skipBuyButton.draw();
    message = "Skip Buy Phase";
    drawText24(message, 1, 1, 1, skipBuyButton.getX() + 25, skipBuyButton.getY() + 45);


    drawPlayerInventory();
    drawPlayerButtons();

    if(Game.turnPhase == roll){

        string dieMessage = "Roll";
        drawText24(dieMessage, 0, 0, 0, rollDieButton.getX() + 10, rollDieButton.getY() + 20);
        dieMessage = "Roll 2";
        drawText24(dieMessage, 0, 0, 0, roll2diceButton.getX() + 10, roll2diceButton.getY() + 20);

        if(!Game.players[Game.currentPlayerIndex].getIsHuman()){
            cpuRollDice();
        }

        if(Game.diceRolled){
            Game.turnPhase = postRoll;
            Game.diceRolled = false;
        }
    }
    else if(Game.turnPhase == postRoll){
        cout << "post roll phase\n";
        // Draw the result of the dice roll
        drawText24(to_string(Game.dice1Roll), 0, 0, 0, rollDieButton.getX() + 30, rollDieButton.getY() + 35);
        drawText24(to_string(Game.dice2Roll), 0, 0, 0, roll2diceButton.getX() + 30, roll2diceButton.getY() + 35);

        if(!Game.players[Game.currentPlayerIndex].getIsHuman()){
            cpuPostRoll();
        }
        else{
            if (Game.players[Game.currentPlayerIndex].getRadioTowerBool() && !Game.skipRadioTower){
                // Do not allow the dice to be rerolled more than once per turn
                Game.skipRadioTower = true;
                Game.turnPhase = radioTower;
            }
            else {
                Game.diceSum = Game.dice1Roll + Game.dice2Roll;
                Game.turnPhase = distribution;
            }
        }

    }
    else if (Game.turnPhase == radioTower){
        //Reset dice roll and dice sum values
        //Wait for player input
        drawText24(to_string(Game.dice1Roll), 0, 0, 0, rollDieButton.getX() + 30, rollDieButton.getY() + 35);
        drawText24(to_string(Game.dice2Roll), 0, 0, 0, roll2diceButton.getX() + 30, roll2diceButton.getY() + 35);

        if(!Game.players[Game.currentPlayerIndex].getIsHuman()){
            cpuRollDice();
        }

    }
    else if (Game.turnPhase == distribution){
        cout << "distribution phase\n";
        // Draw the result of the dice roll
        drawText24(to_string(Game.dice1Roll), 0, 0, 0, rollDieButton.getX() + 30, rollDieButton.getY() + 35);

        cout << "Roll: " << Game.diceSum << "\n";

        //Red/restaurant cards need to be activated in a counter clockwise fashion. This implementation does that for 2 players right now
        //Perhaps there is a more efficient way to do this.
        switch (Game.numOfPlayers) {
            //Case 1: 2 player game
            case (2):
                switch (Game.currentPlayerIndex) {
                    //Activate red cards for player2 on player1's roll
                    case (0):
                      //  cout << to_string(Game.players[1].getEstablishments().size()) << "\n";
                        for (int i = 0; i < Game.players[1].getEstablishments().size(); i++) {
                            cout << to_string(i) << "\n";
                            if (Game.players[1].getEstablishments()[i]->getCardType() == restaurant && Game.players[1].getEstablishments()[i]->getActivationMin() <= Game.diceSum && Game.diceSum <= Game.players[1].getEstablishments()[i]->getActivationMax()) {
                                cout << "num establishments: " << Game.players[i].getEstablishments().size() << "\n";
                                cout << "activating card: " << Game.players[1].getEstablishments()[i]->getName() << "\n";
                                Game.players[1].getEstablishments()[i]->activate(Game.players[1], Game.players, Game.players[Game.currentPlayerIndex]);
                            }
                        }
                        break;
                        //Activate red cards for player1 on player2's roll
                    case (1):
                        for (int i = 0; i < Game.players[0].getEstablishments().size(); i++) {
                            if (Game.players[0].getEstablishments()[i]->getCardType() == restaurant && Game.players[0].getEstablishments()[0]->getActivationMin() <= Game.diceSum && Game.diceSum <= Game.players[0].getEstablishments()[i]->getActivationMax()) {
                                cout << "num establishments: " << Game.players[i].getEstablishments().size() << "\n";
                                cout << "activating card: " << Game.players[1].getEstablishments()[i]->getName() << "\n";
                                Game.players[0].getEstablishments()[i]->activate(Game.players[0], Game.players, Game.players[Game.currentPlayerIndex]);
                            }
                        }
                        break;
                }
                break;
        }

        //Activate all blue/primaryIndustry cards across the board
        for(int i = 0; i < Game.players.size(); i++){
            for (int j = 0; j < Game.players[i].getEstablishments().size(); j++){
                //shared_ptr<Card> card = Game.players[i].getEstablishments()[i];
                if (Game.players[i].getEstablishments()[j]->getCardType() == primaryIndustry && Game.players[i].getEstablishments()[i]->getActivationMin() <= Game.diceSum && Game.diceSum <= Game.players[i].getEstablishments()[i]->getActivationMax()){
                    cout << "num establishments: " << Game.players[i].getEstablishments().size() << "\n";
                    cout << "activating card: " << Game.players[i].getEstablishments()[j]->getName() << "\n";
                    Game.players[i].getEstablishments()[j]->activate(Game.players[i], Game.players, Game.players[Game.currentPlayerIndex]);
                }
            }
        }
        //Activate currentPlayers green/secondary industry cards and purple/majorEstablishment cards
        for (int i = 0; i < Game.players[Game.currentPlayerIndex].getEstablishments().size(); i++){
            //shared_ptr<Card> card = Game.players[i].getEstablishments()[i];
            if ((Game.players[Game.currentPlayerIndex].getEstablishments()[i]->getCardType() == secondaryIndustry || Game.players[Game.currentPlayerIndex].getEstablishments()[i]->getCardType() == majorEstablishment) && Game.players[Game.currentPlayerIndex].getEstablishments()[i]->getActivationMin() <= Game.diceSum && Game.diceSum <= Game.players[Game.currentPlayerIndex].getEstablishments()[i]->getActivationMax()){
                //cout << "num establishments: " << Game.players[Game.currentPlayerIndex].getEstablishments().size() << "\n";
                cout << "activating card: " << Game.players[Game.currentPlayerIndex].getEstablishments()[i]->getName() << "\n";
                Game.players[Game.currentPlayerIndex].getEstablishments()[i]->activate(Game.players[Game.currentPlayerIndex], Game.players, Game.players[Game.currentPlayerIndex]);
                if (Game.players[Game.currentPlayerIndex].getEstablishments()[i]->getName() == BUSINESS_CENTER_NAME){
                    Game.skipBusinessCenter = false;
                }
                else if (Game.players[Game.currentPlayerIndex].getEstablishments()[i]->getName() == TV_STATION_NAME){
                    Game.skipTVStation = false;
                }
            }
        }
        if (Game.skipBusinessCenter && Game.skipTVStation){
            Game.turnPhase = buy;
        }
        else if (!Game.skipBusinessCenter){
            Game.turnPhase = businessCenter;
        }
        else if (!Game.skipTVStation){
            Game.turnPhase = tvStation;
        }
    }
    else if(Game.turnPhase == businessCenter){
        drawText24(to_string(Game.dice1Roll), 0, 0, 0, rollDieButton.getX() + 30, rollDieButton.getY() + 35);
        drawText24(to_string(Game.dice2Roll), 0, 0, 0, roll2diceButton.getX() + 30, roll2diceButton.getY() + 35);

        if (Game.businessCenterCurrentPlayerCard != "" && Game.businessCenterTargetPlayerCard != ""){
            //TODO: Trade cards with target player
            cout << "calling move cards with card1 = '" << Game.businessCenterCurrentPlayerCard << "' and card2 = '" << Game.businessCenterTargetPlayerCard << "'\n";
            cout << "Player " << Game.currentPlayerIndex + 1 << " activated the card, targeting player " << Game.businessCenterTargetPlayerIndex + 1 << "\n";
            moveCards(Game.businessCenterCurrentPlayerCard, Game.businessCenterTargetPlayerCard, Game.currentPlayerIndex, Game.businessCenterTargetPlayerIndex);
            Game.businessCenterCurrentPlayerCard = "";
            Game.businessCenterTargetPlayerCard = "";
            Game.businessCenterUsed = true;
        }


        if (Game.businessCenterUsed) {
            Game.skipBusinessCenter = true;
            Game.businessCenterUsed = false;
            if (Game.skipTVStation){
                Game.turnPhase = buy;
            }
            else{
                Game.turnPhase = tvStation;
            }
        }

    }
    else if(Game.turnPhase == tvStation){
        drawText24(to_string(Game.dice1Roll), 0, 0, 0, rollDieButton.getX() + 30, rollDieButton.getY() + 35);
        drawText24(to_string(Game.dice2Roll), 0, 0, 0, roll2diceButton.getX() + 30, roll2diceButton.getY() + 35);

        if (Game.tvStationUsed) {
            Game.skipTVStation = true;
            Game.tvStationUsed = false;
            if (Game.skipBusinessCenter){
                Game.turnPhase = buy;
            }
            else{
                Game.turnPhase = businessCenter;
            }
        }

    }
    else if(Game.turnPhase == buy){
        //cout << "buy phase\n";
        drawText24(to_string(Game.dice1Roll), 0, 0, 0, rollDieButton.getX() + 30, rollDieButton.getY() + 35);
        drawText24(to_string(Game.dice2Roll), 0, 0, 0, roll2diceButton.getX() + 30, roll2diceButton.getY() + 35);

        if(!Game.players[Game.currentPlayerIndex].getIsHuman()){
            cpuBuyCard();
        }

        if(Game.boughtCard) {
            cout << "card bought" << endl;
//            if(Game.players[Game.currentPlayerIndex].checkWinner()){
//                Game.gameOver = true;
//                // clean up
//            }
            Game.turnPhase = endturn;
            //Game.boughtCard = false;
        }
    }
    else if(Game.turnPhase == endturn){
        cout << "end turn phase" << endl;
        if (Game.players[Game.currentPlayerIndex].checkWinner()){
            Game.gameOver = true;
            screen = endGame;
        }
        else {
            //cout << "currentPlayerIndex: " << Game.currentPlayerIndex << "\n";
            if (Game.players[Game.currentPlayerIndex].getAmusementParkBool() && Game.dice1Roll == Game.dice2Roll) {
                // Current player takes another turn
                //Reset dice roll and dice sum values
                Game.dice1Roll = 0;
                Game.dice2Roll = 0;
                Game.diceSum = 0;
                Game.turnPhase = roll;
                Game.boughtCard = false;
                Game.skipRadioTower = false;
                Game.skipBusinessCenter = true;
                Game.skipTVStation = true;
                Game.businessCenterUsed = false;
                Game.tvStationUsed = false;
                Game.businessCenterCurrentPlayerCard = "";
                Game.businessCenterTargetPlayerCard = "";
            } else {
                Game.currentPlayerIndex++;
                //cout << "currentPlayerIndex: " << Game.currentPlayerIndex << "\n";
                if (Game.currentPlayerIndex >= Game.players.size()) {
                    Game.currentPlayerIndex = 0;
                }
                //Reset dice roll and dice sum values
                Game.dice1Roll = 0;
                Game.dice2Roll = 0;
                Game.diceSum = 0;
                Game.turnPhase = roll;
                Game.boughtCard = false;
                Game.skipRadioTower = false;
                Game.skipBusinessCenter = true;
                Game.skipTVStation = true;
                Game.businessCenterUsed = false;
                Game.tvStationUsed = false;
                Game.businessCenterCurrentPlayerCard = "";
                Game.businessCenterTargetPlayerCard = "";
            }
        }
    }
}

void displayEndGame(){
    mainMenuButton.draw();
    string message = "Main Menu";
    drawText24(message, 1, 1, 1, mainMenuButton.getX() + 25, mainMenuButton.getY() + 45);

    message = "Player " + to_string(Game.currentPlayerIndex) + " WINS!";
    drawText24(message, 1, 1, 1, 600,300);
}








void cpuRollDice(){




    if(Game.players[Game.currentPlayerIndex].getTrainStationBool()){

        bool rollTwice = false;

        int rollTwiceNum = (rand() % 5) + 1;
        Game.dice1Roll = (rand() % 6) + 1;

        if(rollTwiceNum == 1){
            rollTwice = true;
        }

        if(rollTwice) {
            Game.dice2Roll = (rand() % 6) + 1;
        }
        else{
             Game.dice2Roll = 0;
        }

        Game.diceRolled = true;
    }else{
        Game.dice1Roll = (rand() % 6) + 1;
        Game.dice2Roll = 0;
        Game.diceRolled = true;
    }

    cout << "cpu rolled: " << Game.diceRolled << endl;



}


void cpuPostRoll(){


    if (Game.players[Game.currentPlayerIndex].getRadioTowerBool() && !Game.skipRadioTower){

        bool cpuReRoll = false;
        //TODO: Generate number to determine if the cpu will want to reroll or not, or a method to reroll if none of the cards activate
        // Do not allow the dice to be rerolled more than once per turn

        if(cpuReRoll){
            Game.skipRadioTower = true;
            Game.turnPhase = radioTower;
        }
        else{
            Game.diceSum = Game.dice1Roll + Game.dice2Roll;
            Game.turnPhase = distribution;
        }

    }
    else {
        Game.diceSum = Game.dice1Roll + Game.dice2Roll;
        Game.turnPhase = distribution;
    }

}


void cpuBuyCard(){

    int cpuMoney = Game.players[Game.currentPlayerIndex].getMoney();


    //Prioritize buying landmarks first
    if(!Game.players[Game.currentPlayerIndex].getTrainStationBool() && cpuMoney >= TRAIN_STATION_COST && !Game.boughtCard){
        Game.players[Game.currentPlayerIndex].setTrainStationBool(true);
        Game.players[Game.currentPlayerIndex].setMoney(cpuMoney - TRAIN_STATION_COST);
        Game.boughtCard = true;
    }
    else if(!Game.players[Game.currentPlayerIndex].getShoppingMallBool() && cpuMoney >= SHOPPING_MALL_COST && !Game.boughtCard){
        Game.players[Game.currentPlayerIndex].setShoppingMallBool(true);
        Game.players[Game.currentPlayerIndex].setMoney(cpuMoney - SHOPPING_MALL_COST);
        Game.boughtCard = true;
    }
    else if(!Game.players[Game.currentPlayerIndex].getAmusementParkBool() && cpuMoney >= AMUSEMENT_PARK_COST && !Game.boughtCard){
        Game.players[Game.currentPlayerIndex].setAmusementParkBool(true);
        Game.players[Game.currentPlayerIndex].setMoney(cpuMoney - AMUSEMENT_PARK_COST);
        Game.boughtCard = true;
    }
    else if(!Game.players[Game.currentPlayerIndex].getRadioTowerBool() && cpuMoney >= RADIO_TOWER_COST && !Game.boughtCard){
        Game.players[Game.currentPlayerIndex].setRadioTowerBool(true);
        Game.players[Game.currentPlayerIndex].setMoney(cpuMoney - RADIO_TOWER_COST);
        Game.boughtCard = true;
    }


    int buyCardNumGen = (rand() % 3) + 1;

    bool buyCard = true;

    if(buyCardNumGen == 1){
        buyCard = false;
    }

    if(buyCard && !Game.boughtCard) {
        vector<int> availableCards;
        if (cpuMoney == 0) {
            Game.turnPhase = endturn;
        } else if (cpuMoney == 1) {
            availableCards.push_back(numOfWheatField);
            availableCards.push_back(numOfRanch);
            availableCards.push_back(numOfBakery);
        } else if (cpuMoney == 2) {
            availableCards.push_back(numOfWheatField);
            availableCards.push_back(numOfRanch);
            availableCards.push_back(numOfBakery);

            availableCards.push_back(numOfCafe);
            availableCards.push_back(numOfFruitandVeggieMarket);
            availableCards.push_back(numOfConvenienceStore);
        } else if (cpuMoney >= 3 && cpuMoney <= 4) {
            availableCards.push_back(numOfWheatField);
            availableCards.push_back(numOfRanch);
            availableCards.push_back(numOfBakery);

            availableCards.push_back(numOfCafe);
            availableCards.push_back(numOfFruitandVeggieMarket);
            availableCards.push_back(numOfConvenienceStore);

            availableCards.push_back(numOfForest);
            availableCards.push_back(numOfFurnitureFactory);
            availableCards.push_back(numOfFamilyRestaurant);
            availableCards.push_back(numOfAppleOrchard);

        } else if (cpuMoney == 5) {
            availableCards.push_back(numOfWheatField);
            availableCards.push_back(numOfRanch);
            availableCards.push_back(numOfBakery);

            availableCards.push_back(numOfCafe);
            availableCards.push_back(numOfFruitandVeggieMarket);
            availableCards.push_back(numOfConvenienceStore);

            availableCards.push_back(numOfForest);
            availableCards.push_back(numOfFurnitureFactory);
            availableCards.push_back(numOfFamilyRestaurant);
            availableCards.push_back(numOfAppleOrchard);

            availableCards.push_back(numOfCheeseFactory);
        } else if (cpuMoney == 6) {
            availableCards.push_back(numOfWheatField);
            availableCards.push_back(numOfRanch);
            availableCards.push_back(numOfBakery);

            availableCards.push_back(numOfCafe);
            availableCards.push_back(numOfFruitandVeggieMarket);
            availableCards.push_back(numOfConvenienceStore);

            availableCards.push_back(numOfForest);
            availableCards.push_back(numOfFurnitureFactory);
            availableCards.push_back(numOfFamilyRestaurant);
            availableCards.push_back(numOfAppleOrchard);

            availableCards.push_back(numOfCheeseFactory);

            availableCards.push_back(numOfStadium);
            availableCards.push_back(numOfMine);
        } else if (cpuMoney == 7) {
            availableCards.push_back(numOfWheatField);
            availableCards.push_back(numOfRanch);
            availableCards.push_back(numOfBakery);

            availableCards.push_back(numOfCafe);
            availableCards.push_back(numOfFruitandVeggieMarket);
            availableCards.push_back(numOfConvenienceStore);

            availableCards.push_back(numOfForest);
            availableCards.push_back(numOfFurnitureFactory);
            availableCards.push_back(numOfFamilyRestaurant);
            availableCards.push_back(numOfAppleOrchard);

            availableCards.push_back(numOfCheeseFactory);

            availableCards.push_back(numOfStadium);
            availableCards.push_back(numOfMine);

            availableCards.push_back(numOfTVStation);
        } else if (cpuMoney >= 8) {
            availableCards.push_back(numOfWheatField);
            availableCards.push_back(numOfRanch);
            availableCards.push_back(numOfBakery);

            availableCards.push_back(numOfCafe);
            availableCards.push_back(numOfFruitandVeggieMarket);
            availableCards.push_back(numOfConvenienceStore);

            availableCards.push_back(numOfForest);
            availableCards.push_back(numOfFurnitureFactory);
            availableCards.push_back(numOfFamilyRestaurant);
            availableCards.push_back(numOfAppleOrchard);

            availableCards.push_back(numOfCheeseFactory);

            availableCards.push_back(numOfStadium);
            availableCards.push_back(numOfMine);

            availableCards.push_back(numOfTVStation);

            availableCards.push_back(numOfBusinessCenter);
        }


        /** Array Indexes:
         *  0 - WheatField
         *  1 - Ranch
         *  2 - Bakery
         *  3 - Cafe
         *  4 - Fruit and Veggie Market
         *  5 - Convenience Store
         *  6 - Forest
         *  7 - Furniture Factory
         *  8 - Family Restaurant
         *  9 - Apple Orchard
         *  10 - Cheese Factory
         *  11 - Stadium
         *  12 - Mine
         *  13 - TV Station
         *  14 - Business Center
         */

        if (cpuMoney != 0) {
            int arraySize = availableCards.size();

            int cardIndexToBuy = (rand() % arraySize) + 1;

            //Make sure the CPU is buying a card that is still available on the board
            while (availableCards[cardIndexToBuy] == 0) {
                cardIndexToBuy = (rand() % arraySize) + 1;
            }

            switch (cardIndexToBuy) {
                case (0):
                    Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<WheatField>(
                            WheatField(WHEAT_FIELD_DESCRIPTION, WHEAT_FIELD_COST, WHEAT_FIELD_RANGE, WHEAT_FIELD_TYPE,
                                       blueCardRectangle, WHEAT_FIELD_NAME, WHEAT_FIELD_SYMBOL)));
                    Game.players[Game.currentPlayerIndex].setMoney(
                            Game.players[Game.currentPlayerIndex].getMoney() - WHEAT_FIELD_COST);
                    numOfWheatField--;
                    Game.boughtCard = true;
                    break;
                case (1):
                    Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<Ranch>(
                            Ranch(RANCH_DESCRIPTION, RANCH_COST, RANCH_RANGE, RANCH_TYPE, blueCardRectangle, RANCH_NAME,
                                  RANCH_SYMBOL)));
                    Game.players[Game.currentPlayerIndex].setMoney(
                            Game.players[Game.currentPlayerIndex].getMoney() - RANCH_COST);
                    numOfRanch--;
                    Game.boughtCard = true;
                    break;
                case (2):
                    Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<Bakery>(
                            Bakery(BAKERY_DESCRIPTION, BAKERY_COST, BAKERY_RANGE, BAKERY_TYPE, greenCardRectangle,
                                   BAKERY_NAME, BAKERY_SYMBOL)));
                    Game.players[Game.currentPlayerIndex].setMoney(
                            Game.players[Game.currentPlayerIndex].getMoney() - RANCH_COST);
                    numOfBakery--;
                    Game.boughtCard = true;
                    break;
                case (3):
                    Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<Cafe>(
                            Cafe(CAFE_DESCRIPTION, CAFE_COST, CAFE_RANGE, CAFE_TYPE, redCardRectangle, CAFE_NAME,
                                 CAFE_SYMBOL)));
                    Game.players[Game.currentPlayerIndex].setMoney(
                            Game.players[Game.currentPlayerIndex].getMoney() - CAFE_COST);
                    numOfCafe--;
                    Game.boughtCard = true;
                    break;
                case (4):
                    Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<Cafe>(
                            Cafe(FRUIT_AND_VEGETABLE_MARKET_DESCRIPTION, FRUIT_AND_VEGETABLE_MARKET_COST,
                                 FRUIT_AND_VEGETABLE_MARKET_RANGE, FRUIT_AND_VEGETABLE_MARKET_TYPE, greenCardRectangle,
                                 FRUIT_AND_VEGETABLE_MARKET_NAME, FRUIT_AND_VEGETABLE_MARKET_SYMBOL)));
                    Game.players[Game.currentPlayerIndex].setMoney(
                            Game.players[Game.currentPlayerIndex].getMoney() - FRUIT_AND_VEGETABLE_MARKET_COST);
                    numOfFruitandVeggieMarket--;
                    Game.boughtCard = true;
                    break;
                case (5):
                    Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<ConvenienceStore>(
                            ConvenienceStore(CONVENIENCE_STORE_DESCRIPTION, CONVENIENCE_STORE_COST,
                                             CONVENIENCE_STORE_RANGE, CONVENIENCE_STORE_TYPE, greenCardRectangle,
                                             CONVENIENCE_STORE_NAME, CONVENIENCE_STORE_SYMBOL)));
                    Game.players[Game.currentPlayerIndex].setMoney(
                            Game.players[Game.currentPlayerIndex].getMoney() - CONVENIENCE_STORE_COST);
                    numOfConvenienceStore--;
                    Game.boughtCard = true;
                    break;
                case (6):
                    Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<Forest>(
                            Forest(FOREST_DESCRIPTION, FOREST_COST, FOREST_RANGE, FOREST_TYPE, blueCardRectangle,
                                   FOREST_NAME, FOREST_SYMBOL)));
                    Game.players[Game.currentPlayerIndex].setMoney(
                            Game.players[Game.currentPlayerIndex].getMoney() - FOREST_COST);
                    numOfForest--;
                    Game.boughtCard = true;
                    break;
                case (7):
                    Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<FurnitureFactory>(
                            FurnitureFactory(FURNITURE_FACTORY_DESCRIPTION, FURNITURE_FACTORY_COST,
                                             FURNITURE_FACTORY_RANGE, FURNITURE_FACTORY_TYPE, greenCardRectangle,
                                             FURNITURE_FACTORY_NAME, FURNITURE_FACTORY_SYMBOL)));
                    Game.players[Game.currentPlayerIndex].setMoney(
                            Game.players[Game.currentPlayerIndex].getMoney() - FURNITURE_FACTORY_COST);
                    numOfFurnitureFactory--;
                    Game.boughtCard = true;
                    break;
                case (8):
                    Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<FamilyRestaurant>(
                            FamilyRestaurant(FAMILY_RESTAURANT_DESCRIPTION, FAMILY_RESTAURANT_COST,
                                             FAMILY_RESTAURANT_RANGE, FAMILY_RESTAURANT_TYPE, redCardRectangle,
                                             FAMILY_RESTAURANT_NAME, FAMILY_RESTAURANT_SYMBOL)));
                    Game.players[Game.currentPlayerIndex].setMoney(
                            Game.players[Game.currentPlayerIndex].getMoney() - FAMILY_RESTAURANT_COST);
                    numOfFamilyRestaurant--;
                    Game.boughtCard = true;
                    break;
                case (9):
                    Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<AppleOrchard>(
                            AppleOrchard(APPLE_ORCHARD_DESCRIPTION, APPLE_ORCHARD_COST, APPLE_ORCHARD_RANGE,
                                         APPLE_ORCHARD_TYPE, blueCardRectangle, APPLE_ORCHARD_NAME,
                                         APPLE_ORCHARD_SYMBOL)));
                    Game.players[Game.currentPlayerIndex].setMoney(
                            Game.players[Game.currentPlayerIndex].getMoney() - APPLE_ORCHARD_COST);
                    numOfAppleOrchard--;
                    Game.boughtCard = true;
                    break;
                case (10):
                    Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<CheeseFactory>(
                            CheeseFactory(CHEESE_FACTORY_DESCRIPTION, CHEESE_FACTORY_COST, CHEESE_FACTORY_RANGE,
                                          CHEESE_FACTORY_TYPE, greenCardRectangle, CHEESE_FACTORY_NAME,
                                          CHEESE_FACTORY_SYMBOL)));
                    Game.players[Game.currentPlayerIndex].setMoney(
                            Game.players[Game.currentPlayerIndex].getMoney() - CHEESE_FACTORY_COST);
                    numOfCheeseFactory--;
                    Game.boughtCard = true;
                    break;
                case (11):
                    Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<Stadium>(
                            Stadium(STADIUM_DESCRIPTION, STADIUM_COST, STADIUM_RANGE, STADIUM_TYPE, purpleCardRectangle,
                                    STADIUM_NAME, STADIUM_SYMBOL)));
                    Game.players[Game.currentPlayerIndex].setMoney(
                            Game.players[Game.currentPlayerIndex].getMoney() - STADIUM_COST);
                    numOfStadium--;
                    Game.boughtCard = true;
                    break;
                case (12):
                    Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<Mine>(
                            Mine(MINE_DESCRIPTION, MINE_COST, MINE_RANGE, MINE_TYPE, blueCardRectangle, MINE_NAME,
                                 MINE_SYMBOL)));
                    Game.players[Game.currentPlayerIndex].setMoney(
                            Game.players[Game.currentPlayerIndex].getMoney() - MINE_COST);
                    numOfMine--;
                    Game.boughtCard = true;
                    break;
                case (13):
                    Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<TVStation>(
                            TVStation(TV_STATION_DESCRIPTION, TV_STATION_COST, TV_STATION_RANGE, TV_STATION_TYPE,
                                      purpleCardRectangle, TV_STATION_NAME, TV_STATION_SYMBOL)));
                    Game.players[Game.currentPlayerIndex].setMoney(
                            Game.players[Game.currentPlayerIndex].getMoney() - TV_STATION_COST);
                    numOfTVStation--;
                    Game.boughtCard = true;
                case (14):
                    Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<BusinessCenter>(
                            BusinessCenter(BUSINESS_CENTER_DESCRIPTION, BUSINESS_CENTER_COST, BUSINESS_CENTER_RANGE,
                                           BUSINESS_CENTER_TYPE, purpleCardRectangle, BUSINESS_CENTER_NAME,
                                           BUSINESS_CENTER_SYMBOL)));
                    Game.players[Game.currentPlayerIndex].setMoney(
                            Game.players[Game.currentPlayerIndex].getMoney() - CAFE_COST);
                    numOfBusinessCenter--;
                    Game.boughtCard = true;
                    break;
            }

            cout << "cpu bought card: " << cardIndexToBuy << endl;
        }
    }
    else{
        Game.turnPhase = endturn;
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
        displayEndGame();
    }

    //i.draw();

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

        // Menu buttons
        if (mainMenuButton.isOverlapping(x,y)){
            mainMenuButton.setFill(BUTTON_HOVER_COLOR);
        }
        else {
            mainMenuButton.setFill(BUTTON_COLOR);
        }

        // Dice buttons
        if (rollDieButton.isOverlapping(x,y)){
            rollDieButton.setFill(ROLL_BUTTON_HOVER);
        }
        else {
            rollDieButton.setFill(ROLL_BUTTON_COLOR);
        }
        if (roll2diceButton.isOverlapping(x,y)){
            roll2diceButton.setFill(ROLL_BUTTON_HOVER);
        }
        else {
            roll2diceButton.setFill(ROLL_BUTTON_COLOR);
        }

        // Player buttons
        if (player1button.isOverlapping(x,y)){
            player1button.setFill(BUTTON_HOVER_COLOR);
        }
        else {
            player1button.setFill(BUTTON_COLOR);
        }
        if (player2button.isOverlapping(x,y)){
            player2button.setFill(BUTTON_HOVER_COLOR);
        }
        else {
            player2button.setFill(BUTTON_COLOR);
        }

        // Game options buttons
        if (skipBuyButton.isOverlapping(x,y)){
            skipBuyButton.setFill(BUTTON_HOVER_COLOR);
        }
        else {
            skipBuyButton.setFill(BUTTON_COLOR);
        }
        if (rerollButton.isOverlapping(x,y)){
            rerollButton.setFill(BUTTON_HOVER_COLOR);
        }
        else {
            rerollButton.setFill(BUTTON_COLOR);
        }
        if (keepRollButton.isOverlapping(x,y)){
            keepRollButton.setFill(BUTTON_HOVER_COLOR);
        }
        else {
            keepRollButton.setFill(BUTTON_COLOR);
        }
        // Market buttons
        if (wheatFieldButton.isOverlapping(x,y)){
            wheatFieldButton.setFill(BLUE_CARD_HOVER_COLOR);
            cardImage = &wheatFieldFile;
        }
        else {
            wheatFieldButton.setFill(BLUE_CARD_COLOR);
        }
        if (ranchButton.isOverlapping(x,y)){
            ranchButton.setFill(BLUE_CARD_HOVER_COLOR);
            cardImage = &ranchFile;
        }
        else {
            ranchButton.setFill(BLUE_CARD_COLOR);
        }
        if (bakeryButton.isOverlapping(x,y)){
            bakeryButton.setFill(GREEN_CARD_HOVER_COLOR);
            cardImage = &bakeryFile;
        }
        else {
            bakeryButton.setFill(GREEN_CARD_COLOR);
        }
        if (cafeButton.isOverlapping(x,y)){
            cafeButton.setFill(RED_CARD_HOVER_COLOR);
            cardImage = &cafeFile;
        }
        else {
            cafeButton.setFill(RED_CARD_COLOR);
        }
        if (convenienceStoreButton.isOverlapping(x,y)){
            convenienceStoreButton.setFill(GREEN_CARD_HOVER_COLOR);
            cardImage = &convenienceStoreFile;
        }
        else {
            convenienceStoreButton.setFill(GREEN_CARD_COLOR);
        }
        if (forestButton.isOverlapping(x,y)){
            forestButton.setFill(BLUE_CARD_HOVER_COLOR);
            cardImage = &forestFile;
        }
        else {
            forestButton.setFill(BLUE_CARD_COLOR);
        }
        if (tvStationButton.isOverlapping(x,y)){
            tvStationButton.setFill(PURPLE_CARD_HOVER_COLOR);
            cardImage = &tvStationFile;
        }
        else {
            tvStationButton.setFill(PURPLE_CARD_COLOR);
        }
        if (stadiumButton.isOverlapping(x,y)){
            stadiumButton.setFill(PURPLE_CARD_HOVER_COLOR);
            cardImage = &stadiumFile;
        }
        else {
            stadiumButton.setFill(PURPLE_CARD_COLOR);
        }
        if (businessCenterButton.isOverlapping(x,y)){
            businessCenterButton.setFill(PURPLE_CARD_HOVER_COLOR);
            cardImage = &businessCenterFile;
        }
        else {
            businessCenterButton.setFill(PURPLE_CARD_COLOR);
        }
        if (cheeseFactoryButton.isOverlapping(x,y)){
            cheeseFactoryButton.setFill(GREEN_CARD_HOVER_COLOR);
            cardImage = &cheeseFactoryFile;
        }
        else {
            cheeseFactoryButton.setFill(GREEN_CARD_COLOR);
        }
        if (furnitureFactoryButton.isOverlapping(x,y)){
            furnitureFactoryButton.setFill(GREEN_CARD_HOVER_COLOR);
            cardImage = &furnitureFactoryFile;
        }
        else {
            furnitureFactoryButton.setFill(GREEN_CARD_COLOR);
        }
        if (mineButton.isOverlapping(x,y)){
            mineButton.setFill(BLUE_CARD_HOVER_COLOR);
            cardImage = &mineFile;
        }
        else {
            mineButton.setFill(BLUE_CARD_COLOR);
        }
        if (familyRestaurantButton.isOverlapping(x,y)){
            familyRestaurantButton.setFill(RED_CARD_HOVER_COLOR);
            cardImage = &familyRestaurantFile;
        }
        else {
            familyRestaurantButton.setFill(RED_CARD_COLOR);
        }
        if (appleOrchardButton.isOverlapping(x,y)){
            appleOrchardButton.setFill(BLUE_CARD_HOVER_COLOR);
            cardImage = &appleOrchardFile;
        }
        else {
            appleOrchardButton.setFill(BLUE_CARD_COLOR);
        }
        if (fruitAndVegetableMarketButton.isOverlapping(x,y)){
            fruitAndVegetableMarketButton.setFill(GREEN_CARD_HOVER_COLOR);
        }
        else {
            fruitAndVegetableMarketButton.setFill(GREEN_CARD_COLOR);
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

        // Main Menu Button
        if (mainMenuButton.isOverlapping(x,y) && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            screen = start;
        }

        // Game option buttons
        else if (rollDieButton.isOverlapping(x,y) && !Game.diceRolled && Game.turnPhase == roll && button == GLUT_LEFT_BUTTON && state == GLUT_UP ){
            Game.dice1Roll = (rand() % 6) + 1;
            Game.dice2Roll = 0;
            Game.diceRolled = true;
        }
        else if (roll2diceButton.isOverlapping(x,y) && !Game.diceRolled && Game.turnPhase == roll && Game.players[Game.currentPlayerIndex].getTrainStationBool() && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            Game.dice1Roll = (rand() % 6) + 1;
            Game.dice2Roll = (rand() % 6) + 1;
            Game.diceRolled = true;
        }
        else if (skipBuyButton.isOverlapping(x,y) && !Game.boughtCard && Game.turnPhase == buy && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            Game.turnPhase = endturn;
        }
        else if (rerollButton.isOverlapping(x,y) && Game.turnPhase == radioTower && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            Game.dice1Roll = 0;
            Game.dice2Roll = 0;
            Game.diceSum = 0;
            Game.turnPhase = roll;
        }
        else if (keepRollButton.isOverlapping(x,y) && Game.turnPhase == radioTower && button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
            Game.turnPhase = distribution;
        }
        // Market Buttons
        else if(wheatFieldButton.isOverlapping(x, y) && !Game.boughtCard && numOfWheatField > 0 && Game.turnPhase == buy && Game.players[Game.currentPlayerIndex].getMoney() >= WHEAT_FIELD_COST && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<WheatField>(WheatField(WHEAT_FIELD_DESCRIPTION, WHEAT_FIELD_COST, WHEAT_FIELD_RANGE, WHEAT_FIELD_TYPE, blueCardRectangle, WHEAT_FIELD_NAME, WHEAT_FIELD_SYMBOL)));
            Game.players[Game.currentPlayerIndex].setMoney(Game.players[Game.currentPlayerIndex].getMoney() - WHEAT_FIELD_COST);
            numOfWheatField--;
            Game.boughtCard = true;
        }
        else if(ranchButton.isOverlapping(x, y) && !Game.boughtCard && numOfRanch > 0 && Game.players[Game.currentPlayerIndex].getMoney() >= RANCH_COST && Game.turnPhase == buy && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<Ranch>(Ranch(RANCH_DESCRIPTION, RANCH_COST, RANCH_RANGE, RANCH_TYPE, blueCardRectangle, RANCH_NAME, RANCH_SYMBOL)));
            Game.players[Game.currentPlayerIndex].setMoney(Game.players[Game.currentPlayerIndex].getMoney() - RANCH_COST);
            numOfRanch--;
            Game.boughtCard = true;
        }
        else if(bakeryButton.isOverlapping(x, y) && !Game.boughtCard && numOfBakery > 0 && Game.players[Game.currentPlayerIndex].getMoney() >= BAKERY_COST && Game.turnPhase == buy && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<Bakery>(Bakery(BAKERY_DESCRIPTION, BAKERY_COST, BAKERY_RANGE, BAKERY_TYPE, greenCardRectangle, BAKERY_NAME, BAKERY_SYMBOL)));
            Game.players[Game.currentPlayerIndex].setMoney(Game.players[Game.currentPlayerIndex].getMoney() - RANCH_COST);
            numOfBakery--;
            Game.boughtCard = true;
        }
        else if(cafeButton.isOverlapping(x, y) && !Game.boughtCard && numOfCafe > 0 && Game.players[Game.currentPlayerIndex].getMoney() >= CAFE_COST && Game.turnPhase == buy && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<Cafe>(Cafe(CAFE_DESCRIPTION, CAFE_COST, CAFE_RANGE, CAFE_TYPE, redCardRectangle, CAFE_NAME, CAFE_SYMBOL)));
            Game.players[Game.currentPlayerIndex].setMoney(Game.players[Game.currentPlayerIndex].getMoney() - CAFE_COST);
            numOfCafe--;
            Game.boughtCard = true;
        }
        else if(convenienceStoreButton.isOverlapping(x, y) && !Game.boughtCard && numOfConvenienceStore > 0 && Game.players[Game.currentPlayerIndex].getMoney() >= CONVENIENCE_STORE_COST && Game.turnPhase == buy && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<ConvenienceStore>(ConvenienceStore(CONVENIENCE_STORE_DESCRIPTION, CONVENIENCE_STORE_COST, CONVENIENCE_STORE_RANGE, CONVENIENCE_STORE_TYPE, greenCardRectangle, CONVENIENCE_STORE_NAME, CONVENIENCE_STORE_SYMBOL)));
            Game.players[Game.currentPlayerIndex].setMoney(Game.players[Game.currentPlayerIndex].getMoney() - CONVENIENCE_STORE_COST);
            numOfConvenienceStore--;
            Game.boughtCard = true;
        }
        else if(forestButton.isOverlapping(x, y) && !Game.boughtCard && numOfForest > 0 && Game.players[Game.currentPlayerIndex].getMoney() >= FOREST_COST && Game.turnPhase == buy && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<Forest>(Forest(FOREST_DESCRIPTION, FOREST_COST, FOREST_RANGE, FOREST_TYPE, blueCardRectangle, FOREST_NAME, FOREST_SYMBOL)));
            Game.players[Game.currentPlayerIndex].setMoney(Game.players[Game.currentPlayerIndex].getMoney() - FOREST_COST);
            numOfForest--;
            Game.boughtCard = true;
        }
        else if(Game.players[Game.currentPlayerIndex].getNumberOfEstablishment(TV_STATION_NAME) == 0 && tvStationButton.isOverlapping(x, y) && !Game.boughtCard && numOfTVStation > 0 && Game.players[Game.currentPlayerIndex].getMoney() >= TV_STATION_COST && Game.turnPhase == buy && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<TVStation>(TVStation(TV_STATION_DESCRIPTION, TV_STATION_COST, TV_STATION_RANGE, TV_STATION_TYPE, purpleCardRectangle, TV_STATION_NAME, TV_STATION_SYMBOL)));
            Game.players[Game.currentPlayerIndex].setMoney(Game.players[Game.currentPlayerIndex].getMoney() - TV_STATION_COST);
            numOfTVStation--;
            Game.boughtCard = true;
        }
        else if(Game.players[Game.currentPlayerIndex].getNumberOfEstablishment(STADIUM_NAME) == 0 && stadiumButton.isOverlapping(x, y) && !Game.boughtCard && numOfStadium > 0 && Game.players[Game.currentPlayerIndex].getMoney() >= STADIUM_COST && Game.turnPhase == buy && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<Stadium>(Stadium(STADIUM_DESCRIPTION, STADIUM_COST, STADIUM_RANGE, STADIUM_TYPE, purpleCardRectangle, STADIUM_NAME, STADIUM_SYMBOL)));
            Game.players[Game.currentPlayerIndex].setMoney(Game.players[Game.currentPlayerIndex].getMoney() - STADIUM_COST);
            numOfStadium--;
            Game.boughtCard = true;
        }
        else if(Game.players[Game.currentPlayerIndex].getNumberOfEstablishment(BUSINESS_CENTER_NAME) == 0 && businessCenterButton.isOverlapping(x, y) && !Game.boughtCard && numOfBusinessCenter > 0 && Game.players[Game.currentPlayerIndex].getMoney() >= BUSINESS_CENTER_COST && Game.turnPhase == buy && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<BusinessCenter>(BusinessCenter(BUSINESS_CENTER_DESCRIPTION, BUSINESS_CENTER_COST, BUSINESS_CENTER_RANGE, BUSINESS_CENTER_TYPE, purpleCardRectangle, BUSINESS_CENTER_NAME, BUSINESS_CENTER_SYMBOL)));
            Game.players[Game.currentPlayerIndex].setMoney(Game.players[Game.currentPlayerIndex].getMoney() - CAFE_COST);
            numOfBusinessCenter--;
            Game.boughtCard = true;
        }
        else if(cheeseFactoryButton.isOverlapping(x, y) && !Game.boughtCard && numOfCheeseFactory > 0 && Game.players[Game.currentPlayerIndex].getMoney() >= CHEESE_FACTORY_COST && Game.turnPhase == buy && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<CheeseFactory>(CheeseFactory(CHEESE_FACTORY_DESCRIPTION, CHEESE_FACTORY_COST, CHEESE_FACTORY_RANGE, CHEESE_FACTORY_TYPE, greenCardRectangle, CHEESE_FACTORY_NAME, CHEESE_FACTORY_SYMBOL)));
            Game.players[Game.currentPlayerIndex].setMoney(Game.players[Game.currentPlayerIndex].getMoney() - CHEESE_FACTORY_COST);
            numOfCheeseFactory--;
            Game.boughtCard = true;
        }
        else if(furnitureFactoryButton.isOverlapping(x, y) && !Game.boughtCard && numOfFurnitureFactory > 0 && Game.players[Game.currentPlayerIndex].getMoney() >= FURNITURE_FACTORY_COST && Game.turnPhase == buy && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<FurnitureFactory>(FurnitureFactory(FURNITURE_FACTORY_DESCRIPTION, FURNITURE_FACTORY_COST, FURNITURE_FACTORY_RANGE, FURNITURE_FACTORY_TYPE, greenCardRectangle, FURNITURE_FACTORY_NAME, FURNITURE_FACTORY_SYMBOL)));
            Game.players[Game.currentPlayerIndex].setMoney(Game.players[Game.currentPlayerIndex].getMoney() - FURNITURE_FACTORY_COST);
            numOfFurnitureFactory--;
            Game.boughtCard = true;
        }
        else if(mineButton.isOverlapping(x, y) && !Game.boughtCard && numOfMine > 0 && Game.players[Game.currentPlayerIndex].getMoney() >= MINE_COST && Game.turnPhase == buy && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<Mine>(Mine(MINE_DESCRIPTION, MINE_COST, MINE_RANGE, MINE_TYPE, blueCardRectangle, MINE_NAME, MINE_SYMBOL)));
            Game.players[Game.currentPlayerIndex].setMoney(Game.players[Game.currentPlayerIndex].getMoney() - MINE_COST);
            numOfMine--;
            Game.boughtCard = true;
        }
        else if(familyRestaurantButton.isOverlapping(x, y) && !Game.boughtCard && numOfFamilyRestaurant > 0 && Game.players[Game.currentPlayerIndex].getMoney() >= FAMILY_RESTAURANT_COST && Game.turnPhase == buy && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<FamilyRestaurant>(FamilyRestaurant(FAMILY_RESTAURANT_DESCRIPTION, FAMILY_RESTAURANT_COST, FAMILY_RESTAURANT_RANGE, FAMILY_RESTAURANT_TYPE, redCardRectangle, FAMILY_RESTAURANT_NAME, FAMILY_RESTAURANT_SYMBOL)));
            Game.players[Game.currentPlayerIndex].setMoney(Game.players[Game.currentPlayerIndex].getMoney() - FAMILY_RESTAURANT_COST);
            numOfFamilyRestaurant--;
            Game.boughtCard = true;
        }
        else if(appleOrchardButton.isOverlapping(x, y) && !Game.boughtCard && numOfAppleOrchard > 0 && Game.players[Game.currentPlayerIndex].getMoney() >= APPLE_ORCHARD_COST && Game.turnPhase == buy && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<AppleOrchard>(AppleOrchard(APPLE_ORCHARD_DESCRIPTION, APPLE_ORCHARD_COST, APPLE_ORCHARD_RANGE, APPLE_ORCHARD_TYPE, blueCardRectangle, APPLE_ORCHARD_NAME, APPLE_ORCHARD_SYMBOL)));
            Game.players[Game.currentPlayerIndex].setMoney(Game.players[Game.currentPlayerIndex].getMoney() - APPLE_ORCHARD_COST);
            numOfAppleOrchard--;
            Game.boughtCard = true;
        }
        else if(fruitAndVegetableMarketButton.isOverlapping(x, y) && !Game.boughtCard && numOfFruitandVeggieMarket > 0 && Game.players[Game.currentPlayerIndex].getMoney() >= FRUIT_AND_VEGETABLE_MARKET_COST && Game.turnPhase == buy && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            Game.players[Game.currentPlayerIndex].addEstablishment(make_shared<FruitAndVegetableMarket>(FruitAndVegetableMarket(FRUIT_AND_VEGETABLE_MARKET_DESCRIPTION, FRUIT_AND_VEGETABLE_MARKET_COST, FRUIT_AND_VEGETABLE_MARKET_RANGE, FRUIT_AND_VEGETABLE_MARKET_TYPE, greenCardRectangle, FRUIT_AND_VEGETABLE_MARKET_NAME, FRUIT_AND_VEGETABLE_MARKET_SYMBOL)));
            Game.players[Game.currentPlayerIndex].setMoney(Game.players[Game.currentPlayerIndex].getMoney() - FRUIT_AND_VEGETABLE_MARKET_COST);
            numOfFruitandVeggieMarket--;
            Game.boughtCard = true;
        }

        // Landmark Slot buttons
        else if(trainStationSlot.isOverlapping(x, y) && !Game.players[Game.currentPlayerIndex].getTrainStationBool() && !Game.boughtCard && Game.players[Game.currentPlayerIndex].getMoney() >= TRAIN_STATION_COST && Game.turnPhase == buy && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            Game.players[Game.currentPlayerIndex].setTrainStationBool(true);
            Game.players[Game.currentPlayerIndex].setMoney(Game.players[Game.currentPlayerIndex].getMoney() - TRAIN_STATION_COST);
            Game.boughtCard = true;
        }
        else if(shoppingMallSlot.isOverlapping(x, y) && !Game.players[Game.currentPlayerIndex].getShoppingMallBool() && !Game.boughtCard && Game.players[Game.currentPlayerIndex].getMoney() >= SHOPPING_MALL_COST && Game.turnPhase == buy && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            Game.players[Game.currentPlayerIndex].setShoppingMallBool(true);
            Game.players[Game.currentPlayerIndex].setMoney(Game.players[Game.currentPlayerIndex].getMoney() - SHOPPING_MALL_COST);
            Game.boughtCard = true;
        }
        else if(amusementParkSlot.isOverlapping(x, y) && !Game.players[Game.currentPlayerIndex].getAmusementParkBool() && !Game.boughtCard && Game.players[Game.currentPlayerIndex].getMoney() >= AMUSEMENT_PARK_COST && Game.turnPhase == buy && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            Game.players[Game.currentPlayerIndex].setAmusementParkBool(true);
            Game.players[Game.currentPlayerIndex].setMoney(Game.players[Game.currentPlayerIndex].getMoney() - AMUSEMENT_PARK_COST);
            Game.boughtCard = true;
        }
        else if(radioTowerSlot.isOverlapping(x, y) && !Game.players[Game.currentPlayerIndex].getRadioTowerBool() && !Game.boughtCard && Game.players[Game.currentPlayerIndex].getMoney() >= RADIO_TOWER_COST && Game.turnPhase == buy && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            Game.players[Game.currentPlayerIndex].setRadioTowerBool(true);
            Game.players[Game.currentPlayerIndex].setMoney(Game.players[Game.currentPlayerIndex].getMoney() - RADIO_TOWER_COST);
            Game.boughtCard = true;
        }

        if (Game.turnPhase != tvStation) {
            // Player Buttons
            if (player1button.isOverlapping(x, y) && button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
                //Game.focusedPlayer = Game.players[0];
                Game.focusedPlayerIndex = 0;
            } else if (player2button.isOverlapping(x, y) && button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
                //Game.focusedPlayer = Game.players[1];
                Game.focusedPlayerIndex = 1;
            }
        }

        if (Game.turnPhase == businessCenter){
            if (wheatFieldSlot.isOverlapping(x, y) && Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(WHEAT_FIELD_NAME) > 0 && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
                if (Game.focusedPlayerIndex == Game.currentPlayerIndex){
                    Game.businessCenterCurrentPlayerCard = WHEAT_FIELD_NAME;
                }
                else {
                    Game.businessCenterTargetPlayerCard = WHEAT_FIELD_NAME;
                    Game.businessCenterTargetPlayerIndex = Game.focusedPlayerIndex;

                }
            }
            else if (bakerySlot.isOverlapping(x, y) && Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(BAKERY_NAME) > 0 && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
                if (Game.focusedPlayerIndex == Game.currentPlayerIndex){
                    Game.businessCenterCurrentPlayerCard = BAKERY_NAME;
                }
                else {
                    Game.businessCenterTargetPlayerCard = BAKERY_NAME;
                    Game.businessCenterTargetPlayerIndex = Game.focusedPlayerIndex;

                }
            }
            else if (ranchSlot.isOverlapping(x, y) && Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(RANCH_NAME) > 0 && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
                if (Game.focusedPlayerIndex == Game.currentPlayerIndex){
                    Game.businessCenterCurrentPlayerCard = RANCH_NAME;
                }
                else {
                    Game.businessCenterTargetPlayerCard = RANCH_NAME;
                    Game.businessCenterTargetPlayerIndex = Game.focusedPlayerIndex;
                }
            }
            else if (cafeSlot.isOverlapping(x, y) && Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(CAFE_NAME) > 0 && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
                if (Game.focusedPlayerIndex == Game.currentPlayerIndex){
                    Game.businessCenterCurrentPlayerCard = CAFE_NAME;
                }
                else {
                    Game.businessCenterTargetPlayerCard = CAFE_NAME;
                    Game.businessCenterTargetPlayerIndex = Game.focusedPlayerIndex;

                }
            }
            else if (convenienceStoreSlot.isOverlapping(x, y) && Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(CONVENIENCE_STORE_NAME) > 0 && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
                if (Game.focusedPlayerIndex == Game.currentPlayerIndex){
                    Game.businessCenterCurrentPlayerCard = CONVENIENCE_STORE_NAME;
                }
                else {
                    Game.businessCenterTargetPlayerCard = CONVENIENCE_STORE_NAME;
                    Game.businessCenterTargetPlayerIndex = Game.focusedPlayerIndex;

                }
            }
            else if (forestSlot.isOverlapping(x, y) && Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(FOREST_NAME) > 0 && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
                if (Game.focusedPlayerIndex == Game.currentPlayerIndex){
                    Game.businessCenterCurrentPlayerCard = FOREST_NAME;
                }
                else {
                    Game.businessCenterTargetPlayerCard = FOREST_NAME;
                    Game.businessCenterTargetPlayerIndex = Game.focusedPlayerIndex;

                }
            }
            else if (cheeseFactorySlot.isOverlapping(x, y) && Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(CHEESE_FACTORY_NAME) > 0 && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
                if (Game.focusedPlayerIndex == Game.currentPlayerIndex){
                    Game.businessCenterCurrentPlayerCard = CHEESE_FACTORY_NAME;
                }
                else {
                    Game.businessCenterTargetPlayerCard = CHEESE_FACTORY_NAME;
                    Game.businessCenterTargetPlayerIndex = Game.focusedPlayerIndex;

                }
            }
            else if (furnitureFactorySlot.isOverlapping(x, y) && Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(FURNITURE_FACTORY_NAME) > 0 && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
                if (Game.focusedPlayerIndex == Game.currentPlayerIndex){
                    Game.businessCenterCurrentPlayerCard = FURNITURE_FACTORY_NAME;
                }
                else {
                    Game.businessCenterTargetPlayerCard = FURNITURE_FACTORY_NAME;
                    Game.businessCenterTargetPlayerIndex = Game.focusedPlayerIndex;

                }
            }
            else if (mineSlot.isOverlapping(x, y) && Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(MINE_NAME) > 0 && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
                if (Game.focusedPlayerIndex == Game.currentPlayerIndex){
                    Game.businessCenterCurrentPlayerCard = MINE_NAME;
                }
                else {
                    Game.businessCenterTargetPlayerCard = MINE_NAME;
                    Game.businessCenterTargetPlayerIndex = Game.focusedPlayerIndex;

                }
            }
            else if (familyRestaurantSlot.isOverlapping(x, y) && Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(FAMILY_RESTAURANT_NAME) > 0 && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
                if (Game.focusedPlayerIndex == Game.currentPlayerIndex){
                    Game.businessCenterCurrentPlayerCard = FAMILY_RESTAURANT_NAME;
                }
                else {
                    Game.businessCenterTargetPlayerCard = FAMILY_RESTAURANT_NAME;
                    Game.businessCenterTargetPlayerIndex = Game.focusedPlayerIndex;

                }
            }
            else if (appleOrchardSlot.isOverlapping(x, y) && Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(APPLE_ORCHARD_NAME) > 0 && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
                if (Game.focusedPlayerIndex == Game.currentPlayerIndex){
                    Game.businessCenterCurrentPlayerCard = APPLE_ORCHARD_NAME;
                }
                else {
                    Game.businessCenterTargetPlayerCard = APPLE_ORCHARD_NAME;
                    Game.businessCenterTargetPlayerIndex = Game.focusedPlayerIndex;
                }
            }
            else if (fruitAndVegetableMarketSlot.isOverlapping(x, y) && Game.players[Game.focusedPlayerIndex].getNumberOfEstablishment(FRUIT_AND_VEGETABLE_MARKET_NAME) > 0 && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
                if (Game.focusedPlayerIndex == Game.currentPlayerIndex){
                    Game.businessCenterCurrentPlayerCard = FRUIT_AND_VEGETABLE_MARKET_NAME;
                }
                else {
                    Game.businessCenterTargetPlayerCard = FRUIT_AND_VEGETABLE_MARKET_NAME;
                    Game.businessCenterTargetPlayerIndex = Game.focusedPlayerIndex;
                }
            }
        }
        else if(Game.turnPhase == tvStation){
            // Press player 1 button
            if (player1button.isOverlapping(x, y) && button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
                if (Game.currentPlayerIndex == 0){
                    Game.focusedPlayerIndex = 0;
                }
                else if (Game.currentPlayerIndex == 1){
                    if (Game.players[0].getMoney() >= 5){
                        Game.players[0].setMoney(Game.players[0].getMoney() - 5);
                        Game.players[1].setMoney(Game.players[1].getMoney() + 5);
                        if (Game.skipBusinessCenter == true){
                            Game.turnPhase = buy;
                        }
                        else {
                            Game.turnPhase = businessCenter;
                        }
                    }
                }
            }
            // Press player 2 button
            else if (player2button.isOverlapping(x, y) && button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
                if (Game.currentPlayerIndex == 1){
                    Game.focusedPlayerIndex = 1;
                }
                else if (Game.currentPlayerIndex == 0){
                    if (Game.players[1].getMoney() >= 5){
                        Game.players[1].setMoney(Game.players[1].getMoney() - 5);
                        Game.players[0].setMoney(Game.players[0].getMoney() + 5);
                        if (Game.skipBusinessCenter == true){
                            Game.turnPhase = buy;
                        }
                        else {
                            Game.turnPhase = businessCenter;
                        }
                    }
                }
            }
        }

    }
    else if (screen == endGame){
        if (mainMenuButton.isOverlapping(x,y) && button == GLUT_LEFT_BUTTON && state == GLUT_UP){
            screen = start;
            resetGame();
        }
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

