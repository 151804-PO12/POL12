#include <iostream>
#include <string>
using namespace std;

class Cat
{
    public:
        string name;
        int ageYears;
        float weigthKg;
        string furColour;
        string eyeColour;
};

class Person
{
    public:
        string name;
        int ageYears;
        float moneyPln;
        int heightCm;
};

class Box
{
    public:
        int capacityLitres;
        string contents;
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
    return 0;
}
