#include <iostream>
#include <string>

using namespace std;

class Model
{
    private:
        string brand = "unknown brand";
        string name = "unknown name";
        string color = "unknown color";
        int productionYear = 0;
    public:
        Model()
        {
            this->brand = "unknown brand";
            this->name = "unknown name";
            this->color = "unknown color";
            this->productionYear = 0;
        }
        Model(string inputBrand, string inputColor, string inputName, int inputProductionYear)
        {
            this->brand = inputBrand;
            this->name = inputName;
            this->color = inputColor;
            this->productionYear = inputProductionYear;
        }
        
        string Description()
        {
            return "This " + color + " " + name + " car has been produced by "
            + brand + " in " + to_string(productionYear) + ".";
        }
};

class Dimensions
{
    private:
        float length = 0;
        float width = 0;
        float height = 0;
    public:
        Dimensions()
        {
            this->length = 0;
            this->width = 0;
            this->height = 0;
        }
        Dimensions(float inputLength, float inputWidth, float inputHeight)
        {
            this->length = inputLength;
            this->width = inputWidth;
            this->height = inputHeight;
        }
        
        
        bool AbilityToPassUnderBridge(float bridgeHeight)
        {
            return this->height < bridgeHeight;
        }
        float Volume()
        {
            return this->length*this->width*this->height;
        }
};

class Wheels
{
    private:
        int diameter = 0;
        string manufacturer = "unknown manufacturer";
        string tireType = "unknown type";
        int wear = 0;
    public:
        Wheels()
        {
            this->diameter = 0;
            this->manufacturer = "unknown manufacturer";
            this->tireType = "unkown type";
            this->wear = 0;
        }
        Wheels(int inputDiameter, string inputManufacturer, string inputTireType)
        {
            this->diameter = inputDiameter;
            this->manufacturer = inputManufacturer;
            this->tireType = inputTireType;
            this->wear = 0;
        }
        
        string Description()
        {
            return "These " + this->tireType + " tires were manufactured by "
            + this->manufacturer + " and have a diameter of "
            + to_string(diameter) + " cm. They've been used to drive for "
            + to_string(wear) + " kilometers.";
        }
        void UseWheels(int distance)
        {
            this->wear += distance;
        }
        void ReplaceTires()
        {
            this->wear = 0;
        }
};

class Engine
{
    private:
        int cubicCapacity = 0;
        string engineType = "unknown type";
        string manufacturer = "unknown manufacturer";
        int distanceSinceOilRefill = 0;
    public:
        Engine()
        {
            this->cubicCapacity = 0;
            this->engineType = "unknown type";
            this->manufacturer = "unknown manufacturer";
            this->distanceSinceOilRefill = 0;
        }
        Engine(int inputCubicCapacity, string inputEngineType, string inputManufacturer)
        {
            this->cubicCapacity = inputCubicCapacity;
            this->engineType = inputEngineType;
            this->manufacturer = inputManufacturer;
            this->distanceSinceOilRefill = 0;
        }
        
        string Description()
        {
            return "This " + engineType + " engine has been produced by "
            + manufacturer + " and has a cubic capacity of "
            + to_string(cubicCapacity) + " litres. It has been used to drive for "
            + to_string(distanceSinceOilRefill) + " kilometers since last oil refill.";
        }
        void UseEngine(int distance)
        {
            this->distanceSinceOilRefill += distance;
        }
        void RefillOil()
        {
            this->distanceSinceOilRefill = 0;
        }
};

class Car
{
    private:
        Model model;
        Dimensions dimensions;
        Wheels wheels;
        Engine engine;
    public:
        Car()
        {
            this->model = Model();
            this->dimensions = Dimensions();
            this->wheels = Wheels();
            this->engine = Engine();
        }
        Car(Model inputModel, Dimensions inputDimensions, Wheels inputWheels, Engine inputEngine)
        {
            this->model = inputModel;
            this->dimensions = inputDimensions;
            this->wheels = inputWheels;
            this->engine = inputEngine;
        }
        
        void Drive(int distance)
        {
            this->engine.UseEngine(distance);
            this->wheels.UseWheels(distance);
        }
        void Maintain()
        {
            this->engine.RefillOil();
            this->wheels.ReplaceTires();
        }
        string Description()
        {
            return "Model information: " + this->model.Description()
            + "\nWheel information: " + this->wheels.Description()
            + "\nEngine information: " + this->engine.Description();
        }
};

int main()
{
    Model testModel = Model("Subata", "Arcana 3", "yellow", 2019);
    Wheels testWheels = Wheels(60, "a really cool company idk", "winter");
    Engine testEngine = Engine(200, "V8 Diesel", "Kronstadt");
    Dimensions testDimensions = Dimensions(343, 163, 142);
    Car testCar = Car(testModel, testDimensions, testWheels, testEngine);
    testCar.Drive(15);
    cout << testCar.Description() << endl;
    testCar.Maintain();
    cout << testCar.Description() << endl;

    return 0;
}
