double skorostdvigeniya(double s, double t);
double skorostdvigeniya(double s, double t)
{
	if (s <= 0 || t <= 0) // +1 к ?2
	{
		return -1; // +1 к ?1
	}
	double v = (s / t); // +1 к ?1
	return v; //+1 к ?1
}
int main()
{
	setlocale(LC_ALL, "Russian");
	double area = skorostdvigeniya(10, 8); //+1 к ?1
	if (area < 0) //+1 к ?2
		cout << "Нет скорости" << endl; //+1 к ?1
	else (area > 0) //+1 к ?2
		cout << "Скорость:" << area << endl; //+1 к ?1
	return 0;
}