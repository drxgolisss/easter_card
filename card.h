#pragma once
using namespace std;
#include "element.h"

class pattern;

class card 
{
	element*	t;		// a dynamic m * m array representing a square array 
	int	m;				// array dimension (i.e. the number of rows or the number of columns - are equal)

	void init(int _m, element el, element* tab=nullptr);		
	
public:
	card():t(nullptr),m(0){}

	card(int m, element el= element(9));	// dark green
	card(const card& k);

	card& operator=(const card& c);

	~card(){ delete [] t; }

	int size() const; // retruns the size of the card array

	element  operator()(int i,int j) const;	// provides an array element with localization (i, j)
	element& operator()(int i,int j);

	card& operator+=( const pattern& g);

	void egg(element el=element()); //everything except the egg is painted over with the background color (black by default)

	friend ostream& operator<<(ostream& out, const card& k);
													
};