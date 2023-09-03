#include<stdio.h>
#include<omp.h>
void printMes();

int main(){
#pragma omp parallel num_threads(10)
printMes();
return 0;
}

void printMes(){
int tn;
tn = omp_get_thread_num();
printf("\n Hello World! from %d \n", tn);
}