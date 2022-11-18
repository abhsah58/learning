#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void dfs(int node,int& ans,vector<int>vi[] ,int initial[],int expectation[], int one ,int zero)
{     
      
       if(initial[node] == 1)
       {
                if(one%2==1)
                {
                    initial[node] =0;
                }      
                
                if(initial[node] != expectation[node])
                zero++;
       }
        else
       {
            if(zero%2 ==1)
             expectation[node] = 1;

             if(initial[node] != expectation[node])
                one++;
       }

       for(int i=0;i<vi[node].size();i++)
       {
    dfs(vi[node][i],ans,vi,initial,expectation, one, zero);
       }
}

int getMinimumOperations(int tree_node, int tree_from[], int tree_to[], int intial[], int expectation[])
{
    int ans = 0;
    queue<int> q;
    q.push(0);

    vector<int> vi[tree_node];

    for (int i = 0; i < tree_node - 1; i++)
    {
        vi[tree_from[i]].push_back(tree_to[i]);
    }
    int one =0,zero =0;
    dfs(0,ans,vi,intial,expectation, one, zero);
  
    return ans;
}

int main()
{
    int node =2;
    int tree_from[]={0};
    int tree_to[node] ={1};
    int intial[] ={1,1};
    int expection[] ={0,1};

    return getMinimumOperations(node, tree_from, tree_to, intial, exception); 
}
