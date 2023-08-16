#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
  int a,b,s,m,n =0;
  while((cin >>a>>b>>s>>m>>n)&&(a||b||s||m||n)){
    double x,y;
    x=b*n;
    y=a*m;
    double angle = (atan(static_cast<double>(x/y))*180.0)/M_PI;
    double velocity = sqrt(static_cast<double>(x*x+y*y)/(s*s));
    cout << setprecision(2) << fixed;
    cout <<angle << " " << velocity << endl;
  }
}