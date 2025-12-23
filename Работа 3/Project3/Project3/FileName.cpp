#include<iostream>
#include<cmath>
using namespace std;
double skorostdvigeniya(double s, double t);
/// <summary>
/// Вычисляет скорость
/// </summary>
/// <param name="s"> Расстояние </param>
/// <param name="t"> Время </param>
/// <param name="v"> Скорость </param>
/// <returns> Скорость </returns>
/// <remarks> Если скорости не существует -1 </remarks>
double skorostdvigeniya(double s, double t)
{
	if (s <= 0 || t <= 0 )
	{
		return -1; // скорости нет
	}
	double v = (s / t); // скорость
	return v;
}
int main()
{
	// сдесь будет видна подсказка с коментарием
	setlocale(LC_ALL, "Russian");
	double area = skorostdvigeniya(10, 8);
	if (area < 0)
		cout << "Нет скорости" << endl;
	else
		cout << "Скорость:" << area << endl;
	return 0;
}

