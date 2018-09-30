#include<bits/stdc++.h>
using namespace std;
#define N 10

void display(double mat[N][N], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("  %lf", mat[i][j]);
        printf("\n");
    }
}

void getCofactor(double mat[N][N], double tmp[N][N], int p, int q, int n)
{
    int row = 0, col = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(i!=p && j!=q)
            {
                tmp[row][col++] = mat[i][j];

                if(col==n-1)
                {
                    col = 0;
                    row++;
                }
            }
        }
    }
}


double getDeterminant(double mat[N][N], int n)
{
    double D = 0;

    if(n==1)
    {
        return mat[0][0];

    }

    double tmp[N][N];
    double sign = 1;

    for(int i = 0; i<n; i++)
    {
        getCofactor(mat,tmp,0,i,n);

        D+= (sign*mat[0][i] * getDeterminant(tmp,n-1));

        sign = (-sign);
    }
    return D;
}




int main()
{

    double mat[N][N] = {{2, 3, -1, 1},
                     {4, 1, -3, 11},
                     {3, -2, 5, 21}};
    double mat1[N][N];

    copy(&mat[0][0], &mat[0][0]+N*N,&mat1[0][0]);
    puts("");

    display(mat1,3,3);
    puts("");
    //display(mat,3,4);
    double D = getDeterminant(mat1, 3);
    printf("Determinant of the matrix is D : %lf\n",D);
    puts("");
    copy(&mat[0][0], &mat[0][0]+N*N,&mat1[0][0]);
    for(int i=0;i<3;i++)
    {
        mat1[i][0] = mat[i][3];
    }

    //display(mat1,3,3);
    double Dx = getDeterminant(mat1, 3);
    printf("Determinant of the matrix is Dx : %lf\n",Dx);
    printf("x = %lf",Dx/D);
    puts("");


    copy(&mat[0][0], &mat[0][0]+N*N,&mat1[0][0]);


    for(int i=0;i<3;i++)
    {
        mat1[i][1] = mat[i][3];
    }

    //display(mat1,3,3);
    double Dy = getDeterminant(mat1, 3);
    printf("Determinant of the matrix is Dy : %lf\n",Dy);
    printf("y = %lf",Dy/D);
    puts("");


     copy(&mat[0][0], &mat[0][0]+N*N,&mat1[0][0]);


    for(int i=0;i<3;i++)
    {
        mat1[i][2] = mat[i][3];
    }

    //display(mat1,3,3);
    double Dz = getDeterminant(mat1, 3);
    printf("Determinant of the matrix is Dz : %lf\n",Dz);
    printf("z = %lf",Dz/D);
    puts("");

    return 0;
}
