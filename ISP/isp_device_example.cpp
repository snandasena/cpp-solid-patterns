//
// Created by sajith on 4/19/21.
//

#include <iostream>
#include <stdexcept>

class Device
{
public:
    virtual ~Device() = default;
    virtual void print() = 0;
    virtual void scan() = 0;
    virtual void fax() = 0;
};


class AdvancedPrinter : public Device
{

public:

    void print()
    {
        std::cout << "Printing...\n";
    }

    void scan()
    {
        std::cout << "Scanning...\n";
    }

    void fax()
    {
        std::cout << "Faxing...\n";
    }
};


class SimplePrinter : public Device
{

public:

    void print()
    {
        std::cout << "Printing...\n";
    }

    void scan()
    {
        throw std::runtime_error{"Not implemented"};
    }

    void fax()
    {
        throw std::runtime_error{"Not implemented"};
    }
};

// clients
void printUsers(Device &device)
{
    device.print();
}

void scanUsers(Device &device)
{
    device.scan();
}

void faxUsers(Device &device)
{
    device.fax();
}

int main()
{
    AdvancedPrinter advancedPrinter;
    SimplePrinter simplePrinter;

    printUsers(advancedPrinter);
    scanUsers(advancedPrinter);
    faxUsers(advancedPrinter);

    scanUsers(simplePrinter);
    return 0;
}