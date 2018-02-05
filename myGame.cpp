#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<unistd.h>

using namespace std;

class Card{
public:
	int card_index;
	int card;
	char suit;
	int value;
};


//Spades
//Clubs
//Hearts
//Diamonds
#define BLACKJACK 21

int main(){
	Card deck[52];
	int randCard[52] = {NULL};
	Card player[14];
	Card dealer[14];
	srand(time(0));
	int gameCounter = 6;
	double playerBank = 100;
	int winRatio = 0;
	int gameNumber = 0;
	int cardCounter = 0;
	int playerTotal = 0;
	int dealerTotal = 0;
	double placeBet = 0;
	bool playerWinsEh = false;
	bool playerBust = false;
	bool dealerBust = false;
	int choice = 0;
	int wins = 0;
	
	for(int i=0; i<4; i++){
		for(int q=0; q <13 ; q++){
			deck[(i*13) + q].card_index = ((i*13) + (q+1));
			randCard[(i*13) + q] = deck[(i*13) + q].card_index;
			deck[(i*13) + q].card = (q+1);
			if(q == 0){
				deck[(i*13) + q].value = 11;
			}
			else if(q>=10){
				deck[(i*13) + q].value = 10;
			}
			else{
				deck[(i*13) + q].value = q+1;
			}
			if(q < 12){
				cout<<deck[(i*13) + q].card_index<<" "<<deck[(i*13) + q].card<<" "<<deck[(i*13) + q].value<<" "<< "RANDOM:"<<randCard[(i*13) + q]<<"\n";
			}
			else cout<<deck[(i*13)+q].card_index<<" "<<deck[(i*13)+q].card<<" "<<deck[(i*13) + q].value<<" "<<"RANDOM:"<<randCard[(i*13) + q]<<"\n\n\n***\n";
		}
	}
//	cout<<deck[51].card<<deck[51].card_index;
	for (int i = 0; i<52; i++){
		int r = rand() % 52;
		int temp = randCard[i]; randCard[i] = randCard[r]; randCard[r] = temp;
	}
	for (int q = 0; q < 52; q++){
		cout<<randCard[q]<<" * "<<deck[randCard[q] - 1].card<<" * "<<deck[randCard[q]-1].value<<"\n";
	}
	cout<<deck[randCard[0]].card<<" * "<<deck[randCard[0]].card_index<<" * "<<deck[randCard[0]].value<<"\n";
	cout<<"It's a Miracle, Let's Play? ";
	char playGame = ' ';
	cin >> playGame;
	cin.ignore(1000,'\n');
	while ( playGame == 'y' || playGame == 'Y'){
		int playerCardCounter = 0;
		int dealerCardCounter = 0;
		cout<<"Place your Bet... : ";
		cin>>placeBet;
		cin.ignore(1000,'\n');
		playerBank -= placeBet;
		gameNumber++;
		cout<<"Game Number : "<<gameNumber<<" "<<"\n";
		gameCounter--;
		if (gameCounter == 0) {
			cout<<"Shuffling Cards..."<<"\n";
			for (int i = 0; i<52; i++){
				int r = rand() % 52;
				int temp = randCard[i]; randCard[i] = randCard[r]; randCard[r] = temp;
			}
		}
		player[0] = deck[randCard[cardCounter]-1];
		cardCounter++;
		dealer[0] = deck[randCard[cardCounter]-1];
		cardCounter++;
		player[1] = deck[randCard[cardCounter]-1];
		cardCounter++;
		dealer[1] = deck[randCard[cardCounter]-1];
		cardCounter++;
		playerCardCounter += 2;
		dealerCardCounter += 2;
		// player[0] = deck[8];
		// dealer[0] = deck[3];
		// player[1] = deck[1];
		// dealer[1] = deck[4];
		cout << "DEALER: " <<dealer[0].card << " " << "?"<<"\n";
		cout << "PLAYER:";
		for (int i = 0; i < playerCardCounter;i++){
			cout << " " << player[i].card ;
		}
		playerTotal	= player[0].value + player[1].value;
		cout <<"\n";
		cout <<"PLAYER: "<< player[0].value << " " << player[1].value<<"\n";
		cout <<"DEALER: "<< dealer[0].value << " " << dealer[1].value<<"\n";
		if (playerTotal == BLACKJACK){
			cout << "It's a BLACKJACK! : "<< playerTotal << "\n";
		}
		else{
			if(player[0].value == 11 && player[1].value == 11) {
				player[0].value = 1;
				playerTotal -= 10;
				cout << "PASSED" << playerTotal<<'\n';
				cout << "DEALER" <<dealer[0].card << " " << "?"<<"\n";
				cout << "PLAYER:";
				for (int i = 0; i < playerCardCounter;i++){
					cout << " " << player[i].card ;
				}
				cout <<"\n";
			}
			int choice;
			cout << "HIT : 1" <<'\t'<< "STAND : 2" <<"\n";
			cin >> choice;
			cin.ignore(1000,'\n');
			while ( choice == 1 ){
				player[playerCardCounter++] = deck[randCard[cardCounter++]-1];
				cout << "DEALER: " <<dealer[0].card << " " << "?"<<"\n";
				cout << "PLAYER:";
				for (int i = 0; i < playerCardCounter;i++){
					cout << " " << player[i].card ;
				}
				cout <<"\n";
				// player[playerCardCounter++] = deck[0];
				playerTotal += player[playerCardCounter - 1].value;
				cout << "Player Total " << playerTotal << '\n';
				if (playerTotal == BLACKJACK){
					cout << "It's a BLACKJACK! : "<< playerTotal << "\n";
					break;
				}
				else if (playerTotal > 21){
					for(int i = 0; i < playerCardCounter; i++){
						if(player[i].value == 11){
							cout<<playerTotal<<" "<< player[i].card <<" "<<player[i].value<<"\n";
							player[i].value = 1;
							playerTotal -= 10;
							cout<<"UPDATED!" <<playerTotal<<" "<< player[i].card <<" "<<player[i].value<<"\n";
							cout << "DEALER" <<dealer[0].card << " " << "?"<<"\n";
							cout << "PLAYER:";
							for (int i = 0; i < playerCardCounter;i++){
								cout << " " << player[i].card ;
							}
							cout <<"\n";
							break;
						}
					}
					if (playerTotal == BLACKJACK){
						cout << "It's a BLACKJACK! : "<< playerTotal << "\n";
						cout << "DEALER" <<dealer[0].card << " " << "?"<<"\n";
						cout << "PLAYER:";
						for (int i = 0; i < playerCardCounter;i++){
							cout << " " << player[i].card ;
						}
						cout <<"\n";
						break;
					}
					else if (playerTotal > 21){
						cout<< "BUST : " << playerTotal << "\n";
						cout << "DEALER" <<dealer[0].card << " " << "?"<<"\n";
						cout << "PLAYER:";
						for (int i = 0; i < playerCardCounter;i++){
							cout << " " << player[i].card ;
						}
						cout <<"\n";
						playerBust = true;
						break;
					}
					else{
						cout << "HIT : 1" <<'\t'<< "STAND : 2" <<"\n";
						cin >> choice;
						cin.ignore(1000,'\n');
					}
				}
				else{
					cout << "HIT : 1" <<'\t'<< "STAND : 2" <<"\n";
					cin >> choice;
					cin.ignore(1000,'\n');
				}
			}
		}

		// Dealer Block

		if (!playerBust || choice == 2){
			dealerTotal	= dealer[0].value + dealer[1].value;
			cout << "DEALER:";
			for (int i = 0; i < dealerCardCounter;i++){
				cout << " " << dealer[i].card ;
			}
			cout <<"\n";
			cout << "PLAYER:";
			for (int i = 0; i < playerCardCounter;i++){
				cout << " " << player[i].card ;
			}
			cout <<"\n";
			cout << "Dealer Total" << dealerTotal<<'\n';
			// cout << dealer[0].value << " " << dealer[1].value<<"\n";
			// cout << dealer[0].card << " " << dealer[1].card<<"\n";
			if (dealerTotal == BLACKJACK){
				cout << "Dealer has a BLACKJACK! : "<< dealerTotal << "\n";
				cout << "DEALER:";
				for (int i = 0; i < dealerCardCounter;i++){
					cout << " " << dealer[i].card ;
				}
				cout <<"\n";
				cout << "PLAYER:";
				for (int i = 0; i < playerCardCounter;i++){
					cout << " " << player[i].card ;
				}
				cout <<"\n";
			}
			else if (dealerTotal > 17){
				if(dealer[0].value == 11 && dealer[1].value == 11){
					cout<<"2 Aces : Value of 1st one is now 1"<<"\n";
					dealer[0].value = 1;
					dealerTotal -= 10;
					cout << "PASSED " << dealerTotal<<'\n';
					cout << "DEALER: ";
					for (int i = 0; i < dealerCardCounter;i++){
						cout << " " << dealer[i].card ;
					}
					cout <<"\n";
					cout << "PLAYER:";
					for (int i = 0; i < playerCardCounter;i++){
						cout << " " << player[i].card ;
					}
					cout <<"\n";
				}
			while (1){
				usleep(500000);
				cout << "Dealer Total " << dealerTotal << '\n';
				cout << "DEALER:";
				for (int i = 0; i < dealerCardCounter;i++){
					cout << " " << dealer[i].card ;
				}
				cout <<"\n";
				cout << "PLAYER:";
				for (int i = 0; i < playerCardCounter;i++){
					cout << " " << player[i].card ;
				}
				cout <<"\n";
				if (dealerTotal == BLACKJACK){
					cout << "Dealer has a BLACKJACK! : "<< dealerTotal << "\n";
					cout << "DEALER:";
					for (int i = 0; i < dealerCardCounter;i++){
						cout << " " << dealer[i].card ;
					}
					cout <<"\n";
					cout << "PLAYER:";
					for (int i = 0; i < playerCardCounter;i++){
						cout << " " << player[i].card ;
					}
					cout <<"\n";
					break;
				}
				else if (dealerTotal > 21 && dealerTotal == 17){
					for(int i = 0; i < dealerCardCounter; i++){
						if(dealer[i].value == 11){
							cout<<dealerTotal<<" "<< dealer[i].card <<" "<<dealer[i].value<<"\n";
							cout<<"Checking for Aces";
							dealer[i].value = 1;
							dealerTotal -= 10;
							cout<<"UPDATED!"<<dealerTotal<<" "<< dealer[i].card <<" "<<dealer[i].value<<"\n";
							cout << "DEALER:";
							for (int i = 0; i < dealerCardCounter;i++){
								cout << " " << dealer[i].card ;
							}
							cout <<"\n";
							cout << "PLAYER:";
							for (int i = 0; i < playerCardCounter;i++){
								cout << " " << player[i].card ;
							}
							cout <<"\n";
							break;
						}
					}
					if (dealerTotal == BLACKJACK){
						cout << "Dealer has a BLACKJACK! : "<< dealerTotal << "\n";
						cout << "DEALER:";
						for (int i = 0; i < dealerCardCounter;i++){
							cout << " " << dealer[i].card ;
						}
						cout <<"\n";
						cout << "PLAYER:";
						for (int i = 0; i < playerCardCounter;i++){
							cout << " " << player[i].card ;
						}
						cout <<"\n";
						break;
					}
					else if (dealerTotal > 21){
						cout<< "BUST : " << dealerTotal << "\n";
						cout << "DEALER:";
						for (int i = 0; i < dealerCardCounter;i++){
							cout << " " << dealer[i].card ;
						}
						cout <<"\n";
						cout << "PLAYER:";
						for (int i = 0; i < playerCardCounter;i++){
							cout << " " << player[i].card ;
						}
						cout <<"\n";
						dealerBust = true;
						playerWinsEh = true;
						break;
					}
					else if (dealerTotal == 17){
						cout<< "Looks Like a Hard 17 for the Dealer! "<<"\n";
						cout << "DEALER:";
						for (int i = 0; i < dealerCardCounter;i++){
							cout << " " << dealer[i].card ;
						}
						cout <<"\n";
						cout << "PLAYER:";
						for (int i = 0; i < playerCardCounter;i++){
							cout << " " << player[i].card ;
						}
						cout <<"\n";
						//playerWinsEh = true;
						break;
					}
					else if (dealerTotal == 7){
						cout<<"Had a Soft 17, gotta Hit Again! "<<"\n";
						cout << "DEALER:";
						for (int i = 0; i < dealerCardCounter;i++){
							cout << " " << dealer[i].card ;
						}
						cout <<"\n";
						cout << "PLAYER:";
						for (int i = 0; i < playerCardCounter;i++){
							cout << " " << player[i].card ;
						}
						cout <<"\n";
					}
					else cout<<"ERROR 1"<<"\n";
				}
				else if (dealerTotal > 17 || dealerTotal < 21){
					cout<<"Dealer Total : "<<dealerTotal<<"\n";
					cout << "DEALER:";
					for (int i = 0; i < dealerCardCounter;i++){
						cout << " " << dealer[i].card ;
					}
					cout <<"\n";
					cout << "PLAYER:";
					for (int i = 0; i < playerCardCounter;i++){
						cout << " " << player[i].card ;
					}
					cout <<"\n";
					break;
				}
				else if (dealerTotal == 17){
					cout<<"Dealer Total : "<<dealerTotal<<"\n";
					cout << "DEALER:";
					for (int i = 0; i < dealerCardCounter;i++){
						cout << " " << dealer[i].card ;
					}
					cout <<"\n";
					cout << "PLAYER:";
					for (int i = 0; i < playerCardCounter;i++){
						cout << " " << player[i].card ;
					}
					cout <<"\n";
					playerWinsEh = true;
					break;
				}
				else if (dealerTotal < 17){
					cout << "Dealer says: Gotta Hit Again! " << '\n';
					cout << "DEALER:";
					for (int i = 0; i < dealerCardCounter;i++){
						cout << " " << dealer[i].card ;
					}
					cout <<"\n";
					cout << "PLAYER:";
					for (int i = 0; i < playerCardCounter;i++){
						cout << " " << player[i].card ;
					}
					cout <<"\n";
				}
				else cout<<dealerTotal<<" : ERROR 2"<<"\n";
				dealer[dealerCardCounter++] = deck[randCard[cardCounter++]-1];
				// dealer[dealerCardCounter++] = deck[0];
				dealerTotal += dealer[dealerCardCounter - 1].value;
			}
		}
		if (!playerWinsEh){
			if (playerTotal > dealerTotal && !playerBust){
				if (playerTotal != 21){
					playerBank += placeBet;
					cout<<"Regualar Win! Bank: "<<playerBank<<"\n";
				}
				else {
					playerBank += ((1.5)*placeBet);
					cout<<"BLACKJACK WIN! Bank: "<<playerBank<<"\n";
				}
			}
			else if (playerTotal == dealerTotal && !playerBust){
				playerBank += placeBet;
				cout<<"It's a PUSH! Bank: "<<playerBank<<"\n";
			}
			else if (playerBust){
				cout<<"YOU LOSE!"<<"\n";
			}
			else if (dealerBust){
				playerBank += placeBet;
				cout<<"YOU WIN!"<<"\n";
			}
			else {cout<<"YOU * LOSE!"<<"\n";}
		}
	}
		cout<<"Do you want to Play Again? ";
		cin >> playGame;
		cin.ignore(1000,'\n');
	}
	return 0;
}
