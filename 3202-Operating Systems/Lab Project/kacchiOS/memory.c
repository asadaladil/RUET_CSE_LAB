#include "memory.h"

// Defined in your linker script (or the end of your kernel code)
extern uint8_t __kernel_end; 

// The start of our heap
static uint8_t* heap_start = &__kernel_end;
static uint8_t* heap_top = &__kernel_end;

// --------------------------------------------------------
// The Header Structure
// Every memory block will have this 'ticket' attached to it
// so we know its size and status.
// --------------------------------------------------------
typedef struct BlockHeader {
    uint32_t size;            // Usable size (excluding header)
    uint8_t is_free;          // 1 = Free, 0 = Taken
    struct BlockHeader* next; // Pointer to the next block in our list
} BlockHeader;

static BlockHeader* free_list_head = 0; // Head of our linked list

void* k_malloc(uint32_t size) 
{
    BlockHeader* curr = free_list_head;

    // 1. First-Fit: Look for an existing free block that is big enough
    while (curr) 
    {
        if (curr->is_free && curr->size >= size) 
        {
            // Found a reusable block!
            curr->is_free = 0; // Mark as taken
            
            // Return pointer just AFTER the header
            return (void*)(curr + 1); 
        }
        curr = curr->next;
    }

    // 2. No free block found? Request new space from the "Wilderness"
    // We need space for the Header + the User's data
    uint32_t total_size = sizeof(BlockHeader) + size;
    
    // Save the location of the new block
    BlockHeader* new_block = (BlockHeader*)heap_top;
    
    // Move the heap top forward
    heap_top += total_size;

    // 3. Setup the header info
    new_block->size = size;
    new_block->is_free = 0; // Mark as taken
    new_block->next = 0;    // It's the last one for now

    // 4. Add this new block to our linked list
    if (free_list_head == 0) 
    {
        // First block ever allocated
        free_list_head = new_block;
    } 
    else 
    {
        // Append to the end of the list
        BlockHeader* temp = free_list_head;
        while (temp->next != 0) 
        {
            temp = temp->next;
        }
        temp->next = new_block;
    }

    // Return pointer just AFTER the header (User doesn't see the header)
    return (void*)(new_block + 1);
}

// In memory.c

void k_free(void* ptr) 
{
    if (ptr == 0) return;

    // 1. Recover the Header
    BlockHeader* header = (BlockHeader*)ptr - 1;

    // 2. Mark it as free
    header->is_free = 1;

    // --- COALESCING LOGIC (The Bonus Part) ---
    // Check if the NEXT block exists and is also free
    if (header->next != 0 && header->next->is_free == 1) 
    {
        // Merge them! 
        // 1. Add the size of the next block + the size of its header to our current size
        header->size += sizeof(BlockHeader) + header->next->size;
        
        // 2. Update our 'next' pointer to skip over the block we just swallowed
        header->next = header->next->next;
        
        // (Optional: You could repeat this loop to merge multiple consecutive blocks)
    }
}