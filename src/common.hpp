#ifndef __ivip_common__
#define __ivip_common__
namespace ivip
{

void callLambda(int x, void *userContext);

void wait_key(char key);

cv::Mat read_image(std::string path, cv::ImreadModes mode);

}
#endif