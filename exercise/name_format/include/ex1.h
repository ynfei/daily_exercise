#ifndef EX1_H_
#define EX1_H_

#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include <opencv2/highgui.hpp>

class ImageRenamer
{
public:
  ImageRenamer(cv::String img_input_path, cv::String img_output_path);
  void getImgName();
  void renameImg();

private:
  cv::String img_input_path_;
  cv::String img_output_path_;
  std::vector<cv::String> img_name_;
  std::string intToString(int i);
};

ImageRenamer::ImageRenamer(cv::String img_input_path, cv::String img_output_path)
  : img_input_path_(img_input_path), img_output_path_(img_output_path){};

void ImageRenamer::getImgName()
{
  cv::glob(img_input_path_, img_name_, false);
}

void ImageRenamer::renameImg()
{
  for (int i = 0; i < img_name_.size(); ++i)
  {
    cv::Mat img = cv::imread(img_name_[i]);
    if (!img.data)
    {
      std::cout << "Load img error" << std::endl;
      continue;
    }

    std::string id = intToString(i);
    std::string suffix(".png");
    cv::String img_new_name = img_output_path_ + cv::String(id) + cv::String(suffix);
    cv::imwrite(img_new_name, img);
  }
}

std::string ImageRenamer::intToString(int i)
{
  std::stringstream ss;
  ss << std::setw(4) << std::setfill('0') << i;
  return ss.str();
}

#endif