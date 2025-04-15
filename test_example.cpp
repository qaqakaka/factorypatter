// #include <iostream>
// #include <string>
// #include <stdexcept>
// #include <gtest/gtest.h>

// // Student Class Definition
// class Student
// {
// private:
//     std::string name[3] = {"Alice", "Bob", "Charlie"}; // Initialized names
//     int age[3] = {20, 21, 22};                         // Initialized ages
//     int marks[3] = {85, 0, 70};                        // Initialized marks (Bob has 0 marks)

// public:
//     // Method to add marks
//     void addMark(int index, int mark)
//     {
//         if (index < 0 || index >= 3)
//         {
//             throw std::out_of_range("Index out of range");
//         }
//         marks[index] = mark;
//     }

//     // Method to calculate grade based on marks
//     std::string calculateGrade(int index)
//     {
//         if (index < 0 || index >= 3)
//         {
//             throw std::out_of_range("Index out of range");
//         }

//         if (marks[index] == 0)
//         {
//             throw std::runtime_error("No marks entered, cannot calculate grade");
//         }

//         if (marks[index] >= 90)
//             return "A";
//         if (marks[index] >= 75)
//             return "B";
//         if (marks[index] >= 50)
//             return "C";
//         return "F"; // For marks < 50
//     }

//     // Method to calculate average marks
//     double calculateAverage()
//     {
//         double total = 0;
//         for (int i = 0; i < 3; ++i)
//         {
//             total += marks[i];
//         }
//         return total / 3.0;
//     }

//     // Getter methods for name, age, and marks
//     std::string getName(int index)
//     {
//         return name[index];
//     }

//     int getAge(int index)
//     {
//         return age[index];
//     }

//     int getMarks(int index)
//     {
//         return marks[index];
//     }
// };

// // Test case for adding marks and calculating grade
// TEST(StudentTest, TestAddMarkAndCalculateGrade)
// {
//     Student student;

//     // Print individual grades for each student
//     for (int i = 0; i < 3; ++i)
//     {
//         try
//         {
//             std::cout << student.getName(i) << " (" << student.getMarks(i) << " marks) should get a \""
//                       << student.calculateGrade(i) << "\".\n";
//         }
//         catch (const std::exception &e)
//         {
//             std::cout << student.getName(i) << " (" << student.getMarks(i) << " marks) should trigger an exception: "
//                       << e.what() << "\n";
//         }
//     }

//     // Now calculate and print the average
//     double average = student.calculateAverage();
//     std::cout << "Average marks: " << average << "\n";
//     std::cout << "The average grade for the class is: " << student.calculateGrade(0) << "\n";

//     // Test case where marks are 0 and grade calculation should throw an error
//     EXPECT_THROW({
//         student.addMark(1, 0);     // Bob has 0 marks
//         student.calculateGrade(1); // This should throw an error
//     },
//                  std::runtime_error); // Expect a runtime_error to be thrown

//     // Test for the average calculation
//     double expectedAverage = (85 + 0 + 70) / 3.0;
//     EXPECT_NEAR(student.calculateAverage(), expectedAverage, 0.01); // Expect average to be 51.67, allowing a small tolerance
// }

// // Main function to run all tests
// int main(int argc, char **argv)
// {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }

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
