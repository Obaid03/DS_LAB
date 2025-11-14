#include <iostream>
using namespace std;
class MaxHeap{
    private:
        int heap[50];
        int size;
    public:
        MaxHeap(){
            size=0;
        }   
        int right(int i){
            return (2*i)+2;
        } 
        int left(int i){
            return (2*i)+1;
        } 
        int parent(int i){
            return(i-1)/2;
        }
        void insert(int value){
            if(size==50){
                cout<<"Heap OverFlow"<<endl;
                return;
            }
            heap[size]=value;
            heapify_up(size);
            size++;
        }
        void heapify_up(int index){
            while(index!=0&&heap[index]>heap[parent(index)]){
                swap(heap[index],heap[parent(index)]);
                index=parent(index);
            }
        }
        void heapify_down(int index){
            int largest=index;
            int l =left(index);
            int r=right(index);
            if(l<size && heap[l]>heap[largest]) largest=l;
            if(r<size && heap[r]>heap[largest]) largest=r;
            if(largest!=index){
                swap(heap[index],heap[largest]);
                heapify_down(largest);
            }
        } 
        void delete_r(){
            if(size==0){
                cout<<"Heap UnderFlow"<<endl;
                return;
            }
            cout<<"Deleted Elemented "<<heap[0];
            heap[0]=heap[size-1];
            size--;
            heapify_down(0);
        }
        void Update_Key(int i,int val){
            heap[i]=val;
            if(val>heap[parent(i)]){
                heapify_up(i);
            }
            else{
                heapify_down(i);
            }
        }
        void Display(){
            for(int i=0;i<size;i++){
                cout<<"Element at index "<<i<<" -> "<<heap[i]<<endl;
            }
        }
};
int main(){
    MaxHeap h1;
    h1.insert(8);
    h1.insert(7);
    h1.insert(6);
    h1.insert(5);
    h1.insert(4);
    h1.Display();
    h1.Update_Key(1,9);
    h1.Display();
}
