#include "Deck.h"
#include<algorithm>
#include<ctime>


//populating 52 cards;
Deck::Deck()
{
	for (int i = HEARTS; i <= DIAMONDS; i++)
	{
		for (int j = 1; j < 13; j++)
		{
			this->cards.push_back(Card(i, j));
		}
	}
	//prevent sequence repetition between runs;
	srand(time(NULL));
}

void Deck::deal(Hand &h)
{
	h.addCard(this->cards.back());
	this->cards.pop_back();
}

void Deck::reset()
{
	this->cards.clear();
	for (int i = HEARTS; i <= DIAMONDS; i++)
	{
		for (int j = 1; j < 13; j++)
		{
			this->cards.push_back(Card(i, j));
		}
	}
}

//function passed to random_shuffle
int _shuffle(int i)
{
	return std::rand() % i;
}

void Deck::shuffle()
{
	random_shuffle(this->cards.begin(), this->cards.end(), _shuffle);
}




