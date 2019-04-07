//
// Created by Joshua Newton on 3/15/2019.
//

#include <string>
#include "Player.h"
#include "Card.h"

Player::Player(){
    setMoney(0);
    setAllLandmarksFalse();
}
Player::Player(int newMoney){
    setMoney(newMoney);
    setAllLandmarksFalse();
}
Player::Player(int newMoney, vector<shared_ptr<Card>> &newEstablishments){
    setMoney(newMoney);
    setEstablishments(newEstablishments);
    setAllLandmarksFalse();
}

// Copy Constructor
Player::Player(const Player &oldPlayer){
    setMoney(oldPlayer.getMoney());
    vector<shared_ptr<Card>> oldEstablishments = oldPlayer.getEstablishments();
    setEstablishments(oldEstablishments);
    setAllLandmarksFalse();
}


// Destructor
Player::~Player(){

}

// Getters
int Player::getMoney() const{
    return money;
}

vector<shared_ptr<Card>> Player::getEstablishments() const{
    return establishments;
}

bool Player::getTrainStationBool() const{
    return trainStation;
}
bool Player::getShoppingMallBool() const{
    return shoppingMall;
}
bool Player::getAmusementParkBool() const{
    return amusementPark;
}
bool Player::getRadioTowerBool() const{
    return radioTower;
}
int Player::getID() const{
    return ID;
}

// Setters
void Player::setMoney(int newMoney){
    if (newMoney >= 0){
        money = newMoney;
    }
    else{
        money = 0;
    }
}
void Player::setEstablishments(vector<shared_ptr<Card>> &newEstablishments){
    establishments = newEstablishments;
}
void Player::setTrainStationBool(bool newValue){
    trainStation = newValue;
}
void Player::setShoppingMallBool(bool newValue){
    shoppingMall = newValue;
}
void Player::setAmusementParkBool(bool newValue){
    amusementPark = newValue;
}
void Player::setRadioTowerBool(bool newValue){
    radioTower = newValue;
}
void Player::setID(int newID){
    ID = newID;
}

// Other Methods
bool Player::checkWinner() const{
    if (trainStation && shoppingMall && amusementPark && radioTower){
        return true;
    }
    else{
        return false;
    }
}

void Player::addEstablishment(shared_ptr<Card> &establishment) {
    establishments.push_back(establishment);
}

int Player::getNumberOfEstablishment(string name) const{
    int count = 0;
    for (int i = 0; i < establishments.size(); i++){
        if (establishments[i]->getName() == name){
            count++;
        }
    }
    return count;
}

int Player::getNumberOfEstablishment(cardSymbol symbol) const {
    int count = 0;


        for (int i = 0; i < establishments.size(); i++) {
            if (establishments[i]->getCardSymbol() == symbol) {
                count++;
            }
        }

    return count;
}
void Player::setAllLandmarksFalse(){
    trainStation = false;
    shoppingMall = false;
    amusementPark = false;
    radioTower = false;
}


