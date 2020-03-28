#include "../include/kimera_pugin.h"

#include <gflags/gflags.h>
#include <glog/logging.h>
// Kimera Headers

#include <memory>
//using namespace SLAM;

int main(int argc, char* argv[]){
   google::ParseCommandLineFlags(&argc, &argv, true);

   std::string left = "/home/omar/kimera/Kimera-VIO/params/Euroc/LeftCameraParams.yaml";
   std::string right = "/home/omar/kimera/Kimera-VIO/params/Euroc/RightCameraParams.yaml";

   std::string img0 = "/home/omar/MH_05_difficult/mav0/cam0/data";
   std::string img1 = "/home/omar/MH_05_difficult/mav0/cam1/data";
   std::string imu0 = "/home/omar/kimera/slam/data.csv";
   std::string img0_csv = "/home/omar/MH_05_difficult/mav0/cam0/data.csv";
   std::string img1_csv = "/home/omar/MH_05_difficult/mav0/cam1/data.csv";
   
   std::vector<SLAM::slamData> data;
    
   auto ptr = std::make_unique<SLAM::Plugin>();
   ptr->parse_camera();
   //VIO::Pipeline vio_pipeline(ptr->mProvider->pipeline_params_);

   //vio_pipeline.spin();
   //ptr->processImages(img0,img1,img1_csv);
   //ptr->parse_camera(left,right);
   //ptr->mKIMERA = std::make_shared<VIO::Pipeline>(ptr->mProvider->pipeline_params_);
   //ptr->processImu("/home/omar/kimera/slam/data.csv");
   //ptr->doKimera(imu0);
   
    
   std::cout << "Hello Kimera\n";
}
