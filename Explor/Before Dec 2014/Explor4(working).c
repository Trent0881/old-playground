#include <stdio.h>
#include <string.h>

main()
{
	FILE * file1;
	file1 = fopen("out.txt", "w");
    double x = 0.1, y = 0.1;
    int n = 0;
    double r;
for(r = 1;r<=3; r = r + .001)
{
for(n=0; n<10000;n++)
{
 x = r * (x*(1-x));
 if(r>=3)
 {
     if (n > 9990)
 fprintf(file1,"%lf,\n",x);
 
 }
 else
 {
   if (n >= 9999)
   fprintf(file1,"%lf\n",x);

 }
}
x = y;
}
fclose( file1);
}