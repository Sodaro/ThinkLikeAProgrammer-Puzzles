#include <iostream>
#include <string>

enum class State { UPPER, LOWER, PUNCTUATION };

const int LOWER_CASE_OFFSET = 96;
const int UPPER_CASE_OFFSET = 64;

void nextState(State& state, int& modValue, int& offset)
{
    switch (state)
    {
    case State::UPPER:
        state = State::LOWER;
        modValue = 27;
        offset = LOWER_CASE_OFFSET;
        break;
    case State::LOWER:
        state = State::PUNCTUATION;
        modValue = 9;
        break;
    case State::PUNCTUATION:
        state = State::UPPER;
        modValue = 27;
        offset = UPPER_CASE_OFFSET;
        break;
    }
}

int main()
{
    State currentState = State::UPPER;
    int offset = UPPER_CASE_OFFSET;
    char punctuation[8] = { '!', '?', ',', '.', ' ', ';', '"', '\'' };
    int modValue = 27;

    std::string input = "18,12312,171,763,98423,1208,216,11,500,18,241,0,32,20620,27,10";
    std::string word = "";
    int length = input.length();
    for (int i = 0; i < length; i++)
    {
        char c = input[i];
        if (c == ',' || i == length - 1)
        {
            int wordValue = std::stoi(word);
            word = "";

            int remainder = wordValue % modValue;

            if (remainder == 0)
            {
                nextState(currentState, modValue, offset);
                continue;
            }

            char outputLetter;

            if (currentState == State::PUNCTUATION)
            {
                outputLetter = punctuation[remainder - 1];
            }
            else
            {
                outputLetter = remainder + offset;
            }
            std::cout << outputLetter;

        }
        else
        {
            word += c;
        }
    }
}
