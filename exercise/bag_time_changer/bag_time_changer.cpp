#include <ros/ros.h>

#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/highgui/highgui.hpp>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>

ros::Publisher cloud_pub;
ros::Publisher img_pub;

void imgCallback(const sensor_msgs::ImageConstPtr input_msg)
{
  cv_bridge::CvImagePtr cv_ptr;
  cv_ptr = cv_bridge::toCvCopy(input_msg, sensor_msgs::image_encodings::BGR8);

  cv_ptr->header.frame_id = "camera";
  cv_ptr->header.stamp = ros::Time::now();

  img_pub.publish(cv_ptr->toImageMsg());
  std::cout << "img trans..." << std::endl;
}

void cloudCallback(const sensor_msgs::PointCloud2ConstPtr input_msg)
{
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_in(new pcl::PointCloud<pcl::PointXYZI>);
  pcl::fromROSMsg(*input_msg, *cloud_in);

  if (cloud_in->empty())
  {
    std::cout << "empty cloud" << std::endl;
    return;
  }

  sensor_msgs::PointCloud2 output_msg;
  pcl::toROSMsg(*cloud_in, output_msg);
  output_msg.header.frame_id = "rslidar";
  output_msg.header.stamp = ros::Time::now();
  cloud_pub.publish(output_msg);
  std::cout << "cloud trans..." << std::endl;
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "timestamp_changer");
  ros::NodeHandle nh;

  ros::Subscriber img_sub = nh.subscribe("/camera/image_raw", 10, &imgCallback);
  img_pub = nh.advertise<sensor_msgs::Image>("/camera/image_change", 10);

  ros::Subscriber cloud_sub = nh.subscribe("/1_32/rslidar_points", 10, &cloudCallback);
  cloud_pub = nh.advertise<sensor_msgs::PointCloud2>("/rslidar_change/rslidar_points", 10);

  ros::spin();
  return 0;
}
