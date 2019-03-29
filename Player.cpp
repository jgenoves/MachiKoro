//
// Created by Joshua Newton on 3/15/2019.
//

#include "Player.h"

Player::Player(){
    setMoney(0);
    setAllLandmarksFalse();
}
Player::Player(int newMoney){
    setMoney(newMoney);
    setAllLandmarksFalse();
}
Player::Player(int newMoney, vector<Card> newEstablishments){
    setMoney(newMoney);
    setEstablishments(newEstablishments);
    setAllLandmarksFalse();
}

// Destructor
Player::~Player(){

}

// Getters
int Player::getMoney() const{
    return money;
}
/*
vector<unique_ptr<Card>> Player::getEstablishments() const{
    return establishments;
}
 */
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

// Setters
void Player::setMoney(int newMoney){
    if (newMoney >= 0){
        money = newMoney;
    }
    else{
        money = 0;
    }
}
void Player::setEstablishments(vector<Card> newEstablishments){
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

// Other Methods
bool Player::checkWinner() const{
    if (trainStation && shoppingMall && amusementPark && radioTower){
        return true;
    }
    else{
        return false;
    }
}
/*
int Player::getNumberOfEstablishment(Card establishment) const{
    int count = 0;
    for (int i = 0; i < establishments.size(); i++){
        if (establishments[i]->getName() == establishment.getName()){
            count++;
        }
    }
    return count;
}
 */
void Player::setAllLandmarksFalse(){
    trainStation = false;
    shoppingMall = false;
    amusementPark = false;
    radioTower = false;
}
