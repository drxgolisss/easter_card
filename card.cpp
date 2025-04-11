#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#include "card.h"
#include "pattern.h"

void card::init(int _m, element el, element* tab)
{
   m = _m;
   t = new element[m * m];
   if(tab != nullptr)
   {
      for(int i = 0; i < m * m; i++)
      {
         t[i] = tab[i];
      }
   }
   else
   {
      for(int i = 0; i < m * m; i++)
      {
         t[i] = el;
      }
   }
}

int card::size() const
{
   return m;
}

card::card(int m, element el)
{
   init(m, el);
}

card::card(const card &k)
{
   m = k.m;
   t = new element[m * m];
   for (int i = 0; i < m * m; i++)
   {
      t[i] = k.t[i];
   }
}

card& card::operator=(const card& c)
{
   if(this != &c)
   {
      if(t != nullptr)
      {
         delete [] t;
      }
      m = c.m;
      t = new element[m * m];
      for(int i = 0; i < m * m; i++)
      {
         t[i] = c.t[i];
      }
   }
   return *this;
}

element card::operator()(int i, int j) const
{
   return t[i * m + j];
}

element& card::operator()(int i, int j)
{
   return t[i * m + j];
}

card& card::operator+=(const pattern& g)
{
   g.paint(*this);
   return *this;
}

void card::egg(element el)
{
   int sx = m / 2;
   int sy = m / 2;
   int r = std::min(sx, sy) - 1;
   
   for(int i = 0; i < m; i++)
   {
      for(int j = 0; j < m; j++)
      {
         if((i - sx) * (i - sx) + (j - sy) * (j - sy) > r * r)
         {
            (*this)(i, j) = el;
         }
      }
   }
}

ostream& operator<<(ostream& out, const card& k)
{
   for(int i = 0; i < k.m; i++)
   {
      for(int j = 0; j < k.m; j++)
      {
         out << k(i, j) << " ";
      }
      out << std::endl;
   }
   return out;
}
