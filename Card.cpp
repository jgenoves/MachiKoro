//
// Created by jonew on 3/15/2019.
//

#include "Card.h"
#include "Player.h"

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
Card::Card(string newDescription, int newCost, int newActivationMin, int newActivationMax, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol){
    setDescription(newDescription);
    setCost(newCost);
    setActivation(newActivationMin, newActivationMax);
    setCardType(newType);
    setRectangle(newRectangle);
    setName(newName);
    setCardSymbol(newSymbol);
}

Card::Card(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol){
    setDescription(newDescription);
    setCost(newCost);
    setActivation(newRange);
    setCardType(newType);
    setRectangle(newRectangle);
    setName(newName);
    setCardSymbol(newSymbol);
}

// Copy Constructor
Card::Card(const Card &oldCard){
    setDescription(oldCard.getDescription());
    setCost(oldCard.getCost());
    setActivation(oldCard.getActivationMin(), oldCard.getActivationMax());
    setCardType(oldCard.getCardType());
    setRectangle(oldCard.getRectangle());
    setName(oldCard.getName());
    setCardSymbol(oldCard.getCardSymbol());
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
cardSymbol Card::getCardSymbol() const {
    return symbol;
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
void Card::setCardSymbol(cardSymbol newSymbol) {
    symbol = newSymbol;
}

// Virtual Methods
/* Overridden in child classes */

// Other Methods

/***********************************/
/** ABSTRACT CARD CLASS ENDING    **/
/***********************************/

/***********************************/
/** WHEATFIELD CLASS STARTING     **/
/***********************************/

void WheatField::draw(){
    getRectangle().draw();
}

void WheatField::activate(Player owner) {
    owner.setMoney(owner.getMoney() + 1);
}

/***********************************/
/** WHEATFIELD CLASS ENDING       **/
/***********************************/

/***********************************/
/** RANCH CLASS STARTING          **/
/***********************************/

void Ranch::draw(){
    getRectangle().draw();
}

void Ranch::activate(Player owner) {
    owner.setMoney(owner.getMoney() + 1);
}

/***********************************/
/** RANCH CLASS ENDING            **/
/***********************************/

/***********************************/
/** FOREST CLASS STARTING         **/
/***********************************/

void Forest::draw(){
    getRectangle().draw();
}

void Forest::activate(Player owner) {
    owner.setMoney(owner.getMoney() + 1);
}

/***********************************/
/** FOREST CLASS ENDING           **/
/***********************************/

/***********************************/
/** MINE CLASS STARTING         **/
/***********************************/

void Mine::draw(){
    getRectangle().draw();
}

void Mine::activate(Player owner) {
    owner.setMoney(owner.getMoney() + 5);
}

/***********************************/
/** MINE CLASS ENDING           **/
/***********************************/

/***********************************/
/** APPLE ORCHARD CLASS STARTING  **/
/***********************************/

void AppleOrchard::draw(){
    getRectangle().draw();
}

void AppleOrchard::activate(Player owner) {
    owner.setMoney(owner.getMoney() + 3);
}

/***********************************/
/** APPLE ORCHARD CLASS ENDING    **/
/***********************************/

/***********************************/
/** BAKERY CLASS STARTING         **/
/***********************************/

void Bakery::draw(){
    getRectangle().draw();
}

void Bakery::activate(Player owner) {
    owner.setMoney(owner.getMoney() + 1);
}

/***********************************/
/** BAKERY CLASS ENDING           **/
/***********************************/

/***********************************/
/** CONVENIENCE STORE CLASS STARTING         **/
/***********************************/

void ConvenienceStore::draw(){
    getRectangle().draw();
}

void ConvenienceStore::activate(Player owner) {
    owner.setMoney(owner.getMoney() + 1);
}

/***********************************/
/** CONVENIENCE STORE CLASS ENDING           **/
/***********************************/

/***********************************/
/** CHEESE FACTORY CLASS STARTING         **/
/***********************************/

void CheeseFactory::draw(){
    getRectangle().draw();
}

void CheeseFactory::activate(Player owner) {
    owner.setMoney(owner.getMoney() + 1);
}

/***********************************/
/** CHEESE FACTORY CLASS ENDING         **/
/***********************************/

/***********************************/
/** FURNITURE FACTORY CLASS STARTING         **/
/***********************************/

void FurnitureFactory::draw(){
    getRectangle().draw();
}

void FurnitureFactory::activate(Player owner) {
    owner.setMoney(owner.getMoney() + 1);
}

/***********************************/
/** FURNITURE FACTORY CLASS ENDING         **/
/***********************************/

/***********************************/
/** FRUIT AND VEGETABLE MARKET CLASS STARTING         **/
/***********************************/

void FruitAndVegetableMarket::draw(){
    getRectangle().draw();
}

void FruitAndVegetableMarket::activate(Player owner) {
    owner.setMoney(owner.getMoney() + 1);
}

/***********************************/
/** FRUIT AND VEGETABLE MARKET CLASS ENDING         **/
/***********************************/

/***********************************/
/** BAKERY CLASS STARTING         **/
/***********************************/

void Cafe::draw(){
    getRectangle().draw();
}

void Cafe::activate(Player owner) {
    owner.setMoney(owner.getMoney() + 1);
}

/***********************************/
/** BAKERY CLASS ENDING           **/
/***********************************/

/***********************************/
/** FAMILY RESTAURAUNT CLASS STARTING         **/
/***********************************/

void FamilyRestauraunt::draw(){
    getRectangle().draw();
}

void FamilyRestauraunt::activate(Player owner) {
    owner.setMoney(owner.getMoney() + 1);
}

/***********************************/
/** FAMILY RESTAURAUNT CLASS ENDING           **/
/***********************************/

/***********************************/
/** STADIUM CLASS STARTING         **/
/***********************************/

void Stadium::draw(){
    getRectangle().draw();
}

void Stadium::activate(Player owner) {
    owner.setMoney(owner.getMoney() + 1);
}

/***********************************/
/** STADIUM CLASS ENDING           **/
/***********************************/

/***********************************/
/** TV STATION CLASS STARTING         **/
/***********************************/

void TVStation::draw(){
    getRectangle().draw();
}

void TVStation::activate(Player owner) {
    owner.setMoney(owner.getMoney() + 1);
}

/***********************************/
/** TV STATION CLASS ENDING           **/
/***********************************/

/***********************************/
/** BUSINESS CENTER CLASS STARTING         **/
/***********************************/

void BusinessCenter::draw(){
    getRectangle().draw();
}

void BusinessCenter::activate(Player owner) {
    owner.setMoney(owner.getMoney() + 1);
}

/***********************************/
/** BUSINESS CENTER CLASS ENDING           **/
/***********************************/
