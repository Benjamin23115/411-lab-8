#include <omp.h>
#include <stdio.h>



int main () {

double sum = 0.0;
int thread_count = 1, n = 1000, k = 0;
double factor = 1.0;
double pi = 0.0;
double start_time, end_time;

start_time = omp_get_wtime();
#pragma omp parallel for reduction(+:sum) private(factor) num_threads (thread_count) 
for (k = 0; k < n; k++){

factor = k % 2 == 0 ? 1 : -1;
    sum+= factor/(2*k+1);
}

end_time = omp_get_wtime();
pi = 4.0*sum;

printf("%lf", pi);
printf("\n");
printf("elapsed time = %lf", end_time - start_time);
printf("\n");

    return 0;
}