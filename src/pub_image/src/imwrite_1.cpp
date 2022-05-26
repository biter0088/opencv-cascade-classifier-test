#include <ros/ros.h>
#include <opencv2/opencv.hpp>
#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include <image_transport/image_transport.h> //C++标准输入输出库
#include <opencv2/highgui/highgui.hpp> //opencv2标准头文件
#include <cv_bridge/cv_bridge.h> //cv_bridge中包含CvBridge库
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	ros::init(argc, argv, "image_publisher");
    ros::NodeHandle nh;
    image_transport::ImageTransport it(nh);
    image_transport::Publisher pub = it.advertise("/usb_cam/image_raw", 1);

	cv::Mat srcImage;
	//加载图像
	srcImage = cv::imread("/home/meng/ivrc/opencv_adaboost/camera_ws/src/pub_image/src/pos_030.png",1);
	//std::cout << " rows " <<"\t"<<srcImage.rows << std::endl;
	//std::cout << " cols " <<"\t"<<srcImage.cols << std::endl;
	if (srcImage.empty())
	{
		std::cout << "load image fail!" << std::endl;
		return -1;
	}


	sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", srcImage).toImageMsg();
     
    ros::Rate loop_rate(5);
    while (nh.ok()) {
        pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    	//cv::namedWindow("src window", CV_WINDOW_NORMAL);
		//cv::imshow("src window", srcImage);
		//保存图像到当前项目
		//cv::imwrite("save.jpg", srcImage);
    	//cv::namedWindow("save window", CV_WINDOW_NORMAL);
		//cv::imshow("save window", srcImage);
		//cv::waitKey(0);
		//销毁所有窗口
		//cv::destroyAllWindows();
	return 0;
}
