#include <iostream>
#include "povara.h"

using namespace std;

Mouse::Mouse()
{
    bool VacSleep = false;
    bool CookPasta = false;
    int Skill = 100;
    int Stazh = 28;
    int Age = 46;
    string Sex = "Man";
    string Post = "Chef";
}

Cat::Cat()
{
    bool VacKan = false;
    bool CookSushi = false;
    int Skill = 80;
    int Stazh = 20;
    int Age = 40;
    string Sex = "Man";
    string Post = "Assistant Chef";
}

Robot::Robot()
{
    bool VacFam = false;
    bool CookDesert = false;
    int Skill = 50;
    int Stazh = 15;
    int Age = 38;
    string Sex = "Man";
    string Post = "Confectioner";
}

WheelchairUser::WheelchairUser()
{
    bool VacKuba = false;
    bool CookCotlet = false;
    int Skill = 30;
    int Stazh = 5;
    int Age = 30;
    string Sex = "Woman";
    string Post = "Kitchen boy";
}

/*void Mouse::CookON()
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
}*/

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
    wcout << L"Улетел на Канары!" << endl;
    Skill -=20;
    VacKan = true;
}

void Cat::VacOff()
{
    wcout << L"Вернулся с Канар..." << endl;
    VacKan = false;
}

void Robot::CookON()
{
    wcout << L"Ушел готовить десерт" << endl;
    CookDesert = true;
}

void Robot::CookOff()
{
    wcout << L"Приготовил десерт" << endl;
    CookDesert = false;
    if (Skill >= 100)
    {
        Skill = 100;
    }
    else
    {
        Skill +=10;
    }
}

void Robot::Dism()
{
    wcout << L"Застали за взломом пентагона. Увольняют..." << endl;
    Skill = 0;
}

void Robot::VacON()
{
    wcout << L"На отпуск к семье!" << endl;
    Skill -=20;
    VacFam = true;
}

void Robot::VacOff()
{
    wcout << L"Вернулся из отпуска!" << endl;
    VacFam = false;
}

/*void WheelchairUser::CookON()
{
    wcout << L"Ушла готовить котлету" << endl;
    CookCotlet = true;
}

void WheelchairUser::CookOff()
{
    wcout << L"Приготовила котлету" << endl;
    CookCotlet = false;
    if (Skill >= 100)
    {
        Skill = 100;
    }
    else
    {
        Skill +=10;
    }
}

void WheelchairUser::Dism()
{
    wcout << L"Спалила кухню. Увольняют..." << endl;
    Skill = 0;
}

void WheelchairUser::VacON()
{
    wcout << L"На Кубу!" << endl;
    Skill -=20;
    VacKuba = true;
}

void WheelchairUser::VacOff()
{
    wcout << L"Вернулась из отпуска..." << endl;
    VacKuba = false;
}*/
