# Class Design

## Dice Class:
###Data: 
####sides
####current_value
###Actions: 
####roll(): rolls the dice
####get_value(): get the number of the number the dice got
###Relationships: 
####Dice will be used by the Player to roll during the game
##Player Class:
###Data: 
####name
####score
####dice_set: Array of Dice objects
####player_stats: Statistics of the player in question
###Actions:
####roll_dice(): rolls the dice for the player
####get_score(): the number that the player got 
####update_score(): Adds the numbers
###Relationships: Each player has a set of dice and participate in the game
##Game Class:
###Data: 
####players
####rules
####Current_round: Displays the round they are in
###Actions: 
####start_game(): starts game
####end_game(): ends game
####get_winner(): displays the winner
###Relationships: 
####The Game class controls the players and their actions
##Knucklebones Class: 
###Data: 
####board
####knuclebones_specific_rules: rules of the game
###Actions: 
####start_round(): starts the round
####end_round(): ends the round
####calculate_winner(): calculates each score and gets the winner out of it
###Relationships: Inherits from Game, as Knucklebones is a game with specific rules and conditions
##Chat Class:
###Data: 
####User
####Text
###Actions:
####Commands(): highlight text, respond to other users
####Enter(): Enter chat
###Relationship:
####Inherits from player
