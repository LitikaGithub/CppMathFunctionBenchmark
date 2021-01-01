
// system headers

#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES  1
#include <math.h>
#include <time.h>
#include <stdint.h>

// stl

#include <algorithm>
#include <cfloat>
#include <random>
#include <string>
#include <unordered_map>
#include <vector>

// system dependent stuff

#if _WIN64 || _WIN32
#include <windows.h>
    #define CLOCK_REALTIME 1

    int clock_gettime(int, struct timespec * spec)      //C-file part
    {
        __int64 wintime; GetSystemTimeAsFileTime((FILETIME *)&wintime);
        wintime      -=116444736000000000i64;  //1jan1601 to 1jan1970
        spec->tv_sec  =wintime / 10000000i64;           //seconds
        spec->tv_nsec =wintime % 10000000i64 *100;      //nano-seconds
        return 0;
    }
#else
    #include <unistd.h>
    #include <x86intrin.h>
#endif

// type declarations used down below

typedef void (*TestFunc1)(const double *, double *, const int);
typedef void (*TestFunc2)(const double *, const double *, double *, const int);

struct TestResult
{
    double  time = 0.0;
    uint64_t nCycles = 0;
    int nRanges = 0;
    double  minVal1;
    double  maxVal1;
    double  minVal2;
    double  maxVal2;
};

struct TestDef1 {
    std::string name;
    TestFunc1 fun;
    double  minVal = 0.0;
    double  maxVal = 1.0;
} ;

struct TestDef2 {
    std::string name;
    TestFunc2 fun;
    double  minVal1 = 0.0;
    double  maxVal1 = 1.0;
    double  minVal2 = 0.0;
    double  maxVal2 = 1.0;
};



void op_plus(const double * A, const double * B, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = A[kk] + B[kk];
}

void op_minus(const double * A, const double * B, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = A[kk] - B[kk];
}

void op_div(const double * A, const double * B, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = A[kk] / B[kk];
}

void op_mult(const double * A, const double * B, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = A[kk] * B[kk];
}

void op_sqrt(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = sqrt(A[kk]);
}

void op_cbrt(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = cbrt(A[kk]);
}

void op_sin(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = sin(A[kk]);
}

void op_cos(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = cos(A[kk]);
}

void op_cosh(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = cosh(A[kk]);
}


void op_j0(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
    {
#if _WIN64 || _WIN32
        C[kk] = _j0(A[kk]);
#else
        C[kk] = j0(A[kk]);
#endif
    }
}

void op_j1(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
    {
#if _WIN64 || _WIN32
        C[kk] = _j1(A[kk]);
#else
        C[kk] = j1(A[kk]);
#endif
    }
}

void op_acos(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = acos(A[kk]);
}

void op_acosh(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = acosh(A[kk]);
}

void op_asin(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = asin(A[kk]);
}

void op_asinh(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = asinh(A[kk]);
}

void op_sinh(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = sinh(A[kk]);
}

void op_log(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = log(A[kk]);
}

void op_log10(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = log10(A[kk]);
}

void op_copysign(const double * A, const double * B, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = copysign(A[kk], B[kk]);
}

void op_pow(const double * A, const double * B, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = pow(A[kk], B[kk]);
}

void op_exp(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = exp(A[kk]);
}

void op_tan(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = tan(A[kk]);
}

void op_atan(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = atan(A[kk]);
}

void op_atanh(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = atanh(A[kk]);
}

void op_tanh(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = tanh(A[kk]);
}

void op_round(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = round(A[kk]);
}

void op_nearbyint(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = nearbyint(A[kk]);
}

void op_ceil(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = ceil(A[kk]);
}

void op_floor(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = floor(A[kk]);
}


/* Non-double operators */

void op_isnormal(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = (double)isnormal(A[kk]);
}

void op_isnan(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = (double)isnan(A[kk]);
}

void op_isinf(const double * A, double * C, const int N) {
    for (int kk = 0; kk < N; kk++)
        C[kk] = (double)isinf(A[kk]);
}

// utility functions

static double clockdiff(struct timespec * start, struct timespec * finish)
{
    double elapsed = double(finish->tv_sec - start->tv_sec);
    elapsed += double(finish->tv_nsec - start->tv_nsec) / 1000000000.0;
    return elapsed;
}

static void runTest(const TestDef1 & theTest, TestResult & theResult, int nSamples, const double * A, double * C)
{
    struct timespec ts, te;

    uint64_t cycStart = __rdtsc();
    clock_gettime(CLOCK_REALTIME, &ts);
    theTest.fun(A, C, nSamples);
    clock_gettime(CLOCK_REALTIME, &te);

    theResult.nCycles += (__rdtsc() - cycStart);
    theResult.time += clockdiff(&ts, &te);

}

static void runTest(const TestDef2 & theTest, TestResult & theResult, int nSamples, const double * A, const double * B, double * C)
{
    struct timespec ts, te;

    uint64_t cycStart = __rdtsc();
    clock_gettime(CLOCK_REALTIME, &ts);
    theTest.fun(A, B, C, nSamples);
    clock_gettime(CLOCK_REALTIME, &te);

    theResult.nCycles += (__rdtsc() - cycStart);
    theResult.time += clockdiff(&ts, &te);

}

static void populateRandomArray(double * arr, int size, double minv, double maxv)
{
    std::random_device rd;
    std::mt19937 mt(rd());

    std::uniform_real_distribution<double> dist(minv, maxv);

    for (int i = 0; i < size; i++)
    {
        arr[i] =  dist(mt);
    }
}



int main(int argc, char ** argv)
{
    int nSamples = (int)10000;
    int nRepeats = 1000;

    // the random number generator range must be no larger than DBL_MAX
    // so we center that on zero
    const double dMax = DBL_MAX / 2.0;

    // intentionally use FLT_MAX instead of DBL_MAX even though we are using doubles so that
    // there is less of a chance of getting out of range errors on functions where the the
    // maximum input value is not clearly defined.
    std::vector<TestDef1> tests1 {
        {"acos",        op_acos,    -1.0,       1.0},
        {"acosh_1",     op_acosh,    1.0,       10.0},
        {"acosh_2",     op_acosh,    1.0,       FLT_MAX},
        {"acosh_2",     op_acosh,    1.0,       DBL_MAX},
        {"asin",        op_asin,    -1.0,       1.0},
        {"asinh_1",     op_asinh,   -10.0,      10.0},
        {"asinh_2",     op_asinh,   -FLT_MAX,   FLT_MAX},
        {"asinh_3",     op_asinh,   -dMax,      dMax},
        {"atan",        op_atan,    -1.0,       1.0},
        {"atanh",       op_atanh,   -1.0,       1.0},
        {"cbrt",        op_cbrt,    -FLT_MAX,   FLT_MAX},
        {"ceil",        op_ceil,    -FLT_MAX,   FLT_MAX},
        {"cos_1",       op_cos,     -M_PI,      M_PI},
        {"cos_2",       op_cos,     0.0,        M_PI * 2.0},
        {"cos_3",       op_cos,     -FLT_MAX,   FLT_MAX},
        {"cosh_1",      op_cosh,    -1.0,       1.0},
        {"cosh_2",      op_cosh,    -710.0,       710.0},
        {"exp",         op_exp,     -200.0,     200.0},
        {"floor",       op_floor,   -FLT_MAX,   FLT_MAX},
        {"isinf",       op_isinf,   -FLT_MAX,   FLT_MAX},
        {"isnan",       op_isnan,   -FLT_MAX,   FLT_MAX},
        {"isnormal",    op_isnormal,-FLT_MAX,   FLT_MAX},
        {"j0_1",        op_j0,      -10.0,      10.0},
        {"j0_2",        op_j0,      -FLT_MAX,   FLT_MAX},
        {"j0_3",        op_j0,      -dMax,      dMax},
        {"j1_1",        op_j1,      -10.0,      10.0},
        {"j1_2",        op_j1,      -FLT_MAX,   FLT_MAX},
        {"j1_3",        op_j1,      -dMax,      dMax},
        {"log",         op_log,     1.0,        FLT_MAX},
        {"log10",       op_log10,   1.0,        FLT_MAX},
        {"nearbyint_1", op_nearbyint,   -2.0,   2},
        {"nearbyint_2", op_nearbyint,   -10.0,  10.0},
        {"nearbyint_3", op_nearbyint,   -1000000.0, 1000000.0},
        {"nearbyint_4", op_nearbyint,   -FLT_MAX, FLT_MAX},
        {"round_1",     op_round,   -2.0,       2},
        {"round_2",     op_round,   -10.0,      10.0},
        {"round_3",     op_round,   -1000000.0, 1000000.0},
        {"round_4",     op_round,   -FLT_MAX,   FLT_MAX},
        {"sin_1",       op_sin,     -M_PI,      M_PI},
        {"sin_2",       op_sin,     0.0,        M_PI * 2.0},
        {"sin_3",       op_sin,     -FLT_MAX,   FLT_MAX},
        {"sinh_1",      op_sinh,    -1.0,       1.0},
        {"sinh_2",      op_sinh,    -710.0,     710.0},
        {"sqrt",      op_sqrt,      0.0,        FLT_MAX},
        {"tan_1",       op_tan,     -M_PI,      M_PI},
        {"tan_2",       op_tan,     0.0,        M_PI * 2.0},
        {"tan_3",       op_tan,     -FLT_MAX,   FLT_MAX},
        {"tanh_1",      op_tanh,    -1.0,       1.0},
        {"tanh_2",      op_tanh,    -19.0,     19.0},
        {"tanh_3",      op_tanh,    -40.0,     40.0},
    };
    std::vector<TestDef2> tests2 {
        {"pow",         op_pow,     -FLT_MAX,   FLT_MAX,     -1.0,      1.0},
        {"copysign",  op_copysign,  -FLT_MAX,   FLT_MAX,     -FLT_MAX,   FLT_MAX},
        {"div",       op_div,       -FLT_MAX,   FLT_MAX,     -FLT_MAX,   FLT_MAX},
        {"minus",     op_minus,     -FLT_MAX,   FLT_MAX,     -FLT_MAX,   FLT_MAX},
        {"mult",      op_mult,      -FLT_MAX,   FLT_MAX,     -FLT_MAX,   FLT_MAX},
        {"plus",      op_plus,      -FLT_MAX,   FLT_MAX,     -FLT_MAX,   FLT_MAX},
    };

    double * A = (double *)malloc(nSamples*sizeof(double));
    double * B = (double *)malloc(nSamples*sizeof(double));
    double * C = (double *)calloc(nSamples, sizeof(double));

    // where we put the results
    std::unordered_map<std::string, TestResult> resultMap;

    for (int idx = 0; idx < tests1.size(); idx++)
    {
        auto & theTest = tests1[idx];
        auto & theResult = resultMap[theTest.name];

        // each operator can have a different range of inputs
        theResult.nRanges = 1;
        theResult.minVal1 = theTest.minVal;
        theResult.maxVal1 = theTest.maxVal;
        populateRandomArray(A, nSamples, theTest.minVal, theTest.maxVal);

        // Warm up - get cache state in order
        theTest.fun(A, C, nSamples);

        // run the timing test
        for (int kk = 0; kk<nRepeats; kk++)
        {
            runTest(theTest, theResult, nSamples, A, C);
        }
    }

    for (int idx = 0; idx < tests2.size(); idx++)
    {
        auto & theTest = tests2[idx];
        auto & theResult = resultMap[theTest.name];

        // each operator can have a different range of inputs
        theResult.nRanges = 2;
        theResult.minVal1 = theTest.minVal1;
        theResult.maxVal1 = theTest.maxVal1;
        theResult.minVal2 = theTest.minVal2;
        theResult.maxVal2 = theTest.maxVal2;;
        populateRandomArray(A, nSamples, theTest.minVal1, theTest.maxVal1);
        populateRandomArray(B, nSamples, theTest.minVal2, theTest.maxVal2);

        // Warm up - get cache state in order
        theTest.fun(A, B, C, nSamples);

        // run the timing test
        for (int kk = 0; kk<nRepeats; kk++)
        {
            runTest(theTest, resultMap[theTest.name], nSamples, A, B, C);
        }
    }




    // scan the results for the minimum time
    double mintime = 99e99;
    for (auto x : resultMap)
    {
        auto & theResult = x.second;
        if (theResult.time < mintime)
        {
            mintime = theResult.time;
        }
    }

    // The tests could have been done in several groups, but they have all been put into one big
    // map of results. We copy all that into one vector for sorting for output
    struct OutputResult : public TestResult
    {
        OutputResult() = default;
        OutputResult(const TestResult & t) : TestResult(t) {}

        std::string name;
    };

    std::vector<OutputResult> sortedOutput;
    for (auto x : resultMap)
    {
        auto & theName = x.first;
        auto & theResult = x.second;

        OutputResult theOutputResult(theResult);  
        theOutputResult.name = theName;

        sortedOutput.push_back(theOutputResult);
    }


    std::sort(sortedOutput.begin(), sortedOutput.end(), 
        [](const OutputResult & a, const OutputResult & b) -> bool { return a.name < b.name;}
    );

    printf("%20s %10s %10s %11s %10s %10s %10s  %10s %10s\n", "operator", "time (s)", "rel. time", "op/s", "cyc/op", "minA", "maxA", "minB", "maxB");
    for (auto & x : sortedOutput)
    {
        if (x.nRanges == 1)
        {
            printf("%20s %10.6f %10.6lf %11.3le %10.3lf [%10.2le - %10.2le]\n", x.name.c_str(), x.time, x.time/mintime, (nRepeats*nSamples)/x.time, (double)x.nCycles/ (double)(nRepeats*nSamples), x.minVal1, x.maxVal1);
        }
        else
        {
            printf("%20s %10.6f %10.6lf %11.3le %10.3lf [%10.2le - %10.2le]  [%10.2le - %10.2le]\n", x.name.c_str(), x.time, x.time/mintime, (nRepeats * nSamples)/x.time, (double)x.nCycles/ (double)(nRepeats*nSamples), x.minVal1, x.maxVal1, x.minVal2, x.maxVal2);

        }
    }

    free(A);
    free(B);
    free(C);
    return 0;
}
