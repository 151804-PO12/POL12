/////////////////////////
//TODO: Add more methods.
/////////////////////////
#include <iostream>
#include <string>

using namespace std;

class Milk{
    private:
        int volume;
        int age;
        int fatPercentage;
        
    public:
        Milk(int vol, int ag, int fat)
        {
            this->volume = vol;
            this->age = ag;
            this->fatPercentage = fat;
        }
        
        void Spill(int toSpill)
        {
            this->volume = max(volume-toSpill,0);
        }
        
        void Spoil(int toSpoil)
        {
            this->age += toSpoil;
        }
        
        int TotalFatAmount()
        {
            return this->fatPercentage * this->volume;
        }
};

int main()
{
    Milk Fresh(15, 2, 6);
    Fresh.Spill(3);
    Fresh.Spoil(10);
    cout << Fresh.TotalFatAmount();
    Fresh.Spill(18);
}
