//
// Created by sajith on 4/1/21.
//


#include <vector>
#include <string>
#include <iostream>

class Dog
{
    std::string m_name;

public:
    Dog(std::string name) : m_name{std::move(name)} {}

    void speak() const
    {
        std::cout << m_name << " barking..\n";
    }
};


class Cat
{
    std::string m_name;

public:
    Cat(std::string name) : m_name{std::move(name)} {}

    void speak() const
    {
        std::cout << m_name << " meowing..\n";
    }
};

template<typename T>
concept Speakable =
requires(T t)
{
    t.speak();
};


template<Speakable T>
class SpeakableDecorator : public T
{
public:
    template<typename  ...Args>
    SpeakableDecorator(Args... args):   T(std::forward<Args>(args)...) {}

    void speak() const
    {
        std::cout << "Decorated: ";
        T::speak();
    }
};


template<Speakable Animal>
void speak(const Animal &animal)
{
    std::cout << "Hello\n";
    animal.speak();
}

int main()
{
    auto decoratorDog = SpeakableDecorator<Dog>("Charlie");
    auto decoratorCat = SpeakableDecorator<Cat>("Tom");

    speak(decoratorDog);
    speak(decoratorCat);

    return 0;
}