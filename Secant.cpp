#include<bits/stdc++.h>
using namespace std;

double func(double x)
{
    return x*x*x - 0.165*x*x + 3.993 * pow(10,-4);
}


void secant(double x0, double x1)
{
    ofstream myfile;
    myfile.open ("error.csv");
    myfile << "This is the error data.\n";

    double epsilon = 0.0001;
    double x2,p, q, r, c,prev_x,error = 100;
    int iteration = 0;
    while(error>epsilon)
    {
        iteration++;
        cout<<iteration;

        p = func(x0);
        q = func(x1);
        x2 = x1 - ((q*(x1 - x0))/(q - p));
        r = func(x2);
        printf(" %.6lf, %.6lf, %.6lf, %lf, ",x0,x1,x2,r);
        if(iteration == 1)
            puts("");
        if(iteration != 1)
        {
            error = abs((x2 - x1)/x2);
            printf("%.6lf\n",error);
            myfile << iteration <<";" << error<<"\n";
        }
        x0 = x1;
        x1 = x2;
    }
    printf("root is %lf\n",x2);

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
    secant(a,b);
}


