#pragma once
#include <iostream>
#include <string>
using namespace std;

// 0-black, 15-white
// example colors: 8-gray,9-blue,10-green,12-red,14-yellow

inline string getAnsiColor(int color) {
    switch(color) {
        case 0:  return "\033[30m"; // черный
        case 8:  return "\033[90m"; // темно-серый
        case 9:  return "\033[94m"; // синий
        case 10: return "\033[92m"; // зеленый
        case 11: return "\033[96m"; // голубой/циан
        case 12: return "\033[91m"; // красный
        case 13: return "\033[95m"; // пурпурный
        case 14: return "\033[93m"; // желтый
        case 15: return "\033[97m"; // белый
        default: return "\033[0m";  // сброс (обычный цвет)
    }
}

class element {
    char sign;
    int color;
public:
    element(int color = 0, char sign ='*'): sign(sign), color(color){}
    
    friend ostream& operator<<(ostream& out, const element& e) {
    #ifdef _WIN32
        // Если компилируется под Windows, можно оставить оригинальный код
        #include <Windows.h>
        HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hconsole, e.color);
        out << e.sign;
        SetConsoleTextAttribute(hconsole, 15); // сброс на белый
        return out;
    #else
        // Кроссплатформенная версия с использованием ANSI escape-кодов
        out << getAnsiColor(e.color) << e.sign << "\033[0m";
        return out;
    #endif
    }
};