#include "history.h"

history:: history(const card& c) : num(1)
{
    h[0] = c;
}

void history:: write(const card& c)
{
    if(num == n)
    {
        for(int i = 1; i < n; i++)
        {
            h[i- 1] = h[i];
        }
        h[n] = c;
    }
    else{
        h[num] = c;
        num++;
    }
}

card history:: undo()
{
   if(num == 1)
   {
      return h[0];
   }

   else{
     for(int i = 0; i < num; i++)
     {
        return h[num - 2];
     }
   }

  return h[0];
}