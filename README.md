# mpu9250_ros_driver_for_arduino_uno

## Acknowledgment:
I would like to extend credit to the original creator and maintainer of the MPU9250 ROS driver, available at the following link: [MPU9250 ROS Driver](https://github.com/obensustam2/mpu9250_ros_driver).

While I did not develop this driver from scratch, I have contributed to its enhancement and adaptation for specific use cases. When researching the optimal method for interfacing IMU with ROS, I identified the aforementioned driver as one of the best available options.

My motivation for modification stemmed from encountering memory constraints with the Arduino Uno when employing rosserial. To address this limitation, I endeavored to optimize the driver's codebase. By implementing custom message handling within the Arduino firmware, I aimed to mitigate memory overflow issues, enabling compatibility with Arduino Uno.

However, in the process of adaptation, certain alterations were made to the driver library. Regrettably, these modifications rendered the magnetometer values inaccessible, as my focus primarily revolved around utilizing IMU orientation data exclusively.

I express gratitude to the original developer for providing a robust foundation upon which improvements and adaptations could be built. The evolution of the driver underscores the collaborative nature of open-source development and the ongoing quest for refinement and optimization.


## Pin Configuration

Sensor Wiring:
```
MPU9250    -    Arduino UNO

SCL             A5
SDA             A4
VDD             5 V
GND             GND
AD0             GND

```
<img src="https://www.mathworks.com/help/examples/shared_fusion_arduinoio/win64/EstimateOrientationUsingInertialSensorFusionAndMPU9250Example_01.png" alt="Estimate Orientation Using Inertial Sensor Fusion and MPU9250 Example" width="300" height="300">

## ROS Installations

```
sudo apt-get install ros-<ros_version>-rosserial-arduino
sudo apt-get install ros-<ros_version>-rosserial
sudo apt-get install ros-<ros_version>-imu-complementary-filter*

```
## Arduino Libraries

1- Install ros_lib library to your IDE library directory
```
cd <sketchbook>/libraries
rm -rf ros_lib
rosrun rosserial_arduino make_libraries.py .
```

2- copy folder **library/MPU9250-master** into your Arduino libraries directory to use the library of ``` #include "MPU9250.h" ``` in your Arduino code
> **Note:** Make sure you put it in the correct directory.

## Code Execution
### Arduino.launch
Arduino node that publishes "/imu/data_raw" message that doesn't have orientation data

```
roslaunch mpu9250_ros_driver arduino.launch
```

### imu_demo.launch
complementary_filter_node that subscribes "/imu/data_raw" and publishes "imu/data" message that has orientation data.
robot_state_publisher node that publishes robot model.
enable rpy_tf node that updates robot orientation by using upcoming "imu/data".
enable RViZ.

```
roslaunch mpu9250_ros_driver imu_demo.launch
```

## Important Notes 
1- Ensure to download the package file named **mpu9250_ros_driver**. The package must retain this precise name within your ROS environment to function correctly.

2- When incorporating the IMU frame into your robot setup instead of a flat plane, adjustments within the script file **/scripts/tf_broadcaster_imu.py** are necessary. You should modify the following lines:

```
t.header.frame_id = "plane"
t.child_frame_id = "imu_link"
```
Replace "plane" with the name of your base frame, and "imu_link" with the appropriate name for your IMU link. This ensures accurate reference frames within your robot's setup.
These steps ensure seamless integration and proper functioning of the ROS package within your robotic system.



    
