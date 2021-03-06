//
//  HeapVector.cpp
//  Sheet07
//
//  Created by QuMing on 14/6/16.
//  Copyright (c) 2016 QuMing. All rights reserved.
//

#include "HeapVector.h"
#include <limits>
#include <iostream>
#include <vector>
using namespace std;


HeapVector::HeapVector(){
    size=0;
    vector<double> values;
    
}

HeapVector::~HeapVector(){
    values.clear();
}

unsigned int HeapVector::heap_size(){
     return values.size();
}

double HeapVector::top() const{
    return values[0];
}


void HeapVector::insert(double d){// inserts value d into the heap
    values.push_back(d);
    size = heap_size();
    double temp;
    int i = size;
    //set one level higher
    while (i>1 && values.at(i / 2 - 1) > values.at(i - 1) ){ //if parent value>child value
        //swap the value
        temp = values.at(i / 2 -1);
        values.at(i / 2 -1) = values.at(i -1);
        values.at(i -1) = temp;
        i = i / 2;
    }
}



void HeapVector::pop_top(){ // removes the smallest element
    values.front() = values.back();
    values.pop_back();
    size = heap_size();
    double temp;
    int i = 1;
    
    while (2 * i <= size){
        if (2 * i + 1 <= size){
            if (values.at(2 * i - 1) <= values.at(2 * i + 1 - 1) && values.at(i - 1) > values.at(2 * i - 1)){
                temp = values.at(i - 1);
                values.at(i - 1) = values.at(2 * i - 1);
                values.at(2 * i - 1) = temp;
                i = 2 * i;
            }
            else if (values.at(2 * i - 1) > values.at(2 * i + 1 - 1) && values.at(i - 1) > values.at(2 * i + 1 - 1)){
                temp = values.at(i - 1);
                values.at(i - 1) = values.at(2 * i + 1 - 1);
                values.at(2 * i + 1 - 1) = temp;
                i = 2 * i + 1;
            }
            else{
                break;
            }
        }
        
        else{
            if (values.at(i - 1) > values.at(2 * i - 1)){
                temp = values.at(i - 1);
                values.at(i - 1) = values.at(2 * i - 1);
                values.at(2 * i - 1) = temp;
                i = 2 * i;
            }
            else{
                break;
            }
        }
    }
    
    
}

void HeapVector::print(){
    for (int i=0; i<values.size(); i++) {
        cout<<values[i]<<" ";
    }
    cout<<endl;
}

