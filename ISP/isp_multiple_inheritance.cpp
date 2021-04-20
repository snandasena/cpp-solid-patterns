//
// Created by sajith on 4/20/21.
//

#include <iostream>
#include <memory>

class A
{
public:
    virtual ~A() = default;

    virtual void foo()
    {
        std::cout << "A\n";
    }
};


class B : public virtual A
{
public:
    void foo()
    {
        std::cout << "B\n";
    }
};


class C : public virtual A
{
public:
    void foo()
    {
        std::cout << "C\n";
    }
};


class D : public B, public C
{
public:
    void foo()
    {
        std::cout << "D\n"; // otherwise no unique overrider
    }
};

// Diamond problem
/*
/\
\/
*/

int main()
{
    std::unique_ptr<A> p = std::make_unique<D>();
    p->foo();

    return 0;
}