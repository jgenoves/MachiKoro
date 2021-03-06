//
// Created by Joshua Newton on 2019-03-29.
//

#ifndef GRAPHICS_GRAPHICSCONSTANTS_H
#define GRAPHICS_GRAPHICSCONSTANTS_H

#include "Shapes.h"
#include "Card.h"
#include "Image.h"
#include <vector>
#include <memory>

/*************************/
/** General Game Constants **/
/*************************/
int STARTING_MONEY = 3;

/*************************/
/** Rectangle Constants **/
/*************************/

int CARD_BASE_DIMENSION = 5;
int CARD_HEIGHT_DIMENSION = 10;

color RED_CARD_COLOR = {(128.0/255.),(21.0/255.),(21.0/255.)}; // Red
color BLUE_CARD_COLOR = {(20.0/255),(70.0/255),(110.0/255)}; // Blue
color GREEN_CARD_COLOR = {(10.0/255),(100.0/255),(10.0/255)}; // Green
color PURPLE_CARD_COLOR = {0.35, 0.1, 0.35}; // Purple
color LANDMARK_CARD_COLOR = {0.5,0.5,0.5}; // Grey
color LANDMARK_CARD_OWNED_COLOR = {(184.0/255),(184.0/255),(20.0/255)}; // Yellow

color RED_CARD_HOVER_COLOR = {(220.0/255),(20.0/255),(60.0/255)}; // Red
color BLUE_CARD_HOVER_COLOR = {(65.0/255),(105.0/255),(225.0/255)}; // Blue
color GREEN_CARD_HOVER_COLOR = {(34.0/255),(180.0/255),(34.0/255)}; // Green
color PURPLE_CARD_HOVER_COLOR = {(153.0/255), (50.0/255), (204.0/255)}; // Purple
color LANDMARK_CARD_HOVER_COLOR = {.6,.6,.6};
color LANDMARK_CARD_OWNED_HOVER_COLOR = {(224.0/255),(224.0/255),(20.0/255)}; // Yellow

/********************/
/** Card Constants **/
/********************/

// Descriptions

string WHEAT_FIELD_DESCRIPTION = "Get 1 coin from the bank, on anyone's turn";
string BAKERY_DESCRIPTION = "Get 1 coin from the bank, on your turn only";
string RANCH_DESCRIPTION = "Get 1 coin from the bank, on anyone's turn";
string CAFE_DESCRIPTION = "Get 1 coin from the player who rolled the dice";
string CONVENIENCE_STORE_DESCRIPTION = "Get 3 coins from the bank, on your turn only";
string FOREST_DESCRIPTION = "Get 1 coin from the bank, on anyone's turn";
string STADIUM_DESCRIPTION = "Get 2 coins from all players, on your turn only";
string TV_STATION_DESCRIPTION = "Take 5 coins from any one player, on your turn only";
string BUSINESS_CENTER_DESCRIPTION = "Trade one non 'tower' establishment with another player, on your turn only";
string CHEESE_FACTORY_DESCRIPTION = "Get 3 coins from the bank for each 'cow' establishment that you own, on your turn only";
string FURNITURE_FACTORY_DESCRIPTION = "Get 3 coins from the bank for each 'gear' establishment that you own, on your turn only";
string MINE_DESCRIPTION = "Get 5 coins from the bank, on anyone's turn";
string FAMILY_RESTAURANT_DESCRIPTION = "Get 2 coins from the player who rolled the dice";
string APPLE_ORCHARD_DESCRIPTION = "Get 3 coins from the bank, on anyone's turn";
string FRUIT_AND_VEGETABLE_MARKET_DESCRIPTION = "Get 2 coins from the bank for each 'wheat' establishment that you own, on your turn only";

// Names

string WHEAT_FIELD_NAME = "Wheat Field";
string BAKERY_NAME = "Bakery";
string RANCH_NAME = "Ranch";
string CAFE_NAME = "Cafe";
string CONVENIENCE_STORE_NAME = "Convenience Store";
string FOREST_NAME = "Forest";
string STADIUM_NAME = "Stadium";
string TV_STATION_NAME = "TV Station";
string BUSINESS_CENTER_NAME = "Business Center";
string CHEESE_FACTORY_NAME = "Cheese Factory";
string FURNITURE_FACTORY_NAME = "Furniture Factory";
string MINE_NAME = "Mine";
string FAMILY_RESTAURANT_NAME = "Family Restaurant";
string APPLE_ORCHARD_NAME = "Apple Orchard";
string FRUIT_AND_VEGETABLE_MARKET_NAME = "Fruit and Vegetable Market";

// Costs

int WHEAT_FIELD_COST = 1;
int BAKERY_COST = 1;
int RANCH_COST = 1;
int CAFE_COST = 2;
int CONVENIENCE_STORE_COST = 2;
int FOREST_COST = 3;
int STADIUM_COST = 6;
int TV_STATION_COST = 7;
int BUSINESS_CENTER_COST = 8;
int CHEESE_FACTORY_COST = 5;
int FURNITURE_FACTORY_COST = 3;
int MINE_COST = 6;
int FAMILY_RESTAURANT_COST = 3;
int APPLE_ORCHARD_COST = 3;
int FRUIT_AND_VEGETABLE_MARKET_COST = 2;

int TRAIN_STATION_COST = 4;
int SHOPPING_MALL_COST = 10;
int AMUSEMENT_PARK_COST = 16;
int RADIO_TOWER_COST = 22;

// Activation Ranges

range WHEAT_FIELD_RANGE = {1,1};
range BAKERY_RANGE = {2,3};
range RANCH_RANGE = {2,2};
range CAFE_RANGE = {3,3};
range CONVENIENCE_STORE_RANGE = {4,4};
range FOREST_RANGE = {5,5};
range STADIUM_RANGE = {6,6};
range TV_STATION_RANGE = {6,6};
range BUSINESS_CENTER_RANGE = {6,6};
range CHEESE_FACTORY_RANGE = {7,7};
range FURNITURE_FACTORY_RANGE = {8,8};
range MINE_RANGE = {9,9};
range FAMILY_RESTAURANT_RANGE = {9,10};
range APPLE_ORCHARD_RANGE = {10,10};
range FRUIT_AND_VEGETABLE_MARKET_RANGE = {11,12};

// Rectangles

RectangleShape redCardRectangle(CARD_BASE_DIMENSION, CARD_HEIGHT_DIMENSION, RED_CARD_COLOR);
RectangleShape blueCardRectangle(CARD_BASE_DIMENSION, CARD_HEIGHT_DIMENSION, BLUE_CARD_COLOR);
RectangleShape greenCardRectangle(CARD_BASE_DIMENSION, CARD_HEIGHT_DIMENSION, GREEN_CARD_COLOR);
RectangleShape purpleCardRectangle(CARD_BASE_DIMENSION, CARD_HEIGHT_DIMENSION, PURPLE_CARD_COLOR);
//RectangleShape landmarkCardRectangle(CARD_BASE_DIMENSION, CARD_HEIGHT_DIMENSION, LANDMARK_CARD_COLOR);

// cardTypes

cardType WHEAT_FIELD_TYPE = primaryIndustry;
cardType BAKERY_TYPE = secondaryIndustry;
cardType RANCH_TYPE = primaryIndustry;
cardType CAFE_TYPE = restaurant;
cardType CONVENIENCE_STORE_TYPE = secondaryIndustry;
cardType FOREST_TYPE = primaryIndustry;
cardType STADIUM_TYPE = majorEstablishment;
cardType TV_STATION_TYPE = majorEstablishment;
cardType BUSINESS_CENTER_TYPE = majorEstablishment;
cardType CHEESE_FACTORY_TYPE = secondaryIndustry;
cardType FURNITURE_FACTORY_TYPE = secondaryIndustry;
cardType MINE_TYPE = primaryIndustry;
cardType FAMILY_RESTAURANT_TYPE = restaurant;
cardType APPLE_ORCHARD_TYPE = primaryIndustry;
cardType FRUIT_AND_VEGETABLE_MARKET_TYPE = secondaryIndustry;

// cardSymbols

cardSymbol WHEAT_FIELD_SYMBOL = wheat;
cardSymbol BAKERY_SYMBOL = box;
cardSymbol RANCH_SYMBOL = cow;
cardSymbol CAFE_SYMBOL = coffeeCup;
cardSymbol CONVENIENCE_STORE_SYMBOL = box;
cardSymbol FOREST_SYMBOL = gear;
cardSymbol STADIUM_SYMBOL = tower;
cardSymbol TV_STATION_SYMBOL = tower;
cardSymbol BUSINESS_CENTER_SYMBOL = tower;
cardSymbol CHEESE_FACTORY_SYMBOL = factory;
cardSymbol FURNITURE_FACTORY_SYMBOL = factory;
cardSymbol MINE_SYMBOL = gear;
cardSymbol FAMILY_RESTAURANT_SYMBOL = coffeeCup;
cardSymbol APPLE_ORCHARD_SYMBOL = wheat;
cardSymbol FRUIT_AND_VEGETABLE_MARKET_SYMBOL = fruit;

// screen enum and variable
enum screenType {start, game, endGame};
screenType screen = start;

enum turnPhase{roll, postRoll, radioTower, distribution, buy, endturn, businessCenter, tvStation};


// Glut constants
int WIDTH = 1400;
int HEIGHT = 800;

// Button constants
int BUTTON_WIDTH = 210;
int BUTTON_HEIGHT = 75;
color BUTTON_COLOR = {.6,.2,.2}; // Red
color BUTTON_HOVER_COLOR = {.2,.6,.5}; // Green
int BUTTON_X_POSITION = 25;
int BUTTON_Y_POSITION = 17;
int START_BUTTONS_X_POSITION = 300;
int START_BUTTONS_Y_POSITION = 300;
int BUTTON_Y_MARGIN = 20;
int BUTTON_X_MARGIN = 20;

int START_IMAGE_X_POSITION = 750;
int START_IMAGE_Y_POSITION = 200;

// In game card button constants
int CARD_BUTTON_WIDTH = 124;
int CARD_BUTTON_HEIGHT = 162;
int TOP_LEFT_CARD_X_POSITION = 355;
int TOP_LEFT_CARD_Y_POSITION = 72;
int CARD_BUTTON_X_MARGIN = 15;
int CARD_BUTTON_Y_MARGIN = 15;

// In game inventory slot constants
int SLOT_WIDTH = 300;
int SLOT_HEIGHT = 30;
int SLOT_X_POSITION = 25;
int SLOT_TOP_Y_POSITION = 110;
int SLOT_Y_MARGIN = 2;

//Roll dice button constants
int ROLL_BUTTON_WIDTH = BUTTON_HEIGHT + 2;
int ROLL_BUTTON_HEIGHT = BUTTON_HEIGHT + 2;
color ROLL_BUTTON_COLOR = {1,1,1};
color ROLL_BUTTON_HOVER = {1, 0.5, 1};
int ROLL_BUTTON_X_POSITION = 362;
int ROLL_BUTTON_Y_POSITION = 685 - BUTTON_HEIGHT;
int ROLL_BUTTON_X_MARGIN = ROLL_BUTTON_WIDTH + 25;

// Player button constants
int PLAYER_BUTTON_X_POSITION = 351;
int PLAYER_BUTTON_Y_POSITION = 705;
int PLAYER_BUTTON_X_MARGIN = 25 + BUTTON_WIDTH;
int PLAYER_BUTTON_Y_MARGIN = 0;

int REROLL_BUTTON_X_POSITION = PLAYER_BUTTON_X_POSITION + PLAYER_BUTTON_X_MARGIN;
int REROLL_BUTTON_Y_POSITION = 685 - BUTTON_HEIGHT;
int REROLL_BUTTON_X_MARGIN = PLAYER_BUTTON_X_MARGIN;
int REROLL_BUTTON_Y_MARGIN = 0;

int SKIP_X_POSITION = PLAYER_BUTTON_X_POSITION + 2 * PLAYER_BUTTON_X_MARGIN;
int SKIP_Y_POSITION = 705;


// Background Stuff
color bgColor1 = {22/255., 27/255., 33/255.}; // darkblue background
color bgColor2 = {188/255.,152/255.,106/255.};
color bgColor3 = {251/255., 238/255., 193/255.};
color bgColor4 = {218/255.,173/255.,134/255.};
color bgColor5 = {177/255.,162/255.,150/255.}; // highlight
color bgColor6 = {40/255.,40/255.,40/255.}; // darken
color bgColor7 = {31/255.,40/255.,51/255.};  // dark 2


RectangleShape bigBackground(2000, 2000, bgColor1, 0, 0);
RectangleShape cardBack(705, 601, bgColor6, 341, 0);
RectangleShape bottomPanel(1159, 800, bgColor7, 341, 0);
RectangleShape imageHighlight(310,470,bgColor5, 1066, 98);
RectangleShape textBack(500,500,bgColor6, 1046, 601);
vector<RectangleShape> backgroundShapes = {bigBackground,imageHighlight};//, bottomPanel, imageHighlight, cardBack, textBack};


// Menu buttons
RectangleShape startButton(BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_COLOR, START_BUTTONS_X_POSITION, START_BUTTONS_Y_POSITION);
RectangleShape exitButton(BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_COLOR, START_BUTTONS_X_POSITION, startButton.getY() + BUTTON_HEIGHT + BUTTON_Y_MARGIN);
RectangleShape resetButton(BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_COLOR, START_BUTTONS_X_POSITION, exitButton.getY() + BUTTON_HEIGHT + BUTTON_Y_MARGIN);
RectangleShape mainMenuButton(BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_COLOR, SLOT_X_POSITION + (SLOT_WIDTH - BUTTON_WIDTH) / 2, BUTTON_Y_POSITION);


// In game card buttons to buy cards
RectangleShape wheatFieldButton(CARD_BUTTON_WIDTH, CARD_BUTTON_HEIGHT, BLUE_CARD_COLOR, TOP_LEFT_CARD_X_POSITION, TOP_LEFT_CARD_Y_POSITION);
RectangleShape ranchButton(CARD_BUTTON_WIDTH, CARD_BUTTON_HEIGHT, BLUE_CARD_COLOR, wheatFieldButton.getX() + wheatFieldButton.getBase() + CARD_BUTTON_X_MARGIN, wheatFieldButton.getY());
RectangleShape bakeryButton(CARD_BUTTON_WIDTH, CARD_BUTTON_HEIGHT, GREEN_CARD_COLOR, wheatFieldButton.getX() + 2 * wheatFieldButton.getBase() + 2 * CARD_BUTTON_X_MARGIN, wheatFieldButton.getY());
RectangleShape cafeButton(CARD_BUTTON_WIDTH, CARD_BUTTON_HEIGHT, RED_CARD_COLOR, wheatFieldButton.getX() + 3 * wheatFieldButton.getBase() + 3 * CARD_BUTTON_X_MARGIN, wheatFieldButton.getY());
RectangleShape convenienceStoreButton(CARD_BUTTON_WIDTH, CARD_BUTTON_HEIGHT, GREEN_CARD_COLOR, wheatFieldButton.getX() + 4 * wheatFieldButton.getBase() + 4 * CARD_BUTTON_X_MARGIN, wheatFieldButton.getY());

RectangleShape forestButton(CARD_BUTTON_WIDTH, CARD_BUTTON_HEIGHT, BLUE_CARD_COLOR,wheatFieldButton.getX() , wheatFieldButton.getY() + wheatFieldButton.getHeight() + CARD_BUTTON_Y_MARGIN);
RectangleShape tvStationButton(CARD_BUTTON_WIDTH, CARD_BUTTON_HEIGHT, PURPLE_CARD_COLOR, wheatFieldButton.getX() + wheatFieldButton.getBase() + CARD_BUTTON_X_MARGIN, wheatFieldButton.getY() + wheatFieldButton.getHeight() + CARD_BUTTON_Y_MARGIN);
RectangleShape stadiumButton(CARD_BUTTON_WIDTH, CARD_BUTTON_HEIGHT, PURPLE_CARD_COLOR, wheatFieldButton.getX() + 2 * wheatFieldButton.getBase() + 2 * CARD_BUTTON_X_MARGIN, wheatFieldButton.getY() + wheatFieldButton.getHeight() + CARD_BUTTON_Y_MARGIN);
RectangleShape businessCenterButton(CARD_BUTTON_WIDTH, CARD_BUTTON_HEIGHT, PURPLE_CARD_COLOR, wheatFieldButton.getX() + 3 * wheatFieldButton.getBase() + 3 * CARD_BUTTON_X_MARGIN, wheatFieldButton.getY() + wheatFieldButton.getHeight() + CARD_BUTTON_Y_MARGIN);
RectangleShape cheeseFactoryButton(CARD_BUTTON_WIDTH, CARD_BUTTON_HEIGHT, GREEN_CARD_COLOR, wheatFieldButton.getX() + 4 * wheatFieldButton.getBase() + 4 * CARD_BUTTON_X_MARGIN, wheatFieldButton.getY() + wheatFieldButton.getHeight() + CARD_BUTTON_Y_MARGIN);

RectangleShape furnitureFactoryButton(CARD_BUTTON_WIDTH, CARD_BUTTON_HEIGHT, GREEN_CARD_COLOR,wheatFieldButton.getX(), wheatFieldButton.getY() + 2 * wheatFieldButton.getHeight() + 2 * CARD_BUTTON_Y_MARGIN);
RectangleShape mineButton(CARD_BUTTON_WIDTH, CARD_BUTTON_HEIGHT, BLUE_CARD_COLOR, wheatFieldButton.getX() + wheatFieldButton.getBase() + CARD_BUTTON_X_MARGIN, wheatFieldButton.getY() + 2 * wheatFieldButton.getHeight() + 2 * CARD_BUTTON_Y_MARGIN);
RectangleShape familyRestaurantButton(CARD_BUTTON_WIDTH, CARD_BUTTON_HEIGHT, RED_CARD_COLOR, wheatFieldButton.getX() + 2 * wheatFieldButton.getBase() + 2 * CARD_BUTTON_X_MARGIN, wheatFieldButton.getY() + 2 * wheatFieldButton.getHeight() + 2 * CARD_BUTTON_Y_MARGIN);
RectangleShape appleOrchardButton(CARD_BUTTON_WIDTH, CARD_BUTTON_HEIGHT, BLUE_CARD_COLOR, wheatFieldButton.getX() + 3 * wheatFieldButton.getBase() + 3 * CARD_BUTTON_X_MARGIN, wheatFieldButton.getY() + 2 * wheatFieldButton.getHeight() + 2 * CARD_BUTTON_Y_MARGIN);
RectangleShape fruitAndVegetableMarketButton(CARD_BUTTON_WIDTH, CARD_BUTTON_HEIGHT, GREEN_CARD_COLOR, wheatFieldButton.getX() + 4 * wheatFieldButton.getBase() + 4 * CARD_BUTTON_X_MARGIN, wheatFieldButton.getY() + 2 * wheatFieldButton.getHeight() + 2 * CARD_BUTTON_Y_MARGIN);


// In game inventory slots
RectangleShape labelSlot(SLOT_WIDTH, SLOT_HEIGHT, LANDMARK_CARD_OWNED_COLOR, SLOT_X_POSITION, SLOT_TOP_Y_POSITION);
RectangleShape moneySlot(SLOT_WIDTH, SLOT_HEIGHT, LANDMARK_CARD_OWNED_COLOR, SLOT_X_POSITION, labelSlot.getY() + labelSlot.getHeight() + SLOT_Y_MARGIN);

RectangleShape wheatFieldSlot(SLOT_WIDTH, SLOT_HEIGHT, BLUE_CARD_COLOR, SLOT_X_POSITION, moneySlot.getY() + moneySlot.getHeight() + SLOT_Y_MARGIN);
RectangleShape ranchSlot(SLOT_WIDTH, SLOT_HEIGHT, BLUE_CARD_COLOR, SLOT_X_POSITION, wheatFieldSlot.getY() + wheatFieldSlot.getHeight() + SLOT_Y_MARGIN);
RectangleShape bakerySlot(SLOT_WIDTH, SLOT_HEIGHT, GREEN_CARD_COLOR, SLOT_X_POSITION, wheatFieldSlot.getY() + 2 * wheatFieldSlot.getHeight() + 2 * SLOT_Y_MARGIN);
RectangleShape cafeSlot(SLOT_WIDTH, SLOT_HEIGHT, RED_CARD_COLOR, SLOT_X_POSITION, wheatFieldSlot.getY() + 3 * wheatFieldSlot.getHeight() + 3 * SLOT_Y_MARGIN);
RectangleShape convenienceStoreSlot(SLOT_WIDTH, SLOT_HEIGHT, GREEN_CARD_COLOR, SLOT_X_POSITION, wheatFieldSlot.getY() + 4 * wheatFieldSlot.getHeight() + 4 * SLOT_Y_MARGIN);

RectangleShape forestSlot(SLOT_WIDTH, SLOT_HEIGHT, BLUE_CARD_COLOR, SLOT_X_POSITION, wheatFieldSlot.getY() + 5 * wheatFieldSlot.getHeight() + 5 * SLOT_Y_MARGIN);
RectangleShape tvStationSlot(SLOT_WIDTH, SLOT_HEIGHT, PURPLE_CARD_COLOR, SLOT_X_POSITION, wheatFieldSlot.getY() + 6 * wheatFieldSlot.getHeight() + 6 * SLOT_Y_MARGIN);
RectangleShape stadiumSlot(SLOT_WIDTH, SLOT_HEIGHT, PURPLE_CARD_COLOR, SLOT_X_POSITION, wheatFieldSlot.getY() + 7 * wheatFieldSlot.getHeight() + 7 * SLOT_Y_MARGIN);
RectangleShape businessCenterSlot(SLOT_WIDTH, SLOT_HEIGHT, PURPLE_CARD_COLOR, SLOT_X_POSITION, wheatFieldSlot.getY() + 8 * wheatFieldSlot.getHeight() + 8 * SLOT_Y_MARGIN);
RectangleShape cheeseFactorySlot(SLOT_WIDTH, SLOT_HEIGHT, GREEN_CARD_COLOR, SLOT_X_POSITION, wheatFieldSlot.getY() + 9 * wheatFieldSlot.getHeight() + 9 * SLOT_Y_MARGIN);

RectangleShape furnitureFactorySlot(SLOT_WIDTH, SLOT_HEIGHT, GREEN_CARD_COLOR, SLOT_X_POSITION, wheatFieldSlot.getY() + 10 * wheatFieldSlot.getHeight() + 10 * SLOT_Y_MARGIN);
RectangleShape mineSlot(SLOT_WIDTH, SLOT_HEIGHT, BLUE_CARD_COLOR, SLOT_X_POSITION, wheatFieldSlot.getY() + 11 * wheatFieldSlot.getHeight() + 11 * SLOT_Y_MARGIN);
RectangleShape familyRestaurantSlot(SLOT_WIDTH, SLOT_HEIGHT, RED_CARD_COLOR, SLOT_X_POSITION, wheatFieldSlot.getY() + 12 * wheatFieldSlot.getHeight() + 12 * SLOT_Y_MARGIN);
RectangleShape appleOrchardSlot(SLOT_WIDTH, SLOT_HEIGHT, BLUE_CARD_COLOR, SLOT_X_POSITION, wheatFieldSlot.getY() + 13 * wheatFieldSlot.getHeight() + 13 * SLOT_Y_MARGIN);
RectangleShape fruitAndVegetableMarketSlot(SLOT_WIDTH, SLOT_HEIGHT, GREEN_CARD_COLOR, SLOT_X_POSITION, wheatFieldSlot.getY() + 14 * wheatFieldSlot.getHeight() + 14 * SLOT_Y_MARGIN);

RectangleShape trainStationSlot(SLOT_WIDTH, SLOT_HEIGHT, LANDMARK_CARD_COLOR, SLOT_X_POSITION, wheatFieldSlot.getY() + 15 * wheatFieldSlot.getHeight() + 15 * SLOT_Y_MARGIN);
RectangleShape shoppingMallSlot(SLOT_WIDTH, SLOT_HEIGHT, LANDMARK_CARD_COLOR, SLOT_X_POSITION, wheatFieldSlot.getY() + 16 * wheatFieldSlot.getHeight() + 16 * SLOT_Y_MARGIN);
RectangleShape amusementParkSlot(SLOT_WIDTH, SLOT_HEIGHT, LANDMARK_CARD_COLOR, SLOT_X_POSITION, wheatFieldSlot.getY() + 17 * wheatFieldSlot.getHeight() + 17 * SLOT_Y_MARGIN);
RectangleShape radioTowerSlot(SLOT_WIDTH, SLOT_HEIGHT, LANDMARK_CARD_COLOR, SLOT_X_POSITION, wheatFieldSlot.getY() + 18 * wheatFieldSlot.getHeight() + 18 * SLOT_Y_MARGIN);

// Player buttons
RectangleShape player1button(BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_COLOR, PLAYER_BUTTON_X_POSITION, PLAYER_BUTTON_Y_POSITION);
RectangleShape player2button(BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_COLOR, PLAYER_BUTTON_X_POSITION + PLAYER_BUTTON_X_MARGIN, PLAYER_BUTTON_Y_POSITION + PLAYER_BUTTON_Y_MARGIN);

// Game options buttons
RectangleShape rollDieButton(ROLL_BUTTON_WIDTH, ROLL_BUTTON_HEIGHT, ROLL_BUTTON_COLOR, ROLL_BUTTON_X_POSITION, ROLL_BUTTON_Y_POSITION);
RectangleShape roll2diceButton(ROLL_BUTTON_WIDTH, ROLL_BUTTON_HEIGHT, ROLL_BUTTON_COLOR, ROLL_BUTTON_X_POSITION + ROLL_BUTTON_X_MARGIN, ROLL_BUTTON_Y_POSITION);
RectangleShape skipBuyButton(BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_COLOR, SKIP_X_POSITION, SKIP_Y_POSITION);
RectangleShape rerollButton(BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_COLOR, REROLL_BUTTON_X_POSITION, REROLL_BUTTON_Y_POSITION);
RectangleShape keepRollButton(BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_COLOR, REROLL_BUTTON_X_POSITION + REROLL_BUTTON_X_MARGIN, REROLL_BUTTON_Y_POSITION + REROLL_BUTTON_Y_MARGIN);
//GameData
struct GameData {
    int currentPlayerIndex = 0;
    int focusedPlayerIndex = 0;
    vector<Player> players;
    int numOfPlayers;
    bool gameOver = false;
    int dice1Roll = 0;
    int dice2Roll = 0;
    int diceSum = 0;
    bool diceRolled = false;
    turnPhase turnPhase = roll;
    bool boughtCard = false;
    bool businessCenterUsed = false;
    bool tvStationUsed = false;
    bool skipRadioTower = false;
    bool skipBusinessCenter = true;
    bool skipTVStation = true;
    string businessCenterCurrentPlayerCard = "";
    string businessCenterTargetPlayerCard = "";
    int businessCenterTargetPlayerIndex = 0;
};

GameData Game;


//Amount of cards
int numOfWheatField = 6;
int numOfRanch = 6;
int numOfForest = 6;
int numOfMine = 6;
int numOfAppleOrchard = 6;
int numOfBakery = 6;
int numOfConvenienceStore = 6;
int numOfCheeseFactory = 6;
int numOfFurnitureFactory = 6;
int numOfFruitandVeggieMarket = 6;
int numOfCafe = 6;
int numOfFamilyRestaurant = 6;
int numOfStadium = 2;
int numOfTVStation = 2;
int numOfBusinessCenter = 2;

// Card Images
shared_ptr<Image> ranchFile = make_shared<Image>(Image("ranch.BMP"));
shared_ptr<Image> farmersMarketFile = make_shared<Image>(Image("farmersMarket.BMP"));
shared_ptr<Image> shoppingMall2File = make_shared<Image>(Image("shoppingMall2.BMP"));
shared_ptr<Image> radioTower2File = make_shared<Image>(Image("radioTower2.BMP"));
shared_ptr<Image> furnitureFactoryFile = make_shared<Image>(Image("furnitureFactory.BMP"));
shared_ptr<Image> cheeseFactoryFile = make_shared<Image>(Image("cheeseFactory.BMP"));
shared_ptr<Image> amusementParkFile = make_shared<Image>(Image("amusementPark.BMP"));
shared_ptr<Image> convenienceStoreFile = make_shared<Image>(Image("convenienceStore.BMP"));
shared_ptr<Image> shoppingMallFile = make_shared<Image>(Image("shoppingMall.BMP"));
shared_ptr<Image> appleOrchardFile = make_shared<Image>(Image("appleOrchard.BMP"));
shared_ptr<Image> trainStationFile = make_shared<Image>(Image("trainStation.BMP"));
shared_ptr<Image> wheatFieldFile = make_shared<Image>(Image("wheatField.BMP"));
shared_ptr<Image> trainStation2File = make_shared<Image>(Image("trainStation2.BMP"));
shared_ptr<Image> tvStationFile = make_shared<Image>(Image("tvStation.BMP"));
shared_ptr<Image> businessCenterFile = make_shared<Image>(Image("businessCenter.BMP"));
shared_ptr<Image> cafeFile = make_shared<Image>(Image("cafe.BMP"));
shared_ptr<Image> familyRestaurantFile = make_shared<Image>(Image("familyRestaurant.BMP"));
shared_ptr<Image> amusementPark2File = make_shared<Image>(Image("amusementPark2.BMP"));
shared_ptr<Image> testbmpFile = make_shared<Image>(Image("testbmp.bmp"));
shared_ptr<Image> radioTowerFile = make_shared<Image>(Image("radioTower.BMP"));
shared_ptr<Image> stadiumFile = make_shared<Image>(Image("stadium.BMP"));
shared_ptr<Image> mineFile = make_shared<Image>(Image("mine.BMP"));
shared_ptr<Image> bakeryFile = make_shared<Image>(Image("bakery.bmp"));
shared_ptr<Image> forestFile = make_shared<Image>(Image("forest.BMP"));


// variables to keep track of last turn
int previousPlayerIndex = 0;
int previousMoney = 0;
int afterMoney = 0;
int netProfit = 0;
int previousDiceRoll = 0;
string previousCardBought = "";

int updatedNetProfit = 0;
int updatedDiceRoll = 0;
int updatedPlayerIndex = 0;
string updatedCardBought = "";

#endif //GRAPHICS_GRAPHICSCONSTANTS_H
