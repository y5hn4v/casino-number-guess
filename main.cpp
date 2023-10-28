/*
   A number guess game where the user can bet a certain amount of money and choose a number
   A random number is generated and if it matches the user's choice,the user gets twice the bet money,else they loose it all
   The user starts with a fixed amount of money and can play till its zero
 */


#include<iostream>
#include<cstdlib>
#include<ctime>


int game(int bet_amount) {
	int user_guess{};

	//Generating the random number
	std::srand(std::time(0));
	int random_number = std::rand() % 15 + 1;

	//Using a loop to check if the guess is meeting the conditions.(Loops are used to enable restarts)
	while (true) {
		std::cout << "Please enter your guess ( Between 0 and 16) : ";
		std::cin >> user_guess;
		if (user_guess < 1 && user_guess>15) {
			std::cout << "Please enter your guess between 0 and 16 ";
			continue;
		}
		else break;
	}
    
	//Winning condition
	if (random_number == user_guess) {
		std::cout << "You have guessed it right!!!! \n";
		std::cout << "You have won " << bet_amount + bet_amount;
		return(bet_amount+bet_amount);
	}
	else {
		std::cout << "Oops! Wrong guess \n";
		std::cout << "You have lost the bet amount of " << bet_amount;
		return 0;
	}
}



int main() {
	int user_money{ 1 };

	//Using a loop to check if the money is meeting the conditions.(Loops are used to enable restarts)
	while (true) {
		std::cout << "Welcome to Number Guess \n";
		std::cout << "Please enter your starting money (should be less than 1000): \n";
		std::cin >> user_money;
		if (user_money > 1000) {
			std::cout << "Please enter the money below 1000 \n";
			continue;
		}
		else break;
	}


	while (user_money > 0) {
		int bet_amount{};
		std::cout << "Please enter a betting amount: ";
		std::cin >> bet_amount;
		if (bet_amount > user_money) {
			std::cout << "Bet amount can't be bigger than your current balance of : " << user_money;
			std::cout << std::endl;
			continue;
		}
		else {
			user_money -= bet_amount;
			bet_amount = game(bet_amount);
			user_money += bet_amount;
			std::cout << "\nYou have a balance of " << user_money << " left\n";
			std::cout << "\nPress y if you wish to continue..else press n";
			char c{};
			std::cin >> c;
			if (c == 'y') {
				if (user_money <= 0) {
					std::cout << "\nYou do not have enough balance to continue.Please restart\n";
					break;
				}
				else {
					continue;
				}
			}
			else break;
		}
	}
	return 0;
}
