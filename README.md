#Gobblet Mampfer AI


Gobblet Gobblers is a two player game which follows the rules of Tic Tac Toe with some interesting additions. Both players have three different types of tokens to place on the board, small, medium, and large. There is a total of two tokens for each size which results in 6 tokens per player. Each turn the active player can place an unplaced token on the field or relocate an already set token. Tokens canbe placed on top of each other if the token is bigger then the one in place. Covered tokens do not count towards the win condition until the token on top is relocated.

These simple additions to the Tic Tac Toe ruleset create a lot more depth to the game.

The AI provided in this repository is able to play the game and was created on the foundation of Monte Carlo Tree Search. MCTS uses a reinforcment learning tecnique by exploring possible future game states and evaluate them based on random play throughs. Based on these estimations an action is chosen. 

This repository contains a console version of the game Gobblet Gobblers combined with the AI which can play it .

How to play

Runde: 3

1|2|0

1|2|0

---------

---------

-3 | 0 | 0

---------

0 | 3 | 0

---------

3 | 0 | 0

---------

---------

-1|-2|-3

-1|-2|0

Stone :42

Place :13

This is the game field printed to console. The human player can perform an action by typing the coordinates to the console. The first input possibility, "Stone :", takes the coordinates which select the gamepiece the human player wants to move. The next input line, "Place :", also takes coordinates but this time the coordinates of the position where the previously selected gamepiece should go. After each input the player has to press the enter key to confirm the chosen coordinates.

The way the coordinates needs to be inputed into the console is as follows: The first number is the number of the corresponding row. The second number is the one which describes the collumn. The correspondence of rows are 1 2 3 for the game field and 4 and 5 for the unplayed gamepieces collumns are 1 2 3 from left to right, top to bottom for the field coordinates. If those coordinates do not exist in the context of the game or the described move is not legal in terms of game rules the programm will ask again for an input. The programm is resisten to non integer inputs. To cancel the programm the human player can at any point use the keyboard interruption ctrl + c or type 'QUIT' in the coordinate input.
