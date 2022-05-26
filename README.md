# opencv-cascade-classifier-test

# Note

you need change 22th line in ./src/pub_image/src/imwrite_1.cpp   
'srcImage = cv::imread("/home/meng/ivrc/opencv_adaboost/camera_ws/src/pub_image/src/pos_030.png",1);'  
change the address to your image address  

# Build & Run

# Compile:

catkin_make

# Run:

one treminal:  
roscore  

anonther terminal:  

cd  xxx/opencv-cascade-classifier-test  
source devel/setup.bash  
rosrun pub_image pub_image_node  

third terminal:  
source devel/setup.bash  
rosrun opencv_detect book_detect.py  

# the example 
./result_example.png  
