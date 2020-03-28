#include "../include/kimera_pugin.h"

namespace SLAM{
    Plugin::Plugin(){
        mProvider = std::make_shared<VIO::DataProviderInterface>();
        //mKIMERA = std::make_shared<VIO::Pipeline>(mProvider->pipeline_params_);
        std::cout << "Hello Kimera\n";
    }
    Plugin::~Plugin(){
        //mKIMERA->shutdown();
        std::cout << "Destuctor called\n";
    }
    void Plugin::processImages(const std::string& path_cam0,const std::string& path_cam1,const std::string& csv_path){

        data.resize(2);

        std::ifstream f(csv_path);

        std::string time_stamp;
        std::string img_name;
        cv::String path_0(path_cam0 + "/*.png");
        cv::String path_1(path_cam1 + "/*.png");
        std::vector<cv::String> fn0;
        std::vector<cv::String> fn1;
        
        cv::glob(path_0,fn0,true);
        cv::glob(path_1,fn1,true);

        for(size_t k=0;k < fn0.size(); k += 1){
            // Load images to mat 
            cv::Mat leftImg  = cv::imread(fn0[k]);
            cv::Mat rightImg = cv::imread(fn1[k]);

            getline(f,time_stamp,',');
            getline(f,img_name,'\n');

            //mKIMERA->fillLeftFrameQueue(VIO::make_unique<VIO::Frame>(k,atof(time_stamp.c_str())))

            data[0].width = leftImg.size().width;
            data[0].height = leftImg.size().height;
            data[0].time_stamp = atof(time_stamp.c_str());
            data[0].data.push_back(*leftImg.data);

            data[1].width = rightImg.size().width;
            data[1].height = rightImg.size().height;
            data[1].time_stamp = atof(time_stamp.c_str());
            data[1].data.push_back(*rightImg.data);

            std::cout << "Image height " << data[0].height << " Image width " << data[0].width << " Timestamp: " << data[0].time_stamp <<"\n";

        }
    }

    void Plugin::processImu(const std::string& imu_path){

        
        std::fstream imu(imu_path);
          
        Eigen::Vector3d acc;
        Eigen::Vector3d gyr;
        
        std::string time_stamp;
        std::string vel_x;
        std::string vel_y;
        std::string vel_z;
        std::string acc_x;
        std::string acc_y;
        std::string acc_z;

        while (imu.good()){
            getline(imu,time_stamp,',');
            getline(imu,vel_x,',');
            getline(imu,vel_y,',');
            getline(imu,vel_z,',');
            getline(imu,acc_x,',');
            getline(imu,acc_y,',');
            getline(imu,acc_z,'\n');

            gyr << atof(vel_x.c_str()) , atof(vel_y.c_str()) , atof(vel_z.c_str());
            acc << atof(acc_x.c_str()) , atof(acc_y.c_str()) , atof(acc_z.c_str());
            acc_gyr << gyr , acc;

            //mKIMERA->fillSingleImuQueue(VIO::ImuMeasurement(atof(time_stamp.c_str()),acc_gyr));

            std::cout << " Imu Timestamp " << atof(time_stamp.c_str()) << " Vel_x " << acc_gyr[0] << " Vel_y " << acc_gyr[1] << " Vel_z " << acc_gyr[2] << "\n";
            std::cout << "acc_x " << acc_gyr[3] << " acc_y " << acc_gyr[4] << " acc_z " << acc_gyr[5] << "\n";
            
        }
    } 

    void Plugin::doKimera(const std::string& path){
        // Preprocess imu data
        Plugin::processImu(path);
    }

    void Plugin::parse_camera(){
            
            std::string left = "/home/omar/kimera/Kimera-VIO/params/Euroc/LeftCameraParams.yaml";
            std::string right = "/home/omar/kimera/Kimera-VIO/params/Euroc/RightCameraParams.yaml";
            std::string imu = "/home/omar/kimera/Kimera-VIO/params/Euroc/ImuParams.yaml";
            std::string traker_path = "/home/omar/kimera/Kimera-VIO/params/Euroc/trackerParameters.yaml";
            std::string regular_path = "/home/omar/kimera/Kimera-VIO/params/Euroc/regularVioParameters.yaml";
            std::string lcdPath = "/home/omar/kimera/Kimera-VIO/params/Euroc/LCDParameters.yaml";
            //Parse Camera params
            VIO::CameraParams cam0_params;
            VIO::CameraParams cam1_params;
            // //Start parsing
            VIO::parsePipelineParams(left,&cam0_params);
            VIO::parsePipelineParams(right,&cam1_params);
            // //Fill pipeline with params 
            mProvider->pipeline_params_.camera_params_.push_back(cam0_params);
            mProvider->pipeline_params_.camera_params_.push_back(cam1_params);
            // //Parse Imu params 
            VIO::parsePipelineParams(imu,&mProvider->pipeline_params_.imu_params_);
            // //Parse FrontEnd params 
            VIO::parsePipelineParams(traker_path,&mProvider->pipeline_params_.frontend_params_);
            // //Parse BackEnd params
            VIO::parsePipelineParams(regular_path,mProvider->pipeline_params_.backend_params_.get());
            // //Parse LCD params
            VIO::parsePipelineParams(lcdPath,&mProvider->pipeline_params_.lcd_params_);

            mProvider->spin();
                        
            //Path pipeline params to pipeline
            //VIO::Pipeline vio_pipeline(mProvider->pipeline_params_);
           //mKIMERA = std::make_shared<VIO::Pipeline>(mProvider->pipeline_params_);
    }

    
    
}
 // namespace SLAM
