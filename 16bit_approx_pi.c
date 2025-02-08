#include <stdio.h>
#include <math.h>
#include <limits.h>

#define PI 3.141592653589793

int main() {
    unsigned int best_numerator = 0;
    unsigned int best_denominator = 1;
    double min_error = INFINITY; // Initialize with a large value

    // Iterate over possible denominators (powers of 2)
    for (int k = 0; k <= 15; k++) {
        unsigned int denominator = 1 << k; // 2^k
        double target = PI * denominator; // Target numerator value
        unsigned int numerator = (unsigned int)(target + 0.5); // Round to nearest integer

        // Ensure numerator is within 16-bit range
        if (numerator > 65535) {
            continue; // Skip if numerator exceeds 16-bit limit
        }

        // Calculate the fraction and error
        double fraction = (double)numerator / denominator;
        double error = fabs(fraction - PI) / PI * 100.0;

        // Update best combination if this error is smaller
        if (error < min_error) {
            min_error = error;
            best_numerator = numerator;
            best_denominator = denominator;
        }
    }

    // Output the best combination
    printf("Best combination:\n");
    printf("Numerator: %u\n", best_numerator);
    printf("Denominator: %u (2^%d)\n", best_denominator, (int)log2(best_denominator));
    printf("Fraction: %u / %u = %.15f\n", best_numerator, best_denominator, (double)best_numerator / best_denominator);
    printf("Error: %.6f%%\n", min_error);

    return 0;
}