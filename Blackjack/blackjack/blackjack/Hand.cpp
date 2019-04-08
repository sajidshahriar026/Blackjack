#include "Hand.h"

//pushes new card into the list 
void Hand::addCard(Card &c)
{
	this->cards.push_back(c);
}

//returns the total value of hand 
int Hand::getValue()
{
	int value = 0;
	int aceCount = 0;

	for (Card c : this->cards)
	{
		if (c.getNumber() != 1) //card not an ace
		{
			if (c.getNumber() > 9)
			{
				value += 10;
			}
			else
			{
				value += c.getNumber();
			}
		}
		else
		{
			aceCount++;
		}
		while (aceCount > 1)
		{
			//if there's two aces ,at least one of them must be counted as  1
			//or hand goes over 21
			value++;
			aceCount--;

		}

		if (aceCount)
		{
			if ((value + 11) <= 21)
			{
				value += 11;
			}
			else
			{
				value++;
			}
		}
	
	}
	return value;

}

//check if busted or not
bool Hand::isBust()
{
	if (this->getValue() > 21)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Hand::clear()
{
	this->cards.clear();
}

std::ostream& operator<<(std::ostream &strm, Hand &h)
{
	strm << "Cards in hand:\n";
	//print card;

	if (h.cards.size() > 0)
	{
		for (Card c : h.cards)
		{
			strm << "\t" << c << std::endl;
		}
	}
	else
	{
		strm << "\t" << "Your hand is empty\n";
	}

	return strm;


}