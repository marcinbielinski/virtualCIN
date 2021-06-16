#include <iostream>
#include <utility>
#include <vector>

class Shape {
public:
    Shape() { std::cout << "Constructor Shape" << std::endl; }

    virtual ~Shape() { std::cout << "Destructor Shape" << std::endl; }

    virtual void printName() = 0;

    virtual double calcArea() = 0;
};

class Circle : public Shape {
public:
    explicit Circle (std::string name, double radius)
                    : n_name((std::move(name), prom(radius)))
                    { std::cout << "Constructor Circle" << std::endl; }

    ~Circle() override { std::cout << "Destructor Circle" << std::endl; }

    void printName() override {std::cout << "My name is: " << n_name << std::endl; }

    double calcArea() override {
        return pi*prom*prom;
    }

private:
    std::string n_name;
    double prom;
    const double pi = 3.14;

};

class Rectangle : public Shape{
public:
    explicit Rectangle  (std::string name, double length, double breadth)
                        : n_name(std::move(name), a(length), b(breadth))
                        { std::cout << "Constructor Rectangle" << std::endl; }

    ~Rectangle() override { std::cout << "Destructor Rectangle" << std::endl; }

    void printName() override {std::cout << "My name is: " << n_name << std::endl; }

    double calcArea() override {
        return a*b;
    }

private:
    std::string n_name;
    double a;
    double b;

};

class Triangle : public Shape{
public:
    explicit Triangle   (std::string name, double base, double height) :
                        n_name(std::move(name), a(base), h(height))
                        { std::cout << "Constructor Triangle" << std::endl; }

    ~Triangle() override { std::cout << "Destructor Triangle" << std::endl; }

    void printName() override {std::cout << "My name is: " << n_name << std::endl; }

    double calcArea() override {
        return a*h/2;
    }

private:
    std::string n_name;
    double a;
    double h;
};

void greetUser() {
    std::cout << "Chose what you want to create and append to vector. \n"
                 "Circle, Rectangle or Triangle? \n"
                 "Append 5 elements. \n"           << std::endl;
}
int main() {
    std::vector<Shape*> vec;

    greetUser();
    std::string input;

    int counter = 0;
    while (counter < 5)
    {
        std::cin >> input;
        if(input == "Circle")
        {
            std::cout << "Enter the radius of your circle: " << std::endl;
            double r;
            std::cin >> r;
            vec.emplace_back(new Circle(input, r));
            ++counter;
            continue;
        }
        else if (input == "Rectangle")
        {
            std::cout << "Enter the length and breadth of your rectangle: " << std::endl;
            double a;
            std::cin >> a;
            double b;
            std::cin >> b;
            vec.emplace_back(new Rectangle((input), a, b));
            ++counter;
            continue;
        }
        else if (input == "Triangle")
        {
            std::cout << "Enter the length of base and height of Your triangle: " << std::endl;
            double b;
            std::cin >> b;
            double h;
            std::cin >> h;
            vec.emplace_back(new Triangle((input), b, h));
            ++counter;
            continue;
        }
        else {
            std::cout << "Invalid input." << std::endl;
            break;
        }

    }

    for (auto& elem : vec)
    {
        elem->printName();
        elem->calcArea();
    }

    for (auto elem : vec)
    {
        delete elem;
    }
    return 0;
}
