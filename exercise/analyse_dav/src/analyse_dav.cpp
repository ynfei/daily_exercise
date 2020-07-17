
#include <iomanip>
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

std::string intToString(int i)
{
  std::stringstream ss;
  ss << std::setw(4) << std::setfill('0') << i;
  return ss.str();
}

int main()
{
  cv::namedWindow("DAV", cv::WINDOW_AUTOSIZE);
  cv::VideoCapture vcap;
  vcap.open("/home/fyn/Downloads/camera_calibration/2020-07-16/4.dav");
  cv::String output_path("/home/fyn/Downloads/camera_calibration/2020-07-16/4_cali/");

  cv::Mat frame;
  int count = 0;
  while (1)
  {
    vcap >> frame;
    if (frame.empty())
    {
      break;
    }
    cv::imshow("DAV", frame);

    std::string id = intToString(count);
    std::string suffix(".jpg");
    cv::String img_output_path = output_path + cv::String(id) + cv::String(suffix);

    cv::imwrite(img_output_path, frame);
    count++;

    if (cv::waitKey(20) >= 0)
    {
      break;
    }
  }

  return 0;
}