#Gobblet Mampfer AI


Gobblet Gobblers is a two player game which follows the rules of Tic Tac Toe with some interesting additions. Both players have three different types of tokens to place on the board, small, medium, and large. There is a total of two tokens for each size which results in 6 tokens per player. Each turn the active player can place an unplaced token on the field or relocate an already set token. Tokens canbe placed on top of each other if the token is bigger then the one in place. Covered tokens do not count towards the win condition until the token on top is relocated.

These simple additions to the Tic Tac Toe ruleset create a lot more depth to the game.

The AI provided in this repository is able to play the game and was created on the foundation of Monte Carlo Tree Search. MCTS uses a reinforcment learning tecnique by exploring possible future game states and evaluate them based on random play throughs. Based on these estimations an action is chosen. 

This repository contains a console version of the game Gobblet Gobblers combined with the AI which can play it .