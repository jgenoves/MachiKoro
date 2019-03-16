//
// Created by Joshua Newton on 3/15/2019.
//

#ifndef CS205FINAL_PLAYER_H
#define CS205FINAL_PLAYER_H

#include <memory>
#include <vector>
#include "Card.h"

class Player{
public:
    // Constructors
    Player();
    Player(int newMoney);
    Player(int newMoney, vector<unique_ptr<Card>> newEstablishments);

    // Destructor
    ~Player();

    // Getters
    int getMoney() const;
    vector<unique_ptr<Card>> getEstablishments() const;
    bool getTrainStationBool() const;
    bool getShoppingMallBool() const;
    bool getAmusementParkBool() const;
    bool getRadioTowerBool() const;

    // Setters
    void setMoney(int newMoney);
    void setEstablishments(vector<unique_ptr<Card>> newEstablishments);
    void setTrainStationBool(bool newValue);
    bool setShoppingMallBool(bool newValue);
    bool setAmusementParkBool(bool newValue);
    bool setRadioTowerBool(bool newValue);

    // Other Methods
    bool checkWinner() const;
    int getNumberOfEstablishment(Card establishment) const;
    void setAllLandmarksFalse();

protected:
    int money;
    vector<unique_ptr<Card>> establishments;
    bool trainStation;
    bool shoppingMall;
    bool amusementPark;
    bool radioTower;
};

#endif //CS205FINAL_PLAYER_H
