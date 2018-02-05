Hi, welcome to my version of BlackJack!
I learn't about BlackJack from scratch, and was inspired by https://github.com/Lurfadur/Blackjack
It's a constant Work Under progress, for now!

I haven't done code refactoring and made an iterative game for now.
Missing Implementations : Header Files and Classes!

To compile on Linux,  

Step 1: Open the Terminal
Step 2: cd /../directory/
Step 3: ./runrun.sh


About :
Blackjack, also known as twenty-one, is a comparing card game between usually several players and a dealer, where each player in turn competes against the dealer, but players do not play against each other. It is played with one or more decks of 52 cards, and is the most widely played casino banking game in the world. (Wiki)

Rules:
To know more visit https://www.bicyclecards.com/how-to-play/blackjack/

********************************************

My version of BlackJack implements these following things:

•   Dealer must hit on soft 17
•   Single Deck. The deck is shuffled every 6 rounds.
•   Player is not allowed to split cards.
•   Keep track of win percentage for the player.

Logic: 

START 

>>Creat a Deck and Shuffle the Cards.

>>Deal Cards to Player and Dealer

PLAYER: CARD0 CARD3
DEALER: CARD1 CARD4

PLAYER ==
>> Check for 2 Aces dealt 
	>> Change the first one's Value from 11 to 1
>> Check for a BlackJack dealt 
	>> Directly move to Dealer's block

>> Give and Option to HIT [1] or STAY [2]
	>> HIT 
	    ^	Check for:
	    |		>> 3 cards totalling to BLACKJACK
	    |		>> 3 cards leading to a BUST
	    |			>> Check if there was an ACE
	    |		>> If total was still Under 21
	    |			>> Give an option to HIT
            ------------------------------------------|
	>> STAND -> Move to Dealer's Block

DEALER == 
>> Checks for Total, the dealer has to Automatically HIT.
	>> HIT 
	    ^	Check for:
	    |		>> 3 cards totalling to BLACKJACK
	    |		>> 3 cards leading to a BUST
	    |			>> Check if there was an ACE
	    |		>> If total was still Under 21
	    |			>>  HIT
	    |		>> If the total was == 17 
	    |			>> Check for Soft 17 
	    |				>> HIT   (if Yes)
	    |				>> STAND (if No)			
            ------------------------------------------|

>> Start Comparing for Player and Dealer hand totals.
>> Check who wins!!



