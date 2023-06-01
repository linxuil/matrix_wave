#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "wrand.h"

/* #define USE_DEVRANDOM */
#define USE_TIME

#ifdef USE_DEVRANDOM
#include <sys/random.h>
#endif

typedef struct {
    int min_num;
    int max_num;
} Wrand_cfg;
static Wrand_cfg cfg;

static unsigned int
wr_get_seed(void) {
    unsigned int seed = 0;

#ifdef USE_DEVRANDOM
    time_t current_time = 0;
    
    current_time = time(NULL);
    seed = (unsigned int)current_time;
#endif
    
#ifdef USE_DEVRANDOM
    unsigned char buffer[sizeof(unsigned int)];
    ssize_t nbytes = 0;
    
    nbytes = getrandom(buffer, sizeof(buffer), 0);
    if (nbytes == -1) {
        perror("Error read from /dev/urandom with getrandom()");
        exit(1);
    }

    for (int i = 0; i < sizeof(unsigned int); ++i) {
        seed = (seed << 8) | buffer[i];
    }
#endif
    
    return seed;
}

void
wr_set_range(int min, int max) {
    cfg.min_num = min;
    cfg.max_num = max;
}

void
wr_init(void) {
    unsigned int seed = 0;

    seed = wr_get_seed();
    srand(seed);
    wr_set_range(0, 1);
}

int
wr_gen_num(void) {
    int random_number = 0;

    random_number = rand() % (cfg.max_num - cfg.min_num + 1) + cfg.min_num;
    return random_number;
}

/* Module interface structure */
Wr_module wr = {
    .set_range = wr_set_range,
    .init = wr_init,
    .gen_num = wr_gen_num
};
