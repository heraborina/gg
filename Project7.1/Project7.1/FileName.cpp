#include <stdexcept>
#include <algorithm>
#include <iostream>
using namespace std;

struct radianandygol {
    static double toDegrees(double rad) {
        if (rad <= 0) {
            throw std::invalid_argument("Угол должен быть положительным");
        }
        return (rad * 180) / 3.14;
    }
    static double toRadians(double deg) {
        if (deg <= 0) {
            throw std::invalid_argument("Угол должен быть положительным");
        }
        return (deg * 3.14) / 180;
    }
    static double toYgol(double y, double x) {
        if ((y <= 0) || (x <= 0)) {
            throw std::invalid_argument("Угол должен быть положительным");
        }
        return 180 - (x + y);
    }
};

int main() {
    setlocale(LC_ALL, "Russian");


    int choice;
    radianandygol r;
    cout << "Выберите конвертацию:\n";
    cout << "1. Радианы в градусы\n";
    cout << "2. Градусы в радианы\n";
    cout << "3. Найти третий угол\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    if (choice == 1) {
       
            double radians;
            cout << "Введите значение в радианах: ";
            cin >> radians;
            cout << radians << " радиан = " << r. toDegrees(radians) << " градусов\n";
        
    }
    else if (choice == 2) {

        double degrees;
        cout << "Введите значение в градусах: ";
        cin >> degrees;
        cout << degrees << " градусов = " << r. toRadians(degrees) << " радиан\n";
    }
    
    else if (choice == 3) {
  

            double angle1, angle2;
            cout << "Введите первый угол (в градусах): ";
            cin >> angle1;
            cout << "Введите второй угол (в градусах): ";
            cin >> angle2;
            cout << "Третий угол треугольника: " << r. toYgol << " градусов\n";

    }
    else {
        throw std::invalid_argument("Неверный выбор");
    }
    return 0;
}


