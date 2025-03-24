#include <iostream>
#include <vector>

using namespace std;
// class to maintain score / 10 throws
class score
{
private:
    vector<int> frame[10];
    int score[10];

public:
    void score_calc();
    void print_score();
};

void score::score_calc()
{
    int roll1, roll2 = 0, roll3 = 0;
    bool prev_strike = false, prev_spare = false;
    for (int i = 0; i < 10; i++)
    {
        bool spare = false, strike = false;
        cout << "frame" << "[" << i + 1 << "]" << endl;
        cout << "Input score for 1st throw" << endl;
        cout << "roll1: ";
        cin >> roll1;
        if (roll1 == 10)
        {
            cout << "it is a strike" << endl;   // if throw1 is 10 consider it sprike
            strike = true;
            frame[i].push_back(roll1);
        }
        else
        {
            cout << "Input score for 2nd throw" << endl;
            cout << "roll2: ";
            cin >> roll2;
            frame[i].push_back(roll1);
            frame[i].push_back(roll2);
            if ((roll1 + roll2) == 10)
            {
                cout << "it is a spare" << endl;   // if throw1+throw2 are 10 consider it spare
                spare = true;
            }
        }

        if (!(strike == true || spare == true))
        {
            score[i] = roll1 + roll2;   // calculate score for current frame if it doesn't have spare / strike
        }
        else
        {
            score[i] = 10;            // if it is spare / strike assign 10 to current frame score
        }

        if (prev_spare && i > 0)
        {
            score[i - 1] += roll1;  // if previous frame has spare add roll1 score to previous frame score
            prev_spare = false;
        }
        if (prev_strike)
        {
            score[i - 1] += roll1 + roll2; // if previous frame has strike add roll1+roll2 score to previous frame score
            prev_strike = false;
        }
        if (i > 0)
            score[i] += score[i - 1];   // calculate total frame score based on previous score value

        if ((spare || strike) && (i == 9)) // if it 10th frame & either spare /strike occurs  give player extra throw
        {
            cout << "it is bonus throw" << endl;
            cout << "roll3: ";
            cin >> roll3;
            score[i] += roll3;
            frame[i].push_back(roll3);
        }
// maintain current frame spare / strike flag for next frame caculations
        prev_spare = spare;
        prev_strike = strike;
    }
}

void score::print_score()
{
    for (int i = 0; i < 10; i++)
    {
        cout << score[i] << " | ";
    }
    cout << endl;
}

int main()
{
    score s1;
    s1.score_calc();
    cout << "\nScoreBoard is : " << endl;
    s1.print_score();
    return 0;
}
