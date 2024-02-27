# mpu9250_ros_driver_for_arduino_uno

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

    
