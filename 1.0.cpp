#include<bits/stdc++.h>
using namespace std;
int n,m;
// double sum =0;
double sum_xy(double arr[][5],int k)
{
    double sum_in =0;
      for( int i=1;i<m;i++){
        sum_in = sum_in + (arr[0][k] * arr[i][k]);
    }
    return sum_in;
}
double sum_x(double arr[][5],int k ){
    double sum=0;
    for( int i=1;i<n;i++){
        sum=sum+ arr[k][i];
    }
    return sum;
}
double sum_y(double arr[][5]){
    double sum=0;
    for( int i=0;i<m;i++){
        sum = sum + arr[0][i];
    }
    return sum;
}
double sum_x2(double arr[][5],int k){
    double sum=0;
    for(int  i=1;i<n;i++){
        sum=sum+(arr[k][i] * arr[k][i]);
    }
    return sum;
}
int main()
{
 
   m=1; 
   n=5;
    double arr[m][5];
    double  * pred= new double [m];
    double  * beta = new double[n];
    double sum_in =0 ;
    int a=0;
     for( int i=0;i<m;i++){
         cout<<"Enter the " << i + 1<<" dataset";
         cout<<"Enter the details of the dataset in 2D matrix form \n where First Column being dependent variable and corresponding Columns being the independent var";
        for(int j=0;j<n;j++){
            
            cin>>arr[i][j];
        }
        cout<<"\n";
     //   clrscr();
    }
    // calculation of a
    for(int i=0;i<m;i++){
    
    
    
    a=int (((sum_y(arr)*sum_x2(arr,i)) - (sum_x(arr,i)*sum_xy(arr,i)))/((m*sum_x2(arr,i)-(sum_x(arr,i)*sum_x(arr,i)))));


    }
    // calculation of b1,b2,b3....

    for(int i=0;i<m;i++){
        sum_in=0;
        
        for(int j=0,z=1;j<n;j++,z++)
        {
            beta[j]=((m*(sum_xy(arr,i))) - (sum_x(arr,i)*(sum_y(arr))))/(m*(sum_x2(arr,i))-(sum_x(arr,i)*sum_x(arr,i)));
            beta[j]=beta[j]*arr[i][z];
            sum_in+=beta[j];
            
        } 
     pred[i]=sum_in+ a;
        
    }
   for(int i=0;i<m;i++){
       cout<<" the predictor " << i + 1 << " is  "<<int (pred[i])<<"\n";
   }
    return 0;

}
