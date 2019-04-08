#pragma once

#include<vector>
#include"Card.h"

class Hand
{
	std::vector<Card>cards;
public:
	void addCard(Card&);				//add a new card to the hand
	bool isBust();					//checks if busted  or not
	int getValue();					//get the current value of hand
	void clear();					//reset  hand
	friend std::ostream & operator<<(std::ostream&, Hand&);
};

