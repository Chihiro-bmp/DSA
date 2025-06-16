#include <iostream>
#include <vector>
#include "queue.h"
using namespace std;

/********************************* RANDOM ************************************/
#define LCG_MULTIPLIER (1103515245)
#define LCG_INCREMENT (12345)
#define LCG_MODULUS ((unsigned)~0 >> 1)
static unsigned int lcg_seed = 1;
void custom_srand(unsigned int seed)
{
    lcg_seed = seed;
}
int custom_rand()
{
    lcg_seed = (LCG_MULTIPLIER * lcg_seed + LCG_INCREMENT) % (LCG_MODULUS + 1);
    return lcg_seed;
}
int randomQueue(int seed = -1)
{
    static bool initialized = false;
    if (seed != -1 && !initialized)
    {
        custom_srand(seed);
        initialized = true;
        return -1;
    }
    cout << "randomQueue() called" << endl;
    return (custom_rand() % 2) + 1;
}
/*****************************************************************************/

int main()
{
    //freopen("test_input_1.txt", "r", stdin); // Test Case 1
    freopen("test_input_2.txt", "r", stdin); // Test Case 2
    freopen("output_2.txt", "w", stdout);
    // Initialize the random generator with a fixed seed
    // You should set the seed only once at the beginning of your program
    // NOTE: Do not modify the following lines.
    randomQueue(42);

    Queue *Q1 = new ListQueue();
    Queue *Q2 = new ListQueue();
    Queue *Q = new ArrayQueue();

    int N;
    cin >> N;

    const int max_patients=10000;
    int Timestamps[max_patients+1];
    
    for(int i=0;i<=max_patients;i++){
        Timestamps[i]=-1;
    }

    bool merged=false;

    for (int i = 1; i <= N; i++)
    {
        // TODO: Edit here to add your own logic


        int operation_type;
        cin>>operation_type;

        if(operation_type==1){

            int id,timestamp;
            cin>>id>>timestamp;

            Timestamps[id]=timestamp;

            //cout<<"Operation "<<i<<" (Arrival "<<id<<" "<<timestamp<<"): ";

            if(merged){

                cout<<"Operation "<<i<<" (Arrival "<<id<<" "<<timestamp<<"): "<<endl;
                Q->enqueue(id);
            }else{

                if(Q1->empty()&&Q2->empty()){

                    cout<<"Operation "<<i<<" (Arrival "<<id<<" "<<timestamp<<"): ";
                    int random=randomQueue();

                    //cout<<"Operation "<<i<<" (Arrival "<<id<<" "<<timestamp<<"): "<<endl;
                    if(random==1){

                        Q1->enqueue(id);
                    }else{
                        Q2->enqueue(id);
                    }

                }else if(Q1->empty()){

                    cout<<"Operation "<<i<<" (Arrival "<<id<<" "<<timestamp<<"): "<<endl;
                    Q1->enqueue(id);

                }else if(Q2->empty()){

                    cout<<"Operation "<<i<<" (Arrival "<<id<<" "<<timestamp<<"): "<<endl;
                    Q2->enqueue(id);
                }
                else{

                    cout<<"Operation "<<i<<" (Arrival "<<id<<" "<<timestamp<<"): "<<endl;
                    int a=Timestamps[Q1->back()];
                    int b=Timestamps[Q2->back()];

                    if(a>b){
                        Q2->enqueue(id);
                    }else{
                        Q1->enqueue(id);
                    }

                }
            }

        }
        else if(operation_type==2){

            int id, timestamp;

            cin>>id>>timestamp;

            cout<<"Operation "<<i<<" (Leave "<<id<<" "<<timestamp<<"): "<<endl;

            if(merged){

                int length=Q->size();

                for(int i=0;i<length;i++){

                    int check=Q->dequeue();

                    if(check!=id){
                        Q->enqueue(check);
                    }
                }
              
                if(length==Q->size()){

                    cout<<"Error! Patient: "<<id<<"not found."<<endl;
                }
            }

            else{

                int length1=Q1->size();

                for(int i=0;i<length1;i++){

                    int check=Q1->dequeue();

                    if(check!=id){
                        Q1->enqueue(check);
                    }
                }

                int length2=Q2->size();

                for(int i=0;i<length2;i++){

                    int check=Q2->dequeue();

                    if(check!=id){
                        Q2->enqueue(check);
                    }
                }

                if(length1==Q1->size() && length2==Q2->size()){

                    cout<<"Error! Patient: "<<id<<"not found."<<endl;
                }

            }
        }

        else if(operation_type==3){


            cout<<"Operation "<<i<<" (Merge): "<<endl;

            if(merged){
                cout<<"Queues are already merged."<<endl;
            }
            
            else{
                
                while(!Q1->empty() && !Q2->empty()){

                    if(Timestamps[Q1->front()]< Timestamps[Q2->front()]){

                        Q->enqueue(Q1->dequeue());
                    }else{
                       Q->enqueue(Q2->dequeue());
                    }
                }

                while(!Q1->empty()){
                   Q->enqueue(Q1->dequeue());
                }
                while(!Q2->empty()){
                   Q->enqueue(Q2->dequeue());
                }

                             
                merged=true;
            }

           
            
        } else if(operation_type==4){

            cout<<"Operation "<<i<<" (Split): "<<endl;

            if(!merged){

                cout<<"Queues are already splitted"<<endl;

            }else{

               bool flag=true;

               while(!Q->empty()){

                if(flag){

                    Q1->enqueue(Q->dequeue());
                }else{
                    Q2->enqueue(Q->dequeue());
                }

                flag=!flag;
               }

               merged =false;
            }
        } 
        else if(operation_type==5){

            //cout<<"Operation "<<i<<" (Departure):"<<endl;
            if(merged){

                cout<<"Operation "<<i<<" (Departure): "<<endl;
                Q->dequeue();
            }else{
                if(!Q1->empty() && !Q2->empty()){
                    
                    cout<<"Operation "<<i<<" (Departure): ";
                     int random=randomQueue();

                    //cout<<"Operation "<<operation_type<<" (Departure):"<<endl;
                    if(random==1){

                        Q1->dequeue();
                    }else{
                        Q2->dequeue();
                    }

                }else if(!Q1->empty()){

                    cout<<"Operation "<<i<<" (Departure): "<<endl;
                    Q1->dequeue();

                }else if(!Q2->empty()){

                    cout<<"Operation "<<i<<" (Departure): "<<endl;
                    Q2->dequeue();

                }else{
                    cout<<"Both queues are empty."<<endl;
                }
            }
        }


        cout<<"Q1: "<<Q1->toString()<<endl;
        cout<<"Q2: "<<Q2->toString()<<endl;
        cout<<"Q : "<<Q->toString()<<endl;

    
        // After each operation, we will check the queue's size and capacity
        // NOTE: Do not modify the following lines.
        int capacity = ((ArrayQueue *)Q)->getCapacity();
        if ((Q->size() < capacity / 4 && capacity > 2))
        {
            cout << "Error: Queue size is less than 25% of its capacity." << endl;
        }
        else if (capacity < 2)
        {
            cout << "Error: Queue capacity is less than 2." << endl;
        }
    }

    delete Q1;
    delete Q2;
    delete Q;

    return 0;
}