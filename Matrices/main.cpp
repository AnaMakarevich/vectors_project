//
//  main.cpp
//  Vectors Project
//  


#include <iostream>

using namespace std;

struct vector{
    bool bits[8];
};

void print_vector(vector* A, int);
void add_zheg(vector* A, vector* B, vector* C, int);
void add_slc(vector* A, vector* m, vector*, int);
void get_vector(vector* vector, int size);
void get_vector2(vector* vector, string thestring, int size);
vector* find_min(vector** vectors, vector* query, int num_vectors, int size);
bool better(vector* v1, vector* v2, int size);

int main(int argc, const char * argv[]) {
    vector* vect1 = new vector;
    vector* vect2 = new vector;
    vector* vect3 = new vector;
    vector* query = new vector;
    
    //get_vector(vector,8);
    get_vector2(query, "11111100", 8);
    get_vector2(vect1, "10100101", 8);
    get_vector2(vect2, "01001011", 8);
    get_vector2(vect3, "10000000", 8);
    vector* vects[3] = {vect1, vect2, vect3};
    print_vector(find_min(vects, query, 3, 8),8);

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
    for (int i = 0; i < size; i++) {
        vector->bits[i] = thestring[i]=='1';
    }
}

//add_scl - performs simple xor operation on vectors A and m and shifts all 1's to the left
void add_slc(vector* A, vector* m, vector* v, int size) {
    int count=0;
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
    for (int i = 0; i < size; i++) {
        C->bits[i]=(A->bits[i]&B->bits[i])^B->bits[i];
    }
}


// print_vector simply prints out the given array, it's used to check if the program works properly at each step
void print_vector(vector* A, int size) {
    //cout << A->name;
    for (int i = 0; i < size; i++) {
        cout << A->bits[i];
    }
    cout << endl;
}

vector* find_min(vector** vectors, vector* query, int num_vectors, int size){
    vector* best = vectors[0];
    vector* v1, *v11, *v2, *v22;
    v1 = new vector;
    v2 = new vector;
    v11 = new vector;
    v22 = new vector;
    for (int i = 1; i < num_vectors; i++) {
        
        add_slc(best, query, v1, size);
        add_slc(vectors[i], query, v2, size);
        add_zheg(v2,v1, v11, size);
        add_zheg(v1, v2, v22, size);
        best = better(v11,v22, size)?vectors[i]:best;
    }
    return best;
}

bool better(vector* v1, vector* v2, int size) {
    for (int i = 0; i < size; i++) {
        if (v1->bits[i]) {
            return true;
        }
        if (v2->bits[i]) {
            return false;
        }
    }
    return true; // in case they are equal
}
