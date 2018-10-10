/*
 * CODE REVISION NUMBER:
 *
 * The part after the first colon, except the last char, appears on the screen.
 */

char *rev = "$Revision: 6.21 alpha5 $";

char *version = " XSpread v2.1   Based on Sc 6.21";

print_help()
{
   printf("Xspread [-h] [-c] [-m] [-n] [-r] [-x] [-fn font] [filename]\n\n");
   printf("         -c:  Column order recalculation.  Default row order.\n");
   printf("         -m:  Manual recalculation.  Default automatic\n");
   printf("         -n:  Standard Data entry mode.  Default numeric\n");
   printf("         -r:  Row order recalculation.  Default row order\n");
   printf("         -x:  File read/write use encryption.  Default off.\n\n");
   printf("        -fn:  Change the font size\n\n");
   printf("         -h:  Command line help \n");
   printf("Options can be changed through ctrl-t toggle commands.\n\n");
} 
