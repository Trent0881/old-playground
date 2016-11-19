#include <stdio.h>
#include <string.h>

main()
{
FILE *file1;
file1 = fopen("out.txt", "w");
    double x = 0.1, y = 0.1;
    int n = 0,i;
    double r;
	double z[8] = {0};
for(r = 1;r<=4; r = r + .001)
{
for(n=0; n<10000;n++)
{
 x = r * (x*(1-x));
 
 for(i = 0; i < 8; i++)
	if (x != z[i])
{		
if(r>=3)
 {
     if (n > 9000)
			{
			printf("%lf,%lf\n",x,z[i]);
			fprintf(file1,"%lf,%lf\n",x,r);
 }
 }
 else
 {
   if (n >= 9999)
   fprintf(file1,"%lf,%lf\n",x,r);

 }
 }
 if (n > 9000)
 z[n - 9992] = x;
}

x = y;

}

fclose( file1);
}