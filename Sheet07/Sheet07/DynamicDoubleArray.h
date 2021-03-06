//
//  DynamicDoubleArray.h
//  Sheet07
//
//  Created by QuMing on 14/6/16.
//  Copyright (c) 2016 QuMing. All rights reserved.
//

#ifndef __Sheet07__DynamicDoubleArray__
#define __Sheet07__DynamicDoubleArray__

#include <stdio.h>

class DynamicDoubleArray {
public:
    DynamicDoubleArray();
    ~DynamicDoubleArray();
    int get_size(); // get the number of elements stored inside the array
    double& at(int idx); // access the element positioned at idx
    void push_back(double d); // adds a new element to the array
    void remove(int idx); // remove the element at idx from the array
    void clear();   // delete all the data store inside the array
private:
    double* elements; //dynamic array pointer
    int size;
};

#endif /* defined(__Sheet07__DynamicDoubleArray__) */
