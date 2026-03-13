
#include <iostream>
using namespace std;
int read_num_in_range(int from,int to,string m)
{
    int n;
    do
    {
        cout << m <<" "<<from << " to " << to << " ?" << endl;
        cin >> n;
    } while (n < from || n > to);
    return n;
}
int random_number_in_range(int from, int to)
{
    return rand() % (to - from + 1) + from;
}
enum engame_SPS { stone =1, paper, scissor };
string get_choice_SPS(int n)
{
  
        switch (engame_SPS(n))
        {
        case engame_SPS::stone :
            return "stone";
        case engame_SPS::paper :
            return "paper";
        case engame_SPS::scissor :
            return "scissor";
        default:
            return "scissor";
        }
}
struct stresults 
{
    int player = 0, computer = 0, no_winner = 0,rounds=0;
    string final_winner_name;
    bool is_play_again=true;
};
string get_round_winner(engame_SPS num_user, engame_SPS num_computer, stresults &result)
{
    

    if (num_user == num_computer)
    {
        ++result.no_winner;
        system("color 6F");
        return "[no winner]";
    }
    else if (((num_user == engame_SPS::paper) && (num_computer == engame_SPS::stone))
        || ((num_user == engame_SPS::scissor) && (num_computer == engame_SPS::paper)) 
        || ((num_user == engame_SPS::stone ) && (num_computer == engame_SPS::scissor )))
    {
        ++result.player;
        system("color 2F");
        return "[player1]";
    }
    else
    {
        ++result.computer;
        cout << "\a";
        system("color 4F");
        return "[computer]";
    }
    
}
string get_final_winner(stresults result)
{
    if (result.computer > result.player)
        return "computer";
    else if (result.computer < result.player)
        return "player1";
    else
        return "no winner";
}
void game_over(stresults result)
{
    cout << "\n\n\n\t\t____________________________________________________\n";
    cout << "\n\t\t\t\t+++ G a m e  O v e r +++\n";
    cout << "\t\t____________________________________________________\n";
    cout << "\n\t\t___________________[game results]___________________\n\n";
    cout << "\t\tgame rounds       :" << result.rounds << endl;
    cout << "\t\tplay1 won times   :" << result.player << endl;
    cout << "\t\tcomputer won times:" << result.computer << endl;
    cout << "\t\tdraw times        :" << result.no_winner << endl;
    cout << "\t\tfinal winner      :" << get_final_winner(result) << endl;
    cout << "\t\t____________________________________________________\n";
    
}
void reset_screen()
{
    system("color 0F");
    system("cls");
}

void start_game()
{
    char ch;
    stresults temp;
    stresults result;
    temp = result;
    while(result.is_play_again )
    {
        result = temp;

        reset_screen();

       int  how_round = read_num_in_range(1, 10, "how many rounds");
        result.rounds = how_round;

        for (int i = 1; i <= how_round; i++)
        {
            cout << "\n\nround [" << i << "] begins:\n";

            int num_user= read_num_in_range(1, 3, "\nyour choice: [1]stone ,[2]paper ,[3]scissor ?");
           
            string chioce_user = get_choice_SPS(num_user);

            int num_computer = random_number_in_range(1, 3);
            string chioce_computer = get_choice_SPS(num_computer);

            string round_winner = get_round_winner(engame_SPS(num_user), engame_SPS(num_computer), result);
            result.final_winner_name = round_winner;

            cout << "\n\n_______________round [" << i << "] _______________\n\n";
            cout << "player1 choice : " << chioce_user << endl;
            cout << "computer chioce: " << chioce_computer << endl; 
            cout << "round winner   : " << round_winner << endl;
            cout << "________________________________________\n";
        }
        game_over(result);
        cout << "\n\t\tdo you want to play again ? (Y\\N)?";
        cin >> ch;
        if (ch == 'n' || ch == 'N')
        {
           
            result.is_play_again = false;
        }
    }
}

int main()
{

    srand((unsigned)time(NULL));
 
    start_game();
    
   
}


