#include <iostream>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>
#include <openMVG/cameras/Camera_Common.hpp>

// using namespace Eigen ;

int main(int argc, char const *argv[])
{
    //Create matrices 
    Eigen::Matrix<double,3,1> Acc;
    Eigen::Matrix<double,3,1> Gyr;
    // Another way to create eigen matrix 
    Eigen::Matrix3f A;
    Eigen::Matrix4d B;
    // Let's assigen data to the matrix 
    A << 5.0,6.0,9.0,
         1.0,3.0,6.0,
         2.3,4.1,1.6; 
    
    A.col();
    // Matrix operations 
    Eigen::Vector3d v(1.0 , 2.0 , 3.0);
    Eigen::Vector3d v2(3.0 , 5.0 , 1.0);
    Eigen::Vector4d s = v.homogeneous();
    Eigen::Matrix3f C = Eigen::Matrix3f::Constant(3.4);
    
    // std::cout << v.normalized()<< " \n";
    // std::cout << v.cross(v2) << " \n";
    std::cout << " The number of columns is : " << Acc.cols() << "\n";

    // std::cout << " Result for summation " << A + C << std::endl;
    // std::cout << " Result for multiplication " << A * C << std::endl;

    

    //std::cout <<  " Eigen version : " << EIGEN_MAJOR_VERSION << "." <<EIGEN_MINOR_VERSION  << "\n";
    return 0;
}
