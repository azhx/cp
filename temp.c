# include <stdio.h>
# include <ctype.h>

FILE * infp;
FILE * outfp;

int  t,             /* number of test cases */
     i,j,           /* indexes in array A  */
     A[50];         /* arrays to store the digits of a number */
char line[61];      /* a character array to store an input line */    

void subtract( int i )
/* subtract A[i] from the number represented by A[0..(i-1)]  */
{
  int j;
  if ( A[i]<=A[i-1] ) A[i-1] = A[i-1] - A[i]; 
  else {
    A[i-1] = A[i-1] - A[i] + 10;
    for ( j=i-2; A[j]==0; j-- )  A[j]=9;
    A[j]--;
  }                      
}

main()
{   
  infp = fopen( "div.in", "r");
  outfp = fopen( "div.out", "w");

  fscanf(infp, "%d\n", &t);
  while (t>0) {

    fgets(line, 60, infp);       /* get number */
    fprintf(outfp,"%s",line);    /* print number once     */

    /* convert from characters to digits */
    for (i=0; isdigit(line[i]); i++ ) A[i]=line[i]-'0';
 
    while ((A[0]!=0 && i>2) || (A[0]==0 && i>3)) {
      i--;
      subtract(i);
      if (A[0]!=0) fprintf(outfp,"%d",A[0]);   /* don't print leading zero */
      for (j=1; j<i; j++) fprintf(outfp,"%d",A[j]);
      fprintf(outfp,"\n");
    }
    
    line[strlen(line)-1]='\0';  /*  remove end-of-line */
    fprintf(outfp, "The number %s ", line);
    if ((A[0]!=0 && ((A[0]*10 + A[1])%11==0)) ||
        (A[0]==0 && ((A[1]*10 + A[2])%11==0)))
      fprintf(outfp,"is divisible by 11.\n");
    else fprintf( outfp, "is not divisible by 11.\n");
    
    t--; fprintf(outfp, "\n");
 }
}