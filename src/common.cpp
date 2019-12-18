#include <opencv2/opencv.hpp>

namespace ivip
{

void wait_key(char key)
{
    // キー待ち状態に移行
    while (1)
    {
        int c = cv::waitKey(10); // 引数はdelay
        if(c == (int)key)
        {
            return;
        }
    }
}

cv::Mat read_image(std::string path, cv::ImreadModes mode)
{
    auto img = cv::imread(path, cv::IMREAD_COLOR);
    if (img.empty())
    {
        throw ("Unable to load the image: " + path);
    }
    return img;
}

}