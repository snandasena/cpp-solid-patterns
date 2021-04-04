//
// Created by sajith on 4/4/21.
//

#include <iostream>
#include <cassert>

class Rectangle
{
protected:
    int height;
    int width;

public:
    explicit Rectangle(const int h, const int w) : height{h}, width{w}
    {
        assert(getArea() != 0);
    }

    virtual ~Rectangle() = default;

    virtual void setHeight(const int value)
    {
        height = value;
    }

    virtual void setWidth(const int value)
    {
        width = value;
    }

    virtual int getArea() const
    {
        return height * width;
    }

};

class Square : public Rectangle
{
public:
    explicit Square(const int side) : Rectangle(side, side)
    {
        assert(getArea() != 0);
    }

    void setHeight(int val)
    {
        setSide(val);
    }

    void setWidth(int val)
    {
        setSide(val);
    }


    void setSide(int side)
    {
        height = side;
        width = side;
    }
};

int changeArea(Rectangle &rectangle)
{
    assert(rectangle.getArea() != 0);
    rectangle.setHeight(4);
    rectangle.setHeight(5);
    assert(rectangle.getArea() == 20);
    return rectangle.getArea();
}

int main()
{
    Rectangle rectangle{1, 3};
    Square square{2};
    changeArea(rectangle);
    changeArea(square);

    return 0;
}