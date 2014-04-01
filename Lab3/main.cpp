//
//  main.cpp
//  Lab3
//
//  Created by Vladislav Babkin on 3/26/14.
//  Copyright (c) 2014 noorg. All rights reserved.
//

#include <iostream>
#import <time.h>
#import <cstdlib>
#import <math.h>
using namespace std;

long long ssC = 0, ssM = 0;
void shellsort(int* a, int n)
{
    int h, i, j, k;
    for(h = n; h/=2; )
        for(i = h; i<n; ++i)
        {
            k = a[i];

            for(j = i; j>=h && k < a[j-h]; j-=h)
            {
                a[j] = a[j-h];
                ++ssM;
                ++ssC;
            }

            a[j] = k;
            ++ssM;
        }
}
long long isC = 0, isM = 0;
void selectionSort(int* a, int n)
{
    for(int i = 0; i<n-1; ++i)
        for(int j = i+1; j<n; ++j)
        {
            isC++;
            if(a[j] < a[i])
            {
                std::swap(a[j],a[i]);
                isM++;
            }

        }
}

void generateArray(int *a, int n)
{
    for(int i = 0; i<n; ++i)
    {
        a[i] = (rand()%65536)-32768;
    }
}
int main(int argc, const char * argv[])
{

    // insert code here...
    int a[10000] = {};

    for(int i = 10; i<100000; i*=10)
    {
        cout << i << ":" <<endl;
        int tests = 0;
        int time = 0;
        ssC = 0; ssM = 0; isC = 0; isM = 0;
        while(time < 2 * CLOCKS_PER_SEC)
        {
            generateArray(a, i);
            int sT = clock();
            shellsort(a, i);
            int eT = clock();
            time+=eT-sT;
            ++tests;
        }
        double timeInSecs = time / CLOCKS_PER_SEC;
        timeInSecs/=tests;
        double avgC = ssC/tests;
        double avgM = ssM/tests;
        cout << "Shellsort avgC = " << avgC << "; avgM = " << avgM << "; avgT = " << timeInSecs << ";" << endl;

        time = 0;
        tests = 0;

        while(time < 2 * CLOCKS_PER_SEC)
        {
            generateArray(a, i);
            int sT = clock();
            selectionSort(a, i);
            int eT = clock();
            time+=eT-sT;
            ++tests;
        }
        timeInSecs = time / CLOCKS_PER_SEC;
        timeInSecs/=tests;
        avgC = isC/tests;
        avgM = isM/tests;
        cout << "Selectionsort avgC = " << avgC << "; avgM = " << avgM << "; avgT = " << timeInSecs << ";" << endl;

    }

    return 0;
}
