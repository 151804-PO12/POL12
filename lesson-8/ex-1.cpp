#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Shiritori
{
    private:
        vector<string> words;
        bool game_over;
    
    public:
        Shiritori()
        {
            words = {};
            game_over = false;
        }
        Shiritori(vector<string> input_words, bool input_game_over)
        {
            words = input_words;
            game_over = input_game_over;
        }
        
        void printWords()
        {
            for (string word : words)
                cout << word << " ";
            cout << "\n";
        }
        Shiritori play(string new_word)
        {
                //Game has ended already.
            if(game_over)
            {
                cout << "Game is over! Please restart.\n";
                return Shiritori(words, game_over);
            }
            
            vector<string> new_words = words;
            new_words.push_back(new_word);
            
                //No words so far.
            if (words.size() == 0)
                return Shiritori(new_words, game_over);

                //First letter of previous word and first letter of new word are different.
            if(words.back().back() != new_word.front())
            {
                cout << "invalid starting letter\nGame over!\n" << endl;
                return Shiritori(new_words, false);
            }
            
                //New word is a repeat.
            for (string word : words)
            {
                if(word.compare(new_word) == 0)
                {
                    cout << "reused word\nGame over!\n";
                    return Shiritori(new_words, false);
                }
            }
            
            return Shiritori(new_words, game_over);
        }
        Shiritori restart()
        {
            cout << "Game restarted!\n";
            return Shiritori();
        }
};

int main()
{
    string input;
    Shiritori game = Shiritori();
    cout << "Welcome to Shiritori game!\nControls:\nQ - quit\nR - restart\nP - print word list\n";
    do
    {
        cin >> input;
        if(input == "R" or input == "r")
            game = game.restart();
        else if(input == "P" or input == "p")
            game.printWords();
        else if(input != "Q" and input != "q")
            game = game.play(input);
    }while(input != "Q" and input != "q");
    return 0;
}
