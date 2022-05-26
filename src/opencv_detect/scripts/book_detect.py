#!/usr/bin/env python
# -*- coding:utf-8 -*-
import rospy
import cv2
# from std_msgs.msg import String
from sensor_msgs.msg import Image
from cv_bridge import CvBridge

def callback(imgmsg):
    bridge=CvBridge()
    img=bridge.imgmsg_to_cv2(imgmsg,"bgr8")
    cv2.namedWindow("callback",cv2.WINDOW_NORMAL)
    cv2.imshow("callback",img)
    detect_book(img)
    cv2.waitKey(10)


def detect_book(img_detect):
    cascade_tidy=cv2.CascadeClassifier("/home/meng/ivrc/opencv_adaboost/mooc0525/data/cascade.xml")
    cv2.namedWindow("camera",cv2.WINDOW_NORMAL)
    gray=cv2.cvtColor(img_detect,cv2.COLOR_BGR2GRAY)
    tidys=cascade_tidy.detectMultiScale(gray,1.25, 50)  #/home/meng/ivrc/opencv_adaboost/camera_ws/src/pub_image/src/pos_030.png
#     参数3：scaleFactor–表示在前后两次相继的扫描中，搜索窗口的比例系数。默认为1.1即每次搜索窗口依次扩大10%;
# 参数4：minNeighbors–表示构成检测目标的相邻矩形的最小个数(默认为3个)。
    for (x,y,w,h) in tidys:
        cv2.rectangle(img_detect,(x,y),(x+w,y+h),(0,255,0),2)
    cv2.imshow("camera",img_detect)
    cv2.waitKey(10)


def listener():
    rospy.init_node('book_detect',anonymous=True)
    rospy.Subscriber('/usb_cam/image_raw',Image,callback)
    rospy.spin()

if __name__=='__main__':
    listener()



