#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/stitching.hpp>
#include <opencv2/imgcodecs.hpp>
#include <vector>


int main(int argc, char const *argv[])
{
    argc = 4;
    std::vector<cv::Mat> imgs;
    imgs.resize(3);
    for(int i =0;i<argc;i++){
        cv::Mat img = cv::imread(argv[i]);
        imgs.push_back(img);
    }
    for(auto &item : imgs){
        cv::imshow("Image1",item);
        cv::waitKey(0);
    }
    
    //cv::imshow("Image2",imgs[1]);
    //cv::imshow("Image3",imgs[2]);
    
    return 0;
}
