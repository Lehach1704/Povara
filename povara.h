#ifndef PovaraH
#define PovaraH
#include <string>

using namespace std;

class ActionOfCooker
{
protected:
     int Skill;
     int Stazh;
     int Age;
     string Sex;
     string Post;
public:
     virtual void CookOff() const = 0; // не готовка
     virtual void CookON() const = 0; // готовка
     virtual void Dis() const = 0; // увольнение
     virtual void VacON() const = 0;
     virtual void VacOff() const = 0; // отправка в отпуск
};

class Mouse: public ActionOfCooker
{
private:
    bool VacSleep;
    bool CookPasta;
    int Skill = 100;
    int Stazh = 28;
    int Age = 46;
    string Sex = "Man";
    string Post = "Chef";
public:
    Mouse();
    void CookON();
    void CookOff(); // готовит пасту
    void Dism(); // таракан
    void VacON();
    void VacOff(); // отправка в отпуск на отсыпание


};

class Cat: public ActionOfCooker
{
private:
    bool VacKan;
    bool CookSushi;
    int Skill = 80;
    int Stazh = 20;
    int Age = 40;
    string Sex = "Man";
    string Post = "Assistant Chef";
public:
    Cat();
    void CookON();
    void CookOff(); // готовит суши
    void Dism(); // курение
    void VacON();
    void VacOff(); // отправка в отпуск на Канары
};

class Robot: public ActionOfCooker
{
private:
    bool VacFam;
    bool CookDesert;
    int Skill = 50;
    int Stazh = 15;
    int Age = 38;
    string Sex = "Man";
    string Post = "Confectioner";
public:
    Robot();
    void CookON();
    void CookOff(); // готовит карамель
    void Dis(); // взломал базу Пентагона
    void VacON();
    void VacOff(); // отправка на отпуск к семье
};

class WheelchairUser: public ActionOfCooker
{
private:
    bool VacKuba;
    bool CookCotlet;
    int Skill = 30;
    int Stazh = 5;
    int Age = 30;
    string Sex = "Woman";
    string Post = "Kitchen boy";
public:
    WheelchairUser();
    void CookON();
    void CookOff(); // готовит котлету
    void Dis(); // спалил кухню
    void VacON();
    void VacOff(); // отправка на Кубу
};

#endif // PovaraH
