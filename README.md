# mpu9250_ros_driver_for_arduino_uno

## Pin Configuration

Sensor Wiring:
```
MPU9250    -    Arduino UNO

SCL             A5
SDA             A4
VDD             5 V
GND             GND

```

## Arduino Libraries

Install ros_lib library to your IDE library directory
```
cd <sketchbook>/libraries
rm -rf ros_lib
rosrun rosserial_arduino make_libraries.py .
```

## Code Execution
### arduino.launch
arduino node that publishes "/imu/data_raw" message that doesn't have orientation data
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

    
