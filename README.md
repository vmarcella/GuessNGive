#GuessNGive

##Details
A simple game I made to put what I've learned about C++ so far into use. 

##The game has two different game modes you can play:
1. Guessing game
	*The computer generates a random number between the numbers 1 and 100 which you have to guess
2. Giving game
	*You give the computer a number between 1 and 100 and then the computer tries and guesses it	

##It demonstrates mostly the use of...
-Conditional statements
-Logical operators
-iostream file functions
-generating random numbers and seeding the random number generator

##I started working on this project...
###February 19, 2017
####and created the repo...
###February 24, 2017;'

##Some things I'd like to improve are...
-Developing an algorithm for the computer to come up with actual guesses. The only real random number that is actually a "guess" by the computer is the first one generated, which is done with this line of code:

  ```cpp
  int secretNumber = (rand() % 100) + 1;
  ```
