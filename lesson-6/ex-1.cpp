#include <iostream>

using namespace std;

class NumberUtils{
    private:
        int a = 0;
        int b = 0;
    public:
        NumberUtils(int a_in, int b_in)
        {
            this->a = a_in;
            this->b = b_in;
        }
        int max()
        { return a > b ? a : b;}
        int min()
        { return a < b ? a : b;}
        float avg()
        { return ((float)a+b)/2;}
};

int main()
{
    cout << NumberUtils(2,4).max() << endl
    << NumberUtils(7,3).max() << endl
    << NumberUtils(9,12).min() << endl
    << NumberUtils(15,2).min() << endl
    << NumberUtils(13,6).avg() << endl;
    
    cout << NumberUtils(NumberUtils(4,8).max(), NumberUtils(12,3).max()).max();

    return 0;
}
