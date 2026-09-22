#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
    int n,min,o2; int o1=-1;
    cout<<"n="; cin>>n;
    double sum=0,x1;
    cout<<"chislo X dlya novogo massiva="; cin>>x1;
    double* x = new double[n];
    cout<<"VVedite elementy massiva "<<endl;
    for (int i=0;i<n;i++)
    {
        cin>>x[i];
        if (i==0) min=i;
        else {if (x[i]<=x[min]) min=i;}
        if (x[i]<0 && o1==-1) o1=i;
        if (x[i]<0) o2=i;
    }
    cout<<"Nomer min="<<min+1<<endl;
    if (o1==-1) cout<<"otricatelnih net"<<endl;
    else {
    if (o1==o2) cout<<"otricatelnoe odno pod nomerom "<<o1+1<<" i ravno "<<x[o1]<<endl;
    else {    
    for (int i=o1+1; i<o2;i++)
    sum+=x[i];
    cout<<"summa vkluchaya kraynie="<<sum+x[o1]+x[o2]<<endl;
    cout<<"summa ne vkluchaya kraynie="<<sum<<endl;
    }
    }
    cout<<"Noviy massiv:"<<endl;
    for (int i=0; i<n;i++) if (abs(x[i])<=x1) cout<<x[i]<<" ";
    for (int i=0; i<n;i++) if (abs(x[i])>x1) cout<<x[i]<<" ";  
    return 0;
}