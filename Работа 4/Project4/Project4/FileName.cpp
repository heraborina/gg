#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void setConsoleColor(const string& color) {
    if (color == "red") {
        system("color 4F");
    }
    else if (color == "blue") {
        system("color 1F");
    }
    else if (color == "green") {
        system("color 2F");
    }
    else if (color == "yellow") {
        system("color 6F");
    }
    else if (color == "white") {
        system("color 7F");
    }
    else {
        system("color 0F");
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    string color;
    string subject;

    ifstream fin("settings.txt");

    if (fin.is_open()) {
        fin >> color >> subject;
        fin.close();

        setConsoleColor(color);

        cout << "Сохраненные настройки:" << endl;
        cout << "Любимый цвет: " << color << endl;
        cout << "Любимый предмет: " << subject << endl;

        char choice;
        cout << "\nХотите изменить настройки? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            cout << "Введите новый любимый цвет (red, blue, green, yellow, white): ";
            cin >> color;
            cout << "Введите новый любимый предмет: ";
            cin >> subject;

            ofstream fout("settings.txt");
            fout << color << " " << subject;
            fout.close();

            cout << "Настройки обновлены!" << endl;
        }
    }
    else {
        cout << "Введите любимый цвет (red, blue, green, yellow, white): ";
        cin >> color;
        cout << "Введите любимый предмет: ";
        cin >> subject;

        ofstream fout("settings.txt");
        fout << color << " " << subject;
        fout.close();

        cout << "Настройки сохранены!" << endl;
    }

    return 0;
}
