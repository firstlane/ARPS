# ARPS
Advanced Rock Paper Scissors

Project:      Advanced Rock Paper Scissors
Author:       Conner Hurst

Purpose:      This application is a two player console-based game that expands upon the rules of basic Rock Paper Scissors.
              The purpose of the game is for the two players to play matches of Rock Paper Scissors until one player earns 10 
              points and wins. Points can be earned in multiple ways:
              
              - Winning a match (1 point)
              - Winning matches with the same throw multiple times in a row (+1 point for each consecutive win)
              - Winning matches with each of Rock, Paper, and scissors (+2 points)
              
              An example scenario is shown below to further explain the scoring mechanisms:
              
              Player 1 throws ROCK, Player 2 throws PAPER 
              - Player 2 earns 1 point for winning a match.
              
              Player 1 throws ROCK, Player 2 throws PAPER
              - Player 2 earns 2 points. 1 for winning the match, and +1 for winning with PAPER two times in a row. Winning a
                third consecutive game with PAPER would earn 1+2 points, and so on. If player 2 lost, or won with a different throw,
                it would reset this streak. A tie does not reset the streak.
                
              Player 1 throws PAPER, Player 2 throws ROCK
              - Player 2 earns 1 point for winning a match
              
              Player 1 throws PAPER, Player 2 throws SCISSORS
              - Player 2 earns 3 points. 1 for winning the match, and +2 for now having won with ROCK, PAPER, and SCISSORS at
                least one time each. This bonus can only be earned by each player once per game.
                
              The players can also choose to play in either a timed or untimed game before starting. If 'timed' is selected, players
              can select a number of seconds they will have to make a move. If either player fails to make a move within the time, the
              other player is awarded the match win.
