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
    int Skill;
    int Stazh;
    int Age;
    string Sex;
    string Post;
public:
    Mouse();
    virtual ~Mouse() {};
    void CookON(); // готовит пасту
    void CookOff(); // не готовит пасту
    void Dism(); // таракан
    void VacON(); // отправка в отпуск на отсыпание
    void VacOff(); // возврат из отпуска


};

class Cat: public ActionOfCooker
{
private:
    bool VacKan;
    bool CookSushi;
    int Skill;
    int Stazh;
    int Age;
    string Sex;
    string Post;
public:
    Cat();
    virtual ~Cat() {};
    void CookON(); // не готовит суши
    void CookOff(); // не готовит суши
    void Dism(); // курение
    void VacON(); // отправка в отпуск на Канары
    void VacOff(); // возврат из отпуска
};

class Robot: public ActionOfCooker
{
private:
    bool VacFam;
    bool CookDesert;
    int Skill;
    int Stazh;
    int Age;
    string Sex;
    string Post;
public:
    Robot();
    virtual ~Robot() {};
    void CookON(); // готовит карамель
    void CookOff(); // не готовит карамель
    void Dism(); // взломал базу Пентагона
    void VacON(); // отправка на отпуск к семье
    void VacOff(); // возврат из отпуска
};

class WheelchairUser: public ActionOfCooker
{
private:
    bool VacKuba;
    bool CookCotlet;
    int Skill;
    int Stazh;
    int Age;
    string Sex;
    string Post;
public:
    WheelchairUser();
    virtual ~WheelchairUser() {};
    void CookON(); // готовит котлету
    void CookOff(); // не готовит котлету
    void Dism(); // спалил кухню
    void VacON(); // отправка на Кубу
    void VacOff(); // возврат из отпуска
};

#endif // PovaraH
