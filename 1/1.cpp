#include <iostream>
#include <cmath>


class Vector {
private:
    double r;      // Довжина вектора
    double theta;  // Кут в градусах


public:
    // Конструктор за умовчанням
    Vector() : r(0), theta(0) {}


    // Конструктор з параметрами
    Vector(double radius, double angle) : r(radius), theta(angle) {}


    // Конструктор копіювання
    Vector(const Vector &vec) : r(vec.r), theta(vec.theta) {}


    // Метод повороту вектору на будь-який кут
    void rotate(double angle) {
        theta += angle;
    }


    // Методи отримання даних вектору
    double getR() const {
        return r;
    }


    double getTheta() const {
        return theta;
    }


    // Перевантаження оператора ділення
    Vector operator/(double scalar) const {
        if (scalar != 0) {
            return Vector(r / scalar, theta);
        } else {
            throw std::invalid_argument("Division by zero is not allowed");
        }
    }


    // Перевантаження оператора додавання
    Vector operator+(const Vector &other) const {
        // Перетворення полярних координат у декартові для додавання
        double x1 = r * cos(theta * M_PI / 180.0);
        double y1 = r * sin(theta * M_PI / 180.0);
        double x2 = other.r * cos(other.theta * M_PI / 180.0);
        double y2 = other.r * sin(other.theta * M_PI / 180.0);


        // Сума декартових координат
        double x = x1 + x2;
        double y = y1 + y2;


        // Перетворення назад у полярні координати
        double newR = sqrt(x * x + y * y);
        double newTheta = atan2(y, x) * 180.0 / M_PI;


        return Vector(newR, newTheta);
    }


    // Метод для виведення вектора на екран
    void display() const {
        std::cout << "Vector(r=" << r << ", theta=" << theta << " degrees)" << std::endl;
    }
};


int main() {
    // Створення трьох об'єктів, використовуючи різні конструктори
    Vector B1;
    Vector B2(10, 30);
    Vector B3 = B2; // Конструктор копіювання


    // Виведення початкових векторів
    std::cout << "Initial vectors:" << std::endl;
    std::cout << "B1: "; B1.display();
    std::cout << "B2: "; B2.display();
    std::cout << "B3: "; B3.display();


    // Зменшення об'єкта B2 у 2 рази
    B2 = B2 / 2;
    std::cout << "B2 after halving: "; B2.display();


    // Поворот об'єкта B3 на 45 градусів
    B3.rotate(45);
    std::cout << "B3 after rotating by 45 degrees: "; B3.display();


    // Складання об'єктів B2 і B3, результат помістити до об'єкта B1
    B1 = B2 + B3;
    std::cout << "B1 after adding B2 and B3: "; B1.display();


    return 0;
}
