//
// Created by Joshua Newton on 3/15/2019.
//

#ifndef CS205FINAL_PLAYER_H
#define CS205FINAL_PLAYER_H

#ifndef CARD_H
#define CARD_H

class Card;

#include "Card.h"

class Player{
public:
    // Constructors
    Player();
    Player(int newMoney);
    Player(int newMoney, vector<shared_ptr<Card>> &newEstablishments);

    // Copy Constructor
    Player(const Player &oldPlayer);
    // Destructor
    ~Player();

    // Getters
    int getMoney() const;
    vector<shared_ptr<Card>> getEstablishments() const;
    bool getTrainStationBool() const;
    bool getShoppingMallBool() const;
    bool getAmusementParkBool() const;
    bool getRadioTowerBool() const;
    int getID() const;

    // Setters
    void setMoney(int newMoney);
    void setEstablishments(vector<shared_ptr<Card>> &newEstablishments);
    void setTrainStationBool(bool newValue);
    void setShoppingMallBool(bool newValue);
    void setAmusementParkBool(bool newValue);
    void setRadioTowerBool(bool newValue);
    void setID(int newID);

    // Other Methods
    bool checkWinner() const;
    int getNumberOfEstablishment(string name) const;
    int getNumberOfEstablishment(cardSymbol symbol) const;
    void setAllLandmarksFalse();

protected:
    int ID;
    int money;
    vector<shared_ptr<Card>> establishments;
    bool trainStation;
    bool shoppingMall;
    bool amusementPark;
    bool radioTower;
};

#endif //CARD_H

#endif //CS205FINAL_PLAYER_H
