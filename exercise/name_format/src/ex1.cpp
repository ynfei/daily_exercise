#include "ex1.h"

int main()
{
  cv::String img_input_folder = "/home/fyn/fr1/desk/";
  cv::String img_output_folder = "/home/fyn/fr1/new_desk/";

  std::cout << "Rename img..." << std::endl;

  ImageRenamer img_renamer(img_input_folder, img_output_folder);
  img_renamer.getImgName();
  img_renamer.renameImg();

  std::cout << "Rename img sucess" << std::endl;

  return 0;
}