#include "ex1.h"

int main()
{
  cv::String img_input_folder = "/home/fyn/video_ca/video/3/3_3";
  cv::String img_output_folder = "/home/fyn/video_ca/video/3/3_31/";

  std::cout << "Rename img..." << std::endl;

  ImageRenamer img_renamer(img_input_folder, img_output_folder);
  img_renamer.getImgName();
  img_renamer.renameImg();

  std::cout << "Rename img sucess" << std::endl;

  return 0;
}