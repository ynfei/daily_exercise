#include <iostream>
#include <ros/ros.h>
#include <rosbag/bag.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>

long getTotalFrame(const cv::VideoCapture& cap)
{
  return cap.get(CV_CAP_PROP_FRAME_COUNT);
}

cv::Mat getCvMatImgFromCap(cv::VideoCapture& cap)
{
  cv::Mat img;
  cap >> img;
  return img;
}

void writeCvMatToBag(const std::string& topic, const cv::Mat& input_img, rosbag::Bag& output_bag)
{
  std_msgs::Header header;
  header.frame_id = "image_frame";
  header.stamp = ros::Time::now();
  sensor_msgs::ImagePtr image_msg = cv_bridge::CvImage(header, "bgr8", input_img).toImageMsg();
  output_bag.write(topic, ros::Time::now(), image_msg);
}

void showImg(const cv::Mat& img)
{
  cv::imshow("Image", img);
  cv::waitKey(10);
}

void videoToBag(const std::string& input_video_path, const std::string& output_bag_path)
{
  std::string topic("/camera/image_raw");
  ros::Rate loop_rate(25);

  rosbag::Bag bag;
  bag.open(output_bag_path, rosbag::bagmode::Write);

  cv::VideoCapture cap(input_video_path);
  long total_frame = getTotalFrame(cap);

  while (ros::ok())
  {
    cv::Mat frame = getCvMatImgFromCap(cap);
    if (frame.empty())
    {
      std::cout << "error, no image" << std::endl;
      break;
    }

    writeCvMatToBag(topic, frame, bag);

    loop_rate.sleep();
  }

  bag.close();
  cap.release();
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "rosbag_recode_node");
  ros::NodeHandle nh;

  std::string output_bag_path("/media/fyn/DDB2B37488AA702D/video_ca/video/4/3.bag");
  std::string input_video_path("/media/fyn/DDB2B37488AA702D/video_ca/video/4/20200714_163747.dav");

  std::cout << "start write video to bag..." << std::endl;

  videoToBag(input_video_path, output_bag_path);

  std::cout << "Write Finish!" << std::endl;

  nh.shutdown();
  return 0;
}
