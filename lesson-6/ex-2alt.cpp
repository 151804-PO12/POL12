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
  double doubleValue()
  {
    try
    {
        if(this->base == 1)
            throw "Base cannot be equal to 1.";
        if(this->argument <= 0)
            throw "Argument cannot be a non-positive number.";
    }catch (char const* error)
    {
        cout << "Incorrect argument: " << error << endl;
    }
    return log(this->argument) / log(this->base);}
  Logarithm(double inputBase, double inputArgument) {
    this->base = inputBase;
    this->argument = inputArgument;
  }
};

int main()
{
    cout << Logarithm(2 ,0).doubleValue();

    return 0;
}
