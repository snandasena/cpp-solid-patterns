//
// Created by sajith on 4/1/21.
//

#include <iostream>
#include <memory>
#include <cassert>

class Base
{
public:

    void method()
    {
        this->stepA();
        this->stepB();
        this->stepC();
    }


protected:
    virtual void stepA() = 0;

    virtual void stepB()
    {
        std::cout << "Step B. Hook method\n";
    }

    void stepC()
    {
        std::cout << "Step C. Invariant method\n";
    }
};

class Subclass1 : public Base
{
protected:
    void stepA()
    {
        std::cout << "Step A. Subclass1 method\n";
    }
};

class Subclass2 : public Base
{
protected:
    void stepA()
    {
        std::cout << "Step A. Subclass2 method\n";
    }

    void stepB()
    {
        std::cout << "Step B. Hook method overridden\n";
    }
};


int main()
{
    std::unique_ptr<Base> b1 = std::make_unique<Subclass1>();
    std::unique_ptr<Base> b2 = std::make_unique<Subclass2>();

    b1->method();
    std::cout<<"\n";
    b2->method();

    return 0;

}