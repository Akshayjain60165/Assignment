#include<iostream>
#include<fstream>
using namespace std;


int main()
{
    ifstream ut;
    ut.open("filehandling.txt",ios::in|ios::out);
    int t;
    cin>>t;
    while(t--)
    {
      int q=1;
      cout<<"Case #"<<q<<":\n";
   q++;
        int n;
        cin>>n;
        int x;
        ut<<x<<"akshay";
        int arr[2][50];
        string s1,s2;
         cin>>s1;
         cin>>s2;

        for(int j=0;j<n;j++)
        {

            arr[0][j]=int(s1[j]);
          //  cout<<arr[i][j]<<" ";
        }
         for(int j=0;j<n;j++)
        {

            arr[1][j]=int(s2[j]);
          //  cout<<arr[i][j]<<" ";
        }

     ut.close();
    }

}
