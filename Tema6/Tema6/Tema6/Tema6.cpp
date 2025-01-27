#include <iostream>
#include <vector>
#include <string>
#include <utility> 

class MyClass {
private:
    std::string name;
    std::vector<int> data;

public:
   
    MyClass(const std::string& n, int size) : name(n), data(size, 0) {
        std::cout << "Constructor standard apelat" << std::endl;
    }

    
    MyClass(const std::string& n) : MyClass(n, 10) {}

    
    MyClass(MyClass&& other) noexcept : name(std::move(other.name)), data(std::move(other.data)) {
        std::cout << "Move constructor apelat" << std::endl;
    }

  
    void print() const {
        std::cout << "Name: " << name << ", Data: [";
        for (const auto& val : data) {
            std::cout << val << " ";
        }
        std::cout << "]" << std::endl;
    }
};

class Point {
private:
    int x;
    int y;

public:
  
    Point(int x_val, int y_val) : x(x_val), y(y_val) {}

   
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    
    void print() const {
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;
    }
};



int main() {
   
    MyClass obj1("Test", 5); 
    obj1.print();

    MyClass obj2("AnotherTest"); 
    obj2.print();

    MyClass obj3 = std::move(obj1); 
    obj3.print();

 
    Point p1(3, 4);
    Point p2(1, 2);
    Point p3 = p1 + p2; 
    p3.print();

   
  

    return 0;
}
