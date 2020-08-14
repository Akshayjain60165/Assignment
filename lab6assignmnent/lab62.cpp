#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int maxx(int arr[],int n)
{
    int i,j=-1,t=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]>j)
        {
            j=arr[i];
            t=i;
        }
    }
    return t;
}

int naive(int arr[],int n,int j)
{
    for(int i=1;i<j;i++)
    {
        arr[maxx(arr,n)]=-10000;
    }
    return arr[maxx(arr,n)];
}

int Partition(int a[], int low, int high) {
   int pivot, index, i;
   index = low;
   pivot = high;
   for(i=low; i < high; i++) {

      if(a[i] < a[pivot]) {
         swap(&a[i], &a[index]);
         index++;
      }
   }
   swap(a[pivot], a[index]);
   return index;
}
int RandomPivotPartition(int a[], int low, int high){

   int pvt, n, temp;
   n = rand();
   pvt = low + n%(high-low+1);
   swap(&a[high], &a[pvt]);
   return Partition(a, low, high);
}
void quick_sort(int arr[], int p, int q) {

   int pindex;
   if(p < q) {
      pindex = RandomPivotPartition(arr, p, q);

      quick_sort(arr, p, pindex-1);
    quick_sort(arr, pindex+1, q);
}
}

int partition(int arr[], int l, int r, int x)
{

    int i;
    for (i=l; i<r; i++)
        if (arr[i] == x)
           break;
    swap(&arr[i], &arr[r]);


    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}
int findMedian(int arr[], int n)
{
    sort(arr, arr+n);
    return arr[n/2];
}

int kthSmallest(int arr[], int l, int r, int k)
{

    if (k > 0 && k <= r - l + 1)
    {
        int n = r-l+1;
        int i, median[(n+4)/5];
        for (i=0; i<n/5; i++)
            median[i] = findMedian(arr+l+i*5, 5);
        if (i*5 < n)
        {
            median[i] = findMedian(arr+l+i*5, n%5);
            i++;
        }


        int medOfMed = (i == 1)? median[i-1]:
                                 kthSmallest(median, 0, i-1, i/2);


        int pos = partition(arr, l, r, medOfMed);


        if (pos-l == k-1)
            return arr[pos];
        if (pos-l > k-1)
            return kthSmallest(arr, l, pos-1, k);


        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }
  else{
    return -1;
  }
}

int main()
{
    clock_t start,end;

    {cout << "Case 1: when j is fix(n/10) & data=1 to n"<<'\n'<<"1.n=100"<<'\n'<<"naive algorithm: ";
        int a[100];
        for(int i=0;i<100;i++)
            a[i]=i+1;

    start=clock();
        cout<<naive(a,100,10)<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s';}
    {cout<< '\n'<<"pivot algorithm: ";
        int a[100];
        for(int i=0;i<100;i++)
            a[i]=i+1;

    start=clock();
         quick_sort(a,0,100);
        cout<< a[100-10+1]<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s';}
    {cout<< '\n'<<"medOfMed algorithm: ";
        int a[100];
        for(int i=0;i<100;i++)
            a[i]=i+1;

    start=clock();
       cout<< kthSmallest(a,0,100,100+1-10)+1<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s';}


    {cout <<'\n'<< "2.n=200"<<'\n'<<"naive algorithm: ";
        int a[200];
        for(int i=0;i<200;i++)
            a[i]=i+1;

    start=clock();
        cout<<naive(a,200,200/10)<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s';}
    {cout <<'\n'<<"pivot algorithm: ";
        int a[200];
        for(int i=0;i<200;i++)
            a[i]=i+1;

    start=clock();
          quick_sort(a,0,200);
        cout<< a[200-20+1]<<" t=";

    end=clock();
        cout<<double(end-start)/double(100)<<'s';}
    {cout <<'\n'<<"medOfMed algorithm: ";
        int a[200];
        for(int i=0;i<200;i++)
            a[i]=i+1;

    start=clock();
        cout<< kthSmallest(a,0,200,200+1-20)+1<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s';}


    {cout << '\n'<<"3.n=300"<<'\n'<<"naive algorithm: ";
        int a[300];
        for(int i=0;i<300;i++)
            a[i]=i+1;

    start=clock();
        cout<<naive(a,300,300/10)<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s';}
    {cout << '\n'<<"pivot algorithm: ";
        int a[300];
        for(int i=0;i<300;i++)
            a[i]=i+1;

    start=clock();
         quick_sort(a,0,300);
        cout<< a[300-30+1]<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s';}
    {cout << '\n'<<"medOfMed algorithm: ";
        int a[300];
        for(int i=0;i<300;i++)
            a[i]=i+1;

    start=clock();
        cout<<kthSmallest(a,0,300,300+1-300/10)+1<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s';}


    {cout <<'\n'<< "4.n=400"<<'\n'<<"naive algorithm: ";
        int a[400];
        for(int i=0;i<400;i++)
            a[i]=i+1;

    start=clock();
        cout<<naive(a,400,400/10)<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s';}
    {cout <<'\n'<<"pivot algorithm: ";
        int a[400];
        for(int i=0;i<400;i++)
            a[i]=i+1;

    start=clock();
        quick_sort(a,0,400);
        cout<< a[400-40+1]<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s';}
    {cout <<'\n'<<"medOfMed algorithm: ";
        int a[400];
        for(int i=0;i<400;i++)
            a[i]=i+1;

    start=clock();
        cout<<kthSmallest(a,0,400,400+1-400/10)<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s';}


   {cout << '\n'<<"5.n=500"<<'\n'<<"naive algorithm: ";
       int a[500];
       for(int i=0;i<500;i++)
           a[i]=i+1;

   start=clock();
       cout<<naive(a,500,500/10)<<" t=";
   end=clock();
       cout<<double(end-start)/double(100)<<'s';}
    {cout <<'\n'<<"pivot algorithm: ";
        int a[500];
        for(int i=0;i<500;i++)
            a[i]=i+1;

    start=clock();
        quick_sort(a,0,500);
        cout<< a[500-50+1]<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s';}
    {cout <<'\n'<<"medOfMed algorithm: ";
        int a[500];
        for(int i=0;i<500;i++)
            a[i]=i+1;

    start=clock();
        cout<<kthSmallest(a,0,500,500+1-500/10)+1<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s'<<'\n'<<'\n';}






    {cout << "Case 2: when n is fixed(=500) & data=1 to n"<<'\n'<<"1.j=50"<<'\n'<<"naive algorithm: ";

       int a[500];
          for(int i=0;i<500;i++)
              a[i]=i+1;
       start=clock();
           cout<<naive(a,500,50)<<" t=";
       end=clock();
           cout<<double(end-start)/double(100)<<'s';}
    {cout <<'\n'<<"pivot algorithm: ";

    int a[500];
       for(int i=0;i<500;i++)
           a[i]=i+1;
    start=clock();
         quick_sort(a,0,500);
        cout<< a[500+1-50]+1<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s';}
    {cout <<'\n'<<"medOfMed algorithm: ";

    int a[500];
       for(int i=0;i<500;i++)
           a[i]=i+1;
    start=clock();
        cout<<kthSmallest(a,0,500,500+1-50)<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s';}


       {cout <<'\n'<< "2.j=100"<<'\n'<<"naive algorithm: ";
          int a[500];
             for(int i=0;i<500;i++)
                 a[i]=i+1;
       start=clock();
           cout<<naive(a,500,100)<<" t=";
       end=clock();
           cout<<double(end-start)/double(100)<<'s';}
    {cout <<'\n'<<"pivot algorithm: ";
       int a[500];
          for(int i=0;i<500;i++)
              a[i]=i+1;
    start=clock();
         quick_sort(a,0,500);
        cout<< a[500+1-100]+1<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s';}
    {cout <<'\n'<<"medOfMed algorithm: ";
       int a[500];
          for(int i=0;i<500;i++)
              a[i]=i+1;
    start=clock();
        cout<<kthSmallest(a,0,500,500+1-100)<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s';}


       {cout << '\n'<<"3.j=150"<<'\n'<<"naive algorithm: ";
          int a[500];
             for(int i=0;i<500;i++)
                 a[i]=i+1;
       start=clock();
           cout<<naive(a,500,150)<<" t=";
       end=clock();
           cout<<double(end-start)/double(100)<<'s';}
    {cout <<'\n'<<"pivot algorithm: ";
       int a[500];
          for(int i=0;i<500;i++)
              a[i]=i+1;
    start=clock();
         quick_sort(a,0,500);
        cout<< a[500+1-150]+1<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s';}
    {cout <<'\n'<<"medOfMed algorithm: ";
       int a[500];
          for(int i=0;i<500;i++)
              a[i]=i+1;
    start=clock();
        cout<<kthSmallest(a,0,500,500+1-150)<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s';}


       {cout <<'\n'<< "4.j=200"<<'\n'<<"naive algorithm: ";

       int a[500];
          for(int i=0;i<500;i++)
              a[i]=i+1;
       start=clock();
           cout<<naive(a,500,200)<<" t=";
       end=clock();
           cout<<double(end-start)/double(100)<<'s';}
    {cout <<'\n'<<"pivot algorithm: ";

    int a[500];
       for(int i=0;i<500;i++)
           a[i]=i+1;
    start=clock();
         quick_sort(a,0,500);
        cout<< a[500+1-200]+1<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s';}
    {cout <<'\n'<<"medOfMed algorithm: ";

    int a[500];
       for(int i=0;i<500;i++)
           a[i]=i+1;
    start=clock();
        cout<<kthSmallest(a,0,500,500+1-200)+1<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s';}


      {cout << '\n'<<"5.j=250"<<'\n'<<"naive algorithm: ";

      int a[500];
         for(int i=0;i<500;i++)
             a[i]=i+1;
      start=clock();
          cout<<naive(a,500,250)<<" t=";
      end=clock();
          cout<<double(end-start)/double(100)<<'s';}
    {cout <<'\n'<<"pivot algorithm: ";

    int a[500];
       for(int i=0;i<500;i++)
           a[i]=i+1;
    start=clock();
         quick_sort(a,0,500);
        cout<< a[500+1-250]+1<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s';}
    {cout <<'\n'<<"medOfMed algorithm: ";

    int a[500];
       for(int i=0;i<500;i++)
           a[i]=i+1;
    start=clock();
        cout<<kthSmallest(a,0,500,500+1-250)+1<<" t=";
    end=clock();
        cout<<double(end-start)/double(100)<<'s'<<'\n'<<'\n';}

    return 0;
}
