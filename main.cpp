#include <iostream>
#include <vector>

using namespace std;

#include "povara.h"

CookerContainer::CookerContainer(int maxSize) // конструктор контейнера с поварами (1)
{
    CookerBox = new CookerPtr[maxSize];
    for(int i = 0; i < MaxSize; i++)
    {
        CookerBox[i] = NULL;
    }
    CookerCount = 0;
    MaxSize = maxSize;
}

CookerContainer::~CookerContainer() // деструктор контейнера с поварами (1)
{
    for(int i=0; i<MaxSize; i++)
    {
        if(CookerBox[i] != NULL)
        {
            delete CookerBox[i];
            CookerBox[i] = NULL;
        }
    }

    delete[] CookerBox;
}

void ActionOfCooker::CookOff() // описание функции окончания готовки
{
    wcout << L"Дело сделано!" << endl;
    Cooking = false;
    if (Skill >= 100)
    {
        Skill = 100;
    }
    else
    {
        Skill +=10;
    }
}


wstring PrintCookerType(const Cooker type) // описание типа повара
{
    switch(type)
    {
        case Cooker::Mouse: return L"Мышь";
        case Cooker::Cat: return L"Кот";
        case Cooker::Robot: return L"Робот";
        case Cooker::WheelchairUser: return L"Колясочник";
        default: return L"неизвестно";
    }
}

void CookerContainer::AddCooker(CookerPtr newCooker) // создание нового повара
{
    CookerBox[CookerCount++] = newCooker;
}

void OutPut(CookerContainer *cookerBox) //функция для вывода поваров
{
    for(int i=0; i<cookerBox->GetCount(); i++)
    {
        const CookerPtr outCook  = cookerBox->GetByIndex(i);
        wcout << i << L" (" << PrintCookerType(outCook->GetCooker()) << L")" << endl;
    }
}

void Vaccation (CookerContainer *cookerBox) // отправили всех поварят колясочников в отпуск
{
    for(int i=0; i<cookerBox->GetCount(); i++)
    {
        const CookerPtr outCook  = cookerBox->GetByIndex(i);
        if(outCook->GetCooker() == Cooker::WheelchairUser)
        {
            outCook->VacON();
        }

    }
    wcout << L"Все поварята отправлены в отпуск" << endl;
}

void OutPut_iterator(Iterator<CookerPtr> *iter) // функция для вывода всех повааров через итератор
{
    for(iter->First(); !iter->IsDone(); iter->Next())
    {
        const CookerPtr outCook = iter->CurrentItem();
        wcout << L" (" << PrintCookerType(outCook->GetCooker()) << L")" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    CookerContainer cookerBox(100); // создание 100 поваров (циклом for)
    for(int i=0; i<50; i++)
    {
        cookerBox.AddCooker(new Mouse());
    }

    for(int i=0; i<10; i++)
    {
        cookerBox.AddCooker(new Cat());
    }

    for(int i=0; i<10; i++)
    {
        cookerBox.AddCooker(new Robot());
    }

    for(int i=0; i<30; i++)
    {
        cookerBox.AddCooker(new WheelchairUser());
    }

    Iterator<CookerPtr> *iter = cookerBox.GetIterator();

    OutPut_iterator(iter);
    delete iter;
    //OutPut(&cookerBox);
    //Vaccation(&cookerBox);

    return 0;
}
