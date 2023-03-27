#include <iostream>
#include <string>
#include <fstream>


int main()
{
    std::ifstream inf{"NPHAN.INP"};

    std::string input;
    inf >> input;

    int ans {0};
    for(int i = 0; i < input.size(); ++i)
    {
        if(input[input.size() - i - 1] == '1')
        {
            if(i % 2 == 0)
                ans += 1;
            else
                ans -= 1;
        }
    }
    std::ofstream outf{"NPHAN.OUT"};
    outf << ans % 3;
}
