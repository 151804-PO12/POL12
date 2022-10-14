#include <iostream>
#include <string>
using namespace std;

class Box
{
    public:
        int capacityLitres;
        string contents;
};

class Cat
{
    public:
        string name;
        int ageYears;
        float weigthKg;
        string furColour;
        string eyeColour;

        void HopInBox(Box box)
        {
            if(box.capacityLitres > 5)
                cout << "Hop!" << endl;
            else
                cout << "It's too small for this cat!" << endl;
        }
};

class Person
{
    public:
        string name;
        int ageYears;
        float moneyPln;
        int heightCm;

        void InspectCat(Cat cat)
        {
            cout << "This cat has " << cat.furColour << " fur and " << cat.eyeColour << " eyes." << endl;
        }

        void InspectBox(Box box)
        {
            cout << "This box has volume of " << box.capacityLitres << "L and currently has " << box.contents << " inside." << endl;
        }
};

int main()
{
    Cat Sonia;
    Sonia.name = "Sonia";
    Sonia.ageYears = 3;
    Sonia.furColour = "white";
    Sonia.eyeColour = "green";

    cout << Sonia.name << " is " << Sonia.ageYears << " years old." << endl;

    Cat Milka;
    Milka.name = "Milka";
    Milka.ageYears = 1;
    Milka.furColour = "black";
    Milka.eyeColour = "green";

    Person Catowner;
    Catowner.name = "John";
    Catowner.ageYears = 20;
    Catowner.heightCm = 19*10;

    cout << Catowner.name << "'s height is " << Catowner.heightCm << "cm." << endl;

    Box Lunchbox;
    Lunchbox.capacityLitres = 2;
    Lunchbox.contents = "sandwich";

    cout << "There's " << Lunchbox.contents << " inside this box." << endl;

    Box Bin;
    Bin.capacityLitres = 120;
    Bin.contents = "laundry";

    Catowner.InspectCat(Sonia);
    Catowner.InspectCat(Milka);
    Catowner.InspectBox(Bin);

    Milka.HopInBox(Lunchbox);
    Sonia.HopInBox(Bin);

    return 0;
}
