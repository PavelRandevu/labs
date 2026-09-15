#include <iostream> //у меня 4 вариант
#include <cmath>
#include <iomanip>
using namespace std;
int main ()
{
    double a=0,x;
    int k;
    double sl;
    cout<<"k="; cin>>k;
    cout<<"x="; cin>>x;
    for (int i=1;i>-1;i++)
    {
        sl=pow(x,i)/i;
        a=a-sl;
        if (abs(sl)<pow(10,-k)) i=-5;
    }
    cout<<"ln(1-x)="<< fixed << setprecision(k) << a << endl;
    return 0;
}