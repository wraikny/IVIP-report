#include <iostream>
#include <opencv2/opencv.hpp>
#include "common.hpp"

namespace ivip::rep1
{

static cv::Mat gray, binary;
static int threshVal = 127;

static const std::string WindowName = "Report1";

// GUIで閾値を変更したときに実行する関数
void on_trackbar(int x, void*)
{
    cv::threshold(gray, binary, (double)threshVal, 255, cv::ThresholdTypes::THRESH_BINARY);
    cv::imshow(WindowName, binary);
}

int report1()
{
    std::string filename = "images/lamp.png";

    // 画像ファイルの読み込み
    auto img = read_image(filename, cv::IMREAD_COLOR);

    // グレイスケールに変換
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    // ウィンドウ生成
    cv::namedWindow(WindowName, cv::WINDOW_AUTOSIZE);

    // モード選択
    int mode;
    std::cout << "Mode(User : 0, Otsu : 1): ";
    std::cin >> mode;

    if(mode == 0)
    {
        // ユーザが入力した閾値による2値化
        // GUIで値を変更可能にする
        cv::createTrackbar("Threshold", WindowName, &threshVal, 255, on_trackbar);
        on_trackbar(threshVal, 0);
    }
    else if (mode == 1)
    {
        // 判別分析法(大津の方法)による2値化
        cv::threshold(gray, binary, 0.0, 255, cv::ThresholdTypes::THRESH_BINARY | cv::ThresholdTypes::THRESH_OTSU);
        cv::imshow(WindowName, binary);
    }
    else
    {
        throw "Unexpected argument in report1";
    }

    // キー待ち状態に移行
    wait_key('q');

    char flag = 0;
    do
    {
        std::cout << "Save image? [y/n]: ";
        std::cin >> flag;
    } while (flag != 'y' && flag != 'n');

    if (flag == 'y')
    {
        auto prefix = (mode == 0) ? ("user-" + std::to_string(threshVal)) : "otsu";

        int path_i = filename.find_last_of("/") + 1;
        int ext_i = filename.find_last_of(".");
        auto output_name = filename.substr(0, ext_i) + "-binary-" + prefix + ".png";

        cv::imwrite(output_name, binary);

        std::cout << "Saved Image to '" << output_name << "'!" << std::endl;
    }

    return 0;
}

}