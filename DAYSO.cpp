#include <iostream>
#include <vector>
#include <fstream>
int main()
{
    std::ifstream inf{"DAYSO.INP"};
    std::ofstream outf{"DAYSO.OUT"};

    long long m{};
    long long k{};
    inf >> m >> k;

    std::vector<long long> vec (m);

    for(long long i = 0; i < m; ++i)
        inf >> vec[i];

    std::vector<long long> prefixSumArray (m + 1);
    prefixSumArray[0] = 0;
    for(long long i = 1; i < m + 1; ++i)
    {
        prefixSumArray[i] = prefixSumArray[i - 1] + vec[i - 1];
    }
    long long max_sum = prefixSumArray[0];
    long long locate = 0;
    for(long long i = 0; i + k - 1 < m; ++i)
    {
        long long sumArray = prefixSumArray[i + k] - prefixSumArray[i];
        if(sumArray > max_sum)
        {
            max_sum = sumArray;
            locate = i;
        }
    }
    for (long long i = locate; i < locate + k; ++i)
        outf << vec[i] << ' ';
}
