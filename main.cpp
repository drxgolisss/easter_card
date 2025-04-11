#include <iostream>
using namespace std;
#include <time.h>
#include "card.h"
#include "history.h"
#include "pattern.h"

const int M=50;		// card size MxM

int main()
{
	
	// ------------------ PART 1 ------------------
	
	{
		card k1, k2(M);
		card k3(k2);

		k1=k3;

		cout<<"k1:"<<endl<<k1<<endl;
		cout<<"k2:"<<endl<<k2<<endl;
		
		k3(0,0)=element(14);
		k3.egg();
		cout<<"k3:"<<k3.size()<<endl<<k3<<endl;

		for (int i=0;i<M/10;i++) // yellow patterns
		{
			int sx=rand()%M;
			k3 += pattern(sx, element(14));
			//k3.dodaj(szlaczek(sx,element(14)));
		}
		k3.egg();
		cout<<"k3:"<<endl<<k3<<endl;



	}
	
	// ------------------ ETAP2  - history ------------------------

	int pattern_color = 14;	// yellow
	srand((unsigned)time(NULL));
	
	card p(M), empty(p);
	p.egg();
	history	h(p);
	
	int	k;
	
	do  {
				cout<<p;	//zobaczmy obrazek

                cout<<"\nMENU:"<<endl;
				cout<<"1 - PATTERN"<<endl;
				cout<<"2 - EGG"<<endl;
                cout<<"3 - UNDO"<<endl;
                cout<<"0 - END"<<endl;
                cout<<"Enter option:"<<endl;
                
				cin>>k;
                switch (k)
                {
					case 1:
						{
							for (int i=0;i<M/10;i++) // some patterns
								p+=pattern(rand()%M,element(pattern_color));
							
							//8-szary,9-niebieski,10-zielony,11-trukusowy,12-czerwony,13-fioletowy,14-��ty
							pattern_color--;
							if (pattern_color < 8) pattern_color = 14;

							p.egg();
							h.write(p);
						}
						
						break;
                   
					case 2: // onece again starting from empty egg
						p = empty;
						p.egg();
						h.write(p);
						pattern_color = 14;
						break;

                    case 3:
						p=h.undo();
                        break;

                }//switch

                
            } while (k != 0);
			
	
	return 0;
}
			