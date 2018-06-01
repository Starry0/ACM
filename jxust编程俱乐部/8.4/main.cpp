//错误的答案  还没有修改


#include<iostream>
 using namespace std;
 int main()
 {
     int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
     int b[3][3],i,j,k;
     for(i=0;i<=1;i++)
     {
         for(j=0;j<=2;j++)
         {
             for(k=0;k<=3;k++)
             {
                 cout<<a[i][j][k]<<"";
                 b[k][j][i]=a[i][j][k];
             }
         }
         cout<<endl;
     }
     for(k=0;k<=3;k++)
     {
         for(j=0;j<=2;j++)
         {
             for(i=0;i<=1;i++)
                cout<<b[i][j][k]<<"";
             cout<<endl;
         }
     }
     return 0;
 }
