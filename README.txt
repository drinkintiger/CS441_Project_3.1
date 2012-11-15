Vladimir Tsoy 
Jordan Harmel
CS 441/541
11/14/12

Description:
-------------------------------------------------------------------------------
Contains two programs that demonstrate the differences in speed over certain ways
of multipling a square matrix by a scalar and by another matrix of equal size.

The first program included demonstrates the differences between row major and
column major multiplication of a scalar to a square matrix.

The second multiplies a square matrix by another of equal size, this demonstrates
the six different ways that the arrays can be iteated through.

How to compile:
-------------------------------------------------------------------------------
A makefile is supplied with this assignment.
To compile the application:

   make

To clean the build:

   make clean

How to run:
-------------------------------------------------------------------------------
The scalar multiplication takes one optional input as the max size the arrays will
grow to, if no argument is passed it defaults to stop at 1024x1024.
In the shell type:

./scalarmult
or
./scalarmult 2048 

The matrix multplication also takes an optional argument or defaults to 1024.
Un the shell type:

./matrixmult
or
./matrixmult 2048

Example(s):
-------------------------------------------------------------------------------
This example runs scalar multiplication with 1 argument, the argument passed 
sets how big the final array wil be.

Example 1):
===============================================================================
shell$ ./scalarmult 2048
The average time to do scalar multiplication ij on a 2 x 2 matrix is 0.000001
The average time to do scalar multiplication ij on a 4 x 4 matrix is 0.000004
The average time to do scalar multiplication ij on a 8 x 8 matrix is 0.000002
The average time to do scalar multiplication ij on a 16 x 16 matrix is 0.000006
The average time to do scalar multiplication ij on a 32 x 32 matrix is 0.000010
The average time to do scalar multiplication ij on a 64 x 64 matrix is 0.000030
The average time to do scalar multiplication ij on a 128 x 128 matrix is 0.000140
The average time to do scalar multiplication ij on a 256 x 256 matrix is 0.000550
The average time to do scalar multiplication ij on a 512 x 512 matrix is 0.002360
The average time to do scalar multiplication ij on a 1024 x 1024 matrix is 0.008300
The average time to do scalar multiplication ij on a 2048 x 2048 matrix is 0.033152
------------------------------------------------------------------------------
The average time to do scalar multiplication ji on a 2 x 2 matrix is 0.000001
The average time to do scalar multiplication ji on a 4 x 4 matrix is 0.000002
The average time to do scalar multiplication ji on a 8 x 8 matrix is 0.000001
The average time to do scalar multiplication ji on a 16 x 16 matrix is 0.000002
The average time to do scalar multiplication ji on a 32 x 32 matrix is 0.000010
The average time to do scalar multiplication ji on a 64 x 64 matrix is 0.000040
The average time to do scalar multiplication ji on a 128 x 128 matrix is 0.000150
The average time to do scalar multiplication ji on a 256 x 256 matrix is 0.000710
The average time to do scalar multiplication ji on a 512 x 512 matrix is 0.004010
The average time to do scalar multiplication ji on a 1024 x 1024 matrix is 0.061524
The average time to do scalar multiplication ji on a 2048 x 2048 matrix is 0.249714


shell$

===============================================================================

This example runs the matrix multiplication with o arguments, the final array
will be an array 1024x1024

shell$: ./matrixmult
The average time to do matrix multiplication ijk on a 2 x 2 matrix is 0.000006
The average time to do matrix multiplication ijk on a 4 x 4 matrix is 0.000008
The average time to do matrix multiplication ijk on a 8 x 8 matrix is 0.000021
The average time to do matrix multiplication ijk on a 16 x 16 matrix is 0.00013
The average time to do matrix multiplication ijk on a 32 x 32 matrix is 0.001001
The average time to do matrix multiplication ijk on a 64 x 64 matrix is 0.004000
The average time to do matrix multiplication ijk on a 128 x 128 matrix is 0.030000
The average time to do matrix multiplication ijk on a 256 x 256 matrix is 0.244000
The average time to do matrix multiplication ijk on a 512 x 512 matrix is 2.294005
The average time to do matrix multiplication ijk on a 1024 x 1024 matrix is 64.094746
------------------------------------------------------------------------------
(It prints out 5 more chunks of code like this for each permutation of iterating
through the matricies, I have ommitted them because it is pretty redundant)

shell$:

===============================================================================
Questions(Scalar Multiplication):

The row-major multiplication had the best overall performance between the two.

Questions(Matrix Multiplication):

The ikj multiplication had the best performance
From best to worst it was ikj, kij, ijk, jik, and it's a toss up between jki and kji

-------------------------------------------------------------------------------

Known bugs & limitations:
-------------------------------------------------------------------------------
-None that we found.
