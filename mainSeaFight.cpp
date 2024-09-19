#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <ctime>
#include <cstdlib>

#include "headsSeaFight.h"

int main()
{
    int TAB_BOT{}, LINE_BOT{};
    short menuitem1, menuitem2, menuitem3;
    //setlocale(LC_ALL, "rus");
    string a[10][10];
    string b[10][10];
    menu(menuitem1, menuitem2, menuitem3);
    game(a, b, menuitem1, menuitem2, menuitem3, TAB_BOT, LINE_BOT);
}

