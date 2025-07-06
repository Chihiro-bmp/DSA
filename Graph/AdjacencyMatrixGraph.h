#ifndef ADJACENCY_MATRIX_GRAPH_H
#define ADJACENCY_MATRIX_GRAPH_H

#include "GraphADT.h"
#include "ArrayList.h"

class AdjacencyMatrixGraph : public GraphADT
{
private:
    //TODO: Consider necessary private members as per your discretion

    bool** adjMat;
    int capacity;
    ArrayList presentNodes;

    void resizeMatrix( int newNode)
    {
        //TODO: you need to resize your matrix when you will less data or more data

        int newCapacity=newNode+1;

        bool** tempMatrix=new bool*[newCapacity];

        for(int i=0;i<newCapacity;i++){

            tempMatrix[i] = new bool[newCapacity]{false}; 
            
            if(i<capacity){

                for(int j=0;j<capacity;j++){

                    tempMatrix[i][j]=adjMat[i][j];
                }
            }
        }


        for(int i=0;i<capacity;i++){

            delete[] adjMat[i];
        }

        delete[] adjMat;

        adjMat=tempMatrix;
        capacity=newCapacity;
       

       
    }

     void BFSTraversal(int StartNode, bool* visited , int* parent, int* distance)const{

       if(StartNode>=capacity) return;

       

        for(int i=0;i<capacity;i++){
            visited[i]=0;
            parent[i]=-1;
            distance[i]=-1;
        }

        //custom queue for BFS traversal 

        int* queue =new int[capacity];
        int front=0;
        int rear=0;

        //pushing node in the queue
        queue[rear++]=StartNode;
        visited[StartNode]=1;
        distance[StartNode]=0;

        //popping from queue into traversal and checking unvisited neighbours

        while(front<rear){

            int current=queue[front++];

            for(int i=0;i<capacity;i++){

                
                int neighbour=i;

                 
                if( adjMat[current][neighbour] && !visited[neighbour]){

                   visited[neighbour]=1;
                   parent[neighbour]=current;
                   distance[neighbour]=distance[current]+1;
                   queue[rear++]=neighbour;
                }
            }
        }

        delete[] queue;
    }

    

public:

    AdjacencyMatrixGraph(){

       
        capacity=0;
        adjMat=NULL;
    }

    ~AdjacencyMatrixGraph(){

        for(int i=0;i<capacity;i++){
            delete[] adjMat[i];
        }

        delete[] adjMat;

    }

    void AddNode(int v) override
    {
        //TODO: Add a new node v and resize the matrix if your current matrix is almost going to be full.

        if(v>=capacity)
        resizeMatrix(v);

       if(!presentNodes.isAvailable(v)){
        presentNodes.append(v);
       }

    }

    void AddEdge(int u, int v) override
    {
        //TODO: Add a new edge between the nodes u and v

        AddNode(u);
        AddNode(v);

        adjMat[u][v]=1;
        adjMat[v][u]=1;
    }

    bool CheckEdge(int u, int v) const override
    {
        //TODO: Check whether there is an edge between two nodes u and v

        if(!presentNodes.isAvailable(u) || !presentNodes.isAvailable(v)) return false;

        bool uv= adjMat[u][v];
        bool vu=adjMat[v][u];

        return uv && vu;

    }

    void RemoveNode(int v) override
    {
        //TODO: Remove a node.

        if(!presentNodes.isAvailable(v)){

            //std::cout<<"Node does not exist"<<std::endl;
            return;
        }

        for(int i=0;i<capacity;i++){
            adjMat[i][v]=0;
            adjMat[v][i]=0;
        }

        presentNodes.remove(v);

        bool** tempMat=new bool*[capacity-1];

        for(int i=0, i2=0; i<capacity;i++){

            if(i==v) continue;

            tempMat[i2]=new bool[capacity-1];

            for(int j=0,j2=0;j<capacity;j++){

                if(j==v) continue;

                tempMat[i2][j2]=adjMat[i][j];

                j2++;
            }

            i2++;
        }

        for(int i=0;i<capacity;i++){

            delete[] adjMat[i];
        }
        delete[] adjMat;

        adjMat=tempMat;
        capacity--;
       // delete[] tempMat;
    }

    void RemoveEdge(int u, int v) override
    {
        //TODO: remove an edge
        if(!presentNodes.isAvailable(u) || !presentNodes.isAvailable(v)){

            //std::cout<<"Node does not exist"<<std::endl;
            return;            
        }

        adjMat[u][v]=0;
        adjMat[v][u]=0;

    }

    bool CheckPath(int u, int v) const override
    {
        //TODO: Return true if there is a path between nodes u and v. Otherwise return false

        if(u==v) return true;

        if(!presentNodes.isAvailable(u) || !presentNodes.isAvailable(v)){

          //std::cout<<"Node does not exist"<<std::endl;
            return false;    
        }

        bool* visited= new bool[capacity];
        int* parent=new int[capacity];
        int* distance =new int[capacity];

        BFSTraversal(u,visited,parent,distance);

        bool ans=visited[v];

        delete[] visited;
        delete[] parent;
        delete[] distance;

        return ans;

    }

    void FindShortestPath(int u, int v) const override
    {
        //TODO: Find the shortest path between the nodes u and v and print it.

        if(!presentNodes.isAvailable(u) || !presentNodes.isAvailable(v)){

         //std::cout<<"Node does not exist"<<std::endl;
            return;      
        }

        bool* visited= new bool[capacity];
        int* parent=new int[capacity];
        int* distance =new int[capacity];

        BFSTraversal(u,visited,parent,distance);

        if(!visited[v]){

            //std::cout<<"No path exists"<<std::endl;
            return;

        }else{
                int path[capacity];
                int current = v;
                int length = 0;
               
                while(current!=-1){
                    path[length++]=current;
                    current=parent[current];

                }

                std::cout<<"Shortest path: ";
                
                for(int i=length-1;i>=0;i--){
                    std::cout<<path[i]<<" ";
                }
                 std::cout << std::endl;
        }

        delete[] visited;
        delete[] parent;
        delete[] distance;
    }

    int FindShortestPathLength(int u, int v) const override
    {
        //TODO: Return the shortest path length between nodes u and v if any such path exists. Otherwise return -1.

        if(u==v) return 0;

        if(!presentNodes.isAvailable(u) || !presentNodes.isAvailable(v)){
            std::cout<<"Path does not exist"<<std::endl;
            return -1;
        }

        bool* visited=new bool[capacity];
        int* parent= new int[capacity];
        int* distance=new int [capacity];

        BFSTraversal(u,visited,parent,distance);

        int shortestLength=distance[v];

        delete[] visited;
        delete[] parent;
        delete[] distance;

        
        return shortestLength;
    }
    ArrayList GetNeighbors(int u) const override
    {
        //TODO return a list of neighbors of node u

        ArrayList neighbors;

        if(!presentNodes.isAvailable(u)) return neighbors;

        for(int v=0;v<capacity;v++){

            if(adjMat[u][v]){
                neighbors.append(v);
            }
        }

        return neighbors;

    }

};

#endif // ADJACENCY_MATRIX_GRAPH_H
