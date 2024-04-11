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

void Mouse::VacON()
{
    wcout << L"Ушел в отсып" << endl;
    Skill -=20;
    VacSleep = true;
}

void Mouse::VacOff()
{
    wcout << L"Выспался и пришел на работу!" << endl;
    VacSleep = false;
}

void Cat::CookON()
{
    wcout << L"Ушел готовить суши" << endl;
    CookSushi = true;
}

void Cat::CookOff()
{
    wcout << L"Приготовил суши" << endl;
    CookSushi = false;
    if (Skill >= 100)
    {
        Skill = 100;
    }
    else
    {
        Skill +=10;
    }
}

void Cat::Dism()
{
    wcout << L"Застали за курением. Увольняют..." << endl;
    Skill = 0;
}

void Cat::VacON()
{
    wcout << L"Ушел в отсып" << endl;
    Skill -=20;
    VacKan = true;
}

void Cat::VacOff()
{
    wcout << L"Выспался и пришел на работу!" << endl;
    VacKan = false;
}
