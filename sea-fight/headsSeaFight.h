#pragma once

#include <string>
using namespace std;

void menu(short& menuitem1, short& menuitem2, short& menuitem3);
void field(string(&a2)[10][10], string(&b2)[10][10]);
void help1(short& l, short& s, string(&a2)[10][10], string(&b2)[10][10], short menuitem2, short menuitem3, short menuitem1, string(&b3)[10][10]);
void help2(short& l, short& s, string(&a2)[10][10], string(&b2)[10][10], short menuitem2, short menuitem3, short menuitem1, int& TAB_BOT, int& LINE_BOT);
int game(string a[10][10], string b[10][10], short menuitem1, short menuitem2, short menuitem3, int& TAB_BOT, int& LINE_BOT);
void field1(string(&a2)[10][10], string(&b3)[10][10]);
void field2(string(&a3)[10][10], string(&b2)[10][10]);
