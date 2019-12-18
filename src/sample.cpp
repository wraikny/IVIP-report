#include <opencv2/opencv.hpp>
#include "common.hpp"

namespace ivip::sample
{

int sample()
{
    // 画像ファイルの読み込み
    auto img = read_image("images/sample512.png", cv::IMREAD_COLOR);

    // グレイスケールに変換
    cv::Mat gray;
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