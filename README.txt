Vladimir Tsoy 
Jordan Harmel
CS 441/541
11/4/12

Description:
-------------------------------------------------------------------------------
Implementation of the traffic intersection problem.

There is one program included. This program runs with one argument which denotes
the number of cars that approach the intersection.

How to compile:
-------------------------------------------------------------------------------
A makefile is supplied with this assignment.
To compile the application:

   make

To clean the build:

   make clean

How to run:
-------------------------------------------------------------------------------
To run the program type the following into the command line

   ./stoplight 5

Example(s):
-------------------------------------------------------------------------------
This example runs with 1 argument, the argument passed sets how many cars there 
will be.

Example 1):
===============================================================================
shell$ ./stoplight 5
Number of Cars:   5
-------------------------------
 Car ID |   Approach from |       Travel to |           State | Time (msec)
--------+-----------------+-----------------+-----------------+--------------
      3 |            East |           North |        Approach |      0.000
      3 |            East |           North |        Go Right |      0.006
      4 |            East |           North |        Approach |      0.000
      1 |            West |           North |        Approach |      0.000
      0 |           North |            East |        Approach |      0.000
      2 |           North |            West |        Approach |      0.000
      1 |            West |           North |         Go Left |      1.627
      3 |            East |           North |           Leave |      2.461
      1 |            West |           North |           Leave |      8.994
      0 |           North |            East |         Go Left |      7.962
      4 |            East |           North |        Go Right |      8.948
      4 |            East |           North |           Leave |     11.634
      0 |           North |            East |           Leave |     14.413
      2 |           North |            West |        Go Right |     14.227
      2 |           North |            West |           Leave |     16.771
--------+-----------------+-----------------+-----------------+--------------
Min.  time:      2.461
Avg.  time:     10.855
Max.  time:     16.771
Total time:     54.273
--------+-----------------+-----------------+-----------------+--------------

shell$

===============================================================================

Testing:
-------------------------------------------------------------------------------
To test the program, we tried to pass too many or too few arguments to test
that it only accepted the proper amount of arguments. Also, we tried passing
invalid inputs to make sure that they are caught. The code you provided seems 
to provide this functionality.

Special Section: (Pre Programming)

1. The intersection is being controlled by a first come first serve manner, in which
   only one car may be in the intersection at one time no matter the direction of the two.
   It is a solution, but suboptimal because, if there is a car approaching from the north 
   that wants to go straight and another car that approaches from the south and wants to 
   go straight and a third car from either the west or east arrives between the first and
   second. The northbound and southbound cars will not be able to go at the same time, the 
   northbound car will have to wait until the car that approached from the east or west has 
   left the intersection which, is only after the southbound car has also left.   
2. The instance that can produce a deadlock is when there are four cars arriving from each
   of the directions at the same time and all of them want to make a left turn.
Special Section: (Post Programming)

1. This program does not deadlock because of the way we distribute the locks.
   We avoid the situation where one car will acquire a lock and wait on another
   lock that is being held by another car. 
2. Accidents are prevented by using semaphore for each quadrant of the intersection
   to ensure that there are not two cars occupying the same quadrant at the same time.
3. Starvation is addressed by not blocking the entire intersection while there is a 
   car in the intersection.
4. Traffic flow is improved because if you have two cars that want to go straight
   it will allow them to both go, instead of having one go and then having the other
   go once the first car has exited the intersection.
5. Fairness is implemented by using semaphores for each direction to ensure that a 
   car that arrives say at the north behind another car at the north doesn't go 
   before the first car.
-------------------------------------------------------------------------------

Known bugs & limitations:
-------------------------------------------------------------------------------
-None that we found.
