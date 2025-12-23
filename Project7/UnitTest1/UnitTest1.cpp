#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include <cmath>

// Подключаем файл с исходным кодом
#include "H:\УП\Работа 7\Project7\Project7\FileName.cpp" 
namespace OriginalCodeStub {
    struct radianandygol {
        static constexpr double PI = 3.14;

        static double toDegrees(double rad) {
            if (rad <= 0) {
                throw std::invalid_argument("Угол должен быть положительным");
            }
            return (rad * 180) / PI;
        }

        static double toRadians(double deg) {
            if (deg <= 0) {
                throw std::invalid_argument("Угол должен быть положительным");
            }
            return (deg * PI) / 180;
        }

        static double toYgol(double y, double x) {
            if ((y <= 0) || (x <= 0)) {
                throw std::invalid_argument("Угол должен быть положительным");
            }
            return 180 - (x + y);
        }
    };
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(RadianAndYgolTests)
    {
    public:
        // ====================
        // Тесты для toDegrees
        // ====================

        TEST_METHOD(TestToDegrees_ValidRadians_ReturnsCorrectDegrees)
        {
            // Arrange
            double radians = 3.14; // π радиан

            // Act
            double result = OriginalCodeStub::radianandygol::toDegrees(radians);

            // Assert
            double expected = 180.0; // π радиан = 180°
            Assert::AreEqual(expected, result, 0.01);
        }

        TEST_METHOD(TestToDegrees_HalfPiRadians_Returns90Degrees)
        {
            // Arrange
            double radians = 3.14 / 2;

            // Act
            double result = OriginalCodeStub::radianandygol::toDegrees(radians);

            // Assert
            Assert::AreEqual(90.0, result, 0.01);
        }
        TEST_METHOD(TestToDegrees_VeryLargeNegativeValue_ThrowsException)
        {
            // Arrange - очень большое отрицательное значение
            auto func = []() { OriginalCodeStub::radianandygol::toDegrees(-999999.999); };

            // Act & Assert - должен выбросить исключение
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(TestToRadians_AngleExactlyZero_ThrowsException)
        {
            // Arrange - угол ровно ноль
            auto func = []() { OriginalCodeStub::radianandygol::toRadians(0.0); };

            // Act & Assert - должен выбросить исключение (хотя 0 технически допустим)
            Assert::ExpectException<std::invalid_argument>(func);
        }
    };
}