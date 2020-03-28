#include <iostream>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>
#include <openMVG/image/image_io.hpp>
#include <openMVG/image/image_drawing.hpp>
#include <openMVG/numeric/numeric.h>


using rbg = openMVG::image::RGBAColor;
int main(int argc, char const *argv[])
{
    //8 bit gray image  
   openMVG::image::Image<unsigned char> img(10,10);
   img.fill(0);
   img(2,4) = 127;

   openMVG::image::DrawLine(0,5,9,5,255,&img);
   // read image 
   openMVG::image::Image<rbg> rbg_img;
   bool bRet =  openMVG::image::ReadImage("/home/omar/Desktop/multi_view/openMVG/src/openMVG/image/image_test/lena.png",&rbg_img);

    //std::cout << "Hello OpenMVG\n" << bRet << "\n";
    // perform numeric calculations
    openMVG::Mat2X A(2,5);

    A << 2,3,4,5,6,
         7,8,9,11,12;
    
    std::cout << A.row(0) << std::endl;
    /* code */
    return 0;
}

