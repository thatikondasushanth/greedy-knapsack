#include<stdio.h>
int main()
{
int i,j,n,temp1,temp2,temp3,d,totpro=0,nos=0,count=0,jobno[100],profit[100],deadline[100],assigslot[100],slot[100];
printf("\n enter number of jobs");
scanf("%d",&n);
printf("\nenter job number,profit & deadlines for %d jobs\n",n);
//saving data to profits and deadline array
for(i=0;i<n;i++)
{	
   scanf("%d%d%d",&jobno[i],&profit[i],&deadline[i]);
   if(deadline[i]>nos)
	   nos=deadline[i];
   assigslot[i]=-1;
}
for(i=0;i<nos;i++)
{
slot[i]=0;
}
//sorting according to profits from higher to lower
for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	{
         if(profit[i]<profit[j])
	 {
          temp1=profit[i];  temp2=deadline[i]; temp3=jobno[i];
	  profit[i]=profit[j];  deadline[i]=deadline[j]; jobno[i]=jobno[j];
	  profit[j]=temp1;  deadline[j]=temp2; jobno[j]=temp3;
	 }
	}
for(i=0;i<n;i++)
{
if(count<nos)
    {
     d=deadline[i]-1;	    
      while(d>=0 && d<=nos)
      {
	if(slot[d]==0)
	{
         assigslot[i]=d;
	 slot[d]=1;
	 count++;
         break;	 
	}
	  d--;	
      }
    }
}
printf("--------------------------------------------\n");
printf("jobno\tassigned slot\t profit\t totalprofit");
printf("\n--------------------------------------------");
for(i=0;i<n;i++)
{
printf("\n");
if(assigslot[i]!=-1)
{
totpro+=profit[i];	
printf("%d\t   %d-%d\t           %d\t      %d",jobno[i],assigslot[i],assigslot[i]+1,profit[i],totpro);
}
else
printf("%d\t  rejected\t   %d\t      %d",jobno[i],profit[i],totpro);
}
printf("\n--------------------------------------------");
printf("\n                          Total profit=%d",totpro);
printf("\n--------------------------------------------");
}

