#include <stdio.h>
#include <opencv2/opencv.hpp>
// using namespace cv; // 名前空間の設定

int main(void)
{
    cv::Mat img, gray;
    img = cv::imread("images/sample512.png", cv::IMREAD_COLOR); // 画像ファイルの読み込み
    if (img.empty())
    {
        printf("Unable to load the image");
        return 1;
    }

    cvtColor(img, gray, cv::COLOR_BGR2GRAY); // グレイスケールに変換

    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE); // ウィンドウ生成
    imshow("Display Image", gray);                 // 画像表示

    // キー待ち状態に移行
    while (1)
    {
        int c = cv::waitKey(10); // 引数はdelay
        switch ((char)c)
        {
        case 'q': // qキーでプログラム終了
            return 0;
        }
    }

    return 0;
}