#pragma once

#include<vector>
#include<algorithm>
#include"Card.h"
#include"Hand.h"

class Deck
{
	std::vector<Card> cards;
public:
	Deck();						//populates 52 cards
	void shuffle();				//shuffle those cards
	void reset();				//clear and rehuffle cards
	void deal(Hand&);			//deals cards

};

