#include "stdInc.h"

double TAN(int deg){
    deg = deg % 180 ;
    if(deg==90) return 10E6;
    else
    if(deg <90) return Tan[deg-1];
    else        deg-=91 ;
    
    return (-Tan[90-deg]);
}
double COS(int deg){
    deg = deg % 180;
    if(deg<=90) return Cos[deg-1];
    else    deg-=90;
    return (-Cos[90-deg]);
    
}

int Atan(double val){
    int i,sign;
    sign=(val<0?-1:1);
    val*=sign;
    
    for(i=89;i>=0 && val<Tan[i];i--);

    i=(val>((Tan[i]+Tan[i+1])/2)?i+1:i);
    return ((i*sign+180)%180);
}

int Acos(double val){
    int i,sign=1;
    
    sign=(val<0?-1:1);
    val*=sign;

    for(i=0;val<Cos[i];i++);

    i=(val>(Cos[i]+Cos[i+1]/2)?i:i+1);  
    return ((i*sign+180)%180);

}
