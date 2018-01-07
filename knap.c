#include<stdio.h>
int main()
{
int i,j,n,bw,temp1,temp2,temp3,itmno[100],weight[100],value[100];
float vbyw[100],x[100],benfit=0,temp4;
printf("\nenter bag capacity");  
scanf("%d",&bw);
printf("\n enter number of items");
scanf("%d",&n);
printf("\nenter item number,weight & value for %d items\n",n);
for(i=0;i<n;i++)
{	
   scanf("%d%d%d",&itmno[i],&weight[i],&value[i]);
vbyw[i]=(float)value[i]/weight[i];
x[i]=0;
}
for(i=0;i<n-1;i++)
	for(j=i+1;j<n;j++)
	{
         if(vbyw[i]<vbyw[j])
	 {
          temp1=weight[i];  temp2=value[i]; temp3=itmno[i]; temp4=vbyw[i];
	  weight[i]=weight[j];  value[i]=value[j]; itmno[i]=itmno[j]; vbyw[i]=vbyw[j];
	  weight[j]=temp1;  value[j]=temp2; itmno[j]=temp3; vbyw[j]=temp4;
	 }
	}
for(i=0;i<n;i++)
{
if(weight[i]>bw)
	break;
else
{
	bw=bw-weight[i];
	x[i]=1.0;
}
}
if(i<n)
{	
x[i]=(float)bw/weight[i];
}
printf("--------------------------------------------\n");
printf("itemno\tweight\t value\t benfit");
printf("\n--------------------------------------------");
for(i=0;i<n;i++)
{
printf("\n");
if(x[i]>0 && x[i]<1)
{	
benfit+=value[i]*x[i];
printf("  %d\t    %d\t   %.2f \t  %.2f",itmno[i],bw,value[i]*x[i],benfit);
}
else if(x[i]==0)
{
benfit+=value[i]*x[i];	
printf("  %d\t    0\t   %.2f \t  %.2f",itmno[i],value[i]*x[i],benfit);
}
else
{
benfit+=value[i]*x[i];
printf("  %d\t    %d\t   %.2f \t  %.2f",itmno[i],weight[i],value[i]*x[i],benfit);
}

}
printf("\n--------------------------------------------");
printf("\n                          Total profit=%.2f",benfit);
printf("\n--------------------------------------------");
printf("%d",bw);
}

