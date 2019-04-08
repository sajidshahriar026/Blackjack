#pragma once

#include"Deck.h"

class Game
{
	Deck deck;
	Hand player;
	Hand dealer;

	enum {NOTHING,HIT,STAY,RESTART,QUIT,HELP};

	void printGreeting();
	void printHelp();
	void resetGame();
	int askPlayer();
	void dealerTurn();

public:
	Game();
	void play();
};

