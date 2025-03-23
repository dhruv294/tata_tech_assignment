#include <iostream>
#include <vector>

using namespace std;

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
            cout << "it is a strike" << endl;
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
                cout << "it is a spare" << endl;
                spare = true;
            }
        }

        if (!(strike == true || spare == true))
        {
            score[i] = roll1 + roll2;
        }
        else
        {
            score[i] = 10;
        }

        if (prev_spare && i > 0)
        {
            score[i - 1] += roll1;
            prev_spare = false;
        }
        if (prev_strike)
        {
            score[i - 1] += roll1 + roll2;
            prev_strike = false;
        }
        if (i > 0)
            score[i] += score[i - 1];

        if ((spare || strike) && (i == 9))
        {
            cout << "it is bonus throw" << endl;
            cout << "roll3: ";
            cin >> roll3;
            score[i] += roll3;
            frame[i].push_back(roll3);
        }

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
