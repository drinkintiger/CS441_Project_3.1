/*
 * Vladimir Tsoy and Jordan Harmel
 * 11/12/12
 *
 * CS 441/541 : Project 3 Part 1
 */
#include "scalarmult.h"

double run_experiment_ij ( mtype_t *matrix , mtype_t scalar , int buffer_size );

int main(int argc, char * argv[]) {
    mtype_t * matrix = NULL ;
    int i;
    support_init();

    support_finalize();

    // Access matrix [i][j] in the 1D array
    matrix [ GET_INDEX (i, j, buffer_side ) ] = ...;
    
    for ( i = 2; i <= 1024; i * 2 ) {
        // Allocate a matrix of size : buffer_side x buffer_side
        allocate_matrix (& matrix , i );
        // Clear / Initialize the matrix
        clear_matrix (matrix , i );
    }

double run_experiment_ij ( mtype_t *matrix , mtype_t scalar , int buffer_size ) {
    int i, j, iter;
    hptimer_t start , end;
    double final_time ;
    
    start = get_time ();
    for ( iter = 0; iter < MAX_ITERS ; ++ iter ) {
        for (i = 0; i < buffer_size ; ++i ) {
            for (j = 0; j < buffer_size ; ++j ) {
                matrix [i][j] = scalar * matrix [i][j];
            }
        }
    }
    end = get_time ();
    final_time = diff_timers (start , end) / MAX_ITERS ;
}
    return 0;
}
