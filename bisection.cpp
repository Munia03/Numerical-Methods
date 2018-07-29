#include<bits/stdc++.h>
using namespace std;

double func(double x)
{
    return exp(x) - 5*x*x;
}

void bisection(double a, double b)
{
    ofstream myfile;
    myfile.open ("error.csv");
    myfile << "This is the error data.\n";

    double epsilon = 0.0001;
    double p, q, r, c,prev_c,error = 0;
    int iteration = 0;
    while((b-a)>epsilon)
    {
        iteration++;
        prev_c = c;
        c = (a + b)/2;
        p = func(a);
        q = func(b);
        r = func(c);
        printf("%.6lf, %.6lf, %.6lf, %.6lf, %.6lf, %.6lf, ",a,b,c,p,q,r);
        if(p*q>0)
            printf("Wrong assumption\n");

        if(r==0)
            printf("root is %lf\n",c);

        if((p*r)<0)
            b = c;
        else if((q*r)<0)
            a = c;
        if(iteration != 1)
        {
            error = abs((c - prev_c)/c);
            printf("%.6lf\n",error);
            myfile << iteration <<";" << error<<"\n";
        }
    }
    printf("root is %lf\n",c);

}


int main()
{
    double a,b;
    scanf("%lf %lf",&a,&b);
    double i = -1;
    ofstream myfile;
    myfile.open ("example.csv");
    myfile << "This is the x Vs F(x).\n";


    while(i<=1)
    {
        double fx = func(i);
        myfile << i <<";"<< fx<<"\n";
        i += 0.1;
    }
    myfile.close();
    bisection(a,b);
}
