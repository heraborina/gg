#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class RangeWorker {
private:
    int minVal;
    int maxVal;

public:
    // Конструктор
    RangeWorker(int min = 0, int max = 100) {
        minVal = min;
        maxVal = max;
    }

    // 1. Установить диапазон
    void setRange(int min, int max) {
        minVal = min;
        maxVal = max;
    }

    // 2. Сгенерировать случайные числа в диапазоне
    void generateNumbers(int count) {
        srand(time(0));
        for (int i = 0; i < count; i++) {
            // Генерируем случайное число в диапазоне
            int randomNum = minVal + rand() % (maxVal - minVal + 1);

            // 3. Проверяем, находится ли число в диапазоне
            if (isInRange(randomNum)) {
                cout << randomNum << " - в диапазоне" << endl;
            }
            else {
                cout << randomNum << " - НЕ в диапазоне" << endl;
            }
        }
    }

    // 3. Проверить, находится ли число в диапазоне
    bool isInRange(int num) {
        return (num >= minVal && num <= maxVal);
    }

    // 4. Получить длину диапазона
    int getRangeLength() {
        return maxVal - minVal;
    }
};

int main()
{
    setlocale(LC_ALL, "RUssian");
    // Создаем объект
    RangeWorker worker;

    // 1. Устанавливаем диапазон
    worker.setRange(10, 50);

    // 2. Генерируем числа и проверяем их
    cout << "Проверка случайных чисел в диапазоне:" << endl;
    worker.generateNumbers(5);

    // 4. Получаем длину диапазона
    cout << "\nДлина диапазона: " << worker.getRangeLength() << endl;

    return 0;
}