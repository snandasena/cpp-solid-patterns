//
// Created by sajith on 4/24/21.
//

#include <iostream>
#include <set>

template<typename T> concept Notifyable =
requires(T t){
    t.notify();
};


template<Notifyable T>
class WeatherForecast
{
    std::set<T *> subscribers;

public:
    void subscribe(T &subscriber)
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

class User
{
public:
    void notify()
    {
        std::cout << "Notified " << this << "\n";
    }
};

int main()
{
    WeatherForecast<User> forecast;
    User user1, user2;
    forecast.subscribe(user1);
    forecast.subscribe(user2);

    forecast.update();

    return 0;
}