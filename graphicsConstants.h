//
// Created by Joshua Newton on 2019-03-29.
//

#ifndef GRAPHICS_GRAPHICSCONSTANTS_H
#define GRAPHICS_GRAPHICSCONSTANTS_H

#include "Shapes.h"
#include "Card.h"

/*************************/
/** Rectangle Constants **/
/*************************/

int CARD_BASE_DIMENSION = 5;
int CARD_HEIGHT_DIMENSION = 10;

color RED_CARD_COLOR = {1,0,0}; // Red
color BLUE_CARD_COLOR = {0,0,1}; // Blue
color GREEN_CARD_COLOR = {0,1,0}; // Green
color LANDMARK_CARD_COLOR = {0.5,0.5,0.5}; // Grey
// {1,1,0}; // Yellow

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
string BUSSINESS_CENTER_DESCRIPTION = "Trade one non 'tower' establishment with another player, on your turn only";
string CHEESE_FACTORY_DESCRIPTION = "Get 3 coins from the bank for each 'cow' establishment that you own, on your turn only";
string FURNITURE_FACTORY_DESCRIPTION = "Get 3 coins from the bank for each 'gear' establishment that you own, on your turn only";
string MINE_DESCRIPTION = "Get 5 coins from the bank, on anyone's turn";
string FAMILY_RESTAURAUNT_DESCRIPTION = "Get 2 coins from the player who rolled the dice";
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
string BUSSINESS_CENTER_NAME = "Bussiness Center";
string CHEESE_FACTORY_NAME = "Cheese Factory";
string FURNITURE_FACTORY_NAME = "Furniture Factory";
string MINE_NAME = "Mine";
string FAMILY_RESTAURAUNT_NAME = "Family Restauraunt";
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
int BUSSINESS_CENTER_COST = 8;
int CHEESE_FACTORY_COST = 5;
int FURNITURE_FACTORY_COST = 3;
int MINE_COST = 6;
int FAMILY_RESTAURAUNT_COST = 3;
int APPLE_ORCHARD_COST = 3;
int FRUIT_AND_VEGETABLE_MARKET_COST = 2;

// Activation Ranges

range WHEAT_FIELD_RANGE = {1,1};
range BAKERY_RANGE = {2,3};
range RANCH_RANGE = {2,2};
range CAFE_RANGE = {3,3};
range CONVENIENCE_STORE_RANGE = {4,4};
range FOREST_RANGE = {5,5};
range STADIUM_RANGE = {6,6};
range TV_STATION_RANGE = {6,6};
range BUSSINESS_CENTER_RANGE = {6,6};
range CHEESE_FACTORY_RANGE = {7,7};
range FURNITURE_FACTORY_RANGE = {8,8};
range MINE_RANGE = {9,9};
range FAMILY_RESTAURAUNT_RANGE = {9,10};
range APPLE_ORCHARD_RANGE = {10,10};
range FRUIT_AND_VEGETABLE_MARKET_RANGE = {11,12};

// Rectangles

RectangleShape redCardRectangle(CARD_BASE_DIMENSION, CARD_HEIGHT_DIMENSION, RED_CARD_COLOR);
RectangleShape blueCardRectangle(CARD_BASE_DIMENSION, CARD_HEIGHT_DIMENSION, BLUE_CARD_COLOR);
RectangleShape greenCardRectangle(CARD_BASE_DIMENSION, CARD_HEIGHT_DIMENSION, GREEN_CARD_COLOR);
RectangleShape landmarkCardRectangle(CARD_BASE_DIMENSION, CARD_HEIGHT_DIMENSION, LANDMARK_CARD_COLOR);

// cardTypes

cardType WHEAT_FIELD_TYPE = primaryIndustry;
cardType BAKERY_TYPE = secondaryIndustry;
cardType RANCH_TYPE = primaryIndustry;
cardType CAFE_TYPE = restaurant;
cardType CONVENIENCE_STORE_TYPE = secondaryIndustry;
cardType FOREST_TYPE = primaryIndustry;
cardType STADIUM_TYPE = majorEstablishment;
cardType TV_STATION_TYPE = majorEstablishment;
cardType BUSSINESS_CENTER_TYPE = majorEstablishment;
cardType CHEESE_FACTORY_TYPE = secondaryIndustry;
cardType FURNITURE_FACTORY_TYPE = secondaryIndustry;
cardType MINE_TYPE = primaryIndustry;
cardType FAMILY_RESTAURAUNT_TYPE = restaurant;
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
cardSymbol BUSSINESS_CENTER_SYMBOL = tower;
cardSymbol CHEESE_FACTORY_SYMBOL = factory;
cardSymbol FURNITURE_FACTORY_SYMBOL = factory;
cardSymbol MINE_SYMBOL = gear;
cardSymbol FAMILY_RESTAURAUNT_SYMBOL = coffeeCup;
cardSymbol APPLE_ORCHARD_SYMBOL = wheat;
cardSymbol FRUIT_AND_VEGETABLE_MARKET_SYMBOL = fruit;

// screen enum and variable
enum screenType {start, game, endGame};
screenType screen = start;

// Glut constants
int WIDTH = 1500;
int HEIGHT = 800;

// Button constants
int BUTTON_WIDTH = 200;
int BUTTON_HEIGHT = 75;
color BUTTON_COLOR = {1,0,0}; // Red
color BUTTON_HOVER_COLOR = {0,1,0}; // Green
int BUTTON_X_POSITION = 100;
int BUTTON_Y_POSITION = 100;
int BUTTON_Y_MARGIN = 20;


// Menu buttons
RectangleShape startButton(BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_COLOR, BUTTON_X_POSITION, BUTTON_Y_POSITION);
RectangleShape exitButton(BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_COLOR, BUTTON_X_POSITION, startButton.getY() + BUTTON_HEIGHT + BUTTON_Y_MARGIN);
RectangleShape mainMenuButton(BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_COLOR, BUTTON_X_POSITION, BUTTON_Y_POSITION);




#endif //GRAPHICS_GRAPHICSCONSTANTS_H
