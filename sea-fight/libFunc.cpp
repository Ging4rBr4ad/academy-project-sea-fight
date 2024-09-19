#include "headsSeaFight.h"
using namespace std;
#include <iostream>
#include <Windows.h>


void menu(short& menuitem1, short& menuitem2, short& menuitem3)
{
    do {
        cout << "Выберите режим игры\n"
            "1 - игрок VS игрок\n"
            "2 - игрок VS компьютер\n";
        cin >> menuitem1;
    } while (menuitem1 > 2 || menuitem1 < 1);

    switch (menuitem1)
    {
    case 1:
        {do {
            cout << "Выберите расстановку кораблей для игрок1\n"
                "1 - Самостоятельно\n"
                "2 - автоматически\n";
            cin >> menuitem2;
        } while (menuitem2 > 2 || menuitem2 < 1);
        do
        {
            cout << "Выберите расстановку кораблей для игрок2\n"
                "1 - Самостоятельно\n"
                "2 - автоматически\n";
            cin >> menuitem3;
        } while (menuitem3 > 2 || menuitem3 < 1);
        break;}
    case 2:
        {do {
            cout << "Выберите расстановку кораблей\n"
                "1 - Самостоятельно\n"
                "2 - автоматически\n";
            cin >> menuitem2;
        } while (menuitem2 > 2 || menuitem2 < 1);
        break;}
    }
    system("cls");
}

void field(string(&a2)[10][10], string(&b2)[10][10]) {
    cout << endl;
    cout << "                                               " << "Морской бой";
    cout << endl << endl << endl;
    //создание и заполнение таблиц

        for (int w = 0; w < 1; w++)
        {
            cout << "                             ";
            for (int y = 0; y < size(a2); y++)
            {
                cout << y << " ";
                //отвечает за столбцы первой таблицы
            }
            cout << "                   ";
            for (int y = 0; y < size(a2); y++)
            {
                cout << y << " ";
                //отвечает за столбцы второй таблицы
            }
            cout << endl;
            for (int i = 0; i < size(a2); i++)
            {
                cout << "                           ";
                cout << i;
                for (int j = 0; j < size(a2); j++)
                {
                    cout << "|" << a2[i][j];

                }
                cout << "|" << "                 ";
                cout << i;
                for (int f = 0; f < size(b2); f++)
                {
                    cout << "|" << b2[i][f];
                }
                cout << "|" << endl;

            }
        }
}

void help1(short& l, short& s, string(&a2)[10][10], string(&b2)[10][10], short menuitem2, short menuitem3, short menuitem1, string(&b3)[10][10])
{
    if (menuitem2 == 1)
    {
        cout << endl;
        cout << "Игрок1 расставляет корабли" << endl;
        cout << "Выберите местоположение ваших кораблей" << endl << "Корабли выставляются по возрастанию , начиная с однопалубного и заканчивая трёхпалубным" << endl;
        cout << "Введите координаты и поставьте знаки " << endl;
        cout << "Знак" << '"' << "^" << '"' << " " << "чтобы корабль стоял носом наверх\n";
        cout << "Знак" << '"' << "<" << '"' << " " << "чтобы корабль стоял носом вправо\n";
        cout << "Знак" << '"' << ">" << '"' << " " << "чтобы корабль стоял носом влево \n";
        cout << "Знак" << '"' << "!" << '"' << " " << "чтобы корабль стоял носом вниз  \n";
        cout << "введите столбик:"; cin >> l;
        cout << "введите строку: "; cin >> s;
        int tu = 10;
        while (tu != 0) {
            tu = 0;
            if (s > 9 || l > 9)
            {
                tu = 1;
                cout << "\t\t\t\t\t\tНеверные координаты";
                Sleep(2000);
                system("cls");
                field(a2, b2);
                help1(l, s, a2, b2, menuitem2, menuitem3, menuitem1, b3);
            }
            else if (s < 0 || l < 0) {
                tu = 1;
                cout << "\t\t\t\t\t\tНеверные координаты";
                Sleep(2000);
                system("cls");
                field(a2, b2);
                help1(l, s, a2, b2, menuitem2, menuitem3, menuitem1, b3);
            }

        }
    }
    else if (menuitem2 == 2)
    {
        srand(time(NULL));
        s = rand() % 10;
        l = rand() % 10;
        int tu = 10;
        while (tu != 0)
        {
            tu = 0;
            if (s > 9 || l > 9)
            {
                tu = 1;
                cout << "\t\t\t\t\t\tНеверные координаты";
                Sleep(2000);
                system("cls");
                field2(a2, b3);
                help1(l, s, a2, b3, menuitem2, menuitem3, menuitem1, b3);
            }
            else if (s < 0 || l < 0)
            {
                tu = 1;
                cout << "\t\t\t\t\t\tНеверные координаты";
                Sleep(2000);
                system("cls");
                field(a2, b3);
                help1(l, s, a2, b3, menuitem2, menuitem3, menuitem1, b3);
            }

        }
    }
}

void help2(short& l, short& s, string(&a2)[10][10], string(&b2)[10][10], short menuitem2, short menuitem3, short menuitem1, int& TAB_BOT, int& LINE_BOT)
{
    if (menuitem3 == 1)
    {
        cout << endl;
        cout << "Игрок2 расставляет корабли" << endl;
        cout << "Выберите местоположение ваших кораблей" << endl << "Корабли выставляются по возрастанию , начиная с однопалубного и заканчивая трёхпалубным" << endl;
        cout << "Введите координаты и поставьте знаки " << endl;
        cout << "Знак" << '"' << "^" << '"' << " " << "чтобы корабль стоял носом наверх\n";
        cout << "Знак" << '"' << "<" << '"' << " " << "чтобы корабль стоял носом вправо\n";
        cout << "Знак" << '"' << ">" << '"' << " " << "чтобы корабль стоял носом влево \n";
        cout << "Знак" << '"' << "!" << '"' << " " << "чтобы корабль стоял носом вниз  \n";
        cout << "введите столбик:"; cin >> TAB_BOT;
        cout << "введите строку: "; cin >> LINE_BOT;
        int tu = 10;
        while (tu != 0) {
            tu = 0;
            if (LINE_BOT > 9 || TAB_BOT > 9)
            {
                tu = 1;
                cout << "\t\t\t\t\t\tНеверные координаты";
                Sleep(2000);
                system("cls");
                field(a2, b2);
                help2(l, s, a2, b2, menuitem2, menuitem3, menuitem1, TAB_BOT, LINE_BOT);
            }
            else if (LINE_BOT < 0 || TAB_BOT < 0) {
                tu = 1;
                cout << "\t\t\t\t\t\tНеверные координаты";
                Sleep(2000);
                system("cls");
                field(a2, b2);
                help2(l, s, a2, b2, menuitem2, menuitem3, menuitem1, TAB_BOT, LINE_BOT);
            }


        }
    }
    else if (menuitem3 == 2)
    {
        srand(time(NULL));
        LINE_BOT = rand() % 10;
        TAB_BOT = rand() % 10;
        int tu = 10;
        while (tu != 0)
        {
            tu = 0;
            if (LINE_BOT > 9 || TAB_BOT > 9)
            {
                tu = 1;
                cout << "\t\t\t\t\t\tНеверные координаты";
                Sleep(2000);
                system("cls");
                field2(a2, b2);
                help2(l, s, a2, b2, menuitem2, menuitem3, menuitem1, TAB_BOT, LINE_BOT);
            }
            else if (s < 0 || l < 0)
            {
                tu = 1;
                cout << "\t\t\t\t\t\tНеверные координаты";
                Sleep(2000);
                system("cls");
                field2(a2, b2);
                help2(l, s, a2, b2, menuitem2, menuitem3, menuitem1, TAB_BOT, LINE_BOT);
            }

        }
    }
}

void field1(string(&a2)[10][10], string(&b3)[10][10])
{
    cout << endl;
    cout << "                                               " << "Морской бой";
    cout << endl << endl << endl;
    //создание и заполнение таблиц

    for (int w = 0; w < 1; w++)
    {
        cout << "                             ";
        for (int y = 0; y < size(a2); y++)
        {
            cout << y << " ";
            //отвечает за столбцы первой таблицы
        }
        cout << "                   ";
        for (int y = 0; y < size(a2); y++)
        {
            cout << y << " ";
            //отвечает за столбцы второй таблицы
        }
        cout << endl;
        for (int i = 0; i < size(a2); i++)
        {
            cout << "                           ";
            cout << i;
            for (int j = 0; j < size(a2); j++)
            {
                cout << "|" << a2[i][j];

            }
            cout << "|" << "                 ";
            cout << i;
            for (int f = 0; f < size(b3); f++)
            {
                cout << "|" << '?';
            }
            cout << "|" << endl;

        }
    }
}

void field2(string(&a3)[10][10], string(&b2)[10][10])
{
    cout << endl;
    cout << "                                               " << "Морской бой";
    cout << endl << endl << endl;
    //создание и заполнение таблиц

    for (int w = 0; w < 1; w++)
    {
        cout << "                             ";
        for (int y = 0; y < size(a3); y++)
        {
            cout << y << " ";
            //отвечает за столбцы первой таблицы
        }
        cout << "                   ";
        for (int y = 0; y < size(a3); y++)
        {
            cout << y << " ";
            //отвечает за столбцы второй таблицы
        }
        cout << endl;
        for (int i = 0; i < size(a3); i++)
        {
            cout << "                           ";
            cout << i;
            for (int j = 0; j < size(a3); j++)
            {
                cout << "|" << '?';

            }
            cout << "|" << "                 ";
            cout << i;
            for (int f = 0; f < size(b2); f++)
            {
                cout << "|" << b2[i][f];
            }
            cout << "|" << endl;

        }
    }
}

int game(string a[10][10], string b[10][10], short menuitem2, short menuitem3, short menuitem1, int& TAB_BOT, int& LINE_BOT)
{
    char t;
    short s, l;
    string a2[10][10];
    string b2[10][10];
    string a3[10][10];
    string b3[10][10];
    // заполнение массивов

    for (char i = 0; i < size(a2); i++) {
        for (char j = 0; j < size(a2); j++) {
            a2[i][j] = " ";
            b2[i][j] = " ";
            a[i][j] = "0";
            b[i][j] = "0";
            a3[i][j] = " ";
            b3[i][j] = " ";
        }

    }

    field(a2, b2);
    help1(l, s, a2, b2, menuitem2, menuitem3, menuitem1, b3);

    //расстановка корабля
    a[s][l] = "1";
    a2[s][l] = '^';

    system("cls");

    field(a2, b2);
    help1(l, s, a2, b2, menuitem2, menuitem3, menuitem1, b3);
    if (menuitem2 == 1)
    {
        cout << "введите направление::"; cin >> t;
    }
    else if (menuitem2 == 2)
    {
        t = std::rand() % 4 + 1;
        switch (t)
        {
        case 1: t = 94; break;
        case 2: t = 62; break;
        case 3: t = 60; break;
        case 4: t = 33; break;
        }
    }
    //расстановка корабля
    switch (t) {
    case '^':
        if (s - 1 >= 0) {
            a[s][l] = "1";
            a2[s][l] = "O";
            a[s - 1][l] = "1";
            a2[s - 1][l] = "^";
        }
        break;
    case '>':
        if (l + 1 <= 9) {
            a[s][l] = "1";
            a2[s][l] = "O";
            a[s][l + 1] = "1";
            a2[s][l + 1] = ">";
        }
        break;
    case '<':
        if (l - 1 >= 0) {
            a[s][l] = "1";
            a2[s][l] = "O";
            a[s][l - 1] = "1";
            a2[s][l - 1] = "<";
        }
        break;
    case '!':
        if (s + 1 <= 9) {
            a[s][l] = "1";
            a2[s][l] = "O";
            a[s + 1][l] = "1";
            a2[s + 1][l] = "o";
        }
    }

    system("cls");
    field(a2, b2);
    help1(l, s, a2, b2, menuitem2, menuitem3, menuitem1, b3);
    if (menuitem2 == 1)
    {
        cout << "введите направление::"; cin >> t;
    }
    else if (menuitem2 == 2)
    {
        t = std::rand() % 4 + 1;
        switch (t)
        {
        case 1: t = 94; break;
        case 2: t = 62; break;
        case 3: t = 60; break;
        case 4: t = 33; break;
        }
    }

    switch (t) {
    case '^':
        if (s - 2 >= 0) {
            a[s][l] = "1";
            a2[s][l] = "O";
            a[s - 1][l] = "1";
            a2[s - 1][l] = "O";
            a[s - 2][l] = "1";
            a2[s - 2][l] = "^";
        }
        break;
    case '>':
        if (l + 2 <= 9) {
            a[s][l] = "1";
            a2[s][l] = "O";
            a[s][l + 1] = "1";
            a2[s][l + 1] = "O";
            a[s][l + 2] = "1";
            a2[s][l + 2] = ">";
        }
        break;
    case '<':
        if (l - 2 >= 0) {
            a[s][l] = "1";
            a2[s][l] = "O";
            a[s][l - 1] = "1";
            a2[s][l - 1] = "O";
            a[s][l - 2] = "1";
            a2[s][l - 2] = "<";
        }
        break;
    case '!':
        if (s + 2 <= 9) {
            a[s][l] = "1";
            a2[s][l] = "O";
            a[s + 1][l] = "1";
            a2[s + 1][l] = "O";
            a[s + 2][l] = "1";
            a2[s + 2][l] = "o";
        }

    }

    system("cls");
    // корабли второго игрока
    if (menuitem1 == 1)
    {
        field2(a3, b2);
        help2(l, s, a2, b2, menuitem2, menuitem3, menuitem1, TAB_BOT, LINE_BOT);

        b[TAB_BOT][LINE_BOT] = "1";
        b2[TAB_BOT][LINE_BOT] = '^';

        system("cls");
        field2(a3, b2);
        help2(l, s, a2, b2, menuitem2, menuitem3, menuitem1, TAB_BOT, LINE_BOT);

        if (menuitem3 == 1)
        {
            cout << "введите направление::"; cin >> t;
        }
        else if (menuitem3 == 2)
        {
            t = std::rand() % 4 + 1;
            switch (t)
            {
            case 1: t = 94; break;
            case 2: t = 62; break;
            case 3: t = 60; break;
            case 4: t = 33; break;
            }
        }

        switch (t) {
        case '^':
            if (LINE_BOT - 2 >= 0) {
                b[TAB_BOT][LINE_BOT] = "1";
                b2[TAB_BOT][LINE_BOT] = "O";
                b[TAB_BOT - 1][LINE_BOT] = "1";
                b2[TAB_BOT - 1][LINE_BOT] = "O";
                b[TAB_BOT - 2][LINE_BOT] = "1";
                b2[TAB_BOT - 2][LINE_BOT] = "^";
            }
            break;
        case '>':
            if (TAB_BOT + 2 <= 9) {
                b[TAB_BOT][LINE_BOT] = "1";
                b2[TAB_BOT][LINE_BOT] = "O";
                b[TAB_BOT][LINE_BOT + 1] = "1";
                b2[TAB_BOT][LINE_BOT + 1] = "O";
                b[TAB_BOT][LINE_BOT + 2] = "1";
                b2[TAB_BOT][LINE_BOT + 2] = ">";
            }
            break;
        case '<':
            if (TAB_BOT - 2 >= 0) {
                b[TAB_BOT][LINE_BOT] = "1";
                b2[TAB_BOT][LINE_BOT] = "O";
                b[TAB_BOT][LINE_BOT - 1] = "1";
                b2[TAB_BOT][LINE_BOT - 1] = "O";
                b[TAB_BOT][LINE_BOT - 2] = "1";
                b2[TAB_BOT][LINE_BOT - 2] = "<";
            }
            break;
        case '!':
            if (LINE_BOT + 2 <= 9) {
                b[TAB_BOT][LINE_BOT] = "1";
                b2[TAB_BOT][LINE_BOT] = "O";
                b[TAB_BOT + 1][LINE_BOT] = "1";
                b2[TAB_BOT + 1][LINE_BOT] = "O";
                b[TAB_BOT + 2][LINE_BOT] = "1";
                b2[TAB_BOT + 2][LINE_BOT] = "o";
            }

        }
        system("cls");
        field2(a3, b2);
        help2(l, s, a2, b2, menuitem2, menuitem3, menuitem1, TAB_BOT, LINE_BOT);
        if (menuitem3 == 1)
        {
            cout << "введите направление::"; cin >> t;
        }
        else if (menuitem3 == 1)
        {
            t = std::rand() % 4 + 1;
            switch (t)
            {
            case 1: t = 94; break;
            case 2: t = 62; break;
            case 3: t = 60; break;
            case 4: t = 33; break;
            }
        }

        switch (t) {
        case '^':
            if (LINE_BOT - 2 >= 0) {
                b[TAB_BOT][LINE_BOT] = "1";
                b2[TAB_BOT][LINE_BOT] = "O";
                b[TAB_BOT - 1][LINE_BOT] = "1";
                b2[TAB_BOT - 1][LINE_BOT] = "O";
                b[TAB_BOT - 2][LINE_BOT] = "1";
                b2[TAB_BOT - 2][LINE_BOT] = "^";
            }
            break;
        case '>':
            if (TAB_BOT + 2 <= 9) {
                b[TAB_BOT][LINE_BOT] = "1";
                b2[TAB_BOT][LINE_BOT] = "O";
                b[TAB_BOT][LINE_BOT + 1] = "1";
                b2[TAB_BOT][LINE_BOT + 1] = "O";
                b[TAB_BOT][LINE_BOT + 2] = "1";
                b2[TAB_BOT][LINE_BOT + 2] = ">";
            }
            break;
        case '<':
            if (TAB_BOT - 2 >= 0) {
                b[TAB_BOT][LINE_BOT] = "1";
                b2[TAB_BOT][LINE_BOT] = "O";
                b[TAB_BOT][LINE_BOT - 1] = "1";
                b2[TAB_BOT][LINE_BOT - 1] = "O";
                b[TAB_BOT][LINE_BOT - 2] = "1";
                b2[TAB_BOT][LINE_BOT - 2] = "<";
            }
            break;
        case '!':
            if (LINE_BOT + 2 <= 9) {
                b[TAB_BOT][LINE_BOT] = "1";
                b2[TAB_BOT][LINE_BOT] = "O";
                b[TAB_BOT + 1][LINE_BOT] = "1";
                b2[TAB_BOT + 1][LINE_BOT] = "O";
                b[TAB_BOT + 2][LINE_BOT] = "1";
                b2[TAB_BOT + 2][LINE_BOT] = "o";
            }

        }
    }

    system("cls");

    field(a2, b2);

    //бот расставляет корабли
    srand(time(NULL));
    if (menuitem1 == 2)
    {
        TAB_BOT = rand() % 10;
        LINE_BOT = rand() % 10;
        b[TAB_BOT][LINE_BOT] = "1";

        Sleep(200);
        l = 0;
        while (l != 1)
        {
            TAB_BOT = rand() % 10;
            LINE_BOT = rand() % 10;

            if (TAB_BOT + 1 <= 9 && TAB_BOT + 2 <= 9)
            {
                if (b[TAB_BOT][LINE_BOT] != "1" && b[TAB_BOT + 1][LINE_BOT] != "1")
                {
                    if (b[TAB_BOT + 2][LINE_BOT] != "1")
                    b[TAB_BOT][LINE_BOT] = "1";
                    b[TAB_BOT + 1][LINE_BOT] = "1";
                    b[TAB_BOT][LINE_BOT] = "1";
                    b[TAB_BOT + 2][LINE_BOT] = "1";
                    l++;

                }
            }
        }
    }
    //бот закончил



    short bot_heat = 0, person_heat = 0;

    system("cls");
    if (menuitem1 == 2)
    {
        while (bot_heat < 6 && person_heat < 6) {

            short repeat{};
            while (repeat != 1)
            {
                field1(a2, b3);
                cout << endl;
                cout << "Ваш ход , вбейте координаты\n";
                cout << "Введите номер столбца:"; cin >> l;
                cout << "Введите номер строки: "; cin >> s;

                if (b[s][l] == "1")
                {
                    system("cls");
                    field(a2, b2);
                    person_heat++;
                    b2[s][l] = "*";
                    cout << endl;
                    cout << "вы попали\n";
                    Sleep(400);
                    system("cls");
                }
                else
                {
                    b2[s][l] = "x";
                    cout << "вы промахнулись";
                    repeat++;
                }
            }
            repeat = 0;
            system("cls");
            while (repeat != 1)
            {
                field2(a3, b2);
                cout << endl;
                cout << "ход противника";
                Sleep(300);
                l = 1;
                while (l != 0)
                {
                    TAB_BOT = rand() % 10;
                    LINE_BOT = rand() % 10;

                    if (a2[TAB_BOT][LINE_BOT] != "x" && a2[TAB_BOT][LINE_BOT] != "*")
                    {
                        system("cls");
                        field(a2, b2);
                        if (a[TAB_BOT][LINE_BOT] == "1")
                        {
                            bot_heat++;
                            a2[TAB_BOT][LINE_BOT] = "*";
                            cout << "Бот попал";
                            Sleep(400);
                            system("cls");
                        }
                        else
                        {
                            a2[TAB_BOT][LINE_BOT] = "x";
                            l = 0;
                            cout << "Бот промахнулся";
                            Sleep(400);
                            system("cls");
                            repeat++;
                        }
                    }
                }
                repeat = 0;
            }
            system("cls");
        }
    }
    else if (menuitem1 == 1)
    {
        short start{};
        while (bot_heat < 6 && person_heat < 6) {
            short repeat{};
            while (repeat != 1)
            {
                field1(a2, b3);
                cout << endl;
                cout << "Игрок1 ходит, вбейте координаты\n";
                cout << "Введите номер столбца:"; cin >> l;
                cout << "Введите номер строки: "; cin >> s;

                if (b[s][l] == "1")
                {
                    system("cls");
                    field1(a2, b3);
                    person_heat++;
                    b2[s][l] = "*";
                    b3[s][l] = "*";
                    cout << endl;
                    cout << "вы попали\n";
                    Sleep(400);
                    system("cls");
                }
                else
                {
                    b2[s][l] = "x";
                    b3[s][l] = "x";
                    cout << "вы промахнулись\n";
                    repeat++;
                }
            }
            repeat = 0;
            cout << "ход Игрок2\n";
            cout << "Приступать?(введите любое число, кроме нуля): ";
            cin >> start;
            
            while (repeat != 1)
            {
                system("cls");
                field2(a2, b2);
                cout << endl;
                cout << "Игрок2 ходит, вбейте координаты\n";
                cout << "Введите номер столбца:"; cin >> TAB_BOT;
                cout << "Введите номер строки: "; cin >> LINE_BOT;
                if (a[TAB_BOT][LINE_BOT] == "1")
                {
                    system("cls");
                    field2(a3, b2);
                    bot_heat++;
                    a2[TAB_BOT][LINE_BOT] = "*";
                    a3[TAB_BOT][LINE_BOT] = "*";
                    cout << endl;
                    cout << "вы попали\n";
                    Sleep(400);
                    system("cls");
                }
                else
                {
                    a2[TAB_BOT][LINE_BOT] = "x";
                    a3[TAB_BOT][LINE_BOT] = "x";
                    cout << "вы промахнулись\n";
                    repeat++;
                }
            }
               repeat = 0;
            cout << "ход Игрок1\n";
            cout << "Приступать?(введите любое число, кроме нуля): ";
            cin >> start;
            system("cls");
        }
    }

    if (menuitem1 == 2)
    {
        if (bot_heat > person_heat) {
            cout << "\t\t\t\t\t\tБот победил!";
        }
        else {
            cout << "\t\t\t\t\t\tВ победили!";
        }
    }
    else
    {
        if (bot_heat > person_heat) {
            cout << "\t\t\t\t\t\tИгрок2 победил!";
        }
        else {
            cout << "\t\t\t\t\t\tИгрок1 победили!";
        }
    }
    return 0;
}
