#include <iostream>
#include <unordered_map>

namespace ivip
{

namespace sample { int sample(); }
namespace rep1 { int report1(); }
namespace rep2 { int report2(); }

static const std::unordered_map<std::string, std::function<int(void)>> modeDict = {
    {"sample", sample::sample},
    {"rep1", rep1::report1},
    {"rep2", rep2::report2}
};

}

int main(int argc, char *argv[])
{
    if (argc > 0)
    {
        auto mode = std::string(argv[1]);
        try
        {
            auto f = ivip::modeDict.at(mode);
            return f();
        }
        catch (std::out_of_range e)
        {
            std::cerr << "Unexpected argument: " << mode << std::endl;
            return -1;
        }
        // catch (std::exception e)
        // {
        //     std::cerr << "Unexpected Exception:" << e.what() << std::endl;
        //     return -1;
        // }
    }
    else
    {
        std::cerr << "Set argument" << std::endl;
        return -1;
    }

    return 0;
}