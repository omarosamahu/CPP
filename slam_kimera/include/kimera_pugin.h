#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
// Kimera Headers
#include <kimera-vio/dataprovider/DataProviderInterface-definitions.h>
#include <kimera-vio/dataprovider/DataProviderInterface.h>
#include <kimera-vio/imu-frontend/ImuFrontEnd.h>
#include <kimera-vio/pipeline/Pipeline.h>
#include <kimera-vio/frontend/StereoVisionFrontEnd-definitions.h>
#include <kimera-vio/backend/VioBackEnd.h>
#include <kimera-vio/backend/VioBackEnd-definitions.h>
#include <kimera-vio/frontend/StereoVisionFrontEnd-definitions.h>
#include <kimera-vio/logging/Logger.h>
#include <kimera-vio/visualizer/Visualizer3D.h>
#include <functional>

namespace SLAM{
    struct slamData{
        std::string img_name;
        double width;
        double height;
        double time_stamp;
        std::vector<u_char> data;             
    };
    struct ImuData{
        VIO::ImuAcc acc;
        VIO::ImuGyr gyr;
        VIO::Timestamp timetsamp;
    };
    class Plugin {
    public:
        Plugin();
        ~Plugin();
        void processImages(const std::string& path_cam0,const std::string& path_cam1,const std::string& csv1_path);
        void processImu(const std::string& path);
        void doKimera(const std::string& path);
        void parse_camera();
    public:
        // Initial k 
        VIO::FrameId k = 10;
        // IMU matrix 
        VIO::Vector6 acc_gyr;
        // Create a shared pointer to your Pipeline 
	std::shared_ptr<VIO::Pipeline> mKIMERA;
	// Create a unique pointer to your Provider  
	std::shared_ptr<VIO::DataProviderInterface> mProvider;
	// Create object from VIOBackend
	std::unique_ptr<VIO::BackendOutput> vio_output;
        // Image Data
        std::vector<slamData> data;
        
    };
}
