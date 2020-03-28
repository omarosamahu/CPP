#include <iostream>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>
#include <ceres/ceres.h>

using ceres::AutoDiffCostFunction;
using ceres::CostFunction;
using ceres::Problem;
using ceres::Solver;
using ceres::Solve;


struct CostFunctor {
  template <typename T> bool operator()(const T* const x, T* residual) const {
    residual[0] = 10.0 - x[0];
    return true;
  }
};

int main(int argc, char const *argv[])
{   
  
    Eigen::Matrix<float,2,3> mat3f;

    
    Eigen::Vector3d vec;
    mat3f << 2,1,3,4,5,6; 
    vec << 2,3,1;

    Eigen::Matrix<double,2,1> result = mat3f.cast<double>() * vec ;
    std::cout << result.transpose()  << "\n";
    std::cout << vec.trace()  << "\n";
    
             
    //Eigen::Matrix3d R ; // 3x3 rotation matrix 
    //Eigen::Vector3d T(3.0 , 5.0 , 1.0); // 3x1 transtaltion vector
    //
    //R << 5.0,6.0,9.0,
    //     1.0,3.0,6.0,
    //     2.3,4.1,1.6; 
    //

    //Eigen::Matrix4d trans;
    //trans.setIdentity();
    //trans.block<3,3>(0,1) = R;
    //trans.block<3,1>(0,0) = T;
    //std::cout << "Print identity matrix:\n" << trans << "\n";
    return 0;
}
