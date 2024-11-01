#include <iostream>
#include <cmath>
using namespace std;

int *allocate_memory(int n);
void input_vector(int n, int *x, int *y);
int sum_vector(int n, int *x);
int sum_composition(int n, int *x, int *y);
int sum_square(int n, int *x);
double calculate_average(int n, int *x);
double calculate_linear_coef(int n, int *x, int *y);
double independent_unit(int n, int *x, int *y);
void print_linear_regression(int n, int *x, int *y);



int main(){
    int n, *x, *y;
    double x1, y1, pred_y;
    cout << "Number of dots:" << endl;
    cin >> n;
    x = allocate_memory(n);
    y = allocate_memory(n);
    input_vector(n, x, y);
    print_linear_regression(n, x, y);
    cout << "Please, enter X" << endl;
    cin >> x1;
    cout << "Please, enter  Y" << endl;
    cin >> y1;
    pred_y = calculate_linear_coef(n, x, y)  +  independent_unit(n, x, y)  * x1;
    cout << "Predictable Y: " << pred_y << endl;
    cout << "Error: " << abs(y1 - pred_y) << endl;
}

// function for dynamic allocation of memory for vectors using malloc
int *allocate_memory(int n){
    return (int *) malloc(n * sizeof(int));
}


// procedure to input the elements in 1 vector
void input_vector(int n, int *x, int *y){
    for(int i=0; i<n; i++){
        cout<<"X["<<i<<"]: ";
        cin>>x[i];
        cout<<"Y["<<i<<"]: ";
        cin>>y[i];
    }
}


double calculate_average(int n, int *x){
    int sum;
    sum = sum_vector(n, x);
    return sum / n;
}

int sum_vector(int n, int *x){
    int sum;
    for(int i=0; i < n; i++){
        sum += x[i];
    }
    return sum;
}

int sum_composition(int n, int *x, int *y){
    int sum;
    for(int i=0; i < n; i++){
        sum += x[i]*y[i];
    }
    return sum;
}

int sum_square(int n, int *x){
    int sum;
    for(int i=0; i < n; i++){
        sum += x[i]*x[i];
    }
    return sum;
}

double calculate_linear_coef(int n, int *x, int *y){
    int sum, sum_sq, sum_comp;
    double ave_x, ave_y;
    ave_x = calculate_average(n, x);
    ave_y = calculate_average(n, y);
    sum = sum_vector(n, x);
    sum_comp = sum_composition(n, x, y);
    sum_sq = sum_square(n, x);
    return (sum_comp - n * ave_x * ave_y) / (sum_sq - (1/n) * pow(sum, 2));
}

double independent_unit(int n, int *x, int *y){
    double ave_x, ave_y;
    ave_x = calculate_average(n, x);
    ave_y = calculate_average(n, y);
    return ave_y - calculate_linear_coef(n, x, y) * ave_x;
}

void print_linear_regression(int n, int *x, int *y){
    cout << "Formula: " << calculate_linear_coef(n, x, y) << " + " << independent_unit(n, x, y) << " * x " << endl;
}