#include<stdio.h>
#include<math.h>

float afunc(float,float,float pol[]);
float dfunc(float,float,float pol[]);
int main()
{
  int x,deg,i,k,m=0;
  float a[10],p,q,b[10];
  float value,app,j;
  double z;

  printf("enter the degree of polynomial ");
  scanf("%d",&deg);

   for( i=deg; i>=0; i--)
    {
        printf("enter coefficient for X^%d term ",i);
        scanf("%f",&a[i]);
    }
   printf("your entered polynomial is \n");
    for( i=deg; i>=0; i--)
    {
        printf(" (%.0f)X^%d",a[i],i);
        if(i==0)
          continue;
        printf(" +");

    }
   printf("\nenter valuue for initial approximation ");
   scanf("%f",&j);
   i=0;

  for(i=0;i<4;i++)
   {

        p=afunc(deg,j,a);
        q=dfunc(deg,j,a);
        z=p/q;
        app= j - z;
        printf("\nthe value after %d approximation is  %f",i+1,app);
        j=app;
        b[m]=j;
        m++;

    }

   printf("\nroot is %0.5lf \t" ,j);
   return 0;

}

  float afunc(float deg, float y,float pol[])
  {
      
      float value=0;
      int i;
      for(i=deg; i>=0; i-- )
       {

          value= value + pol[i]*pow(y,i);
       }

     return value;

  }

  float dfunc(float deg, float y,float pol[])
  {
      float value=0;
      int i;
      for(i=deg; i>=0; i-- )
       {

          value= value + pol[i]*i*pow(y,i-1);
          if(i-1==0)
          break;
       }
     return value;

  }

