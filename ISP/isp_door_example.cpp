
//
// Created by sajith on 4/18/21.
//

#include <iostream>
#include <optional>
#include <stdexcept>

class TimerClient
{
public:
    virtual ~TimerClient() = default;
    virtual void timeout() = 0;
};

class Door : public TimerClient
{
public:
    virtual void open() = 0;
    virtual void close() = 0;
};

class Timer
{
    TimerClient &client;

public:
    Timer(TimerClient &client) : client{client}
    {
        client.timeout();
    }
};


class TimedDoor : public Door
{
    std::optional<Timer> timer;
public:
    void open()
    {
        std::cout << "Open\n";
        timer.emplace(Timer(*this));
    }

    void close()
    {
        std::cout << "Close\n";
    }

    void timeout()
    {
        std::cout << "Timeout\n";
        close();
        timer = std::nullopt;
    }
};


class NormalDoor : public Door
{
public:
    void open()
    {
        std::cout << "Open\n";
    }

    void close()
    {
        std::cout << "Close\n";
    }

    void timeout()
    {
        throw std::runtime_error{"Not implemented"};
    }

};

int main()
{
    TimedDoor door;
    door.open();
    door.open();

    return 0;
}

