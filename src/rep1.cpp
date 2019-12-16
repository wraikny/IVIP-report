#include <opencv2/opencv.hpp>
#include "common.hpp"

namespace ivip
{

int report1()
{
    cv::Mat img, gray;

    // 画像ファイルの読み込み
    img = cv::imread("images/sample512.png", cv::IMREAD_COLOR);
    if (img.empty())
    {
        printf("Unable to load the image");
        return 1;
    }

    // グレイスケールに変換
    cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    // ウィンドウ生成
    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);

    // 画像表示
    imshow("Display Image", gray);

    // キー待ち状態に移行
    wait_key('q');

    return 0;
}

}