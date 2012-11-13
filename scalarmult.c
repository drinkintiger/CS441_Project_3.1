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
    int i, MAX_SIZE;
    support_init();

    support_finalize();
    if(argc==2)
        MAX_SIZE = atoi(argv[1]);
    else MAX_SIZE = 1024;
    for ( i = 2; i <= MAX_SIZE; i = i * 2 ) {
        // Allocate a matrix of size : buffer_side x buffer_side
        allocate_matrix (& matrix , i );
        // Clear / Initialize the matrix
        clear_matrix (matrix , i );
    }
    return 0;
}

double run_experiment_ij ( mtype_t *matrix , mtype_t scalar , int buffer_size ) {
    int i, j, iter;
    hptimer_t start , end;
    double final_time ;
    
    start = get_time ();
    for ( iter = 0; iter < 5 ; ++ iter ) {
        for (i = 0; i < buffer_size ; ++i ) {
            for (j = 0; j < buffer_size ; ++j ) {
                matrix [ GET_INDEX (i, j, buffer_size ) ] = scalar * matrix [ GET_INDEX (i, j, buffer_size ) ];
            }
        }
    }
    end = get_time ();
    return final_time = diff_timers (start , end) / 5 ;
}
