//
// Created by jonew on 3/15/2019.
//

#ifndef CS205FINAL_CARD_H
#define CS205FINAL_CARD_H

#ifndef PLAYER_H
#define PLAYER_H

class Player;

#include <string>
#include "Shapes.h"
#include "Player.h"
#include "enums.h"
using namespace std;

struct range {
    int minimum;
    int maximum;
};

/**
 * primaryIndustry = Blue
 * secondaryIndustry = Green
 * restaurants = Red
 * majorEstablishment = Purple
 * landmark = Yellow (Gray if not constructed)
 */



class Card{
public:
    // Constructors
    Card();
    Card(string newDescription, int newCost, range newActivation);
    Card(string newDescription, int newCost, int newActivationMin, int newActivationMax);
    Card(string newDescription, int newCost, int newActivationMin, int newActivationMax, cardType newType);
    Card(string newDescription, int newCost, int newActivationMin, int newActivationMax, cardType newType, RectangleShape newRectangle);
    Card(string newDescription, int newCost, int newActivationMin, int newActivationMax, cardType newType, RectangleShape newRectangle, string newName);
    Card(string newDescription, int newCost, int newActivationMin, int newActivationMax, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol);
    Card(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol);

    // Copy Constructor
    Card(const Card &oldCard);

    // Destructor
    ~Card();

    // Getters
    string getDescription() const;
    int getCost() const;
    range getActivation() const;
    int getActivationMin() const;
    int getActivationMax() const;
    RectangleShape getRectangle() const;
    string getName() const;
    cardType getCardType() const;
    cardSymbol getCardSymbol() const;


    // Setters
    void setDescription(string newDescription);
    void setCost(int newCost);
    void setActivation(range newRange);
    void setActivation(int newMin, int newMax);
    void setActivationMin(int newMin);
    void setActivationMax(int newMax);
    void setRectangle(RectangleShape newRectangle);
    void setName(string newName);
    void setCardType(cardType newType);
    void setCardSymbol(cardSymbol newSymbol);


    // Virtual Methods
    virtual void draw() = 0;
    virtual void activate(Player owner, vector<Player> &players, Player diceRoller) = 0;

    // Other Methods

protected:
    string description;
    string name;
    int cost;
    range activation;
    RectangleShape rectangle;
    cardType type;
    cardSymbol symbol;

};

class WheatField : public Card{
public:
    WheatField();
    WheatField(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol);
    void draw() override;
    void activate(Player owner, vector<Player> &players, Player diceRoller) override;
};

class Ranch : public Card{
public:
    Ranch();
    Ranch(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol);
    void draw() override;
    void activate(Player owner, vector<Player> &players, Player diceRoller) override;
};

class Forest : public Card{
public:
    Forest();
    Forest(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol);
    void draw() override;
    void activate(Player owner, vector<Player> &players, Player diceRoller) override;
};

class Mine : public Card{
public:
    Mine();
    Mine(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol);
    void draw() override;
    void activate(Player owner, vector<Player> &players, Player diceRoller) override;
};

class AppleOrchard : public Card{
public:
    AppleOrchard();
    AppleOrchard(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol);
    void draw() override;
    void activate(Player owner, vector<Player> &players, Player diceRoller) override;
};

class Bakery : public Card{
public:
    Bakery();
    Bakery(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol);
    void draw() override;
    void activate(Player owner, vector<Player> &players, Player diceRoller) override;
};

class ConvenienceStore : public Card{
public:
    ConvenienceStore();
    ConvenienceStore(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol);
    void draw() override;
    void activate(Player owner, vector<Player> &players, Player diceRoller) override;
};

class CheeseFactory : public Card{
public:
    CheeseFactory();
    CheeseFactory(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol);
    void draw() override;
    void activate(Player owner, vector<Player> &players, Player diceRoller) override;
};

class FurnitureFactory : public Card{
public:
    FurnitureFactory();
    FurnitureFactory(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol);
    void draw() override;
    void activate(Player owner, vector<Player> &players, Player diceRoller) override;
};

class FruitAndVegetableMarket : public Card{
public:
    FruitAndVegetableMarket();
    FruitAndVegetableMarket(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol);
    void draw() override;
    void activate(Player owner, vector<Player> &players, Player diceRoller) override;
};

class Cafe : public Card{
public:
    Cafe();
    Cafe(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol);
    void draw() override;
    void activate(Player owner, vector<Player> &players, Player diceRoller) override;
};

class FamilyRestaurant : public Card{
public:
    FamilyRestaurant();
    FamilyRestaurant(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol);
    void draw() override;
    void activate(Player owner, vector<Player> &players, Player diceRoller) override;
};

class Stadium : public Card{
public:
    Stadium();
    Stadium(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol);
    void draw() override;
    void activate(Player owner, vector<Player> &players, Player diceRoller) override;
};

class TVStation : public Card{
public:
    TVStation();
    TVStation(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol);
    void draw() override;
    void activate(Player owner, vector<Player> &players, Player diceRoller) override;
};

class BusinessCenter : public Card{
public:
    BusinessCenter();
    BusinessCenter(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol);
    void draw() override;
    void activate(Player owner, vector<Player> &players, Player diceRoller) override;
};

#endif //PLAYER_H

#endif //CS205FINAL_CARD_H
