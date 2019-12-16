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
}