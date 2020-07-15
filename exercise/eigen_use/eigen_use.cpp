#include <iostream>

#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

int main()
{
  //这里注意初始化顺序：w,x,y,z
  Eigen::Quaterniond q(0.1, 0.35, 0.2, 0.3);
  //这里需要进行归一化，归一化的四元数才表示一个欧式空间的旋转
  Eigen::Quaterniond qua = q.normalized();
  //这里另外小知识，可以直接使用normalize()对自身进行归一化
  // q.normalize();

  Eigen::Matrix3d r = qua.toRotationMatrix();
  std::cout << "**********************************" << std::endl;
  std::cout << "旋转矩阵： " << std::endl;
  std::cout << r << std::endl;
  std::cout << "**********************************" << std::endl;

  Eigen::Matrix3d rt = r.transpose();
  std::cout << "**********************************" << std::endl;
  std::cout << "旋转矩阵的转置： " << std::endl;
  std::cout << rt << std::endl;
  std::cout << "**********************************" << std::endl;

  Eigen::Matrix3d r_inv = r.inverse();
  std::cout << "**********************************" << std::endl;
  std::cout << "旋转矩阵的逆矩阵： " << std::endl;
  std::cout << r_inv << std::endl;
  std::cout << "**********************************" << std::endl;

  Eigen::Matrix3d identity = r * rt;
  std::cout << "**********************************" << std::endl;
  std::cout << "旋转矩阵乘以自身的转置： " << std::endl;
  std::cout << identity << std::endl;
  std::cout << "**********************************" << std::endl;

  identity = r * r_inv;
  std::cout << "**********************************" << std::endl;
  std::cout << "旋转矩阵乘以自身的逆： " << std::endl;
  std::cout << identity << std::endl;
  std::cout << "**********************************" << std::endl;

  return 0;
}