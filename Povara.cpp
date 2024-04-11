#include <iostream>
#include "povara.h"

using namespace std;

void Mouse::CookON()
{
    wcout << L"Ушел готовить пасту" << endl;
    CookPasta = true;
}

void Mouse::CookOff()
{
    wcout << L"Приготовил пасту" << endl;
    CookPasta = false;
    if (Skill >= 100)
    {
        Skill = 100;
    }
    else
    {
        Skill +=10;
    }
}

void Mouse::Dism()
{
    wcout << L"Нашли таракана. Увольняют..." << endl;
    Skill = 0;
}

void Mouse::Vac()
{
    wcout << L"Ушел в отсып" << endl;
    Skill -=20;
}

void Mouse::CookON()
{
    wcout << L"Ушел готовить пасту" << endl;
    CookPasta = true;
}

void Mouse::CookOff()
{
    wcout << L"Приготовил пасту" << endl;
    CookPasta = false;
    if (Skill >= 100)
    {
        Skill = 100;
    }
    else
    {
        Skill +=10;
    }
}

void Mouse::Dism()
{
    wcout << L"Нашли таракана. Увольняют..." << endl;
    Skill = 0;
}

void Mouse::Vac()
{
    wcout << L"Ушел в отсып" << endl;
    Skill -=20;
}
