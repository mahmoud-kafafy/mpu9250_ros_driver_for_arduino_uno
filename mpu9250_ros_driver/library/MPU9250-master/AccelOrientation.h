// Generated by gencpp from file mpu9250_ros_driver/AccelOrientation.msg
// DO NOT EDIT!


#ifndef MPU9250_ROS_DRIVER_MESSAGE_ACCELORIENTATION_H
#define MPU9250_ROS_DRIVER_MESSAGE_ACCELORIENTATION_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Vector3.h>

namespace mpu9250_ros_driver
{
template <class ContainerAllocator>
struct AccelOrientation_
{
  typedef AccelOrientation_<ContainerAllocator> Type;

  AccelOrientation_()
    : acceleration()
    , orientation()  {
    }
  AccelOrientation_(const ContainerAllocator& _alloc)
    : acceleration(_alloc)
    , orientation(_alloc)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _acceleration_type;
  _acceleration_type acceleration;

   typedef  ::geometry_msgs::Vector3_<ContainerAllocator>  _orientation_type;
  _orientation_type orientation;





  typedef boost::shared_ptr< ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator> const> ConstPtr;

}; // struct AccelOrientation_

typedef ::mpu9250_ros_driver::AccelOrientation_<std::allocator<void> > AccelOrientation;

typedef boost::shared_ptr< ::mpu9250_ros_driver::AccelOrientation > AccelOrientationPtr;
typedef boost::shared_ptr< ::mpu9250_ros_driver::AccelOrientation const> AccelOrientationConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator1> & lhs, const ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator2> & rhs)
{
  return lhs.acceleration == rhs.acceleration &&
    lhs.orientation == rhs.orientation;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator1> & lhs, const ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace mpu9250_ros_driver

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0c49ed07ad2c722e5c80b89ae86045f4";
  }

  static const char* value(const ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0c49ed07ad2c722eULL;
  static const uint64_t static_value2 = 0x5c80b89ae86045f4ULL;
};

template<class ContainerAllocator>
struct DataType< ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mpu9250_ros_driver/AccelOrientation";
  }

  static const char* value(const ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Vector3 acceleration\n"
"geometry_msgs/Vector3 orientation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
;
  }

  static const char* value(const ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.acceleration);
      stream.next(m.orientation);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct AccelOrientation_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mpu9250_ros_driver::AccelOrientation_<ContainerAllocator>& v)
  {
    s << indent << "acceleration: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.acceleration);
    s << indent << "orientation: ";
    s << std::endl;
    Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "  ", v.orientation);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MPU9250_ROS_DRIVER_MESSAGE_ACCELORIENTATION_H
