
/*
 * pow10 calculates the power function of base 10
 */

double pow10(p)
   double p;
{
   double q;

   p = floor(p);
   if (p >= 0) {
      for (q = 1; p > 0; --p)
         q = q * 10;
   }
   else {
      p = -p;
      for (q = 1; p > 0; --p)
         q = q / 10;
   }
   return q;
}

