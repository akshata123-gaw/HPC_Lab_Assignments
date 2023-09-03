#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define NUM_POINTS 1000000

int main() {
    int i, num_inside_circle = 0;
    double x, y;

    // Set the seed for random number generation
    srand(12345);

    #pragma omp parallel private(x, y)
    {
        int local_inside_circle = 0;

        #pragma omp for
        for (i = 0; i < NUM_POINTS; i++) {
            // Generate random points within the unit square
            x = (double)rand() / RAND_MAX;
            y = (double)rand() / RAND_MAX;

            // Check if the point is inside the quarter-circle (radius <= 1)
            if (x * x + y * y <= 1.0) {
                local_inside_circle++;
            }
        }

        // Accumulate local_inside_circle values from all threads
        #pragma omp atomic
        num_inside_circle += local_inside_circle;
    }

    // Estimate Pi using the Monte Carlo method
    double pi_estimate = 4.0 * num_inside_circle / NUM_POINTS;

    printf("Estimated Pi: %f\n", pi_estimate);

    return 0;
}
