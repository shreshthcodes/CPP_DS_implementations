#include<bits/stdc++.h>
using namespace std;
class Heap{
    vector<int>heap;
    bool type; // if set to true: Min heap(default), false: Max heap
    bool comparator(int a,int b){
        if(type){
            return a>b;
        }
        else{
            return a<b;
        }
    }
    void heapify(int idx){
        int left=idx*2;
        int right=idx*2+1;
        int last=heap.size();
        int swapIdx=idx;
        if(left<last && comparator(heap[idx],heap[left])){
            swapIdx=left;
        }
        if(right<last && comparator(heap[swapIdx],heap[right])){
            swapIdx=right;
        }
       if(swapIdx!=idx){
        swap(heap[swapIdx],heap[idx]);
        heapify(swapIdx);
       }
       return;
    }
    public:
    //constructors
    Heap(){
        heap.push_back(-1); //can't start min heap from 0th index if we want to represent it in the form of a an array
        this->type=true; //default: Min heap
    }

    Heap(bool type){
        heap.push_back(-1);
        this->type=type;
    }


    void push(int val){
        heap.push_back(val);
        int idx=heap.size()-1;
        int parent=idx/2;
        while(idx>1 && comparator(heap[parent],heap[idx])){
            swap(heap[parent],heap[idx]);
            idx=parent;
            parent=parent/2;
        }
    }

    int top(){
        return heap[1];
    }
    
    void pop(){
       swap(heap[1],heap[heap.size()-1]);
       heap.pop_back();
       heapify(1);
    }
   

    void print(){
        for(auto i=heap.begin()+1;i!=heap.end();i++){
            cout<<*i<<" ";
        }
    }
};
int main()
{
    // Heap*obj = new Heap(false); //Max heap [9,8,7,4,3,2]
    // obj->push(3);
    // obj->push(9);
    // obj->push(2);
    // obj->push(7);
    // obj->push(8);
    // obj->push(4);
    // obj->pop();
    // obj->print();
    Heap obj(true); //Min heap [0,3,89,5,67,95]
    obj.push(3);
    obj.push(5);
    obj.push(89);
    obj.push(0);
    obj.push(67);
    obj.push(95);
    obj.pop();
    obj.print();
    return 0;
}