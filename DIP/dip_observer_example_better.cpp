//
// Created by sajith on 4/24/21.
//

#include <iostream>
#include <set>


class WeatherForecast;

class User
{
public:
    User(WeatherForecast &);
    void notify();
};

class WeatherForecast
{
    std::set<User *> listeners;

public:
    void subscribe(User &);
    void update();
};


User::User(WeatherForecast &forecast)
{
    forecast.subscribe(*this);
}

void User::notify()
{
    std::cout << "Notified " << this << "\n";
}

void WeatherForecast::subscribe(User &user)
{
    listeners.insert(&user);
}

void WeatherForecast::update()
{
    for (auto &l: listeners)
    {
        l->notify();
    }
}

int main()
{
    WeatherForecast forecast;
    User user1(forecast), user2(forecast);
    forecast.update();
    
    return 0;
}