#include <omp.h>
#include <stdio.h>

void oddEvenSort(int a[], int n, int thread_count) {
    int phase, i, tmp;

    #pragma omp parallel num_threads(thread_count) default(none) shared(a, n) private(i, tmp, phase)
    for (phase = 0; phase < n; phase++) {
        if (phase % 2 == 0) {
            // Even phase
            #pragma omp for
            for (i = 1; i < n; i += 2) {
                if (a[i - 1] > a[i]) {
                    tmp = a[i - 1];
                    a[i - 1] = a[i];
                    a[i] = tmp;
                }
            }
        } else {
            // Odd phase
            #pragma omp for
            for (i = 1; i < n - 1; i += 2) {
                if (a[i] > a[i + 1]) {
                    tmp = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = tmp;
                }
            }
        }
    }
}

int main() {
    int n = 10;  // Size of the array
    int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};  // Example array to sort
    int thread_count = 2;  // Number of threads to use

    double start_time, end_time;

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

start_time = omp_get_wtime();
    oddEvenSort(a, n, thread_count);

end_time = omp_get_wtime();
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("elapsed time = %lf", end_time - start_time);
    printf("\n");

    return 0;
}

 