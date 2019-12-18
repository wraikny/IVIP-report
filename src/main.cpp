#include <iostream>
#include <unordered_map>

namespace ivip
{

int sample();
int report1();

static const std::unordered_map<std::string, std::function<int(void)>> modeDict = {
    {"sample", sample},
    {"rep1", report1}};
}

int main(int argc, char *argv[])
{
    if (argc > 0)
    {
        auto mode = std::string(argv[1]);
        std::cout << "Arg:" << mode << std::endl;
        try
        {
            auto f = ivip::modeDict.at(mode);
            return f();
        }
        catch (std::out_of_range e)
        {
            std::cerr << "Unexpected argument" << std::endl;
            return -1;
        }
    }
    else
    {
        std::cerr << "Set argument" << std::endl;
        return -1;
    }

    return 0;
}