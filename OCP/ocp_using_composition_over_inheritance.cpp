//
// Created by sajith on 4/1/21.
//

#include <iostream>
#include <memory>

class SwimDelegate
{
public:
    virtual ~SwimDelegate() = default;
    virtual void swim() const = 0;
};

class Submarine : public SwimDelegate
{
public:
    void swim() const
    {
        std::cout << "Submarine moving\n";

    }
};


class AircraftCarrier : public SwimDelegate
{
public:
    void swim() const
    {
        std::cout << "Aircraft carrier moving\n";
    }
};


class FlyDelegate
{
public:
    virtual ~FlyDelegate() = default;
    virtual void fly() const = 0;
};


class Helicopter : public FlyDelegate
{
public:
    void fly() const
    {
        std::cout << "Helicopter moving\n";
    }
};

class FighterAircraft : public FlyDelegate
{
public:
    void fly() const
    {
        std::cout << "Fighter aircraft moving\n";
    }
};


class Player
{
    std::unique_ptr<SwimDelegate> _swimDelegate;
    std::unique_ptr<FlyDelegate> _flyDelegate;

public:
    Player(std::unique_ptr<SwimDelegate> swimDelegate, std::unique_ptr<FlyDelegate> flyDelegate) :
            _swimDelegate{std::move(swimDelegate)}, _flyDelegate{std::move(flyDelegate)} {}

    void swim()
    {
        if (_swimDelegate)
        {
            _swimDelegate->swim();
        }
    }


    void fly()
    {
        if (_flyDelegate)
        {
            _flyDelegate->fly();
        }
    }
};


int main()
{
    Player player1(std::make_unique<Submarine>(), std::make_unique<Helicopter>());
    player1.fly();
    player1.swim();

    Player player2(std::make_unique<AircraftCarrier>(), std::make_unique<FighterAircraft>());
    player2.fly();
    player2.swim();

    return 0;
}