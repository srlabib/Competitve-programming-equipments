#include<bits/stdc++.h>

using namespace std;

vector<vector<long long>> matrix_multiply(vector<vector<long long>> a, vector<vector<long long>> b,int a_column,int a_row,int b_column,int b_row)
{
    vector<vector<long long>>ans(a_row,vector<long long>(b_column));
    if(a_column!=b_row){
        cout<<"not possible!\n";
        return ans;
    }
    for(int i  = 0;i<a_row;i++){
        for(int j = 0; j<b_column;j++){
            long long sum  = 0;
            for(int k = 0;k<a_column;k++)
            {
                sum+=a[i][k]*b[k][j];
            }
            ans[i][j]  = sum;
        }
    }
    return ans;
}
int main()
{
    cout<<"Enter First matrix's number of column and row respectively: ";
    int a_columns,a_row;
    cin>>a_columns>>a_row;
    vector<vector<long long>> a(a_row,vector<long long>(a_columns));
    cout<<"enter the matrix\n";
    for(int i = 0;i<a_row;i++)for(int j= 0;j<a_columns;j++)cin>>a[i][j];
    
    cout<<"Enter second matrix's number of column and row respectively: "; 
    int b_columns,b_row;
    cin>>b_columns>>b_row;
    vector<vector<long long>> b(b_row,vector<long long>(b_columns));
    for(int i = 0;i<b_row;i++)for(int j= 0;j<b_columns;j++)cin>>b[i][j];

    vector<vector<long long>>ans = matrix_multiply(a,b,a_columns,a_row,b_columns,b_row);
    for(auto e:ans){
        for(auto f:e)cout<<f<<" ";
        cout<<endl;
    }
    return 0;
}
