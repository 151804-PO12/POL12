#include <iostream>
#include <cmath>

using namespace std;

class Number {
    public:
        double DoubleValue();
};

class Logarithm : public Number {
 private:
  double base, argument;
 public:
  double doubleValue() { return log(this->argument) / log(this->base);}
  Logarithm(double inputBase, double inputArgument) {
    try
    {
        if(inputBase == 1)
            throw "Base cannot be equal to 1.";
        if(inputArgument <= 0)
            throw "Argument cannot be a non-positive number.";
    }catch (char const* error)
    {
        cout << "Incorrect argument: " << error << endl;
    }
    this->base = inputBase;
    this->argument = inputArgument;
  }
};

int main()
{
    Logarithm(2 ,0);

    return 0;
}
