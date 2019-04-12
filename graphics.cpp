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
    turnPhase turnPhase = roll;
    bool boughtCard = false;

}Game;


struct CardData{

    shared_ptr<WheatField> wheat_field_card = make_shared<WheatField>();
    shared_ptr<Ranch> ranch_card = make_shared<Ranch>();
    shared_ptr<Forest> forest_card = make_shared<Forest>();
    shared_ptr<Mine> mine_card = make_shared<Mine>();
    shared_ptr<AppleOrchard> apple_orchard_card = make_shared<AppleOrchard>();
    shared_ptr<Bakery> bakery_card = make_shared<Bakery>();
    shared_ptr<ConvenienceStore> convenience_store_card = make_shared<ConvenienceStore>();
    shared_ptr<CheeseFactory> cheese_factory_card = make_shared<CheeseFactory>();
    shared_ptr<FurnitureFactory> furniture_factory_card = make_shared<FurnitureFactory>();
    shared_ptr<FruitAndVegetableMarket> fruit_and_veggie_market_card = make_shared<FruitAndVegetableMarket>();
    shared_ptr<Cafe> cafe_card = make_shared<Cafe>();
    shared_ptr<FamilyRestaurant> family_restaurant_card = make_shared<FamilyRestaurant>();
    shared_ptr<Stadium> stadium_card = make_shared<Stadium>();
    shared_ptr<TVStation> tv_station_card = make_shared<TVStation>();
    shared_ptr<BusinessCenter> business_center_card = make_shared<BusinessCenter>();

    int numOfWheatField = 1;
    int numOfRanch = 0;
    int numOfForest = 0;
    int numOfMine = 0;
    int numOfAppleOrchard = 0;
    int numOfBakery = 0;
    int numOfConvenienceStore = 0;
    int numOfCheeseFactory = 0;
    int numOfFurnitureFactory = 0;
    int numOfFruitandVeggieMarket = 0;
    int numOfCafe = 0;
    int numOfFamilyRestaurant = 0;
    int numOfStadium = 0;
    int numOfTVStation = 0;
    int numOfBusinessCenter = 0;

    vector<shared_ptr<WheatField>> wfCards;
    vector<shared_ptr<Ranch>> ranchCards;
    vector<shared_ptr<Forest>> forestCards;
    vector<shared_ptr<Mine>> mineCards;
    vector<shared_ptr<AppleOrchard>> aoCards;
    vector<shared_ptr<Bakery>> bakeryCards;
    vector<shared_ptr<ConvenienceStore> > csCards;
    vector<shared_ptr<CheeseFactory>> cfCards;
    vector<shared_ptr<FurnitureFactory>> ffCards;
    vector<shared_ptr<FruitAndVegetableMarket>> fvmCards;
    vector<shared_ptr<Cafe>> cafeCards;
    vector<shared_ptr<FamilyRestaurant>> frCards;
    vector<shared_ptr<Stadium>> stadiumCards;
    vector<shared_ptr<TVStation>> tvsCards;
    vector<shared_ptr<BusinessCenter>> bcCards;


}Cards;


//Function Declarations

void init() {
    width = WIDTH;
    height = HEIGHT;

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

    wheatFieldSlot.draw();
    string message = "Wheat Field";
    drawText18(message, 1, 1, 1, wheatFieldSlot.getX() + 10, wheatFieldSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(WHEAT_FIELD_NAME));
    drawText18(message, 1, 1, 1, wheatFieldSlot.getX() + (wheatFieldSlot.getBase() - 30), wheatFieldSlot.getY() + 20);

    ranchSlot.draw();
    message = "Ranch";
    drawText18(message, 1, 1, 1, ranchSlot.getX() + 10, ranchSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(RANCH_NAME));
    drawText18(message, 1, 1, 1, ranchSlot.getX() + (ranchSlot.getBase() - 30), wheatFieldSlot.getY() + 20);

    bakerySlot.draw();
    message = "Bakery";
    drawText18(message, 1, 1, 1, bakerySlot.getX() + 10, bakerySlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(BAKERY_NAME));
    drawText18(message, 1, 1, 1, bakerySlot.getX() + (bakerySlot.getBase() - 30), wheatFieldSlot.getY() + 20);

    cafeSlot.draw();
    message = "Cafe";
    drawText18(message, 1, 1, 1, cafeSlot.getX() + 10, cafeSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(CAFE_NAME));
    drawText18(message, 1, 1, 1, cafeSlot.getX() + (cafeSlot.getBase() - 30), wheatFieldSlot.getY() + 20);

    convenienceStoreSlot.draw();
    message = "Convenience Store";
    drawText18(message, 1, 1, 1, convenienceStoreSlot.getX() + 10, convenienceStoreSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(CONVENIENCE_STORE_NAME));
    drawText18(message, 1, 1, 1, convenienceStoreSlot.getX() + (convenienceStoreSlot.getBase() - 30), wheatFieldSlot.getY() + 20);

    forestSlot.draw();
    message = "Forest";
    drawText18(message, 1, 1, 1, forestSlot.getX() + 10, forestSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(FOREST_NAME));
    drawText18(message, 1, 1, 1, forestSlot.getX() + (forestSlot.getBase() - 30), wheatFieldSlot.getY() + 20);

    tvStationSlot.draw();
    message = "TV Station";
    drawText18(message, 1, 1, 1, tvStationSlot.getX() + 10, tvStationSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(TV_STATION_NAME));
    drawText18(message, 1, 1, 1, tvStationSlot.getX() + (tvStationSlot.getBase() - 30), wheatFieldSlot.getY() + 20);

    stadiumSlot.draw();
    message = "Stadium";
    drawText18(message, 1, 1, 1, stadiumSlot.getX() + 10, stadiumSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(STADIUM_NAME));
    drawText18(message, 1, 1, 1, stadiumSlot.getX() + (stadiumSlot.getBase() - 30), wheatFieldSlot.getY() + 20);

    bussinessCenterSlot.draw();
    message = "Bussiness Center";
    drawText18(message, 1, 1, 1, bussinessCenterSlot.getX() + 10, bussinessCenterSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(BUSSINESS_CENTER_NAME));
    drawText18(message, 1, 1, 1, bussinessCenterSlot.getX() + (bussinessCenterSlot.getBase() - 30), wheatFieldSlot.getY() + 20);

    cheeseFactorySlot.draw();
    message = "Cheese Factory";
    drawText18(message, 1, 1, 1, cheeseFactorySlot.getX() + 10, cheeseFactorySlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(CHEESE_FACTORY_NAME));
    drawText18(message, 1, 1, 1, cheeseFactorySlot.getX() + (cheeseFactorySlot.getBase() - 30), wheatFieldSlot.getY() + 20);

    furnitureFactorySlot.draw();
    message = "Furniture Factory";
    drawText18(message, 1, 1, 1, furnitureFactorySlot.getX() + 10, furnitureFactorySlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(FURNITURE_FACTORY_NAME));
    drawText18(message, 1, 1, 1, furnitureFactorySlot.getX() + (furnitureFactorySlot.getBase() - 30), wheatFieldSlot.getY() + 20);

    mineSlot.draw();
    message = "Mine";
    drawText18(message, 1, 1, 1, mineSlot.getX() + 10, mineSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(MINE_NAME));
    drawText18(message, 1, 1, 1, mineSlot.getX() + (mineSlot.getBase() - 30), wheatFieldSlot.getY() + 20);

    familyRestaurantSlot.draw();
    message = "Family Restaurant";
    drawText18(message, 1, 1, 1, familyRestaurantSlot.getX() + 10, familyRestaurantSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(FAMILY_RESTAURANT_NAME));
    drawText18(message, 1, 1, 1, familyRestaurantSlot.getX() + (familyRestaurantSlot.getBase() - 30), wheatFieldSlot.getY() + 20);

    appleOrchardSlot.draw();
    message = "Apple Orchard";
    drawText18(message, 1, 1, 1, appleOrchardSlot.getX() + 10, appleOrchardSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(APPLE_ORCHARD_NAME));
    drawText18(message, 1, 1, 1, appleOrchardSlot.getX() + (appleOrchardSlot.getBase() - 30), wheatFieldSlot.getY() + 20);

    fruitAndVegetableMarketSlot.draw();
    message = "Fruit and Vegetable Market";
    drawText18(message, 1, 1, 1, fruitAndVegetableMarketSlot.getX() + 10, fruitAndVegetableMarketSlot.getY() + 20);
    message = to_string(Game.currentPlayer.getNumberOfEstablishment(FRUIT_AND_VEGETABLE_MARKET_NAME));
    drawText18(message, 1, 1, 1, fruitAndVegetableMarketSlot.getX() + (fruitAndVegetableMarketSlot.getBase() - 30), wheatFieldSlot.getY() + 20);

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

    if(Game.gameBegin){
        initializeGame(2);
    }

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

void initializeCards(){

    Cards.wheat_field_card->setName(WHEAT_FIELD_NAME);
    Cards.wheat_field_card->setCost(WHEAT_FIELD_COST);
    Cards.wheat_field_card->setActivation(WHEAT_FIELD_RANGE);
    Cards.wheat_field_card->setCardType(WHEAT_FIELD_TYPE);
    Cards.wheat_field_card->setDescription(WHEAT_FIELD_DESCRIPTION);
    Cards.wheat_field_card->setCardSymbol(WHEAT_FIELD_SYMBOL);
    for(int i = 0; i < Cards.numOfWheatField; ++i){
        Cards.wfCards.push_back(Cards.wheat_field_card);
    }

    Cards.ranch_card->setName(RANCH_NAME);
    Cards.ranch_card->setCost(RANCH_COST);
    Cards.ranch_card->setActivation(RANCH_RANGE);
    Cards.ranch_card->setCardType(RANCH_TYPE);
    Cards.ranch_card->setDescription(RANCH_DESCRIPTION);
    Cards.ranch_card->setCardSymbol(RANCH_SYMBOL);
    for(int i = 0; i < Cards.numOfRanch; ++i){
        Cards.ranchCards.push_back(Cards.ranch_card);
    }

    Cards.forest_card->setName(FOREST_NAME);
    Cards.forest_card->setCost(FOREST_COST);
    Cards.forest_card->setActivation(FOREST_RANGE);
    Cards.forest_card->setCardType(FOREST_TYPE);
    Cards.forest_card->setDescription(FOREST_DESCRIPTION);
    Cards.forest_card->setCardSymbol(FOREST_SYMBOL);
    for(int i = 0; i < Cards.numOfForest; ++i){
        Cards.forestCards.push_back(Cards.forest_card);
    }

    Cards.mine_card->setName(MINE_DESCRIPTION);
    Cards.mine_card->setCost(MINE_COST);
    Cards.mine_card->setActivation(MINE_RANGE);
    Cards.mine_card->setCardType(MINE_TYPE);
    Cards.mine_card->setDescription(MINE_DESCRIPTION);
    Cards.mine_card->setCardSymbol(MINE_SYMBOL);
    for(int i = 0; i < Cards.numOfMine; ++i){
        Cards.mineCards.push_back(Cards.mine_card);
    }

    Cards.apple_orchard_card->setName(APPLE_ORCHARD_NAME);
    Cards.apple_orchard_card->setCost(APPLE_ORCHARD_COST);
    Cards.apple_orchard_card->setActivation(APPLE_ORCHARD_RANGE);
    Cards.apple_orchard_card->setCardType(APPLE_ORCHARD_TYPE);
    Cards.apple_orchard_card->setDescription(APPLE_ORCHARD_DESCRIPTION);
    Cards.apple_orchard_card->setCardSymbol(APPLE_ORCHARD_SYMBOL);
    for(int i = 0; i < Cards.numOfAppleOrchard; ++i){
        Cards.aoCards.push_back(Cards.apple_orchard_card);
    }

    Cards.bakery_card->setName(BAKERY_NAME);
    Cards.bakery_card->setCost(BAKERY_COST);
    Cards.bakery_card->setActivation(BAKERY_RANGE);
    Cards.bakery_card->setCardType(BAKERY_TYPE);
    Cards.bakery_card->setDescription(BAKERY_DESCRIPTION);
    Cards.bakery_card->setCardSymbol(BAKERY_SYMBOL);
    for(int i = 0; i < Cards.numOfBakery; ++i){
        Cards.bakeryCards.push_back(Cards.bakery_card);
    }

    Cards.convenience_store_card->setName(CONVENIENCE_STORE_NAME);
    Cards.convenience_store_card->setCost(CONVENIENCE_STORE_COST);
    Cards.convenience_store_card->setActivation(CONVENIENCE_STORE_RANGE);
    Cards.convenience_store_card->setCardType(CONVENIENCE_STORE_TYPE);
    Cards.convenience_store_card->setDescription(CONVENIENCE_STORE_DESCRIPTION);
    Cards.convenience_store_card->setCardSymbol(CONVENIENCE_STORE_SYMBOL);
    for(int i = 0; i < Cards.numOfConvenienceStore; ++i){
        Cards.csCards.push_back(Cards.convenience_store_card);
    }

    Cards.cheese_factory_card->setName(CHEESE_FACTORY_NAME);
    Cards.cheese_factory_card->setCost(CHEESE_FACTORY_COST);
    Cards.cheese_factory_card->setActivation(CHEESE_FACTORY_RANGE);
    Cards.cheese_factory_card->setCardType(CHEESE_FACTORY_TYPE);
    Cards.cheese_factory_card->setDescription(CHEESE_FACTORY_DESCRIPTION);
    Cards.cheese_factory_card->setCardSymbol(CHEESE_FACTORY_SYMBOL);
    for(int i = 0; i < Cards.numOfCheeseFactory; ++i){
        Cards.cfCards.push_back(Cards.cheese_factory_card);
    }

    Cards.furniture_factory_card->setName(FURNITURE_FACTORY_NAME);
    Cards.furniture_factory_card->setCost(FURNITURE_FACTORY_COST);
    Cards.furniture_factory_card->setActivation(FURNITURE_FACTORY_RANGE);
    Cards.furniture_factory_card->setCardType(FURNITURE_FACTORY_TYPE);
    Cards.furniture_factory_card->setDescription(FURNITURE_FACTORY_DESCRIPTION);
    Cards.furniture_factory_card->setCardSymbol(FURNITURE_FACTORY_SYMBOL);
    for(int i = 0; i < Cards.numOfFurnitureFactory; ++i) {
        Cards.ffCards.push_back(Cards.furniture_factory_card);
    }

    Cards.fruit_and_veggie_market_card->setName(FRUIT_AND_VEGETABLE_MARKET_NAME);
    Cards.fruit_and_veggie_market_card->setCost(FRUIT_AND_VEGETABLE_MARKET_COST);
    Cards.fruit_and_veggie_market_card->setActivation(FRUIT_AND_VEGETABLE_MARKET_RANGE);
    Cards.fruit_and_veggie_market_card->setCardType(FRUIT_AND_VEGETABLE_MARKET_TYPE);
    Cards.fruit_and_veggie_market_card->setDescription(FRUIT_AND_VEGETABLE_MARKET_DESCRIPTION);
    Cards.fruit_and_veggie_market_card->setCardSymbol(FRUIT_AND_VEGETABLE_MARKET_SYMBOL);
    for(int i = 0; i < Cards.numOfFruitandVeggieMarket; ++i){
        Cards.fvmCards.push_back(Cards.fruit_and_veggie_market_card);
    }

    Cards.cafe_card->setName(CAFE_NAME);
    Cards.cafe_card->setCost(CAFE_COST);
    Cards.cafe_card->setActivation(CAFE_RANGE);
    Cards.cafe_card->setCardType(CAFE_TYPE);
    Cards.cafe_card->setDescription(CAFE_DESCRIPTION);
    Cards.cafe_card->setCardSymbol(CAFE_SYMBOL);
    for(int i = 0; i < Cards.numOfCafe; ++i){
        Cards.cafeCards.push_back(Cards.cafe_card);
    }

    Cards.family_restaurant_card->setName(FAMILY_RESTAURANT_NAME);
    Cards.family_restaurant_card->setCost(FAMILY_RESTAURANT_COST);
    Cards.family_restaurant_card->setActivation(FAMILY_RESTAURANT_RANGE);
    Cards.family_restaurant_card->setCardType(FAMILY_RESTAURANT_TYPE);
    Cards.family_restaurant_card->setDescription(FAMILY_RESTAURANT_DESCRIPTION);
    Cards.family_restaurant_card->setCardSymbol(FAMILY_RESTAURANT_SYMBOL);
    for(int i = 0; i < Cards.numOfFamilyRestaurant; ++i){
        Cards.frCards.push_back(Cards.family_restaurant_card);
    }

    Cards.stadium_card->setName(STADIUM_NAME);
    Cards.stadium_card->setCost(STADIUM_COST);
    Cards.stadium_card->setActivation(STADIUM_RANGE);
    Cards.stadium_card->setCardType(STADIUM_TYPE);
    Cards.stadium_card->setDescription(STADIUM_DESCRIPTION);
    Cards.stadium_card->setCardSymbol(STADIUM_SYMBOL);
    for(int i = 0; i < Cards.numOfStadium; ++i){
        Cards.stadiumCards.push_back(Cards.stadium_card);
    }

    Cards.tv_station_card->setName(TV_STATION_NAME);
    Cards.tv_station_card->setCost(TV_STATION_COST);
    Cards.tv_station_card->setActivation(TV_STATION_RANGE);
    Cards.tv_station_card->setCardType(TV_STATION_TYPE);
    Cards.tv_station_card->setDescription(TV_STATION_DESCRIPTION);
    Cards.tv_station_card->setCardSymbol(TV_STATION_SYMBOL);
    for(int i = 0; i < Cards.numOfTVStation; ++i){
        Cards.tvsCards.push_back(Cards.tv_station_card);
    }

    Cards.business_center_card->setName(BUSSINESS_CENTER_NAME);
    Cards.business_center_card->setCost(BUSSINESS_CENTER_COST);
    Cards.business_center_card->setActivation(BUSSINESS_CENTER_RANGE);
    Cards.business_center_card->setCardType(BUSSINESS_CENTER_TYPE);
    Cards.business_center_card->setDescription(BUSSINESS_CENTER_DESCRIPTION);
    Cards.business_center_card->setCardSymbol(BUSSINESS_CENTER_SYMBOL);
    for(int i = 0; i < Cards.numOfBusinessCenter; ++i){
        Cards.bcCards.push_back(Cards.business_center_card);
    }

}

void initializePlayers(int numOfPlayers){

    Player player1 = Player(3);
    Player player2 = Player(3);


    Game.players.push_back(player1);
    Game.players.push_back(player2);

    Game.numOfPlayers = numOfPlayers;


    for(Player player : Game.players){
        player.addEstablishment(Cards.wheat_field_card);
        player.addEstablishment(Cards.bakery_card);
    }

    Game.currentPlayer = player1;
}

void initializeGame(int numOfPlayers){

    initializeCards();

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
    cout << x << "," << y << "\n";

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
        else if (rollDieButton.isOverlapping(x,y) && button == GLUT_LEFT_BUTTON && state == GLUT_UP && !Game.diceRolled){
            Game.dice1Roll = rand() % (6 - 1 + 1) + 1;
            Game.diceRolled = true;
        }
        else if(wheatFieldButton.isOverlapping(x, y) && button == GLUT_LEFT_BUTTON && state == GLUT_UP && !Game.boughtCard && Cards.numOfWheatField != 0){
            Game.currentPlayer.addEstablishment(Cards.wheat_field_card);
            Cards.numOfWheatField--;
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

