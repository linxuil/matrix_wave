#include <stdio.h>
#include <stdbool.h>

/* minunit */
#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
                            if (message) return message; } while (0)
int tests_run = 0;

// Empty definitions for the mockup functions
int mx_multiply(void) {};

static char*
test_predefined_mx_multiply() {
    /*
     * We're going to create some predefined matrices here,
     * but for now, we'll just fail the test.
     */
    mx_multiply();
    mu_assert("matrix_multiply not implemented yet", false);
    return 0;
}

static char*
test_random_mx_multiply() {
    /* 
     * We're going to generate some random matrices here,
     * but for now, we'll just fail the test.
     */
    mx_multiply();
    mu_assert("matrix_multiply not implemented yet", false);
    return 0;
}

static char*
all_tests() {
    mu_run_test(test_predefined_mx_multiply);
    mu_run_test(test_random_mx_multiply);
    return 0;
}

int
main(int argc, char **argv) {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}

