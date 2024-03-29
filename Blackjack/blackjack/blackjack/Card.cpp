#include "Card.h"
#include<string>


Card::Card()
{
	this->setSuit(JOKER);
	this->setNumber(0);
}

Card::Card(int s, int num)
{
	this->setSuit(s);
	this->setNumber(num);

}
int Card::getSuit()
{
	return this->suit;
}
int Card::getNumber()
{
	return this->number;
}
void Card::setSuit(int s)
{
	this->suit = s;
	return;
}
void Card::setNumber(int num)
{
	this->number = num;
	return;
}

//extra function to convert the number to string
std::string getNameFromNumber(Card c)
{
	int num = c.getNumber();
	std::string ret = "";
	
	if (num > 1 && num < 10)
	{
		ret = std::to_string(num);
	}
	else
	{
		switch (num)
		{
		case 10:
			ret = "Jack";
			break;
		case 11:
			ret = "Queen";
			break;
		case 12:
			ret = "King";
			break;
		case 1:
			ret = "Ace";
			break;
		}

	}

	return ret;

}
//extra function to convert the suit to string

std::string getNameFromSuit(Card c)
{
	int s = c.getSuit();
	std::string ret = "";

	switch (s)
	{
	case HEARTS:
		ret = "Hearts";
		break;
	case SPADES:
		ret = "Spades";
		break;
	case CLUBS:
		ret = "Clubs";
		break;
	case DIAMONDS:
		ret = "Diamonds";
		break;
	}

	return ret;
}

//right shift operator overloading for cout
std::ostream& operator<<(std::ostream &strm, Card& c)
{
	{
		if (!c.getNumber())
		{
			strm << "Joker";
		}
		else
		{
			strm << getNameFromNumber(c) << " of " << getNameFromSuit(c);
		}
		return strm;
	}
}




