//
//  main.cpp
//  Matrices
//
//  Created by Anastasia Makarevich on 01/01/2015.
//  Copyright (c) 2015 Anastasia Makarevich. All rights reserved.
//

#include <iostream>

using namespace std;
void print_vector(bool* A, int);
void add_zheg(bool* A, bool* B, bool* C, int);
void add_slc(bool* A, bool* m, int);

int main(int argc, const char * argv[]) {
    // insert code here...
    bool A[8] = {1, 0, 1, 0, 0, 1, 0, 1};
    bool B[8] = {0, 1, 0, 0, 1, 0, 1, 1};
    bool m[8] = {1, 1, 1, 1 ,1, 1, 0, 0};
    bool C[8] = {0};
    bool D[8] = {0};
    add_slc(&A[0],&m[0], 8);
    print_vector(&A[0],8);
    add_slc(&B[0],&m[0],8);
    print_vector(&B[0],8);
    add_zheg(&A[0],&B[0],&C[0],8);
    print_vector(&C[0],8);
    add_zheg(&B[0],&A[0],&D[0],8);
    print_vector(&D[0],8);
}

void add_slc(bool* A, bool* m, int size) {
    int count=0;
    for (int i = 0; i < size; i++){
        if (A[i]^m[i]){
            A[count]=1;
            count++;
        }
    }
    for (int i = count; i < size; i++) {
        A[i]=0;
    }
}

void add_zheg(bool* A, bool* B, bool* C, int size){
    for (int i = 0; i < size; i++) {
        C[i]=(A[i]&B[i])^B[i];
    }
}
void print_vector(bool* A, int size) {
    for (int i = 0; i < size; i++) {
        cout << A[i];
    }
    cout << endl;
}

