#ifndef PROCESS_H
#define PROCESS_H

#include "types.h"

#define MAX_PROCESSES 8  // Maximum process we can run
#define STACK_SIZE 4096  // per process stack size 4KB

typedef enum {
    READY,
    CURRENT,
    TERMINATED
} ProcessState;

typedef struct {
    uint32_t* esp;       // Stack Pointer (Saved CPU context)
    uint32_t pid;        // Process ID
    ProcessState state;  // Current state
    void* stack_start;
} PCB; // Process Control Block

extern PCB process_table[MAX_PROCESSES]; // scheduler can access it
extern int current_process_index;

// Function Prototypes
void init_process_manager();
int create_process(void (*entry_point)());
void exit_process();
#endif