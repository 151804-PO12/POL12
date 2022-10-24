#include <iostream>
#include <string>

using namespace std;

class Towel{
    private:
        int width;
        int length;
        string color;
        
    public:
        Towel(int wid, int len, string col) //The basic one.
        {
            this->width = wid;
            this->length = len;
            this->color = col;
        }
    
        Towel(int size, string col) //For making square towels.
        {   
            this->width = size;
            this->length = size;
            this->color = col;
        }
        
        Towel(string wid, string len, string col)   //For when dimensions are strings.
        {
            this->width = stoi(wid);
            this->length = stoi(len);
            this->color = col;
        }
};

int main()
{
                        //Testing if it all works.
    Towel(15, 30, "white");
    Towel(24, "red");
    Towel("7", "5", "purple");
    return 0;
}
