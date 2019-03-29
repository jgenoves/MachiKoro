//
// Created by jonew on 3/15/2019.
//

#include "Card.h"
/***********************************/
/** ABSTRACT CARD CLASS BEGINNING **/
/***********************************/

// Constructors
Card::Card(){
    setDescription("Default Constructor Used");
    setActivation(1,12);
    setCost(1);
}
Card::Card(string newDescription, int newCost, range newActivation){
    setDescription(newDescription);
    setCost(newCost);
    setActivation(newActivation);
}
Card::Card(string newDescription, int newCost, int newActivationMin, int newActivationMax){
    setDescription(newDescription);
    setCost(newCost);
    setActivation(newActivationMin, newActivationMax);
}
Card::Card(string newDescription, int newCost, int newActivationMin, int newActivationMax, cardType newType){
    setDescription(newDescription);
    setCost(newCost);
    setActivation(newActivationMin, newActivationMax);
    setCardType(newType);
}
Card::Card(string newDescription, int newCost, int newActivationMin, int newActivationMax, cardType newType, RectangleShape newRectangle){
    setDescription(newDescription);
    setCost(newCost);
    setActivation(newActivationMin, newActivationMax);
    setCardType(newType);
    setRectangle(newRectangle);
}
Card::Card(string newDescription, int newCost, int newActivationMin, int newActivationMax, cardType newType, RectangleShape newRectangle, string newName){
    setDescription(newDescription);
    setCost(newCost);
    setActivation(newActivationMin, newActivationMax);
    setCardType(newType);
    setRectangle(newRectangle);
    setName(newName);
}
Card::Card(string newDescription, int newCost, int newActivationMin, int newActivationMax, cardType newType, RectangleShape newRectangle, string newName, cardKind newKind){
    setDescription(newDescription);
    setCost(newCost);
    setActivation(newActivationMin, newActivationMax);
    setCardType(newType);
    setRectangle(newRectangle);
    setName(newName);
    setCardKind(newKind);
}

// Copy Constructor
Card::Card(const Card &oldCard){
    setDescription(oldCard.getDescription());
    setCost(oldCard.getCost());
    setActivation(oldCard.getActivationMin(), oldCard.getActivationMax());
    setCardType(oldCard.getCardType());
    setRectangle(oldCard.getRectangle());
    setName(oldCard.getName());
    setCardKind(oldCard.getCardKind());
}


// Destructor
Card::~Card(){

}

// Getters
string Card::getDescription() const{
    return description;
}
int Card::getCost() const{
    return cost;
}
range Card::getActivation() const{
    return activation;
}
int Card::getActivationMin() const{
    return activation.minimum;
}
int Card::getActivationMax() const{
    return activation.maximum;
}
RectangleShape Card::getRectangle() const {
    return rectangle;
}
string Card::getName() const{
    return name;
}
cardType Card::getCardType() const {
    return type;
}
cardKind Card::getCardKind() const {
    return kind;
}

// Setters
void Card::setDescription(string newDescription){
    description = newDescription;
}
void Card::setCost(int newCost){
    // Ensure that the cost is not negative before accepting it
    if(newCost >= 0){
        cost = newCost;
    }
    // Set to 0 if it is negative
    else{
        cost = 0;
    }
}
void Card::setActivation(range newRange){
    //Note: input validation occurs inside of the two functions called
    setActivationMin(newRange.minimum);
    setActivationMax(newRange.maximum);
}
void Card::setActivation(int newMin, int newMax){
    //Note: input validation occurs inside of the two functions called
    setActivationMax(newMax);
    setActivationMin(newMin);
}
void Card::setActivationMin(int newMin){
    if (newMin >= 1 && newMin <= 12){
        activation.minimum = newMin;
    }
    else {
        activation.minimum = 1;
    }
}
void Card::setActivationMax(int newMax){
    if (newMax >= 1 && newMax <= 12){
        activation.minimum = newMax;
    }
    else {
        activation.minimum = 12;
    }
}
void Card::setRectangle(RectangleShape newRectangle) {
    rectangle = newRectangle;
}
void Card::setName(string newName){
    name = newName;
}
void Card::setCardType(cardType newType) {
    type = newType;
}
void Card::setCardKind(cardKind newKind) {
    kind = newKind;
}

// Virtual Methods
/* Overridden in child classes */

// Other Methods

/***********************************/
/** ABSTRACT CARD CLASS ENDING    **/
/***********************************/

