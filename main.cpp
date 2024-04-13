#include <iostream>
#include <vector>

using namespace std;

#include "povara.h"

CookerContainer::CookerContainer(int maxSize)
{
    CookerBox = new CookerPtr[maxSize];
    for(int i = 0; i < MaxSize; i++)
    {
        CookerBox[i] = NULL;
    }
    CookerCount = 0;
    MaxSize = maxSize;
}

wstring PrintCookerType(const Cooker type)
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

void CookerContainer::AddCooker(CookerPtr newCooker)
{
    CookerBox[CookerCount++] = newCooker;
}

void Task1(CookerContainer *cookerBox)
{
    for(int i=0; i<cookerBox->GetCount(); i++)
    {
        const CookerPtr outCook  = cookerBox->GetByIndex(i); // outCook = currentFruit
        wcout << i << L" (" << PrintCookerType(outCook->GetCooker()) << L")" << endl;
    }


}

int main()
{
    setlocale(LC_ALL, "Russian");
    CookerContainer cookerBox(100);
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

    Task1(&cookerBox);
    /*for(int i=0; i<10; i++)
    {
        fruitBox.AddFruit(new Apple(ColorEnum::Red));
    }
    for(int i=0; i<20; i++)
    {
        fruitBox.AddFruit(new Kiwi);
    }
    for(int i=0; i<20; i++)
    {
        fruitBox.AddFruit(new Orange);
    }*/

    return 0;
}
