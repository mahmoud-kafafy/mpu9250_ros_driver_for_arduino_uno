
#include "MPU9250.h"
#include <ros.h>
#include <mpu9250_ros_driver/imu_custom.h>

ros::NodeHandle  nh;
mpu9250_ros_driver::imu_custom test;
ros::Publisher p("my_topic", &test);
long sequence = 0;


 MPU9250 IMU(Wire,0x68);

int c = 0;
void setup() {
  // serial to display data
  Serial.begin(57600);
  nh.initNode();
  nh.advertise(p);
  // start communication with IMU 
  IMU.begin();
  
}

void loop() {
 
  // read the sensoIMU.begin();
  IMU.readSensor();
  // display the data
/*
  Serial.print("AccelX: ");
  Serial.print(IMU.getAccelX_mss(),6);
  Serial.print("\t");
  Serial.print("AccelY: ");  
  Serial.print(IMU.getAccelY_mss(),6);
  Serial.print("\t");
  Serial.print("AccelZ: ");  
  Serial.println(IMU.getAccelZ_mss(),6);
  
  Serial.print("GyroX: ");
  Serial.print(IMU.getGyroX_rads(),6);
  Serial.print("\t");
  Serial.print("GyroY: ");  
  Serial.print(IMU.getGyroY_rads(),6);
  Serial.print("\t");
  Serial.print("GyroZ: ");  
  Serial.println(IMU.getGyroZ_rads(),6);

  Serial.print("MagX: ");  
  Serial.print(IMU.getMagX_uT(),6);
  Serial.print("\t");  
  Serial.print("MagY: ");
  Serial.print(IMU.getMagY_uT(),6);
  Serial.print("\t");
  Serial.print("MagZ: ");  
  Serial.println(IMU.getMagZ_uT(),6);
  */

  test.ax = IMU.getAccelX_mss();
  test.ay = IMU.getAccelY_mss();
  test.az = IMU.getAccelZ_mss();
  test.gx = IMU.getGyroX_rads() ;
  test.gy = IMU.getGyroY_rads() ;
  test.gz = IMU.getGyroZ_rads() ;
  //test.t  = temp;
  p.publish( &test );
   nh.spinOnce();
   
  delay(100);
} 
