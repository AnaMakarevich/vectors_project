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
void get_vector(vector* vector, string thestring, int size);
vector* find_min(vector** vectors, vector* query, int num_vectors, int size);
bool better(vector* v1, vector* v2, int size);

int main(int argc, const char * argv[]) {
    
    // The following code is just for testing purposes
    
    // Here we create an additional vector because we don't want to modify the original one if we want to return it at the end of the search so that we can transform it into something
    vector* vect1 = new vector;
    vector* vect2 = new vector;
    vector* vect3 = new vector;
    vector* query = new vector;
    
    // Test vectors: vect1-3 - search set, query - metric vector
    get_vector(query, "11111100", 8);
    get_vector(vect1, "10100101", 8);
    get_vector(vect2, "01001011", 8);
    get_vector(vect3, "10000000", 8);
    vector* vects[3] = {vect1, vect2, vect3};
    
    print_vector(find_min(vects, query, 3, 8),8);

}


// get_vector2 converts the string into bool array: thus it would be easy to process the vectors once we've extracted them from the file. I assume that we have a txt file which we can read line by line, where each line has 8 symbols (0's and 1's)
void get_vector(vector* vector, string thestring, int size) {
    for (int i = 0; i < size; i++) {
        vector->bits[i] = thestring[i]=='1';
    }
}

//add_scl - performs simple xor operation on vectors A and m and shifts all 1's to the left
// Algorithm: First it saves all the 1's it finds ignoring 0's and then fills in the rest of the vector with 0's
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

// find_min iterates over the array of vectors searching for the best solution. First it takes the first vector in the array as the reference vector and compares other vectors to it.
vector* find_min(vector** vectors, vector* query, int num_vectors, int size){
    vector* best = vectors[0]; //reference vector
    vector* v1, *v11, *v2, *v22; // create additional vectors so that we can return the winnder in the end instead of it's number
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

// Checks if one vector is better than the other: since we assume that one of the vectors is always all 0's we can just return true or false once it finds 1 in one of the 2 vectors: if it finds 1 in v1, then v2 is better and vice versa
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
