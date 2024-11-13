// Assignment 2: Aaron Truong
// This program simulates a game of blackjack.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{   
    const int MIN = 1, MAX = 10;
    char again;
    unsigned seed = time(0);
    srand(seed);
    do
    {
        char draw_again;
        int first1 = (rand() % (MAX - MIN + 1)) + MIN;
        int first2 = (rand() % (MAX - MIN + 1)) + MIN;
        int total = first1 + first2;

        cout << "First cards: " << first1 << ", " << first2 << endl;
        cout << "Total: " << total << endl;

        do
        {   
            cout << "Do you want another card? (y/n): ";
            cin >> draw_again;

            if (draw_again == 'n')
            {
                break;
            }

            int new_card = (rand() % (MAX - MIN + 1)) + MIN;
            cout << "Card: " << new_card << endl;
            total += new_card;
            cout << "Total: " << total << endl;

            if(total > 21)
            {
                cout << "Bust." << endl;
                break;
            }

        } while (draw_again == 'y');

        cout << "Do you want to go again? (y/n): ";
        cin >> again;
        cout << endl;

    } while (again == 'y');
    return 0;
}

/* SAMPLE OUTPUT
[atruon77@hills ~]$ ./a.out
First cards: 9, 1
Total: 10
Do you want another card? (y/n): y
Card: 7
Total: 17
Do you want another card? (y/n): y
Card: 3
Total: 20
Do you want another card? (y/n): n
Do you want to go again? (y/n): y

First cards: 2, 9
Total: 11
Do you want another card? (y/n): y
Card: 7
Total: 18
Do you want another card? (y/n): y
Card: 4
Total: 22
Bust.
Do you want to go again? (y/n): n

[atruon77@hills ~]$ 
*/