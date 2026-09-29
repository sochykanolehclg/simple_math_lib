#include "math_lib.h"
#include <cmath>
#include <algorithm>

namespace MathLib
{
    bool isEqual(double a, double b, double tolerance)
    {
        return abs(a - b) <= tolerance;
    }

    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;        
        }
        return true;
    }

    int leastCommonMultiple(int a, int b)
    {
        int lcm = 1;
        int maxNum = std::max(a, b);
        for (int i = maxNum; i <= a * b; i += maxNum)
        {
            if (i % a == 0 && i % b == 0)
            {
                lcm = i;
                break;
            }
        }
        return lcm;
    }

    int GCD(int a, int b)
    {
		if (b == 0) return a;
		return GCD(b, a % b);
	}


    unsigned long long fibonacci(int n)
    {
        if (n < 0)
            throw std::invalid_argument("Fibonacci number is not defined for negative index");
        if (n > 93)
            throw std::overflow_error("Fibonacci result does not fit into unsigned long long");

        if (n == 0)
            return 0;

        unsigned long long prev = 0;
        unsigned long long curr = 1;
        for (int i = 2; i <= n; i++)
        {
            unsigned long long next = prev + curr;
            prev = curr;
            curr = next;
        }
        return curr;
    }
}

