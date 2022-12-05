#include <iostream>

using namespace std;

class NumberPair{
    private:
        int a = 0;
        int b = 0;
    public:
        NumberPair(int a_in, int b_in)
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
    cout << NumberPair(2,4).max() << endl
    << NumberPair(7,3).max() << endl
    << NumberPair(9,12).min() << endl
    << NumberPair(15,2).min() << endl
    << NumberPair(13,6).avg() << endl;
    
    cout << NumberPair(NumberPair(4,8).max(), NumberPair(12,3).max()).max();

    return 0;
}
