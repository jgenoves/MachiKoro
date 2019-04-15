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
WheatField::WheatField(): Card(){

}
WheatField::WheatField(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol):
    Card(newDescription, newCost, newRange, newType, newRectangle, newName, newSymbol){
}

void WheatField::draw(){
    getRectangle().draw();
}

void WheatField::activate(Player &owner, vector<Player> &players, Player &diceRoller) {
    owner.setMoney(owner.getMoney() + 1);
}

/***********************************/
/** WHEATFIELD CLASS ENDING       **/
/***********************************/

/***********************************/
/** RANCH CLASS STARTING          **/
/***********************************/
Ranch::Ranch(): Card(){

}
Ranch::Ranch(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol):
        Card(newDescription, newCost, newRange, newType, newRectangle, newName, newSymbol){
}

void Ranch::draw(){
    getRectangle().draw();
}

void Ranch::activate(Player &owner, vector<Player> &players, Player &diceRoller) {
    owner.setMoney(owner.getMoney() + 1);
}

/***********************************/
/** RANCH CLASS ENDING            **/
/***********************************/

/***********************************/
/** FOREST CLASS STARTING         **/
/***********************************/
Forest::Forest(): Card(){

}

Forest::Forest(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol):
        Card(newDescription, newCost, newRange, newType, newRectangle, newName, newSymbol){
}

void Forest::draw(){
    getRectangle().draw();
}

void Forest::activate(Player &owner, vector<Player> &players, Player &diceRoller) {
    owner.setMoney(owner.getMoney() + 1);
}

/***********************************/
/** FOREST CLASS ENDING           **/
/***********************************/

/***********************************/
/** MINE CLASS STARTING         **/
/***********************************/
Mine::Mine(): Card(){

}

Mine::Mine(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol):
        Card(newDescription, newCost, newRange, newType, newRectangle, newName, newSymbol){
}

void Mine::draw(){
    getRectangle().draw();
}

void Mine::activate(Player &owner, vector<Player> &players, Player &diceRoller) {
    owner.setMoney(owner.getMoney() + 5);
}

/***********************************/
/** MINE CLASS ENDING           **/
/***********************************/

/***********************************/
/** APPLE ORCHARD CLASS STARTING  **/
/***********************************/
AppleOrchard::AppleOrchard(): Card(){

}

AppleOrchard::AppleOrchard(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol):
        Card(newDescription, newCost, newRange, newType, newRectangle, newName, newSymbol){
}

void AppleOrchard::draw(){
    getRectangle().draw();
}

void AppleOrchard::activate(Player &owner, vector<Player> &players, Player &diceRoller) {
    owner.setMoney(owner.getMoney() + 3);
}

/***********************************/
/** APPLE ORCHARD CLASS ENDING    **/
/***********************************/

/***********************************/
/** BAKERY CLASS STARTING         **/
/***********************************/
Bakery::Bakery(): Card(){

}

Bakery::Bakery(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol):
        Card(newDescription, newCost, newRange, newType, newRectangle, newName, newSymbol){
}

void Bakery::draw(){
    getRectangle().draw();
}

void Bakery::activate(Player &owner, vector<Player> &players, Player &diceRoller) {
    if (owner.getShoppingMallBool()){
        owner.setMoney(owner.getMoney() + 2);
    }
    else {
        owner.setMoney(owner.getMoney() + 1);
    }
}

/***********************************/
/** BAKERY CLASS ENDING           **/
/***********************************/

/***********************************/
/** CONVENIENCE STORE CLASS STARTING         **/
/***********************************/
ConvenienceStore::ConvenienceStore(): Card(){

}

ConvenienceStore::ConvenienceStore(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol):
        Card(newDescription, newCost, newRange, newType, newRectangle, newName, newSymbol){
}

void ConvenienceStore::draw(){
    getRectangle().draw();
}

void ConvenienceStore::activate(Player &owner, vector<Player> &players, Player &diceRoller) {
    if (owner.getShoppingMallBool()){
        owner.setMoney(owner.getMoney() + 4);
    }
    else {
        owner.setMoney(owner.getMoney() + 3);
    }
}

/***********************************/
/** CONVENIENCE STORE CLASS ENDING           **/
/***********************************/

/***********************************/
/** CHEESE FACTORY CLASS STARTING         **/
/***********************************/
CheeseFactory::CheeseFactory(): Card(){

}

CheeseFactory::CheeseFactory(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol):
        Card(newDescription, newCost, newRange, newType, newRectangle, newName, newSymbol){
}

void CheeseFactory::draw(){
    getRectangle().draw();
}

void CheeseFactory::activate(Player &owner, vector<Player> &players, Player &diceRoller) {
    int numCowsOwned = owner.getNumberOfEstablishment(cow);
    owner.setMoney(owner.getMoney() + (3 * numCowsOwned));
}

/***********************************/
/** CHEESE FACTORY CLASS ENDING         **/
/***********************************/

/***********************************/
/** FURNITURE FACTORY CLASS STARTING         **/
/***********************************/
FurnitureFactory::FurnitureFactory(): Card(){

}

FurnitureFactory::FurnitureFactory(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol):
        Card(newDescription, newCost, newRange, newType, newRectangle, newName, newSymbol){
}

void FurnitureFactory::draw(){
    getRectangle().draw();
}

void FurnitureFactory::activate(Player &owner, vector<Player> &players, Player &diceRoller) {
    int numGearsOwned = owner.getNumberOfEstablishment(gear);
    owner.setMoney(owner.getMoney() + (3 * numGearsOwned));
}

/***********************************/
/** FURNITURE FACTORY CLASS ENDING         **/
/***********************************/

/***********************************/
/** FRUIT AND VEGETABLE MARKET CLASS STARTING         **/
/***********************************/
FruitAndVegetableMarket::FruitAndVegetableMarket(): Card(){

}

FruitAndVegetableMarket::FruitAndVegetableMarket(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol):
        Card(newDescription, newCost, newRange, newType, newRectangle, newName, newSymbol){
}

void FruitAndVegetableMarket::draw(){
    getRectangle().draw();
}

void FruitAndVegetableMarket::activate(Player &owner, vector<Player> &players, Player &diceRoller) {
    int numWheatsOwned = owner.getNumberOfEstablishment(wheat);
    owner.setMoney(owner.getMoney() + (2 * numWheatsOwned));
}

/***********************************/
/** FRUIT AND VEGETABLE MARKET CLASS ENDING         **/
/***********************************/

/***********************************/
/** BAKERY CLASS STARTING         **/
/***********************************/
Cafe::Cafe(): Card(){

}

Cafe::Cafe(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol):
        Card(newDescription, newCost, newRange, newType, newRectangle, newName, newSymbol){
}

void Cafe::draw(){
    getRectangle().draw();
}

void Cafe::activate(Player &owner, vector<Player> &players, Player &diceRoller) {
    if (owner.getShoppingMallBool()) {
        if (diceRoller.getMoney() < 2) {
            owner.setMoney(owner.getMoney() + diceRoller.getMoney());
            diceRoller.setMoney(0);
        }
        else{
            owner.setMoney(owner.getMoney() + 2);
            diceRoller.setMoney(diceRoller.getMoney() - 2);
        }
    }
    else {
        if (diceRoller.getMoney() < 1) {
            owner.setMoney(owner.getMoney() + diceRoller.getMoney());
            diceRoller.setMoney(0);
        }
        else{
            owner.setMoney(owner.getMoney() + 1);
            diceRoller.setMoney(diceRoller.getMoney() - 1);
        }
    }
}

/***********************************/
/** BAKERY CLASS ENDING           **/
/***********************************/

/***********************************/
/** FAMILY RESTAURANT CLASS STARTING         **/
/***********************************/
FamilyRestaurant::FamilyRestaurant(): Card(){

}

FamilyRestaurant::FamilyRestaurant(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol):
        Card(newDescription, newCost, newRange, newType, newRectangle, newName, newSymbol){
}

void FamilyRestaurant::draw(){
    getRectangle().draw();
}

void FamilyRestaurant::activate(Player &owner, vector<Player> &players, Player &diceRoller) {
    if (owner.getShoppingMallBool()) {
        if (diceRoller.getMoney() < 2) {
            owner.setMoney(owner.getMoney() + diceRoller.getMoney());
            diceRoller.setMoney(0);
        }
        else{
            owner.setMoney(owner.getMoney() + 2);
            diceRoller.setMoney(diceRoller.getMoney() - 2);
        }
    }
    else {
        if (diceRoller.getMoney() < 1) {
            owner.setMoney(owner.getMoney() + diceRoller.getMoney());
            diceRoller.setMoney(0);
        }
        else{
            owner.setMoney(owner.getMoney() + 1);
            diceRoller.setMoney(diceRoller.getMoney() - 1);
        }
    }
}

/***********************************/
/** FAMILY RESTAURANT CLASS ENDING           **/
/***********************************/

/***********************************/
/** STADIUM CLASS STARTING         **/
/***********************************/
Stadium::Stadium(): Card(){

}

Stadium::Stadium(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol):
        Card(newDescription, newCost, newRange, newType, newRectangle, newName, newSymbol){
}

void Stadium::draw(){
    getRectangle().draw();
}

void Stadium::activate(Player &owner, vector<Player> &players, Player &diceRoller) {
    for (int i = 0; i < players.size(); i++){
        if (players[i].getID() != owner.getID()){
            if (players[i].getMoney() >= 2){
                players[i].setMoney(players[i].getMoney() - 2);
                owner.setMoney(owner.getMoney() + 2);
            }
            else {
                owner.setMoney(owner.getMoney() + players[i].getMoney());
                players[i].setMoney(0);
            }
        }
    }
}

/***********************************/
/** STADIUM CLASS ENDING           **/
/***********************************/

/***********************************/
/** TV STATION CLASS STARTING         **/
/***********************************/
TVStation::TVStation(): Card(){

}

TVStation::TVStation(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol):
        Card(newDescription, newCost, newRange, newType, newRectangle, newName, newSymbol){
}

void TVStation::draw(){
    getRectangle().draw();
}

void TVStation::activate(Player &owner, vector<Player> &players, Player &diceRoller) {
    // TODO: Implement choosing a player to take 5 coins from
    // Note: maybe set a global boolean here to indicate to the game loop that the player
    //       needs to choose a player to take coins from
}

/***********************************/
/** TV STATION CLASS ENDING           **/
/***********************************/

/***********************************/
/** BUSINESS CENTER CLASS STARTING         **/
/***********************************/
BusinessCenter::BusinessCenter(): Card(){

}

BusinessCenter::BusinessCenter(string newDescription, int newCost, range newRange, cardType newType, RectangleShape newRectangle, string newName, cardSymbol newSymbol):
    Card(newDescription, newCost, newRange, newType, newRectangle, newName, newSymbol){
}

void BusinessCenter::draw(){
    getRectangle().draw();
}

void BusinessCenter::activate(Player &owner, vector<Player> &players, Player &diceRoller) {
    // TODO: Implement taking an establishment from any player
    // Note: maybe set a global boolean here to indicate to the game loop that the player
    //       needs to choose a player to trade an establishment with
}

/***********************************/
/** BUSINESS CENTER CLASS ENDING           **/
/***********************************/
