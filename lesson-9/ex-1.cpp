#include <iostream>

using namespace std;

class Game
{
    public:
        int result();  
};

class FakeFootballGame: private Game
{
    public:
        int result()
        {
            return 0;
        }
};

int main()
{
    FakeFootballGame test = FakeFootballGame();
    cout<<test.result();

    return 0;
}
