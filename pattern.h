#pragma once
#include "element.h"


class card;


class pattern	
{	
	int sx;			// coordinate of the pattern (0<=sx<m)
	element el;		// element used to draw the pattern

public:
	pattern(int sx, element el);
		
	void paint(card& c) const;	// "draws" a line pattern in the card table
};
