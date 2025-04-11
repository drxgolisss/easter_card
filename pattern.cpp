#include "pattern.h"
#include "card.h"

pattern :: pattern(int _sx, element _el): sx(_sx), el(_el)
{
}

void pattern:: paint(card &c) const
{
   int size = c.size();
   for(int i = 0; i < size; i += 2)
   {
      c(sx, i) = el;
   }
}