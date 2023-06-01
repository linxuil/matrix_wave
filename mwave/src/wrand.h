#ifndef WRAND_H
#define WRAND_H

typedef struct {
    void (*init)(void);
    void (*set_range)(int min, int max);
    int (*gen_num)(void);
} Wr_module;

extern Wr_module wr;

#endif // WRAND_H
