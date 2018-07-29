#include<bits/stdc++.h>
using namespace std;

double func(double x)
{
    return x*x*x - 0.165*x*x + 3.993 * pow(10,-4);
}
 double func_deriv(double x)
 {
     return 3*x*x - 0.33*x;
 }


void newton_raphson(double x)
{
    ofstream myfile;
    myfile.open ("error.csv");
    myfile << "This is the error data.\n";

    double epsilon = 0.0001;
    double p, q, r, c,prev_x,error = 100;
    int iteration = 0;
    while(error>epsilon)
    {
        iteration++;
        prev_x = x;

        p = func(x);
        q = func_deriv(x);
        x = prev_x - (p/q);
        printf("%.6lf, %.6lf, %.6lf, ",x,p,q);
        if(iteration == 1)
            puts("");
        if(iteration != 1)
        {
            error = abs((x - prev_x)/x);
            printf("%.6lf\n",error);
            myfile << iteration <<";" << error<<"\n";
        }
    }
    printf("root is %lf\n",x);

}


int main()
{
    double a,b;
    scanf("%lf",&a);
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
    newton_raphson(a);
}

