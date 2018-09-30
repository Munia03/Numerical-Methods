#include<bits/stdc++.h>
using namespace std;
#define N 5

void print_matrix(double mat[N][N], double identity[N][N],int n)
{
    for (int i=0; i<n; i++, printf("\n"))
    {
        for (int j=0; j<n; j++)
            printf("%0.2lf ", mat[i][j]);

        printf("   |   ");
        for (int j=0; j<n; j++)
            printf("%0.2lf ", identity[i][j]);
    }

    printf("\n");
}

void swap_rows(double mat[N][N],double identity[N][N], int i, int j,int n)
{

    for (int k=0; k<n; k++)
    {
        double temp = mat[i][k];
        mat[i][k] = mat[j][k];
        mat[j][k] = temp;

        double temp1 = identity[i][k];
        identity[i][k] = identity[j][k];
        identity[j][k] = temp1;
    }
    print_matrix(mat,identity,n);
}



void elementaryRowOperation(double mat[N][N], double identity[N][N],int n)
{
    for(int i = 0; i<n; i++)
    {
        //find maximum value
        double v_max = mat[i][i];
        double i_max = i;
        for(int j = i+1; j<n; j++)
        {
            if(v_max< mat[j][i])
            {
                v_max = mat[j][i];
                i_max = j;
            }
        }
        //swap rows
        if(i_max != i)
        {
            swap_rows(mat,identity,i,i_max,n);
        }
        //division by mat[i][i];
        double d = mat[i][i];
        for(int j = 0; j<n; j++)
        {
            mat[i][j] /= d;
            identity[i][j] /= d;
        }
        //lower triangular to zero
        for(int j = i+1; j<n; j++)
        {
            double a = mat[j][i];
            for(int k = 0; k<n; k++)
            {
                mat[j][k] = (mat[j][k]) - (mat[i][k]*a);
                identity[j][k] = (identity[j][k] ) - (identity[i][k]*a) ;
            }
        }

    print_matrix(mat,identity,n);
    }

    //upper triangular to zero
    for(int i = n-1; i>0; i--)
    {

        for(int j = i-1; j>=0; j--)
        {
            double a = mat[j][i];
            for(int k = 0; k<n; k++)
            {
                mat[j][k] = (mat[j][k]) - (mat[i][k]*a);
                identity[j][k] = (identity[j][k]) - (identity[i][k]*a) ;
            }
        }
        print_matrix(mat,identity,n);
    }
}

int main()
{
    double mat[N][N] = {{3, 0, 2},
        {2, 0, -2},
        {0, 1, 1}
    };

    double identity[N][N] = {{1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    elementaryRowOperation(mat,identity,3);
    return 0;
}
