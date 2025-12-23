#include <iostream>
#include <windows.h>
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

bool writeToRegistry(const string& color, const string& subject) {
    HKEY hKey;
    LSTATUS status;
    status = RegCreateKeyExA(
        HKEY_CURRENT_USER,
        "Software\\MyAppSettings",
        0,
        NULL,
        REG_OPTION_NON_VOLATILE,
        KEY_WRITE,
        NULL,
        &hKey,
        NULL
    );

    if (status != ERROR_SUCCESS) {
        return false;
    }

    status = RegSetValueExA(
        hKey,
        "FavoriteColor",
        0,
        REG_SZ,
        (const BYTE*)color.c_str(),
        color.length() + 1
    );

    if (status != ERROR_SUCCESS) {
        RegCloseKey(hKey);
        return false;
    }

    status = RegSetValueExA(
        hKey,
        "FavoriteSubject",
        0,
        REG_SZ,
        (const BYTE*)subject.c_str(),
        subject.length() + 1
    );

    RegCloseKey(hKey);
    return (status == ERROR_SUCCESS);
}

bool readFromRegistry(string& color, string& subject) {
    HKEY hKey;
    LSTATUS status;
    char buffer[256];
    DWORD bufferSize = sizeof(buffer);

    status = RegOpenKeyExA(
        HKEY_CURRENT_USER,
        "Software\\MyAppSettings",
        0,
        KEY_READ,
        &hKey
    );

    if (status != ERROR_SUCCESS) {
        return false;
    }

    bufferSize = sizeof(buffer);
    status = RegQueryValueExA(
        hKey,
        "FavoriteColor",
        NULL,
        NULL,
        (LPBYTE)buffer,
        &bufferSize
    );

    if (status == ERROR_SUCCESS) {
        color = buffer;
    }
    else {
        RegCloseKey(hKey);
        return false;
    }

    bufferSize = sizeof(buffer);
    status = RegQueryValueExA(
        hKey,
        "FavoriteSubject",
        NULL,
        NULL,
        (LPBYTE)buffer,
        &bufferSize
    );

    if (status == ERROR_SUCCESS) {
        subject = buffer;
    }
    else {
        RegCloseKey(hKey);
        return false;
    }

    RegCloseKey(hKey);
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");
    string color;
    string subject;

    if (readFromRegistry(color, subject)) {
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

            if (writeToRegistry(color, subject)) {
                cout << "Настройки обновлены в реестре!" << endl;
            }
            else {
                cout << "Ошибка при сохранении в реестр!" << endl;
            }
        }
    }
    else {
        cout << "Настройки не найдены в реестре." << endl;
        cout << "Введите любимый цвет (red, blue, green, yellow, white): ";
        cin >> color;
        cout << "Введите любимый предмет: ";
        cin >> subject;

        if (writeToRegistry(color, subject)) {
            cout << "Настройки сохранены в реестр!" << endl;
        }
        else {
            cout << "Ошибка при сохранении в реестр!" << endl;
        }
    }

    return 0;
}