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
            throw exception();
        else if(this->argument <= 0)
            throw exception();
    }catch(exception)
    {
        throw exception();
    }
    return log(this->argument) / log(this->base);
  }
  Logarithm(double inputBase, double inputArgument) {
    this->base = inputBase;
    this->argument = inputArgument;
  }
};

int main()
{
    try
    {
        Logarithm(2 ,0).doubleValue();
    }
    catch (exception)
    {
        cout << "Incorrect argument" << endl;
    }

    return 0;
}
