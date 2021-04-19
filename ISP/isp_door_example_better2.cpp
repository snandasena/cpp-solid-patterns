
//
// Created by sajith on 4/18/21.
//

#include <iostream>
#include <optional>
#include <stdexcept>
#include <memory>

class TimerClient
{
public:
    virtual ~TimerClient() = default;
    virtual void timeout() = 0;
};

class Door
{
public:
    virtual ~Door() = default;
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

class TimedDoorAdapter;


class TimedDoor : public Door
{
    std::unique_ptr<TimedDoorAdapter> adapter;
public:
    void open()
    {
        std::cout << "Open\n";
        adapter = std::make_unique<TimedDoorAdapter>(*this);
    }

    void close()
    {
        std::cout << "Close\n";
    }

    void timeout()
    {
        std::cout << "Timeout\n";
        close();
        adapter = nullptr;
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
};

class TimedDoorAdapter : public TimerClient
{
    TimedDoor &door;
    Timer timer;

public:
    TimedDoorAdapter(TimedDoor &door) : door{door}, timer{Timer{*this}} {}

    void timeout()
    {
        door.timeout();
    }
};

int main()
{
    TimedDoor door;
    door.open();
    door.open();

    return 0;
}

