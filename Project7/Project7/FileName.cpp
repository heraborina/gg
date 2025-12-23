#include <stdexcept>
#include <algorithm>
#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");
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
        static void convertFromInput() {
            using namespace std;

            int choice;
            cout << "Выберите конвертацию:\n";
            cout << "1. Радианы в градусы\n";
            cout << "2. Градусы в радианы\n";
            cout << "3. Найти третий угол\n";
            cout << "Ваш выбор: ";
            cin >> choice;

            if (choice == 1) {
                convertRadiansToDegrees();
            }
            else if (choice == 2) {
                convertDegreesToRadians();
            }
            else if (choice == 3) {
                findThirdAngle();
            }
            else {
                throw std::invalid_argument("Неверный выбор");
            }
        }
        static void convertRadiansToDegrees() {
            using namespace std;

            double radians;
            cout << "Введите значение в радианах: ";
            cin >> radians;

            if (cin.fail()) {
                throw std::invalid_argument("Некорректный ввод");
            }

            if (radians < 0) {
                throw std::invalid_argument("Радианы не могут быть отрицательными");
            }

            double degrees = toDegrees(radians);
            cout << radians << " радиан = " << degrees << " градусов\n";
        }
        static void convertDegreesToRadians() {
            using namespace std;

            double degrees;
            cout << "Введите значение в градусах: ";
            cin >> degrees;

            if (cin.fail()) {
                throw std::invalid_argument("Некорректный ввод");
            }

            if (degrees < 0) {
                throw std::invalid_argument("Градусы не могут быть отрицательными");
            }

            double radians = toRadians(degrees);
            cout << degrees << " градусов = " << radians << " радиан\n";
        }
        static void findThirdAngle() {
            using namespace std;

            double angle1, angle2;
            cout << "Введите первый угол (в градусах): ";
            cin >> angle1;

            if (cin.fail()) {
                throw std::invalid_argument("Некорректный ввод первого угла");
            }

            cout << "Введите второй угол (в градусах): ";
            cin >> angle2;

            if (cin.fail()) {
                throw std::invalid_argument("Некорректный ввод второго угла");
            }

            if (angle1 <= 0 || angle2 <= 0) {
                throw std::invalid_argument("Углы должны быть положительными");
            }

            if (angle1 + angle2 >= 180) {
                throw std::invalid_argument("Сумма двух углов треугольника должна быть меньше 180 градусов");
            }

            double thirdAngle = toYgol(angle1, angle2);
            cout << "Третий угол треугольника: " << thirdAngle << " градусов\n";
            double thirdAngleRadians = toRadians(thirdAngle);
            cout << "Третий угол в радианах: " << thirdAngleRadians << " радиан\n";
        }
        static void showInDegreesMinutesSeconds(double degrees) {
            using namespace std;

            int deg = static_cast<int>(degrees);
            double minutesDecimal = (degrees - deg) * 60.0;
            int minutes = static_cast<int>(minutesDecimal);
            double seconds = (minutesDecimal - minutes) * 60.0;

            cout << "В формате DMS: "
                << deg << "° "
                << minutes << "' "
                << seconds << "\"\n";
        }
        static void showCommonValues() {
            using namespace std;

            cout << "\nОбщие значения:\n";
            cout << "? радиан = " << toDegrees(3.14) << " градусов\n";
            cout << "?/2 радиан = " << toDegrees(3.14 / 2) << " градусов\n";
            cout << "?/4 радиан = " << toDegrees(3.14 / 4) << " градусов\n";
            cout << "2? радиан = " << toDegrees(2 * 3.14) << " градусов\n";
        }
    };  
    {
        using namespace std;

        try {
            cout << "=== Конвертер радиан/градусов ===\n";
            radianandygol::convertFromInput();
            radianandygol::showCommonValues();
        }
        catch (const invalid_argument& e) {
            cerr << "Ошибка: " << e.what() << endl;
            return 1;
        }
        catch (...) {
            cerr << "Неизвестная ошибка" << endl;
            return 1;
        }

        return 0;
    }
};