#include <iostream>

bool is_prime(long long number)
{
    if(number <= 1) return false;

    if(number == 2) return true;
    if(number == 3) return true;

    if(number % 2 == 0) return false;
    if(number % 3 == 0) return false;

    for(long long i {5}; i * i <= number; i += 6)
    {
        if(number % i == 0 || number % (i + 2) == 0)
            return false;
    }
    return true;
}

int main()
{
    long long input {};
    std::cin >> input;

    long long answer {input};

    do
    {
        ++answer;
    }while(!is_prime(answer));

    std::cout << answer;
}
