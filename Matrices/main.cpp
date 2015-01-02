//
//  main.cpp
//  Vectors Project
//  


#include <iostream>

using namespace std;
void print_vector(bool* A, int);
void add_zheg(bool* A, bool* B, bool* C, int);
void add_slc(bool* A, bool* m, int);
bool* get_vector(int size);
int main(int argc, const char * argv[]) {
    int x;
    cin >> x;
    cout << x;
    // Testing the example given on page 14
    bool* vector;
    vector = get_vector(8);
    print_vector(vector,8);
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

bool* get_vector(int size){
    bool * vector;
    int* keeper;
    vector = new bool[size];
    for (int i = 0; i < size; i++) {
        
        scanf("%d", keeper);
        vector[i] = (bool)keeper;
    }
    return vector;
}

//add_scl - performs simple xor operation on vectors A and m and shifts all 1's to the left
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
//add_zheg - pefroms bitwise and operation on vectors A and B and then performs xor operation on the resulting vector and B
void add_zheg(bool* A, bool* B, bool* C, int size){
    for (int i = 0; i < size; i++) {
        C[i]=(A[i]&B[i])^B[i];
    }
}
// print_vector simply prints out the given array, it's used to check if the program works properly at each step
void print_vector(bool* A, int size) {
    for (int i = 0; i < size; i++) {
        cout << A[i];
    }
    cout << endl;
}

