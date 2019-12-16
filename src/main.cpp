#include <iostream>
#include <unordered_map>

namespace ivip
{

int sample();
int report1();

static const std::unordered_map<std::string, std::function<int(void)>> modeList = {
    {"sample", sample},
    {"rep1", report1}};

int main(int argc, char *argv[])
{
    if(argc > 0)
    {
        auto mode = std::string(argv[1]);
        try
        {
            auto f = modeList.at(mode);
            return f();
        }
        catch (std::out_of_range e)
        {
            std::cout << "Unexpected argument" << std::endl;
        }
    }
    else
    {
        std::cout << "Set argument" << std::endl;
    }
    

    return 0;
}

}