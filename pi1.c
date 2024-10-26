#include <omp.h>
#include <stdio.h>



int main () {
double factor = 1.0;
double sum = 0.0;
int thread_count = 2;
int n = 1000;
int k = 0;
double start_time, end_time;

start_time = omp_get_wtime();

#pragma omp parallel for num_threads (thread_count) \
reduction(+:sum)
for (k = 0; k < n; k++){

    sum+= factor/(2*k+1);
    factor = -factor;
}

end_time = omp_get_wtime();
double pi = 4.0*sum;


printf("%lf", pi);
printf("\n");
printf("elapsed time = %lf", end_time - start_time);
printf("\n");
    return 0;
}