/*  Solving simple simultaneous equations of multiple variables.  */

#include<bits/stdc++.h>

using namespace std;

vector<double> solve_equations(int n,vector<vector<double>> equation){
    vector<double>result(n);
    for(int i= 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            double ratio = equation[i][0]/equation[j][0];
            int k ;
            for(k = 1;k<n;k++){
                if(ratio!=(equation[i][k]/equation[j][k]))
                    break;
            
            }
            if(k==n){
                if(ratio==(equation[i][k]/equation[j][k])){
                    cout<<"The equations have infinite solutions\n";
                }
                else cout<<"The equation have no solution\n";
                return result;
            }
        }
    }
    cout<<"The equations have a unique solution\n";
   
    int i;
    for(i = 0;i<n;i++){
        int id = i;
        for(int j = i+1;j<n;j++){
            if(fabs(equation[j][i])>fabs(equation[id][i]))
                id = j;
        }

/*
        if(equation[id][i]==0){   //exit if the equations have no unique solution
            cout<<"The equation is not valid!\n";
            exit(1);
        }
*/
        if(id!=i){
            swap(equation[i],equation[id]);
        }
        double divisor = equation[i][i];
        for(int j = 0;j<=n;j++){
            equation[i][j]/=divisor;
        }
        
        for(int j = 0;j<n;j++){
            if(j!=i){
                double factor = equation[j][i]/equation[i][i];
                for(int k=0;k<=n;k++){
                    equation[j][k] -= factor*equation[i][k];
                }
            }
        }
    }

    for(int i = 0;i<n;i++)
        result[i] = equation[i][n];
    return result;
}

int main(){
    int n;
    cin>>n;
    vector<vector<double>>equation(n,vector<double>(n+1));
    for(int i = 0;i<n;i++){
        for(int j=0;j<=n;j++){
            cin>>equation[i][j];
        }
    }
    vector<double> ans;
    ans = solve_equations(n,equation);
    for(auto e:ans)cout<<e<<" ";
    cout<<endl;
}
