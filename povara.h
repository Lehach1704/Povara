#ifndef PovaraH
#define PovaraH
#include <string>
#include <list>

using namespace std;

#include"Patterns.h"

enum class Cooker: int // перечисление поваров
{
    Mouse,
    Cat,
    Robot,
    WheelchairUser
};

class ActionOfCooker
{
protected:
     bool Cooking;
     int Skill;
     int Stazh;
     int Age;
     string Sex;
     string Post;
public:
     virtual void CookOff() = 0; // не готовка
     virtual void CookON() = 0; // готовка
     virtual void Dism() = 0; // увольнение
     virtual void VacON() = 0; // отправка в отпуск
     virtual void VacOff() = 0; // вернуть из отпуска
     virtual Cooker GetCooker() const = 0; // определение повара
};

typedef ActionOfCooker * CookerPtr;

class Mouse: public ActionOfCooker
{
private:
    bool VacSleep;
    bool Cooking;
    int Skill;
    int Stazh;
    int Age;
    string Sex;
    string Post;
public:
    Mouse();
    virtual ~Mouse() {};
    void CookON() {wcout << L"Ушел готовить пасту" << endl; Cooking = true;} // готовит пасту
    void CookOff() {}; // не готовит пасту
    void Dism() {wcout << L"Нашли таракана. Увольняют..." << endl; Skill = 0;} // таракан
    void VacON() {wcout << L"Ушел в отсып" << endl; Skill -=20; VacSleep = true;} // отправка в отпуск на отсыпание
    void VacOff() {wcout << L"Выспался и пришел на работу!" << endl; VacSleep = false;} // возврат из отпуска
    Cooker GetCooker() const {return Cooker::Mouse;} // определение типа повара
};

class Cat: public ActionOfCooker
{
private:
    bool VacKan;
    bool Cooking;
    int Skill;
    int Stazh;
    int Age;
    string Sex;
    string Post;
public:
    Cat();
    virtual ~Cat() {};
    void CookON() {wcout << L"Ушел готовить суши" << endl; Cooking = true;} // готовит суши
    void CookOff() {}; // не готовит суши
    void Dism() {wcout << L"Застали за курением. Увольняют..." << endl; Skill = 0;} // курение
    void VacON() {wcout << L"Улетел на Канары!" << endl; Skill -=20; VacKan = true;} // отправка в отпуск на Канары
    void VacOff() {wcout << L"Вернулся с Канар..." << endl; VacKan = false;} // возврат из отпуска
    Cooker GetCooker() const {return Cooker::Cat;}
};

class Robot: public ActionOfCooker
{
private:
    bool VacFam;
    bool Cooking;
    int Skill;
    int Stazh;
    int Age;
    string Sex;
    string Post;
public:
    Robot();
    virtual ~Robot() {};
    void CookON() {wcout << L"Ушел готовить десерт" << endl; Cooking = true;} // готовит карамель
    void CookOff() {}; // не готовит карамель
    void Dism() {wcout << L"Застали за взломом пентагона. Увольняют..." << endl; Skill = 0;} // взломал базу Пентагона
    void VacON() {wcout << L"На отпуск к семье!" << endl; Skill -=20; VacFam = true;} // отправка на отпуск к семье
    void VacOff() {wcout << L"Вернулся из отпуска!" << endl; VacFam = false;} // возврат из отпуска
    Cooker GetCooker() const {return Cooker::Robot;}
};

class WheelchairUser: public ActionOfCooker
{
private:
    bool VacKuba;
    bool Cooking;
    int Skill;
    int Stazh;
    int Age;
    string Sex;
    string Post;
public:
    WheelchairUser();
    virtual ~WheelchairUser() {};
    void CookON() {wcout << L"Ушла готовить котлету" << endl; Cooking = true;} // готовит котлету
    void CookOff() {}; // не готовит котлету
    void Dism() {wcout << L"Спалила кухню. Увольняют..." << endl; Skill = 0;} // спалил кухню
    void VacON() {wcout << L"На Кубу!" << endl; Skill -=20; VacKuba = true;} // отправка на Кубу
    void VacOff() {wcout << L"Вернулась из отпуска..." << endl; VacKuba = false;} // возврат из отпуска
    Cooker GetCooker() const {return Cooker::WheelchairUser;} //тип повара: колясочник
};

class FirstContIterator : public Iterator<CookerPtr> // итератор для первого контейнера
{
private:
    const CookerPtr *CookerBox;
    int Position;
    int Count;

public:
    FirstContIterator(const CookerPtr *cookerBox, int count)
    {
        CookerBox = cookerBox;
        Count = count;
        Position = 0;
    }

    void First() { Position = 0; }
    void Next() { Position++; }
    bool IsDone() const { return Position >= Count; }
    CookerPtr CurrentItem() const { return CookerBox[Position]; }
};

class CookerContainer
{
private:
    CookerPtr *CookerBox;
    int CookerCount;
    int MaxSize;
public:
    CookerContainer(int maxSize);
    virtual ~CookerContainer();
    void AddCooker (CookerPtr newCooker);
    int GetCount() const {return CookerCount;}
    CookerPtr GetByIndex(int index) const {return CookerBox[index];}

    Iterator<CookerPtr> *GetIterator() // использование итератора
    {
        return new FirstContIterator(CookerBox, CookerCount);
    }

};

class SecondContIterator : public Iterator<CookerPtr> // итератор для второго контейнера
{
private:
    const list<CookerPtr> *CookerBox;
    list<CookerPtr>::const_iterator iter; //тот итератор, который не может изменить содержимое списка

public:
    SecondContIterator(const list<CookerPtr> *cookerBox)
    {
        CookerBox = cookerBox;
        iter = CookerBox->begin();
    }

    void First() { iter = CookerBox->begin(); }
    void Next() { iter++; }
    bool IsDone() const { iter == CookerBox->end(); }
    CookerPtr CurrentItem() const {  return *iter; }
};

class CookerContainerV2 // контейнер номер 2
{
private:
    list<CookerPtr> CookerBox;

public:
    void AddCooker(CookerPtr newCooker) {CookerBox.push_back(newCooker);}
    int GetCount() const {return CookerBox.size();}
    Iterator<CookerPtr> *GetIterator()
    {
        return new SecondContIterator(&CookerBox);
    }
};

#endif // PovaraH
