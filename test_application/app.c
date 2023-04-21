#include <stdio.h>
#include <stdint.h>

int main()
{
  // Initialize constants
  const uint8_t BLOCK_OFFSET = 6;
  const int64_t CACHE_SIZE = 32768 * 16; // 2MB cache
  const int64_t NUM_SETS = 1 << 12; // 4096 sets
  const int64_t DIR_INDEX = 3; // Index of set bits in memory address
  

  // Initialize variables
  int64_t thrasher[CACHE_SIZE]; // Integer array for thrashing cache
  
  int set_1_start = 0;
  int set_1_index = set_1_start; // Index of cache set targeted for sending a 1

  int set_0_start = set_1_start + 4096*2;
  int set_0_index = set_0_start; // Index of cache set targeted for sending a 0

  printf("Cache thrashing");
  // Loop through cache sets
  for (int i = 0; i < 512; i++)
  {
    // Send a 1 to the target set
    thrasher[set_1_index] = 1;

    // Send a 0 to the target set
    thrasher[set_0_index] = 0;

    // Update indices for next iteration
    set_1_index += NUM_SETS << DIR_INDEX;
    set_0_index += NUM_SETS << DIR_INDEX;

    // Wrap indices around if necessary
    if (set_1_index >= CACHE_SIZE)
      set_1_index = set_1_start;
    if (set_0_index >= CACHE_SIZE)
      set_0_index = set_0_start;
  }

  printf("Cache thrashing complete.\n");

  return 0;
}
