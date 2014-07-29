// Pulse Code Modulation program

#include<math.h>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int x[512],z[512],A;
    cout<<"Enter Amplitude:";cin>>A;
  
    float f;

   
    int t=0,T;
    cout<<"Enter time:";cin>>T;
    f=1.0/T;
    for(t=0;t<=T;t++)
    {
        x[t] = A * sin(2 * (22.0/7) * f * t); //sine wave input in sine1.txt
        cout<<x[t]<<"  ";
    }
    cout<<"\n\n";  

    int b,size,m;
    cout<<"Enter No of bits for Quantisation code:";
    cin>>b;
    m=pow(2,b-1);
    size=A/m;
  
    int p,n,k;
    for(t=0;t<=T;t++)
    {
                    if(x[t]>=0){
                    p=0;n=size;
                    for(k=0;k<m;k++)
                    {
                     if(x[t]>=p&&x[t]<=n)
                     {
                             z[t]=k+m;
                break;                
                     }  
            p=n;
                    n=n+size;         
                    }
                  
                    }
                    else
                    {
                        p=-1;n=-size;
                    for(k=0;k<m;k++)
                    {
                     if(x[t]<=p&&x[t]>=n)
                     {
                             z[t]=m-k-1;
                break;                
                     } 
                p=n;
                    n=n-size;          
                    }
                  
                    }
    cout<<" "<<z[t];

    }
  
    cout<<"\n\n";
    long i,rem,j=0,sum=0;
    for(j=0;j<=T;j++)
    {
        i=1;    sum=0;
        do
        {
            rem=z[j]%2;
            sum=sum + (i*rem);
            z[j]=z[j]/2;
            i=i*10;
        }while(z[j]>0);
        cout<<" "<<sum;
    }
    cin.get();
    cout<<"\n";
        return 0;
   
}
