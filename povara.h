#ifndef PovaraH
#define PovaraH
#include <string>
#include <vector>

using namespace std;

enum class Cooker: int // перечисление поваров
{
    Mouse,
    Cat,
    Robot,
    WheelchairUser
};

/*class ActionOfCooker
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
     virtual void VacON() const = 0; // отправка в отпуск
     virtual void VacOff() const = 0; // вернуть из отпуска
};*/

class ActionOfCooker
{
protected:
     int Skill;
     int Stazh;
     int Age;
     string Sex;
     string Post;
public:
     void CookOff(); // не готовка
     void CookON(); // готовка
     void Dis(); // увольнение
     virtual void VacON() = 0; // отправка в отпуск
     void VacOff(); // вернуть из отпуска
     virtual Cooker GetCooker() const = 0; // определение повара
};

typedef ActionOfCooker * CookerPtr;

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
    void CookON() {}; // готовит пасту
    void CookOff() {}; // не готовит пасту
    void Dism() {}; // таракан
    void VacON() {}; // отправка в отпуск на отсыпание
    void VacOff() {wcout << L"Выспался и пришел на работу!" << endl; VacSleep = false;} // возврат из отпуска
    Cooker GetCooker() const {return Cooker::Mouse;} // определение типа повара
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
    void CookON(); // готовит суши
    void CookOff(); // не готовит суши
    void Dism(); // курение
    void VacON(); // отправка в отпуск на Канары
    void VacOff(); // возврат из отпуска
    Cooker GetCooker() const {return Cooker::Cat;}
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
    Cooker GetCooker() const {return Cooker::Robot;}
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
    void CookON() {}; // готовит котлету
    void CookOff() {}; // не готовит котлету
    void Dism() {}; // спалил кухню
    void VacON() {wcout << L"На Кубу!" << endl; Skill -=20; VacKuba = true;}; // отправка на Кубу
    void VacOff() {} // возврат из отпуска
    Cooker GetCooker() const {return Cooker::WheelchairUser;} //тип повара: колясочник
};

/*class CookerContIterator1 : public Iterator<FruitPtr>
{
private:
    const  FruitPtr *FruitBox;
    int Pos;
    int Count;

public:
    FruitContainerIterator(const  FruitPtr *fruitBox, int count)
    {
        FruitBox = fruitBox;
        Count = count;
        Pos = 0;
    }

    void First() {Pos = 0;}
    void Next() {Pos++;}
    bool IsDone() const {return Pos >= Count;}
    FruitPtr GetCurrent() const {return FruitBox[Pos];}
};*/

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
    int GetCount() const { return CookerCount; }
    CookerPtr GetByIndex(int index) const { return CookerBox[index]; }

};

class CookerContainerV2 // контейнер номер 2
{
private:
    vector<CookerPtr> CookerBox;

public:
    void AddCooker(CookerPtr newCooker) {CookerBox.push_back(newCooker);}
    int GetCount() const {return CookerBox.size();}
    CookerPtr GetByIndex(int index) const { return CookerBox[index]; }
};

/*class CookerContainerSQLite //контейнер с БД
{
private:
    CookerPtr *CookerBox;
    int CookerCount;
    int MaxSize;
public:
    CookerContainer(int maxSize);
    virtual ~CookerContainer();
    void AddCooker (CookerPtr newCooker);
    int GetCount() const { return CookerCount; }
    CookerPtr GetByIndex(int index) const { return CookerBox[index]; }

};*/

#endif // PovaraH
