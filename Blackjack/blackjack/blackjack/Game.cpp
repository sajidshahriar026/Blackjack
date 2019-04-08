#include "Game.h"



Game::Game()
{
	this->deck.shuffle();

	//hand two cards to dealer and player
	this->deck.deal(this ->player);
	this->deck.deal(this->dealer);
	this->deck.deal(this->player);
	this->deck.deal(this->dealer);

	//print directions
	this->printGreeting();
	this->printHelp();
}

void Game::printGreeting()
{
	std::cout << "Welcome to Blackjack simulator" << std::endl;
}

void Game::printHelp()
{
	std::cout << "Enter choice: " << std::endl;
	std::cout << "Press [h] to hit" << std::endl;
	std::cout << "Press [s] to stay" << std::endl;
	std::cout << "Press [r] to restart" << std::endl;
	std::cout << "press [q] to quit" << std::endl;
	std::cout << "press [?] to help" << std::endl;

}

int Game::askPlayer()
{
	std::cout << this->player;
	std::cout << "What do you want to do?" << std::endl;

	char cmd ;
	std::cin >> cmd;
	

	switch (cmd)
	{
	case 'h':
		return HIT;
		break;
	case 's':
		return STAY;
	case 'r':
		return RESTART;
		break;
	case 'q':
		return QUIT;
		break;
	case '?':
		return HELP;
		break;
	default:
		std::cout << "Command not recognized" << std::endl;
		return NOTHING;
		break;
	}
}

void Game::dealerTurn()
{
	std::cout << "Conducting dealer turn" << std::endl;
	while (dealer.getValue() < 18)
	{
		deck.deal(this->dealer);
	}
	std::cout << "The dealer hand\n" << this->dealer;
	std::cout << "The value of dealer's hand: " << this->dealer.getValue() << std::endl;

	if (this->dealer.getValue() > 21)
	{
		std::cout << "Dealer bust!!!You've won!!!" << std::endl;

	}
	else if (this->dealer.getValue() == this->player.getValue())
	{
		std::cout << "It's a tie." << std::endl;
	}
	else if(this->dealer.getValue() > this->player.getValue())
	{
		std::cout << "Sorry,You've lost." << std::endl;
	}
	else
	{
		std::cout << "You've won!!!" << std::endl;
	}

	std::cout << "press [q] to quit,any other key to restart." << std::endl;

	char cmd;
	std::cin >> cmd;

	if (cmd == 'q')
	{
		
		std::cout << "Thank you for playing" << std::endl;
		system("pause");
		exit(0);
	}
	
	resetGame();

}

void Game::resetGame()
{
	this->deck.reset();
	this->deck.shuffle();

	this->player.clear();
	this->dealer.clear();

	this->deck.deal(this->player);
	this->deck.deal(this->dealer);
	this->deck.deal(this->player);
	this->deck.deal(this->dealer);

}

int playerBust()
{
	std::cout << "Sorry,you've lost" << std::endl;
	std::cout << "Press [q] to quit,any other key to restart" << std::endl;

	char cmd;
	std::cin >> cmd;
	
	
	if (cmd == 'q')
	{
		return 1;
	}
	return 0;

}

void Game::play()
{
	while (1)
	{
		int choice = askPlayer();

		switch (choice)
		{	
		case HIT:
			std::cout << "You chose to hit on " << this->player.getValue() << std::endl;
			this->deck.deal(this->player);

			if (this->player.isBust())
			{
				std::cout << player;

				if (playerBust())
				{
					std::cout << "Thank you for playing" << std::endl;
					system("pause");
					exit(0);
				}
				else
				{
					resetGame();
				}
			}
			break;
		case STAY:
			std::cout << "You chose to stay on " << this->player.getValue() << std::endl;
			dealerTurn();
			break;
		case RESTART:
			std::cout << "Restarting Game..." << std::endl;
			break;
		case QUIT:
			std::cout << "Thank you for playing" << std::endl;
			system("pause");
			exit(0);
			break;
		case HELP:
			printHelp();
			break;
		}
		std::cout << "\n";
	}
}



