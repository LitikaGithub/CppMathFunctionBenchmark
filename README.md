# Tests the speed of functions in the standard math library

## Notes
 * This code has been tested with gcc 9 on Ubuntu 18.04 and 20.04, as well as on Visual Studio 2019 on Windows 10.
 
 * The results show remarkable differences between the std math libraries that come from Microsoft and Visual Studio, and GCC/Linux. Worth exploring
 
 * While I have not tested the Windows version on multiple hardware generations, the performance difference of the same linux executable on different generations of the I7 processor is quite significant on some functions. Again, worth exploring.
 
 * In the code, where the array of tests is initialized, you will notice that there multiple tests for the same function. These are to explore the performance implications of value ranges on those functions. Feel free to add your own tests. All you need to do is add a line with the correct parameters. 
 
 * There might be more clever ways to time the commands in a way that does not include the overhead of the loops. I am open to suggestions.

 

## Results

```
$ ./CppMathFunctionBenchmark

            operator   time (s)  rel. time        op/s     cyc/op       minA       maxA        minB       maxB
                acos   0.107136  43.201621   9.334e+07     38.529 [ -1.00e+00 -   1.00e+00]
             acosh_1   0.155274  62.612847   6.440e+07     55.962 [  1.00e+00 -   1.00e+01]
             acosh_2   0.146789  59.191379   6.813e+07     52.928 [  1.00e+00 -  1.80e+308]
                asin   0.111601  45.002057   8.961e+07     40.290 [ -1.00e+00 -   1.00e+00]
             asinh_1   0.235600  95.003871   4.244e+07     84.781 [ -1.00e+01 -   1.00e+01]
             asinh_2   0.099696  40.201621   1.003e+08     35.936 [ -3.40e+38 -   3.40e+38]
             asinh_3   0.099200  40.001613   1.008e+08     35.792 [-8.99e+307 -  8.99e+307]
                atan   0.111600  45.001855   8.961e+07     40.110 [ -1.00e+00 -   1.00e+00]
               atanh   0.174096  70.202710   5.744e+07     62.788 [ -1.00e+00 -   1.00e+00]
                cbrt   0.408233 164.616718   2.450e+07    146.962 [ -3.40e+38 -   3.40e+38]
                ceil   0.005431   2.189887   1.841e+09      2.003 [ -3.40e+38 -   3.40e+38]
            copysign   0.043648  17.600710   2.291e+08     15.748 [ -3.40e+38 -   3.40e+38]  [ -3.40e+38 -   3.40e+38]
               cos_1   0.077376  31.201177   1.292e+08     27.901 [ -3.14e+00 -   3.14e+00]
               cos_2   0.083328  33.601436   1.200e+08     30.005 [  0.00e+00 -   6.28e+00]
               cos_3   0.202368  81.603290   4.941e+07     72.827 [ -3.40e+38 -   3.40e+38]
              cosh_1   0.121024  48.802169   8.263e+07     43.628 [ -1.00e+00 -   1.00e+00]
              cosh_2   0.145824  58.802411   6.858e+07     52.557 [ -7.10e+02 -   7.10e+02]
                 div   0.004464   1.799992   2.240e+09      1.586 [ -3.40e+38 -   3.40e+38]  [ -3.40e+38 -   3.40e+38]
                 exp   0.040176  16.200573   2.489e+08     14.520 [ -2.00e+02 -   2.00e+02]
               floor   0.005456   2.199968   1.833e+09      1.979 [ -3.40e+38 -   3.40e+38]
               isinf   0.026288  10.600589   3.804e+08      9.329 [ -3.40e+38 -   3.40e+38]
               isnan   0.004960   2.000040   2.016e+09      1.977 [ -3.40e+38 -   3.40e+38]
            isnormal   0.023808   9.600468   4.200e+08      8.665 [ -3.40e+38 -   3.40e+38]
                j0_1   0.162192  65.402557   6.166e+07     58.453 [ -1.00e+01 -   1.00e+01]
                j0_2   0.514352 207.408242   1.944e+07    185.090 [ -3.40e+38 -   3.40e+38]
                j0_3   1.408144 567.822815   7.102e+06    506.873 [-8.99e+307 -  8.99e+307]
                j1_1   0.168144  67.802936   5.947e+07     60.529 [ -1.00e+01 -   1.00e+01]
                j1_2   0.514848 207.608210   1.942e+07    185.202 [ -3.40e+38 -   3.40e+38]
                j1_3   1.346640 543.021815   7.426e+06    484.842 [-8.99e+307 -  8.99e+307]
                 log   0.048608  19.600669   2.057e+08     17.495 [  1.00e+00 -   3.40e+38]
               log10   0.046624  18.800879   2.145e+08     16.697 [  1.00e+00 -   3.40e+38]
               minus   0.002480   1.000000   4.032e+09      0.982 [ -3.40e+38 -   3.40e+38]  [ -3.40e+38 -   3.40e+38]
                mult   0.002480   1.000081   4.032e+09      0.985 [ -3.40e+38 -   3.40e+38]  [ -3.40e+38 -   3.40e+38]
         nearbyint_1   0.197408  79.603210   5.066e+07     71.080 [ -2.00e+00 -   2.00e+00]
         nearbyint_2   0.198896  80.203395   5.028e+07     71.734 [ -1.00e+01 -   1.00e+01]
         nearbyint_3   0.163654  65.992217   6.110e+07     58.955 [ -1.00e+06 -   1.00e+06]
         nearbyint_4   0.076384  30.801202   1.309e+08     27.548 [ -3.40e+38 -   3.40e+38]
                plus   0.002480   1.000081   4.032e+09      0.987 [ -3.40e+38 -   3.40e+38]  [ -3.40e+38 -   3.40e+38]
                 pow   0.375472 151.406065   2.663e+07    135.102 [ -3.40e+38 -   3.40e+38]  [ -1.00e+00 -   1.00e+00]
             round_1   0.159216  64.202629   6.281e+07     57.224 [ -2.00e+00 -   2.00e+00]
             round_2   0.160208  64.602565   6.242e+07     57.725 [ -1.00e+01 -   1.00e+01]
             round_3   0.123008  49.601960   8.130e+07     44.373 [ -1.00e+06 -   1.00e+06]
             round_4   0.037201  15.000847   2.688e+08     13.469 [ -3.40e+38 -   3.40e+38]
               sin_1   0.077897  31.411267   1.284e+08     28.053 [ -3.14e+00 -   3.14e+00]
               sin_2   0.083824  33.801323   1.193e+08     30.229 [  0.00e+00 -   6.28e+00]
               sin_3   0.202367  81.603089   4.942e+07     72.856 [ -3.40e+38 -   3.40e+38]
              sinh_1   0.123504  49.802089   8.097e+07     44.433 [ -1.00e+00 -   1.00e+00]
              sinh_2   0.138880  56.002178   7.200e+07     50.023 [ -7.10e+02 -   7.10e+02]
                sqrt   0.006448   2.600185   1.551e+09      2.359 [  0.00e+00 -   3.40e+38]
               tan_1   0.102176  41.201500   9.787e+07     36.755 [ -3.14e+00 -   3.14e+00]
               tan_2   0.106640  43.001734   9.377e+07     38.384 [  0.00e+00 -   6.28e+00]
               tan_3   0.234112  94.404008   4.271e+07     84.117 [ -3.40e+38 -   3.40e+38]
              tanh_1   0.074895  30.200976   1.335e+08     26.842 [ -1.00e+00 -   1.00e+00]
              tanh_2   0.156240  63.002621   6.400e+07     56.095 [ -1.90e+01 -   1.90e+01]
              tanh_3   0.124992  50.402032   8.001e+07     44.999 [ -4.00e+01 -   4.00e+01]



