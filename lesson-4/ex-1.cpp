#include <iostream>
#include <string>

using namespace std;

class Vehicle {
    public:
        int maxSpeed;
        string color;
};

class Car: private Vehicle {
    private:
        int fuel;
    public:
        
        Car Refuel(int amount) {
            return Car(this->maxSpeed, this->color, this->fuel+amount);
        }
        Car Drive(int amount) {
            cout << "Drove for " << min(this->fuel, amount) << " kilometres." << endl;
            if(amount>this->fuel)
            {
                cout << "Fuel ran out in the middle of the road :(" << endl;
            }
            return Car(this->maxSpeed, this->color, max(0,this->fuel-amount));
        }
        Car(int inputMaxSpeed, string inputColor, int inputFuel) {
            this->maxSpeed = inputMaxSpeed;
            this->color = inputColor;
            this->fuel = inputFuel;
        }
        int TankCapacity() {
            return this->fuel;
        }
};

class Plane: private Vehicle {
    public:
        Plane(int inputMaxSpeed, string inputColor) {
            this->maxSpeed = inputMaxSpeed;
            this->color = inputColor;
        }
        Plane Crash() {
            return Plane(0, "charred");
        }
};

int main()
{
    Car test = Car(4, "blue", 12);
    cout << test.TankCapacity() << endl;
    test = test.Refuel(4);
    cout << test.TankCapacity() << endl;
    Car usedCar = test.Drive(12);
    cout << usedCar.TankCapacity() << endl;
    Car desertedCar = test.Drive(25);
    cout << desertedCar.TankCapacity() << endl;

    return 0;
}
