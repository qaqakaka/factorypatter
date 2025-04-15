#include <iostream>
#include <cmath>
#include <string>
#include <gtest/gtest.h>

// Base class Shape
class Shape
{
public:
    virtual double area() const = 0;
    virtual ~Shape() {}
};

// Derived class Circle
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double area() const override
    {
        return M_PI * radius * radius;
    }
};

// Derived class Square
class Square : public Shape
{
private:
    double side;

public:
    Square(double s) : side(s) {}
    double area() const override
    {
        return side * side;
    }
};

// Derived class Rectangle
class Rectangle : public Shape
{
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override
    {
        return length * width;
    }
};

// ShapeFactory to create shapes
class ShapeFactory
{
public:
    static Shape *createShape(const std::string &shapeType, double arg1, double arg2 = 0)
    {
        if (shapeType == "circle")
        {
            return new Circle(arg1);
        }
        else if (shapeType == "square")
        {
            return new Square(arg1);
        }
        else if (shapeType == "rectangle")
        {
            return new Rectangle(arg1, arg2);
        }
        return nullptr;
    }
};

// Google Test Unit Tests

TEST(CircleTest, AreaCalculation)
{
    Shape *circle = ShapeFactory::createShape("circle", 5);
    ASSERT_NE(circle, nullptr);
    EXPECT_NEAR(circle->area(), 78.5398, 0.0001);
    delete circle;
}

TEST(SquareTest, AreaCalculation)
{
    Shape *square = ShapeFactory::createShape("square", 4);
    ASSERT_NE(square, nullptr);
    EXPECT_EQ(square->area(), 16);
    delete square;
}

TEST(RectangleTest, AreaCalculation)
{
    Shape *rectangle = ShapeFactory::createShape("rectangle", 4, 6);
    ASSERT_NE(rectangle, nullptr);
    EXPECT_EQ(rectangle->area(), 24);
    delete rectangle;
}

// Google Test main runner
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// clang++ -std=c++14 \
//   -I/opt/homebrew/Cellar/googletest/1.16.0/include \
//   test_example.cpp \
//   -L/opt/homebrew/Cellar/googletest/1.16.0/lib \
//   -lgtest -lgtest_main -pthread \
//   -o test_example

//./test_example
