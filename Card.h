//
// Created by jonew on 3/15/2019.
//

#ifndef CS205FINAL_CARD_H
#define CS205FINAL_CARD_H

#include <string>
#include "Shapes.h"


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
enum cardType {primaryIndustry, secondaryIndustry, restaurant, majorEstablishment, landmark};
enum cardSymbol {wheat, cow, gear, box, factory, fruit, coffeeCup, tower};


class Card{
public:
    // Constructors
    Card();
    Card(string newDescription, int newCost, range newActivation);
    Card(string newDescription, int newCost, int newActivationMin, int newActivationMax);
    Card(string newDescription, int newCost, int newActivationMin, int newActivationMax, cardType newType);
    Card(string newDescription, int newCost, int newActivationMin, int newActivationMax, cardType newType, RectangleShape newRectangle);
    Card(string newDescription, int newCost, int newActivationMin, int newActivationMax, cardType newType, RectangleShape newRectangle, string newName);
    Card(string newDescription, int newCost, int newActivationMin, int newActivationMax, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newCardSymbol);

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
    virtual void activate() = 0;

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

// TODO: Machi Koro cards will inherit the above abstract Card class.
//  Cards Remaining:
//  Wheat Field, Ranch, Forest, Mine, Apple Orchard, Bakery, Convenience Store, Cheese Factory, Furniture Factory,
//  Fruit and Vegetable Market, Cafe, Family Restaurant, Stadium, TV Station, Business Center, Train Station,
//  Shopping Mall, Amusement Park, Radio Tower

//class WheatField : Card{
//public:
//    // Constructor for WheatField
//    WheatField();
//
//    void draw() override;
//    void activate() override;
//};
#endif //CS205FINAL_CARD_H
