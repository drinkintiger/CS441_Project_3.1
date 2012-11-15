/*
 * <AUTHOR>
 * <DATE>
 *
 * CS 441/541 : Project 3 Part 1
 */
#include "matrixmult.h"

double run_experiment_ijk ( mtype_t *matrix_a , mtype_t *matrix_b , mtype_t *matrix_c , int buffer_size );
double run_experiment_ikj ( mtype_t *matrix_a , mtype_t *matrix_b , mtype_t *matrix_c , int buffer_size );
double run_experiment_jik ( mtype_t *matrix_a , mtype_t *matrix_b , mtype_t *matrix_c , int buffer_size );
double run_experiment_jki ( mtype_t *matrix_a , mtype_t *matrix_b , mtype_t *matrix_c , int buffer_size );
double run_experiment_kij ( mtype_t *matrix_a , mtype_t *matrix_b , mtype_t *matrix_c , int buffer_size );
double run_experiment_kji ( mtype_t *matrix_a , mtype_t *matrix_b , mtype_t *matrix_c , int buffer_size );
int MAX_ITERS = 1000;

int main(int argc, char * argv[]) {
    mtype_t * matrix_a = NULL ;
    mtype_t * matrix_b = NULL ;
    mtype_t * matrix_c = NULL ;
    int i, MAX_SIZE;
    double avg_time;
    support_init();
    
    MAX_ITERS = 5;
    
    if(argc==2)
        if(atoi(argv[1])>=2)
            MAX_SIZE = atoi(argv[1]);
        else{
        printf("The argument must be an integer and larger than or equal to 2");
        return -1;
        }
    else if(argc>2){
        printf("This program takes one or no arguments, you entered too many.");
        return -1;
    }
    else MAX_SIZE = 1024;
    for ( i = 2; i <= MAX_SIZE; i = i * 2 ) {
        // Allocate a matrix of size : buffer_side x buffer_side
        allocate_matrix (& matrix_a , i );
        allocate_matrix (& matrix_b , i );
        allocate_matrix (& matrix_c , i );
        // Clear / Initialize the matrix
        clear_matrix (matrix_a , i );
        clear_matrix (matrix_b , i );
        clear_matrix (matrix_c , i );
        
        avg_time = run_experiment_ijk (matrix_a, matrix_b, matrix_c, i);
        printf("The average time to do matrix multiplication ijk on a %d x %d matrix is %f \n", i, i, avg_time);
        
        avg_time = run_experiment_jik (matrix_a, matrix_b, matrix_c, i);
        printf("The average time to do matrix multiplication jik on a %d x %d matrix is %f \n", i, i, avg_time);
        

        avg_time = run_experiment_jki (matrix_a, matrix_b, matrix_c, i);
        printf("The average time to do matrix multiplication jki on a %d x %d matrix is %f \n", i, i, avg_time);
        
        avg_time = run_experiment_ikj (matrix_a, matrix_b, matrix_c, i);
        printf("The average time to do matrix multiplication ikj on a %d x %d matrix is %f \n", i, i, avg_time);
        

        avg_time = run_experiment_kji (matrix_a, matrix_b, matrix_c, i);
        printf("The average time to do matrix multiplication kji on a %d x %d matrix is %f \n", i, i, avg_time);
        

        avg_time = run_experiment_kij (matrix_a, matrix_b, matrix_c, i);
        printf("The average time to do matrix multiplication kij on a %d x %d matrix is %f \n", i, i, avg_time);
        
        free(matrix_a);
        free(matrix_b);
        free(matrix_c);
        printf("------------------------------------------------------------------------------\n");
    }
    printf("------------------------------------------------------------------------------\n");
   /* for ( i = 2; i <= MAX_SIZE; i = i * 2 ) {
        // Allocate a matrix of size : buffer_side x buffer_side
        allocate_matrix (& matrix_a , i );
        allocate_matrix (& matrix_b , i );
        allocate_matrix (& matrix_c , i );
        // Clear / Initialize the matrix
        clear_matrix (matrix_a , i );
        clear_matrix (matrix_b , i );
        clear_matrix (matrix_c , i );
        
        avg_time = run_experiment_jik (matrix_a, matrix_b, matrix_c, i);
        printf("The average time to do matrix multiplication jik on a %d x %d matrix is %f \n", i, i, avg_time);
        
        free(matrix_a);
        free(matrix_b);
        free(matrix_c);
    }
    printf("------------------------------------------------------------------------------\n");
    for ( i = 2; i <= MAX_SIZE; i = i * 2 ) {
        // Allocate a matrix of size : buffer_side x buffer_side
        allocate_matrix (& matrix_a , i );
        allocate_matrix (& matrix_b , i );
        allocate_matrix (& matrix_c , i );
        // Clear / Initialize the matrix
        clear_matrix (matrix_a , i );
        clear_matrix (matrix_b , i );
        clear_matrix (matrix_c , i );
        
        avg_time = run_experiment_jki (matrix_a, matrix_b, matrix_c, i);
        printf("The average time to do matrix multiplication jki on a %d x %d matrix is %f \n", i, i, avg_time);
        
        free(matrix_a);
        free(matrix_b);
        free(matrix_c);
    }
    printf("------------------------------------------------------------------------------\n");
    for ( i = 2; i <= MAX_SIZE; i = i * 2 ) {
        // Allocate a matrix of size : buffer_side x buffer_side
        allocate_matrix (& matrix_a , i );
        allocate_matrix (& matrix_b , i );
        allocate_matrix (& matrix_c , i );
        // Clear / Initialize the matrix
        clear_matrix (matrix_a , i );
        clear_matrix (matrix_b , i );
        clear_matrix (matrix_c , i );
        
        avg_time = run_experiment_ikj (matrix_a, matrix_b, matrix_c, i);
        printf("The average time to do matrix multiplication ikj on a %d x %d matrix is %f \n", i, i, avg_time);
        
        free(matrix_a);
        free(matrix_b);
        free(matrix_c);
    }
    printf("------------------------------------------------------------------------------\n");
    for ( i = 2; i <= MAX_SIZE; i = i * 2 ) {
        // Allocate a matrix of size : buffer_side x buffer_side
        allocate_matrix (& matrix_a , i );
        allocate_matrix (& matrix_b , i );
        allocate_matrix (& matrix_c , i );
        // Clear / Initialize the matrix
        clear_matrix (matrix_a , i );
        clear_matrix (matrix_b , i );
        clear_matrix (matrix_c , i );
        
        avg_time = run_experiment_kji (matrix_a, matrix_b, matrix_c, i);
        printf("The average time to do matrix multiplication kji on a %d x %d matrix is %f \n", i, i, avg_time);
        
        free(matrix_a);
        free(matrix_b);
        free(matrix_c);
    }
    printf("------------------------------------------------------------------------------\n");
    for ( i = 2; i <= MAX_SIZE; i = i * 2 ) {
        // Allocate a matrix of size : buffer_side x buffer_side
        allocate_matrix (& matrix_a , i );
        allocate_matrix (& matrix_b , i );
        allocate_matrix (& matrix_c , i );
        // Clear / Initialize the matrix
        clear_matrix (matrix_a , i );
        clear_matrix (matrix_b , i );
        clear_matrix (matrix_c , i );
        
        avg_time = run_experiment_kij (matrix_a, matrix_b, matrix_c, i);
        printf("The average time to do matrix multiplication kij on a %d x %d matrix is %f \n", i, i, avg_time);
        
        free(matrix_a);
        free(matrix_b);
        free(matrix_c);
    }*/
    return 0;
}

double run_experiment_ijk ( mtype_t * matrix_a , mtype_t * matrix_b , mtype_t * matrix_c , int buffer_size ) {
    int i, j, k, iter;
    hptimer_t start , end;
    double final_time ;
    
    start = get_time ();
    for ( iter = 0; iter < MAX_ITERS ; ++ iter ) {
        for ( i = 0; i < buffer_size ; ++ i ) {
            for ( j = 0; j < buffer_size ; ++ j ) {
                for ( k = 0; k < buffer_size ; ++ k ) {
                    matrix_c [ GET_INDEX (i, j, buffer_size ) ] += matrix_a [ GET_INDEX (i, k, buffer_size ) ] * matrix_b [ GET_INDEX (k, j, buffer_size ) ];
                }
            }
        }
    }
    end = get_time ();
    return final_time = diff_timers (start , end) / MAX_ITERS ;
}

double run_experiment_jik ( mtype_t * matrix_a , mtype_t * matrix_b , mtype_t * matrix_c , int buffer_size ) {
    int i, j, k, iter;
    hptimer_t start , end;
    double final_time ;
    
    start = get_time ();
    for ( iter = 0; iter < MAX_ITERS ; ++ iter ) {
        for ( j = 0; j < buffer_size ; ++ j ) {
            for ( i = 0; i < buffer_size ; ++ i ) {
                for ( k = 0; k < buffer_size ; ++ k ) {
                    matrix_c [ GET_INDEX (i, j, buffer_size ) ] += matrix_a [ GET_INDEX (i, k, buffer_size ) ] * matrix_b [ GET_INDEX (k, j, buffer_size ) ];
                }
            }
        }
    }
    end = get_time ();
    return final_time = diff_timers (start , end) / MAX_ITERS ;
}

double run_experiment_jki ( mtype_t * matrix_a , mtype_t * matrix_b , mtype_t * matrix_c , int buffer_size ) {
    int i, j, k, iter;
    hptimer_t start , end;
    double final_time ;
    
    start = get_time ();
    for ( iter = 0; iter < MAX_ITERS ; ++ iter ) {
        for ( j = 0; j < buffer_size ; ++ j ) {
            for ( k = 0; k < buffer_size ; ++ k ) {
                for ( i = 0; i < buffer_size ; ++ i ) {
                    matrix_c [ GET_INDEX (i, j, buffer_size ) ] += matrix_a [ GET_INDEX (i, k, buffer_size ) ] * matrix_b [ GET_INDEX (k, j, buffer_size ) ];
                }
            }
        }
    }
    end = get_time ();
    return final_time = diff_timers (start , end) / MAX_ITERS ;
}

double run_experiment_ikj ( mtype_t * matrix_a , mtype_t * matrix_b , mtype_t * matrix_c , int buffer_size ) {
    int i, j, k, iter;
    hptimer_t start , end;
    double final_time ;
    
    start = get_time ();
    for ( iter = 0; iter < MAX_ITERS ; ++ iter ) {
        for ( i = 0; i < buffer_size ; ++ i ) {
            for ( k = 0; k < buffer_size ; ++ k ) {
                for ( j = 0; j < buffer_size ; ++ j ) {
                    matrix_c [ GET_INDEX (i, j, buffer_size ) ] += matrix_a [ GET_INDEX (i, k, buffer_size ) ] * matrix_b [ GET_INDEX (k, j, buffer_size ) ];
                }
            }
        }
    }
    end = get_time ();
    return final_time = diff_timers (start , end) / MAX_ITERS ;
}

double run_experiment_kji ( mtype_t * matrix_a , mtype_t * matrix_b , mtype_t * matrix_c , int buffer_size ) {
    int i, j, k, iter;
    hptimer_t start , end;
    double final_time ;
    
    start = get_time ();
    for ( iter = 0; iter < MAX_ITERS ; ++ iter ) {
        for ( k = 0; k < buffer_size ; ++ k ) {
            for ( j = 0; j < buffer_size ; ++ j ) {
                for ( i = 0; i < buffer_size ; ++ i ) {
                    matrix_c [ GET_INDEX (i, j, buffer_size ) ] += matrix_a [ GET_INDEX (i, k, buffer_size ) ] * matrix_b [ GET_INDEX (k, j, buffer_size ) ];
                }
            }
        }
    }
    end = get_time ();
    return final_time = diff_timers (start , end) / MAX_ITERS ;
}

double run_experiment_kij ( mtype_t * matrix_a , mtype_t * matrix_b , mtype_t * matrix_c , int buffer_size ) {
    int i, j, k, iter;
    hptimer_t start , end;
    double final_time ;
    
    start = get_time ();
    for ( iter = 0; iter < MAX_ITERS ; ++ iter ) {
        for ( k = 0; k < buffer_size ; ++ k ) {
            for ( i = 0; i < buffer_size ; ++ i ) {
                for ( j = 0; j < buffer_size ; ++ j ) {
                    matrix_c [ GET_INDEX (i, j, buffer_size ) ] += matrix_a [ GET_INDEX (i, k, buffer_size ) ] * matrix_b [ GET_INDEX (k, j, buffer_size ) ];
                }
            }
        }
    }
    end = get_time ();
    return final_time = diff_timers (start , end) / MAX_ITERS ;
}
