#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

/* minunit */
#define mu_assert(message, test) do { if (!(test)) return message; } while (0)
#define mu_run_test(test) do { char *message = test(); tests_run++; \
                            if (message) return message; } while (0)

#define TEST_NAME (__FILE__)
int tests_run = 0;

/* Empty definitions for the mockup functions */
int wr_get_seed() {}
int wr_init() {}
int wr_set_range() {}
int wr_gen_num() {}

/* Tests */

/* 
 * Test case name: Seed generation
 *   Steps:
 *   - Get first seed value
 *   - Check this value more 0
 *   - Get second seed value
 *   - Check first and second values differents
 */
static char*
test_wr_get_seed() {
    wr_get_seed();
    mu_assert("wr_get_seed: not implemented yet", false);
    return 0;
}

/* 
 * Test case name: Check range generation
 *   Steps:
 *   - Set range 1-100
 *   - Run cycle where generated 100 random values
 *   - Each generated value check >=1 <=100
 *   - Each error increment fail counter
 *   - Check fail counter == 0
 */
static char*
test_wr_set_range() {
    wr_set_range();
    mu_assert("wr_set_range: not implemented yet", false);
    return 0;
}

/* 
 * Test case name: Check random generations
 *   Steps:
 *   - Set range 0-9
 *   - Run cycle where generated 100 random values
 *   - Write 1 in array 0-9 element (this num generated 1 or more times)
 *   - Summ all 1 in array
 *   - Check counter >= 5 (this value may configure)
 */
static char*
test_wr_gen_num() {
    wr_gen_num();
    mu_assert("wr_gen_num: not implemented yet", false);
    return 0;
}

/* Run all tests */
static char*
run_all_tests() {
    mu_run_test(test_wr_get_seed);
    mu_run_test(test_wr_set_range);
    mu_run_test(test_wr_gen_num);
    return 0;
}

int
main(int argc, char **argv) {
    printf("\n= = %s = =\n", TEST_NAME);
    char *result = run_all_tests();
    if (result != 0) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
