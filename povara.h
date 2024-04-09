class ActionOfCooker
{
     int Stazh;
     int Age;
     string Sex;
     string Post;
     virtual void Cook const = 0;
     virtual void Dismissal const = 0;
     virtual void Vacation const = 0;
};

class Mouse: public ActionOfCooker
{
private:
    Stazh = 28;
    Age = 46;
    Sex = "Man";
    Post = L"Шеф-повар";
public:



};

class Cat: public ActionOfCooker
{
private:
    Stazh = 20;
    Age = 40;
    Sex = "Man";
    Post = L"Помощник шеф-повара";
public:

};

class Robot: public ActionOfCooker
{
private:
    Stazh = 15;
    Age = 38;
    Sex = "Man";
    Post = L"Кондитер";
public:
};

class WheelchairUser: public ActionOfCooker
{
private:
    Stazh = 5;
    Age = 30;
    Sex = "Woman";
    Post = L"Поварёнок";
public:
};
