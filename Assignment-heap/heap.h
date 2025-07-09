#include <vector>
#include<iostream>
using namespace std;

class Heap{

    private:
        int* data;
        int index;
        int capacity;

    
    void resize(int newCapacity){

        int* temp=new int[newCapacity];

        for(int i=0;i<=index;i++){
            temp[i]=data[i];

        }

        delete[] data;

        data=temp;
        capacity=newCapacity;

       
    }

    void heapifydown(int i){

        int largest=i;
        int left=2*i+1;
        int right=2*i+2;

        while(left<index && data[left]>data[largest])

        largest=left;

         while(right<index && data[right]>data[largest])

        largest=right;

        if(largest!=i){
            swap(data[largest],data[i]);
            heapifydown(largest);
        }

    }

    void heapifyup(int i){

        if(i==0) return;

        int parent= (i-1)/2;

        if(data[i]>data[parent]){
            swap(data[i],data[parent]);
           heapifyup(parent);
        }

    }

   void swap(int &a, int &b){

        int temp=a;
        a=b;
        b=temp;
   }


    public:

    Heap(){
        index=0;
        capacity=2;
        data=new int[capacity];

    }

    Heap(int capacity){

        data=new int[capacity];
        index=0;
        this->capacity=capacity;
    }

    Heap( vector <int> &v){

        index=v.size();
        capacity=v.size();
        data= new int[v.size()];
        for(int i=0;i<capacity;i++){
            data[i]=v[i];
        }

        for(int i=index/2-1;i>=0;i--){
            heapifydown(i);
        }
    }

    ~Heap(){

        delete[] data;
    }

    void insert(int key){

        if(index>= capacity/2){

            resize(capacity*2);
        }

        data[index]=key;
        heapifyup(index);
        index++;

    }

    int getMax(){

        if(index==0){
            
            cout<<"Heap is empty"<<endl;
            return -1;
        }

        return data[0];
    }

    int size()const{

        return index;
    }

    void deleteKey(){

        if(index==0){
            cout<<"Heap is empty"<<endl;
            return;
        }

        data[0]=data[index-1];
        index--;
        heapifydown(0);

        if(capacity>2 && index<=capacity/4){
            resize(capacity/2);
        }
        
    }

    

};

void heapsort(std::vector<int> &v) {

    Heap h(v);
  
    for(int i=0;i<v.size();i++){
        v[i]=h.getMax();
        h.deleteKey();
    }

    
}

