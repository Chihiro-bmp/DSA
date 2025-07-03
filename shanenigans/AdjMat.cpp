#include<bits/stdc++.h>
using namespace std;

int main(){

    int vertex,edges;
    cin>>vertex>>edges;

    vector< vector<int> >adjMat(vertex, vector<int>(vertex,0));

    int u,v,weight;

    

    for(int i=0;i<edges;i++){

        cin>>u>>v>>weight;

        
        /*
        for undirected unweighted 

        adjMat[u][v]=1;
        adjMat[v][u]=1;
        */

        /*
        //for undirected weighted 
             adjMat[u][v]=weight;
            adjMat[v][u]=weight;

            */

        //for directed weighted 
            adjMat[u][v]=weight;

    }

    for(int i=0;i<vertex;i++){

        for(int j=0;j<vertex;j++){

            cout<<adjMat[i][j]<<" ";


            
        }
        cout<<endl;
    }

}