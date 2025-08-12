#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*You are given  triangles, specifically, their sides ai,bi,ci.
Print them in the same style but sorted by their areas from the smallest one to the largest one.
It is guaranteed that all the areas are different.

The best way to calculate a area of a triangle with sides a,b,c  is "Heron's formula".

Input Format:

The first line of each test file contains a single integer n. n lines follow with three space-separated integers ai,bi,ci.

Constraints:

1<=n<=100
1<=ai,bi,ci<=70
ai+bi>ci and bi+ci>ai and ci+ai>bi

Output Format:

Print exactly n lines. On each line print 3 space-separated integers ai,bi,ci of the corresponding triangle.

sample input:

7 24 25
5 12 13
3 4 5

sample output:

3 4 5
5 12 13
7 24 25

*/



// All functions & structures should be above main function


 struct triangle
    {
        int a;
        int b;
        int c;
    };


// function prototypes
int getnumberofTriangles();
void sortTriangles(int n,double triangleArea[], struct triangle tr[]);
double calculateArea(double p,int a,int b,int c);
void printOutput(int n,  struct triangle tr[]);




int main()
{
    int n= getnumberofTriangles();

    struct triangle tr[n];
    double triangleArea[n];
    double p[n];



    if (n<1 || n>100) {printf("\nNumber you entered is not in the range!\n"); return 1;}
    else
    {
        int i;
        for (i=0;i<n;i++)
        {
            printf("\nEnter values for ai,bi and ci for the triangle %d:\n",i+1);
            scanf("%d %d %d", &tr[i].a, &tr[i].b, &tr[i].c);
            if((tr[i].a>=1 && tr[i].a<=70) && (tr[i].b>=1 && tr[i].b<=70) && (tr[i].c>=1 && tr[i].c<=70))
            {
                if((tr[i].a+tr[i].b>tr[i].c) && (tr[i].b+tr[i].c>tr[i].a) && (tr[i].a+tr[i].c>tr[i].b))
                {
                    p[i] = (tr[i].a + tr[i].b + tr[i].c)/2;
                triangleArea[i]= calculateArea(p[i],tr[i].a,tr[i].b,tr[i].c);
                }
                else
                    {printf("Data you entered don't satisfy input conditions!\n"); return 1;}
            }
            else
                {printf("Data you entered is not in the valid range!\n"); return 1;}
        }
            sortTriangles(n, triangleArea, tr);
            // parameters should not  be like tr[] ; it'll mistakenly think we are inputing one element of those arrays

            printOutput(n, tr);
            printf("\nThank you!");
    }

    return 0;
}




int getnumberofTriangles()
{
    int n;

    printf("---Sorting triangles according to their area---\n\n");
    printf("Detail menu:\n\tn- number of triangles\n\tai,bi,ci- lengths of 3 sides the tiangle");
    printf("Input conditions:\n\t1<=n<=100\n\t1<=ai,bi,ci<=70\n\tai+bi>ci and bi+ci>ai and ci+ai>bi");
    printf("\n\nEnter number of triangles:\n");
    scanf("%d", &n);
    return n;
}



double calculateArea(double p,int a,int b,int c)
{
    double triangleArea= sqrt(p*(p-a)*(p-b)*(p-c));  // calculate area of triangles
    return triangleArea;
}



void sortTriangles(int n,double triangleArea[], struct triangle tr[])
{
    int i,j;
    double tmp;
    struct  triangle tmp1;
    for(i=0;i<n-1;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
        if(triangleArea[j]>triangleArea[j+1])
        {
            // Sort the area array
            tmp=triangleArea[j];
            triangleArea[j]=triangleArea[j+1];
            triangleArea[j+1]=tmp;

            // Sort the triangle array
            tmp1=tr[j];
            tr[j]=tr[j+1];
            tr[j+1]=tmp1;
        }
        }
    }
}

void printOutput(int n, struct triangle tr[])
{
    printf("\nSorted triangles by area:\n\n");
            for (int i = 0; i < n; i++)
                {
                    printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);   // print the sorted array of triangles

                }
}




