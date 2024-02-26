#!/usr/bin/env python3

import rospy
from mpu9250_ros_driver.msg import imu_custom
from sensor_msgs.msg import Imu
#import time 

def custom_callback(msg):
    # Your custom callback logic here
    #rospy.loginfo("Received custom message: field1=%s, field2=%s", msg.field1, msg.field2)

    # Create an IMU message
    imu_msg = Imu()
    #Header
    imu_msg.header.seq += 1
    imu_msg.header.stamp = rospy.Time.now()
    imu_msg.header.frame_id  ="imu_link"

    #Linear Acceleration 
    imu_msg.linear_acceleration.x = msg.ax 
    imu_msg.linear_acceleration.y = msg.ay 
    imu_msg.linear_acceleration.z = msg.az
    
    #Angular Velocity
    imu_msg.angular_velocity.x = msg.gx
    imu_msg.angular_velocity.y = msg.gy  
    imu_msg.angular_velocity.z = msg.gz   

    #Orientation
    imu_msg.orientation.x = 0 
    imu_msg.orientation.y = 0 
    imu_msg.orientation.z = 0 
    imu_msg.orientation.w = 0 
    # Publish the IMU message
    imu_pub.publish(imu_msg)

def custom_node():
    rospy.init_node('custom_node', anonymous=True)

    # Subscribe to the custom message topic
    rospy.Subscriber('my_topic', imu_custom, custom_callback)

    # Spin to keep the script from exiting
    rospy.spin()

if __name__ == '__main__':
    try:
        # Create a publisher for the IMU message
        imu_pub = rospy.Publisher('/imu/data_raw', Imu, queue_size=10)
        custom_node()
    except rospy.ROSInterruptException:
        pass
