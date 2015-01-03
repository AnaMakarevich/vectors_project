//
//  main.cpp
//  Vectors Project
//  


#include <iostream>

using namespace std;

struct vector{
    string name;
    bool bits[8];
};

void print_vector(vector* A, int);
void add_zheg(vector* A, vector* B, vector* C, int);
void add_slc(vector* A, vector* m, vector*, int);
void get_vector(vector* vector, int size);
void get_vector2(vector* vector, string thestring, int size);
void find_min(vector** vectors, vector* query, int num_vectors, int size);
vector* compare(vector* v1, vector* v2, int size);

int main(int argc, const char * argv[]) {
    vector* vect1 = new vector;
    vector* vect2 = new vector;
    vector* vect3 = new vector;
    vector* query = new vector;
    
    //get_vector(vector,8);
    get_vector2(query, "-11111100", 8);
    get_vector2(vect1, "a10100101", 8);
    get_vector2(vect2, "b01001011", 8);
    get_vector2(vect3, "c10000000", 8);
    vector* vects[3] = {vect1, vect2, vect3};
    find_min(vects, query, 3, 8);
    /*
     Test case for the example given on page 14
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
     */
}

//First version that allows the user to enter the vector manually
void get_vector(vector* vector, int size){
    char keeper;
    for (int i = 0; i < size; i++) {
        cin >> keeper;
        vector->bits[i] = keeper=='1';
    }
}

// get_vector2 converts the string into bool array: thus it would be easy to process the vectors once we've extracted them from the file
void get_vector2(vector* vector, string thestring, int size) {
    vector->name=thestring[0];
    for (int i = 0; i < size; i++) {
        vector->bits[i] = thestring[i+1]=='1';
    }
}

//add_scl - performs simple xor operation on vectors A and m and shifts all 1's to the left
void add_slc(vector* A, vector* m, vector* v, int size) {
    int count=0;
    v->name = A->name;
    for (int i = 0; i < size; i++){
        if (A->bits[i]^m->bits[i]){
            v->bits[count]=1;
            count++;
        }
    }
    for (int i = count; i < size; i++) {
        v->bits[i]=0;
    }
}
//add_zheg - pefroms bitwise and operation on vectors A and B and then performs xor operation on the resulting vector and B
void add_zheg(vector* A, vector* B, vector* C, int size){
    C->name = A->name;
    for (int i = 0; i < size; i++) {
        C->bits[i]=(A->bits[i]&B->bits[i])^B->bits[i];
    }
}


// print_vector simply prints out the given array, it's used to check if the program works properly at each step
void print_vector(vector* A, int size) {
    cout << A->name;
    for (int i = 0; i < size; i++) {
        cout << A->bits[i];
    }
    cout << endl;
}

void find_min(vector** vectors, vector* query, int num_vectors, int size){
    vector* best = vectors[0];
    vector* v1, *v11, *v2, *v22;
    v1 = new vector;
    v2 = new vector;
    v11 = new vector;
    v22 = new vector;
    for (int i = 1; i < num_vectors; i++) {
        
        add_slc(best, query, v1, size);
        add_slc(vectors[i], query, v2, size);
        add_zheg(v1,v2, v11, size);
        add_zheg(v2, v1, v22, size);
        best = compare(v11,v22, size);
    }
    cout << best->name;
}

vector* compare(vector* v1, vector* v2, int size) {
    for (int i = 0; i < size; i++) {
        if (v1->bits[i]) {
            return v2;
        }
        if (v2->bits[i]) {
            return v1;
        }
    }
    return v1; // in case they are equal
}
