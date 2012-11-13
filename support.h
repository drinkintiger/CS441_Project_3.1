/*
 * Josh Hursey
 * Nov. 2, 2012
 *
 * CS 441/541 : Project 3 Part 1 Template
 *
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>
#include <math.h>
#if defined(__APPLE__)
#include <mach/mach_time.h>
#endif

/*****************************
 * Defines
 *****************************/
#define TRUE  1
#define FALSE 0

/* Millisecond: 1 second = 1000 msec */
#define TIME_MSEC     1000

/* Microsecond: 1 second = 1000000 usec */
#define TIME_USEC     1000000

/* Nanosecond: 1 second = 1000000000 nsec */
#define TIME_NSEC     1000000000

/* Page Size */
#define PAGESIZE 4096

/* Get a 1D index for a 2D array of 'size'
 * To access a 2D array element you would use:
 *    matrix[i][j]
 *
 * Since we have to use 1D arrays and impersonate 2D arrays
 * we need a macro to help with the conversion between the two.
 * If the size of the first dimension is 'size' then we can
 * rewrite the above expression as:
 *    matrix[ GET_INDEX(i, j, size) ]
 *
 */
#define GET_INDEX(i, j, size) ( i*size + j )

/*****************************
 * Structures
 *****************************/
/*
 * Type of the elements
 */
typedef double mtype_t;

/*
 * High precision timer for the given platform
 */
struct hptimer_t {
#if defined(__APPLE__)
    uint64_t ctime;
#else
#ifdef CLOCK_REALTIME
    struct timespec ctime;
#else
    struct timeval ctime;
#endif
#endif
};
typedef struct hptimer_t hptimer_t;

/*****************************
 * Global Variables
 *****************************/


/*****************************
 * Function Declarations
 *****************************/
/*
 * Initialize support library.
 *
 * Arguments:
 *   None
 *
 * Returns:
 *   0 on success
 *  -1 on error
 */
int support_init(void);

/*
 * Finalize support library
 *
 * Arguments:
 *   None
 *
 * Returns:
 *   0 on success
 *  -1 on error
 */
int support_finalize(void);

/*
 * Allocate a matrix along a page boundary
 *
 * Arguments:
 *   **matrix : A pointer to an array to allocate
 *   buffer_side : The length of one side of the matrix
 *
 * Returns:
 *   0 if the memory could be allocated
 *   non-0 if the memory could not be allocated
 *
 * Example:
 *   mtype_t *matrix = NULL;
 *   allocate_matrix(&matrix, buffer_side);
 */
int allocate_matrix( mtype_t **matrix, int buffer_side );

/*
 * Initialize the matrix to random values
 *
 * Arguments:
 *   *matrix : Matrix to initialize
 *   buffer_side : The length of one side of the matrix
 *
 * Returns:
 *   Nothing
 *
 * Example:
 *   mtype_t *matrix = NULL;
 *   allocate_matrix(&matrix, buffer_side);
 *   clear_matrix(matrix, buffer_side);
 */
void clear_matrix( mtype_t *matrix, int buffer_size);

/*
 * Get the current time
 *
 * Arguments:
 *   None
 *
 * Returns:
 *   Time structure
 */
hptimer_t get_time();

/*
 * Take the difference between two time structures
 *
 * Arguments:
 *   start  = Start time (must be smaller than End time)
 *   end    = End time (must be larger than Start time)
 *
 * Returns:
 *   Time in seconds
 */
double diff_timers(hptimer_t start, hptimer_t end);

/*
 * Convert the timer to to a double
 *
 * Arguments:
 *   ctime  = timer to convert
 *
 * Returns:
 *   Time in seconds
 */
double timer_to_double(hptimer_t ctime);


/*
 * Convert the number of bytes provided to a human readable string
 *
 * Arguments:
 *   bytes = number of bytes
 *
 * Returns:
 *   Human readable string
 */
char * human_readable(int bytes);
