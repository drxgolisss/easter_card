#pragma once
#include "card.h"

class history
{
	static const int n = 3;	//maximum number of cards in history

	card h[n];
	int num;		// 1<=num<=n
					// there is always at least 1 picture left in the history (index 0)

public:
	history(const card& c);	// right at the beginning we enter the current picture in the history (index 0)

	void write(const card& c);	// 
	
	card undo();		// if we only have 1 card in the history (num == 1), we return it
						// otherwise we return one before last
						// (there is always at least 1 picture left in the history)

};