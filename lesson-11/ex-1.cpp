#include <iostream>
#include <string>

using namespace std;

class Sequence
{
    public:
        virtual string printedSeq() = 0;
};

class Characters: public Sequence
{
    private:
        string text;
    public:
        Characters(string input)
        {
            text = input;
        }
        string printedSeq()
        {
            return text;
        }
};


class LowerCased: public Sequence
{
    private:
        string text;
    public:
        LowerCased(Sequence input)
        {
            text = input.printedSeq();
        }
        string printedSeq()
        {
            string new_text = text;
            for(int i = 0; i < text.size(); i++)
            {
                new_text[i] = tolower(text[i]);
            }
            return new_text;
        }
};

class Substring: public Sequence
{
    private:
        string text;
        int pos;
        int len;
    public:
        Substring(Sequence input_seq, int input_pos, int input_len)
        {
            text = input_seq.printedSeq();
            pos = input_pos;
            len = input_len;
        }
        string printedSeq()
        {
            return text.substr(pos, len);
        }
};

class Concatenation: public Sequence
{
    private:
        string text1;
        string text2;
    public:
        Concatenation(Sequence input1, Sequence input2)
        {
            text1 = input1.printedSeq();
            text2 = input2.printedSeq();
        }
        string printedSeq()
        {
            return text1+text2;
        }
};

int main()
{
    /**
    Sequence test = Characters("HaHaLoLo");
    Sequence test2 = Characters("Dziala");
    test =  LowerCased(Concatenation(Substring(test, 3,4), test2));
    cout << test.printedSeq();
    **/

    return 0;
}
