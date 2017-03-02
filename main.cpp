//The GiveNGuess game!
//In this program, you can either have the computer
//generate a secret number and then guess the number for yourself,
//or you could be the one that gives the computer a secret number and 
//then the computer has to try and keep it!
//
//Any criticism/feedback would be appreciated, thanks!
//Author - https://Github.com/C3NZ

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//Seed the random number generator using the current time
	//and then casting it 
	srand(static_cast<unsigned int>(time(0)));
	
	//gameRunning - Whether our program is running or not
	bool gameRunning = true;
	
	//Possible states our game can be in.
	bool menuState = false;
	bool guessState = false;
	bool giveState = false;
	
	//boolean value for letting the loop know when a number has been entered for the giving game.
	bool numEntered = false;
	
	//boolean value for letting the loop know when our user has entered a name.
	bool nameEntered = false;
	
	string name;
	cout << "Welcome to the Guess/Give a number game!" << endl;
	
	//Start the game loop
	while(gameRunning)
	{
		//Check to see if we got the players username, if not get it.
		if(!nameEntered)
		{
			cout << "Please enter your name:";
			cin >> name;
			menuState = true;
			nameEntered = true;
		}
		
		//While we're in the menuState...
		while(menuState)
		{
			//Allow players to pick gamemode
			string enteredGameMode;
			cout << "Hello, " << name << ", you can play these two seperate game modes." << endl;
			cout << "------------------------------------" << endl;
			cout << "1.)Guess the number" << endl;
			cout << "2.)Give the number" << endl;
			cout << "------------------------------------" << endl;
			cout << "Type in the first word of each choice to select your gamemode." << endl;
			cout << "Input:";
			cin >> enteredGameMode;
			cout << "\n";
			
			if (enteredGameMode == "Guess")
			{
				guessState = true;
				menuState = false;
			}
			else if (enteredGameMode == "Give")
			{
				giveState = true;
				menuState = false;
			}
			else
			{
				cout <<  "You typed in an incorrect choice, try again!" << endl;
				continue;
			}
		}//End of while(menuState) loop.
	
		//Guessing game loop
		while(guessState)
		{
			cout << "Welcome to Guess the number!" << endl;
			cout << "In this game, you have to guess the computers secret number!"  << endl;
			cout << "The number is inbetween 1 and 100!" << endl;
			cout << "Start now!" << endl;
				
			//Generate the secret number you have to guess
			int secretNumber = (rand() % 100) + 1;
			int yourNumber;
			int tries = 0;
				
			bool correctGuess = false;
				
			//While your number doesn't match the secret number...
			while (!correctGuess)
			{
				tries++;
				cout << "Guess:";
				cin >> yourNumber;
					
				if (yourNumber != secretNumber)
				{
					if (yourNumber > secretNumber)
					{
						cout << "You guessed " << yourNumber << " which is too high! Please guess again!" << endl;
					}
					else if (yourNumber < secretNumber)
					{
						cout << "You guessed " << yourNumber << " which is too low! Please guess again!" << endl;
					}
						continue;
				}
				else
				{
					cout << secretNumber << ", That's correct! You guessed the number in " << tries << "tries!" << endl;
					correctGuess = true;
				}
			}//End of while(!correctGuess) loop.
				
			//Ask the user if they'd like to play again.
			while(gameRunning)
			{
				char answer;
				cout << "Would you like to continue playing? (y/n)" << endl;
				cout << "Input:";
				cin >> answer;
				cout << "\n";
							
				if (answer == 'y')
				{
					guessState = false;
					menuState = true;
				}
				else if (answer == 'n')
				{
					guessState = false;
					gameRunning = false;
				}
				else
				{
					cout << "That's not a valid option, please try again!" << endl;
				}
			}//End of while(gameRunning) sub loop. 
		}//End of while(guessState) loop.
			
			//Giving game loop
			while(giveState)
			{
				int secretNumber;	
				
				//While the user hasn't entered a secret number...
				while(!numEntered)
				{
					//Get a secret number from the user.
					cout << "Welcome to Give the number!" << endl;
					cout << "In this game, you have to create a secre number for the computer to guess!" << endl;
					cout << "The number has to be inbetween 1 and 100!" << endl;
					cout << "Start now!" << endl;
					cout << "Enter a secret number:";
					cin >> secretNumber;
					
					//Make sure the secret number is not greater than 100 or less than 0.
					if (secretNumber > 100 || secretNumber < 0)
					{
						cout << "Your number is out of bounds! Please try again!" << endl;
					}
					else if (secretNumber <= 100 && secretNumber >= 1)
					{
						numEntered = true;
					}
				}//End of while(!numEntered) loop
		
				//Reset the value of this boolean
				numEntered = false; 
				
				//Keep track of how many guesses the computer has made and if the computer's guess is correct.
				int computerTries = 0;
				bool computerCorrect = false; 
				
				
				//Variables used to keep track of the search boundaries and the computer's guess.
				int lowerBoundary = 1;
				int upperBoundary = 99;
				int computerGuess;
				
				//While the computer hasn't guessed your number...
				while(!computerCorrect)
				{
					computerTries++;
					
					//If the lower bound is higher than the upperbound, terminate the search as the set isn't sorted.
					if(lowerBoundary > upperBoundary)
					{
						cout << "Search has terminated as unseccessful, is your set ordered?" << endl;
						return 0;
					}
					
					//The computers guess is the sum of both bounds divided by 2.
					//The computers first guess will always be 50, since that is the midpoint of 1-100
					computerGuess = (lowerBoundary + upperBoundary) / 2;
				
					//If the computers number is less than the secret number,
					//set the lower bound to the last guess plus 1.
					//If it is greater than the secret number,
					//set the upper bound to the last guess minus 1.
					if(computerGuess < secretNumber)
					{
						cout << "The computer has guessed the number " << computerGuess << ", which is too low!" << endl;
						lowerBoundary = (computerGuess + 1);
					}
					else if (computerGuess > secretNumber)
					{
						cout << "The computer has guessed the number " << computerGuess << ", which is too high!" << endl;
						upperBoundary = (computerGuess - 1);
					}
					else
					{
						cout << "Congratulations, the computer guessed the number " << computerGuess << " in " << computerTries << " tries." << endl;
						computerCorrect = true;
					}
				}//End of while(!computerCorrect) loop
				
				cout << "The bot guessed your numbers in " << computerTries << " tries!" << endl;
				
				//Ask the player if they'd like to play the game again.
				while(gameRunning)
				{
					char answer;
					cout << "Would you like to continue playing? (y/n)" << endl;
					cout << "Input:";
					cin >> answer;
					cout << "\n";
							
					if (answer == 'y')
					{
						giveState = false;
						menuState = true;
						break;		
					}
					else if (answer == 'n')
					{
						giveState = false;
						gameRunning = false;
					}
				}//End of while(gameRunning) sub loop
			}//End of while(giveState) loop
		}//End of the while(gameRunning) main loop	
	return 0;
}//End of the main function
