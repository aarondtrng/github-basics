// Assignment 3: Aaron Truong, CS110B
// Number guessing program
#include <iostream>
using namespace std;

void play_one_game();
bool should_play_again();
char get_user_response_to_guess(int guess);
int get_midpoint(int low, int high);


int main()
{   
    do
    {
        play_one_game();
    } while (should_play_again());
    
}

void play_one_game()
{
    cout << "Think of a number between 1 and 100\n";
    int low = 1;
    int high = 100;
    int mid = get_midpoint(low,high);
    char user_response;

    user_response = get_user_response_to_guess(mid);
    while (user_response != 'c')
    {
        if (user_response == 'h')
        {
            low = mid;
            mid = get_midpoint(low,high);
            user_response = get_user_response_to_guess(mid);
        }
        else if (user_response == 'l')
        {
            high = mid;
            mid = get_midpoint(low,high);
            user_response = get_user_response_to_guess(mid);
        }
    }
    cout << "Great! ";
}

bool should_play_again()
{
    char again;
    cout << "Do you want to play again? (y/n): ";
    cin >> again;
    if (again == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

char get_user_response_to_guess(int guess)
{
    char user_input;
    cout << "Is it " << guess << "?" << " (h/l/c): ";
    cin >> user_input;
    return user_input;
}

int get_midpoint(int low, int high)
{
    int mid; 
    mid = (low + high) / 2;
    return mid;
}

/* SAMPLE OUTPUT
[atruon77@hills ~]$ ./a.out
Think of a number between 1 and 100
Is it 50? (h/l/c): h
Is it 75? (h/l/c): h
Is it 87? (h/l/c): l
Is it 81? (h/l/c): h
Is it 84? (h/l/c): h
Is it 85? (h/l/c): c
Great! Do you want to play again? (y/n): y
Think of a number between 1 and 100
Is it 50? (h/l/c): l
Is it 25? (h/l/c): l
Is it 13? (h/l/c): l
Is it 7? (h/l/c): l
Is it 4? (h/l/c): h
Is it 5? (h/l/c): h
Is it 6? (h/l/c): c
Great! Do you want to play again? (y/n): n
[atruon77@hills ~]$ 
*/