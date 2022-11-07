#include <iostream>
#include <string>

using namespace std;

class Model
{
    private:
        string brand = "unknown brand";
        string model = "unknown model";   //Having a member named the same way as class it is in doesn't sound right, but I cannot come up with better naming for now.
        string color = "unknown color";
        int productionYear = 0;
    public:
        Model()
        {
            this->brand = "unknown brand";
            this->model = "unknown model";
            this->color = "unknown color";
            this->productionYear = 0;
        }
        Model(string inputBrand, string inputColor, string inputModel, int inputProductionYear)
        {
            this->brand = inputBrand;
            this->model = inputModel;
            this->color = inputColor;
            this->productionYear = inputProductionYear;
        }
        
        string Description()
        {
            return "This " + color + " " + model + " car has been produced by " + brand + " in " + to_string(productionYear);
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
        float diameter = 0;
        string manufacturer = "unknown manufacturer";
        string tireType = "unkown type";
        int wear = 0;
    public:
        Wheels()
        {
            this->diameter = 0;
            this->manufacturer = "unknown manufacturer";
            this->tireType = "unkown type";
            this->wear = 0;
        }
        Wheels(float inputDiameter, string inputManufacturer, string inputTireType)
        {
            this->diameter = inputDiameter;
            this->manufacturer = inputManufacturer;
            this->tireType = inputTireType;
            this->wear = 0;
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
        float cubicCapacity = 0;
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
        Engine(float inputCubicCapacity, string inputEngineType, string inputManufacturer)
        {
            this->cubicCapacity = inputCubicCapacity;
            this->engineType = inputEngineType;
            this->manufacturer = inputManufacturer;
        }
        string Description()
        {
            return "This " + engineType + " engine has been produced by " + manufacturer + " has a cubic capacity of " + to_string(cubicCapacity) + " litres";
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
};

int main()
{
    cout<<"Hello World";

    return 0;
}
