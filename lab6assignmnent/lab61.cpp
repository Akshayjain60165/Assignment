#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int power(int t,int  p){
    int y;
    y=1;
    for(int i=1;i<=p;i++){
        y=y*t;
    }

    return y;
}

int fun(int n){
if(n=1){
    return 1;
}
    else{
        return 1/10;
    }

}

void *sortt(int* arr,int n, int p){

                  int t[10];
                  int r;
                  for(r=0;r<10;r++)
                    {
                     t[r]=0;
                    }

                 int y,u=0,i,o;
                 y=n;
                 int z;
                 if(p==1){
                    z=1;
                 }
                 else{
                    z=power(10,p-1);
                 }

                 while(u<=n-1)
                    {
                      t[(arr[u]%power(10,p))/z]++;

                      u++;
                    }
                    int x;
                    for(x=1;x<10;x++){
                        t[x]=t[x]+t[x-1];

                    }


                int arr2[n];
                 for(r=0;r<n;r++)
                    {
                     arr2[r]=0;
                    }
                for(i=n-1;i>=0;i--){
                        arr2[(t[((arr[i]%power(10,p))/z)]-1)]=arr[i];

                           t[(arr[i]%power(10,p))/z]--;
                }
                for(o=0;o<n;o++){
                    arr[o]=arr2[o];

                }





}

 void redexsort(int arr[], int n){

                   int q,maxx;
                   maxx=arr[0];
                   for(q=0;q<n;q++)
                    {
                        if(maxx<arr[q])
                        {
                            maxx=arr[q];
                        }
                    }
                   int w,e=0;
                   w=maxx;
                   while(w>1)
                    {
                      w=w/10;
                      e++;
                    }


              int j;
              int *arr3[n];
              for(j=1;j<=e;j++){
                 sortt( arr,n,j);

              }

       int g;
       for(g=0;g<n;g++){
        cout<<arr[g]<<" ";

       }

}

void counting(int arr[], int n){
     int arr2[10000];
     int y;
     for(y=0;y<10000;y++){
        arr2[y]=0;
     }
     int d,z=0,g;
     for(d=0;d<n;d++){
            g=arr[d];
        arr2[g]++;
     }
      for(y=0;y<10000;y++){
        if(arr2[y]!=0){
            z=arr2[y];
            while(z!=0){
                cout<<y<<" ";
                z--;
            }
        }
      }

}
void bs(float arr[],int n,int m){
          float w;
          int q,e;
          for(q=(n+1);q<=m;q++){
            w=arr[q];
            e=q-1;
            while(e>=0&&w>arr[e]){
                arr[e+1]=arr[e];
                e=e-1;
            }
            arr[e+1]=w;
          }




}

 void bucket(int arr[],int n){
          int q,maxx;
                   maxx=arr[0];
                   for(q=0;q<n;q++)
                    {
                        if(maxx<arr[q])
                        {
                            maxx=arr[q];
                        }
                    }
                   int w,e=0,i;
                   w=maxx;
                   while(w>1)
                    {
                      w=w/10;
                      e++;
                    }
                    float arr2[n],f,k,l;
                      k=power(10,e);

                    int g;
                    for(g=0;g<n;g++){
                        f=arr[g];
                        arr2[g]=f/k;
                    }
                    float arr3[10][100];
                    int zx[10];
                    for(g=0;g<10;g++){
                            zx[g]=1;

                    }
                    for(g=0;g<10;g++){
                        for(w=0;w<100;w++){
                           arr3[g][w]=0;

                        }
                    }
                    for(g=0;g<n;g++){
                        i=arr2[g]*10;

                        arr3[i][0]++;

                        arr3[i][zx[i]]=arr2[g];
                          zx[i]++;

                    }
                    int d,c;
                    for(g=0;g<10;g++){
                            d=arr3[g][0];
                        bs(arr3[g],1,d);
                        if(d!=0){
                        for(c=arr3[g][0];c>=1;c--){
                            cout<<(arr3[g][c])*k<<" ";
                        }
                        }


                    }

 }

int main(){
     clock_t start, end;
          start = clock();
   int t;
   cout<<"give the size of array ";
   cin>>t;
   cout<<"\n";
   int arr[t];
   cout<<"give the elements";
   int i,j;
   for(i=0;i<t;i++){
    cin>>arr[i];
   }
   cout<<"give the number according to different sorting \n 1=redex \n 2=bucket \n 3=counting\n";
   cin>>j;

   if(j==1){
    redexsort( arr, t);
     end = clock();
     double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
         cout << " sec " << endl;
   }
    if(j==2){
        bucket( arr, t);
        end = clock();
     double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
         cout << " sec " << endl;
    }
    else{
        counting( arr, t);
        end = clock();
     double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
         cout << " sec " << endl;
    }
   return 0;
}
