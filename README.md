# Tests the speed of functions in the standard math library

## Notes
 * This code has been tested with gcc 9 on Ubuntu 18.04 and 20.04, as well as on Visual Studio 2019 on Windows 10.
 
 * The results show remarkable differences between the std math libraries that come from Microsoft and Visual Studio, and GCC/Linux. Worth exploring
 
 * While I have not tested the Windows version on multiple hardware generations, the performance difference of the same linux executable on different generations of the I7 processor is quite significant on some functions. Again, worth exploring.
 
 * In the code, where the array of tests is initialized, you will notice that there multiple tests for the same function. These are to explore the performance implications of value ranges on those functions. Feel free to add your own tests. All you need to do is add a line with the correct parameters. 
 
 * The ability to resize the number of samples from the command line has been removed. It is too easy to put in values that invalidate the cache. There is no harm, however, in allowing the user the modify the number of repetitions and that might be added in the future.

 * There might be more clever ways to time the commands.

 * When the arrays are larger than the L3-cache size,
   speed is capped.

 * The operators are called within a double loop-which has some overhead. 
   That is not compensated for.

 * 
 * See also [https://latkin.org/blog/2014/11/09/a-simple-benchmark-of-various-math-operations/](https://latkin.org/blog/2014/11/09/a-simple-benchmark-of-various-math-operations/)

## Results

```
$ ./CppMathFunctionBenchmark

            operator   time (s)  rel. time        op/s     cyc/op       minA       maxA        minB       maxB
                acos   0.107155  43.214591   9.332e+07     38.458 [ -1.00e+00 -   1.00e+00]
             acosh_1   0.155744  62.809969   6.421e+07     56.153 [  1.00e+00 -   1.00e+03]
             acosh_2   0.064505  26.014196   1.550e+08     23.256 [  1.00e+00 -   3.40e+38]
                asin   0.112567  45.397080   8.884e+07     40.488 [ -1.00e+00 -   1.00e+00]
             asinh_1   0.235128  94.825173   4.253e+07     84.656 [ -1.00e+01 -   1.00e+01]
             asinh_2   0.097686  39.395911   1.024e+08     35.140 [ -3.40e+38 -   3.40e+38]
                atan   0.111129  44.817309   8.999e+07     39.951 [ -1.00e+00 -   1.00e+00]
               atanh   0.174094  70.210437   5.744e+07     62.584 [ -1.00e+00 -   1.00e+00]
                cbrt   0.406218 163.823883   2.462e+07    146.334 [ -3.40e+38 -   3.40e+38]
                ceil   0.004961   2.000686   2.016e+09      1.983 [ -3.40e+38 -   3.40e+38]
            copysign   0.043672  17.612558   2.290e+08     15.756 [ -3.40e+38 -   3.40e+38]  [ -3.40e+38 -   3.40e+38]
               cos_1   0.077401  31.214954   1.292e+08     27.931 [ -3.14e+00 -   3.14e+00]
               cos_2   0.083794  33.793394   1.193e+08     30.100 [  0.00e+00 -   6.28e+00]
               cos_3   0.201896  81.422971   4.953e+07     72.714 [ -3.40e+38 -   3.40e+38]
              cosh_1   0.117059  47.208743   8.543e+07     42.239 [ -2.00e+00 -   2.00e+00]
              cosh_2   0.147340  59.420713   6.787e+07     52.941 [ -2.00e+02 -   2.00e+02]
                 div   0.004439   1.790248   2.253e+09      1.578 [ -3.40e+38 -   3.40e+38]  [ -3.40e+38 -   3.40e+38]
                 exp   0.040670  16.401678   2.459e+08     14.523 [ -2.00e+02 -   2.00e+02]
               floor   0.005456   2.200395   1.833e+09      1.982 [ -3.40e+38 -   3.40e+38]
               isinf   0.025765  10.390749   3.881e+08      9.370 [ -3.40e+38 -   3.40e+38]
               isnan   0.005455   2.199992   1.833e+09      1.974 [ -3.40e+38 -   3.40e+38]
            isnormal   0.024303   9.800976   4.115e+08      8.699 [ -3.40e+38 -   3.40e+38]
                j0_1   0.163184  65.810494   6.128e+07     58.767 [ -1.00e+01 -   1.00e+01]
                j0_2   0.501455 202.232296   1.994e+07    180.591 [ -3.40e+38 -   3.40e+38]
                j0_3   1.410124 568.690273   7.092e+06    507.660 [-8.99e+307 -  8.99e+307]
                j1_1   0.168640  68.011010   5.930e+07     60.855 [ -1.00e+01 -   1.00e+01]
                j1_2   0.512335 206.619979   1.952e+07    184.454 [ -3.40e+38 -   3.40e+38]
                j1_3   1.349630 544.293515   7.409e+06    485.885 [-8.99e+307 -  8.99e+307]
                 log   0.043151  17.402484   2.317e+08     15.552 [  1.00e+00 -   3.40e+38]
               log10   0.045657  18.413131   2.190e+08     16.511 [  1.00e+00 -   3.40e+38]
               minus   0.002480   1.000000   4.033e+09      0.946 [ -3.40e+38 -   3.40e+38]  [ -3.40e+38 -   3.40e+38]
                mult   0.002505   1.010284   3.992e+09      0.898 [ -3.40e+38 -   3.40e+38]  [ -3.40e+38 -   3.40e+38]
         nearbyint_1   0.197407  79.612639   5.066e+07     71.091 [ -2.00e+00 -   2.00e+00]
         nearbyint_2   0.199392  80.412889   5.015e+07     71.688 [ -1.00e+01 -   1.00e+01]
         nearbyint_3   0.164647  66.400589   6.074e+07     59.349 [ -1.00e+06 -   1.00e+06]
         nearbyint_4   0.076880  31.004880   1.301e+08     27.618 [ -3.40e+38 -   3.40e+38]
                plus   0.002480   1.000202   4.032e+09      0.920 [ -3.40e+38 -   3.40e+38]  [ -3.40e+38 -   3.40e+38]
                 pow   0.380953 153.634699   2.625e+07    137.051 [ -3.40e+38 -   3.40e+38]  [ -1.00e+00 -   1.00e+00]
             round_1   0.160209  64.610703   6.242e+07     57.511 [ -2.00e+00 -   2.00e+00]
             round_2   0.163209  65.820657   6.127e+07     58.721 [ -1.00e+01 -   1.00e+01]
             round_3   0.123975  49.997943   8.066e+07     44.595 [ -1.00e+06 -   1.00e+06]
             round_4   0.037201  15.002662   2.688e+08     13.389 [ -3.40e+38 -   3.40e+38]
               sin_1   0.076414  30.817269   1.309e+08     27.467 [ -3.14e+00 -   3.14e+00]
               sin_2   0.082832  33.405348   1.207e+08     30.146 [  0.00e+00 -   6.28e+00]
               sin_3   0.202368  81.613083   4.941e+07     72.832 [ -3.40e+38 -   3.40e+38]
              sinh_1   0.122982  49.597717   8.131e+07     44.234 [ -2.00e+00 -   2.00e+00]
              sinh_2   0.140395  56.620181   7.123e+07     50.720 [ -2.00e+02 -   2.00e+02]
                sqrt   0.006942   2.799605   1.441e+09      2.373 [  0.00e+00 -   3.40e+38]
               tan_1   0.102176  41.206525   9.787e+07     36.771 [ -3.14e+00 -   3.14e+00]
               tan_2   0.105620  42.595782   9.468e+07     38.060 [  0.00e+00 -   6.28e+00]
               tan_3   0.234583  94.605299   4.263e+07     84.412 [ -3.40e+38 -   3.40e+38]
              tanh_1   0.135407  54.608405   7.385e+07     48.844 [ -2.00e+00 -   2.00e+00]
              tanh_2   0.073878  29.794241   1.354e+08     26.662 [ -2.00e+02 -   2.00e+02]


