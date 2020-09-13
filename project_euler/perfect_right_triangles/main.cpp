#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

bool isSquare(float n)
{
    return fmod(sqrt(n),1)==0 ? true : false;
}

bool notDivisable(int square)
{
    // Perfect numbers
    int m = 6;
    int n = 28;

    if(fmod(square,m)==0 && fmod(square,n)==0) { return false; }
    return true;
}

bool isRightTriangle(int a, int b, int c)
{
    int leftSide = pow(a,2) + pow(b,2);
    int rightSide = pow(c,2);

    return (leftSide-rightSide)==0 ? true : false;
}

bool notSuperPerfect(int a, int b)
{
    float square = 0.5*a*b;

    if(isSquare(square))
    {
        if(notDivisable(square)) { return true; }
    }  
    return false;
}

int *findAB(int c)
{
    int x=1;
    static int arr[2];
    for(;sqrt(24*x+pow(c,2))<pow(c,2); x++)
    {
        float expr = sqrt(24*x+pow(c,2));
        if(fmod(expr,1)==0) // expr must be an integer
        {
            int a = expr - c;
            for(;a<c;a++)
            {
                if(fmod(a,3)==0) // a is divisible for 3
                {
                    int b = expr - a;
                    if(isRightTriangle(a,b,c)) 
                    {
                        arr[0] = a;
                        arr[1] = b;
                        return arr;
                    }
                }

            }
        }
    }
    return NULL;
}

int main()
{
    // Declare Varibales
    int q, i=0, n=1;
    int count=0;
    vector<int> queries;

    cin >> q;
    for(;i<q;i++)
    {
        int testCase;
        cin >> testCase;
        queries.push_back(testCase);
    }

    for(int x: queries)
    {
        for(;4*n+1<=q; n++)
        {
            int c = 4*n+1;
            if(isSquare(c)) 
            {
                int *p;
                p = findAB(c);
                if(p!=NULL) 
                {
                    int a = *(p+0);
                    int b = *(p+1);
    
                    if(notSuperPerfect(a,b)) { count++; }
                }
            }
        }
    
        cout << count << endl;
    }

    return 0;
}