#include <iostream>
#include <iomanip>
#include <math.h>
#include <random>
using namespace std;

int main()
{
    int con=67694252;
    int n,min,o2; int o1=-1;
    cout<<"n="; cin>>n;
    if (n > con || n < 1)     cout << "kolvo elementov vixodit za ramki";
    else {
    int vybor;
    cout<<"vibirayte: samim vvodit ili na random(vvedite 1 ili 2 sootv)"<<endl; cin>>vybor;
    if (vybor!=1 && vybor!=2) cout<<"tak nelzya, plohoi malchik";


    if (vybor==1) {
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
    }


    if (vybor==2){
    double niz,verx;
    cout<<"Vvedite granitsy(niz i verx): "; cin>>niz>>verx;
    if (verx<niz) cout<<"tak nelzya, plohoi malchik";
    else {
    mt19937 gen(0);
    uniform_real_distribution<double> dis(niz, verx);   
    double sum=0,x1;
    cout<<"chislo X dlya novogo massiva="; cin>>x1;
    double* x = new double[n];
    cout<<"Vot perviy massiv "<<endl;
    for (int i=0;i<n;i++)
    {
        x[i]=dis(gen);
        cout<<x[i]<<" ";
        if (i==0) min=i;
        else {if (x[i]<=x[min]) min=i;}
        if (x[i]<0 && o1==-1) o1=i;
        if (x[i]<0) o2=i;
    }
    cout<<endl<<"Nomer min="<<min+1<<endl;
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
    }  
    }
}
return 0;
}