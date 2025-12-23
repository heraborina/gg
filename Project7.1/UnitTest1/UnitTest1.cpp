#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include <cmath>
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
        TEST_METHOD(TestToDegrees_ValidRadians_ReturnsCorrectDegrees)
        {
            double radians = 3.14;
            double result = OriginalCodeStub::radianandygol::toDegrees(radians);
            double expected = 180.0;
            Assert::AreEqual(expected, result, 0.01);
        }
        TEST_METHOD(TestToDegrees_HalfPiRadians_Returns90Degrees)
        {
            double radians = 3.14 / 2;
            double result = OriginalCodeStub::radianandygol::toDegrees(radians);
            Assert::AreEqual(90.0, result, 0.01);
        }
        TEST_METHOD(TestToDegrees_VeryLargeNegativeValue_ThrowsException)
        {
            auto func = []() { OriginalCodeStub::radianandygol::toDegrees(-999999.999); };
            Assert::ExpectException<std::invalid_argument>(func);
        }
        TEST_METHOD(TestToRadians_AngleExactlyZero_ThrowsException)
        {
            auto func = []() { OriginalCodeStub::radianandygol::toRadians(0.0); };

            Assert::ExpectException<std::invalid_argument>(func);
        }
    };
}
