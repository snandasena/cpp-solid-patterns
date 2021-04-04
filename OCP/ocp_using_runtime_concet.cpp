//
// Created by sajith on 4/4/21.
//


#include <iostream>
#include <memory>
#include <vector>


class Dog
{

    std::string m_name;
public:
    Dog(std::string name) : m_name{name} {}

    void speak() const
    {
        std::cout << m_name << " barking...\n";
    }
};

class Cat
{

    std::string m_name;
public:
    Cat(std::string name) : m_name{name} {}

    void speak() const
    {
        std::cout << m_name << " meowing...\n";
    }
};


template<typename T>
concept Speakable=
requires(T t)
{
    t.speak();
};


class Wrapper
{
public:
    template<Speakable T>
    Wrapper(T &&speakable): ptr{std::make_unique<Model<T>>(std::forward<T>(speakable))} {}

    void speak() const
    {
        ptr->speak();
    }

private:
    class Concept
    {
    public:
        virtual ~Concept() = default;
        virtual void speak() const = 0;
    };

    template<Speakable T>
    class Model : public Concept
    {
    public:
        Model(T &&speakable) : m_speakable{std::move(speakable)} {}

        void speak() const
        {
            m_speakable.speak();
        }

    private:
        T m_speakable;
    };

    std::unique_ptr<Concept> ptr;
};

void talk(const std::vector<Wrapper> &vec)
{
    for (const auto &e:vec)
    {
        e.speak();
    }
}

int main()
{
    std::vector<Wrapper> vec;
    vec.emplace_back(Wrapper(Dog("Buddy")));
    vec.emplace_back(Wrapper(Cat("Tom")));

    talk(vec);
    return 0;
}