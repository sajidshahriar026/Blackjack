#pragma once

#include<iostream>

enum suits{JOKER,HEARTS,SPADES,CLUBS,DIAMONDS};

//represents cards in a deck
class Card
{
	int suit;
	int number;
public:
	Card();
	Card(int, int);
	int getSuit();
	int getNumber();
	void setSuit(int);
	void setNumber(int);
	friend std::ostream & operator<<(std::ostream&, Card&);

};

