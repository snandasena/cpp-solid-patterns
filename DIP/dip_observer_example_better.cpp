//
// Created by sajith on 4/24/21.
//

#include <iostream>
#include <set>

class Subscriber;

class Forecast
{
public:
    virtual ~Forecast() = default;
    virtual void subscribe(Subscriber &) = 0;
};

class Subscriber
{
public:
    virtual ~Subscriber() = default;
    virtual void notify() = 0;
};

class WeatherForecast : public Forecast
{
    std::set<Subscriber *> subscribers;

public:

    void subscribe(Subscriber &subscriber)
    {
        subscribers.insert(&subscriber);
    }

    void update()
    {
        for (auto &s: subscribers)
        {
            s->notify();
        }
    }
};

class User : public Subscriber
{
public:
    User(Forecast &forecast)
    {
        forecast.subscribe(*this);
    }

    void notify()
    {
        std::cout << "Notified " << this << "\n";
    }
};

int main()
{
    WeatherForecast forecast;
    User user1(forecast), user2(forecast);
    forecast.update();

    return 0;
}