#GuessNGive

##Details
A simple game I made to put what I've learned about C++ so far into use. 

##The game has two different game modes you can play:
1. Guessing game
	*The computer generates a random number between the numbers 1 and 100 which you have to guess
2. Giving game
	*You give the computer a number between 1 and 100 and then the computer tries and guesses it	

##It demonstrates mostly the use of...
- Conditional statements
- Logical operators
- iostream file functions
- generating random numbers and seeding the random number generator

##I started working on this project...
February 19, 2017
####and created the repo...
February 24, 2017

##This project is compiled with...
GCC compiler

##Some things I'd like to improve are...
- [ ] Implementing an algorithm for the computer to come up with more realistic guesses. The only random number that is actually a "guess" by the computer is the first one generated. 
  
  Since the rules of our guessing game state that the secret number has to be within the range of 1-100, we take the remainder of the randomly generated number divided by 100. 

  This gives us a result of 0-99, which we then add 1 to in order for the result to be within our specified range:

  ```cpp
  int computerGuess = (rand() % 100) + 1;
  ```
  
  From here on out, the computer generates more guesses by evaluating whether the number it had previously generated is greater than or less than the secret number we had initially gave it. 

  If the number the computer had previously generated is too high, we're going to subtract a newly generated number from the previous one. 

  We generate this new number by adding one to the remainder of a randomly generated number divided by the difference of the computers previous guess and the secret number you had entered. 

  ```cpp
  computerGuess -=  ((rand() % (computerGuess - secretNumber)) + 1);
  ```

  We subtract the computers previous guess from secret number to get the "distance" from the computers number to the number it's trying to guess. Although it does end up guessing the secret number pretty quickly, it's technically cheating since it's calculation is dependent on knowing the secret number.

  I'd like to eliminate the dependency on knowing the secret number the user has given and instead calculate the result solely off of the knowledge of it's previous guesses like how another human would do.

  Here is how I implemented the evaluation: 

  ```cpp
  if(tooHigh)
  {
  	computerGuess -=  ((rand() % (computerGuess - secretNumber)) + 1);
  	tooHigh = false;
  }
  else
  {	
    computerGuess += ((rand() % (secretNumber - computerGuess)) + 1);						
  }
  ```
  <br />
- [ ] Modularizing the code.
  
  The functionality of the entire program exists inside the main function. I think that's kind of enough said.
   <br />
- [ ] Commenting on code.
  
  Is there a better system I could adopt in order to create cleaner comments?

##Notes
####February 26th, 2017
  This is simply just a project to help me Develop my skills in C++. I am fairly new to the language and have just started teaching myself again. Any Feedback/critism on what I am doing right/wrong would be greatly appreciated. 

