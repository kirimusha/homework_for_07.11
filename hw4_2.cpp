#include <iostream>
#include <cmath>
using namespace std;
char *allocate_memory(int n);
void input_vector_1(int n, char *x);
void print_vector(int n, char *x);

int main(){
    int n1, n2;
    char *a, *c, *x;

    cout<<"Number of elements of vector A: ";
    cin>>n1;
    cout<<"Number of elements of vector C: ";
    cin>>n2;
    a = allocate_memory(n1);
    c = allocate_memory(n2);
    x = allocate_memory(n1 + n2);
    input_vector_1(n1, a);
    print_vector(n1, a);

    return 0;
}

char *allocate_memory(int n){
    return (char*)malloc(n*sizeof(char));
}

void input_vector_1(int n, char *x){
    for(int i=0;i < n; i++){
        cout<<"A[" << i << "]: ";
        cin >>x[i];
    }
}

void input_vector_2(int n, char *x){
    for(int i=0;i < n; i++){
        cout<<"C[" << i << "]: ";
        cin >>x[i];
    }
}

void print_vector(int n, char *x){
    for(int i=0;i < n; i++){
        cout<<x[i]<< " ";
    }
    cout<<endl;
}

void generate_vector(int n1, int n2, char *x, char *y, char *z){
    int aux=0;
    if(n1 > n2){
        for(int i=0; i < n2; i++){
            z[aux] = x[i];
            aux++;
            z[aux] = y[i];
            aux++;
        }
        for(int i=n1; i < n1; i++){
            z[aux] = x[i];
            aux++;
        }
    }if(n1 > n2){
        for(int i=0; i < n2; i++){
            z[aux] = x[i];
            aux++;
            z[aux] = y[i];
            aux++;
        }
        for(int i=n1; i < n1; i++){
            z[aux] = x[i];
            aux++;
        }
}
}