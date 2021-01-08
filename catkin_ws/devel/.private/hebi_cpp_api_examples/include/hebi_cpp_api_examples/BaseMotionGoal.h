// Generated by gencpp from file hebi_cpp_api_examples/BaseMotionGoal.msg
// DO NOT EDIT!


#ifndef HEBI_CPP_API_EXAMPLES_MESSAGE_BASEMOTIONGOAL_H
#define HEBI_CPP_API_EXAMPLES_MESSAGE_BASEMOTIONGOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace hebi_cpp_api_examples
{
template <class ContainerAllocator>
struct BaseMotionGoal_
{
  typedef BaseMotionGoal_<ContainerAllocator> Type;

  BaseMotionGoal_()
    : x(0.0)
    , y(0.0)
    , theta(0.0)
    , set_color(false)
    , r(0)
    , g(0)
    , b(0)  {
    }
  BaseMotionGoal_(const ContainerAllocator& _alloc)
    : x(0.0)
    , y(0.0)
    , theta(0.0)
    , set_color(false)
    , r(0)
    , g(0)
    , b(0)  {
  (void)_alloc;
    }



   typedef double _x_type;
  _x_type x;

   typedef double _y_type;
  _y_type y;

   typedef double _theta_type;
  _theta_type theta;

   typedef uint8_t _set_color_type;
  _set_color_type set_color;

   typedef uint8_t _r_type;
  _r_type r;

   typedef uint8_t _g_type;
  _g_type g;

   typedef uint8_t _b_type;
  _b_type b;





  typedef boost::shared_ptr< ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator> const> ConstPtr;

}; // struct BaseMotionGoal_

typedef ::hebi_cpp_api_examples::BaseMotionGoal_<std::allocator<void> > BaseMotionGoal;

typedef boost::shared_ptr< ::hebi_cpp_api_examples::BaseMotionGoal > BaseMotionGoalPtr;
typedef boost::shared_ptr< ::hebi_cpp_api_examples::BaseMotionGoal const> BaseMotionGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator1> & lhs, const ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator2> & rhs)
{
  return lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.theta == rhs.theta &&
    lhs.set_color == rhs.set_color &&
    lhs.r == rhs.r &&
    lhs.g == rhs.g &&
    lhs.b == rhs.b;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator1> & lhs, const ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace hebi_cpp_api_examples

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "28f4303134ac5c0340dc34500202a721";
  }

  static const char* value(const ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x28f4303134ac5c03ULL;
  static const uint64_t static_value2 = 0x40dc34500202a721ULL;
};

template<class ContainerAllocator>
struct DataType< ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "hebi_cpp_api_examples/BaseMotionGoal";
  }

  static const char* value(const ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n"
"# Goal position (relative to start)\n"
"float64 x\n"
"float64 y\n"
"float64 theta\n"
"\n"
"# Optionally, set a color when doing the move; otherwise, clear the color.\n"
"bool set_color\n"
"uint8 r\n"
"uint8 g\n"
"uint8 b\n"
;
  }

  static const char* value(const ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.theta);
      stream.next(m.set_color);
      stream.next(m.r);
      stream.next(m.g);
      stream.next(m.b);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct BaseMotionGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::hebi_cpp_api_examples::BaseMotionGoal_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "theta: ";
    Printer<double>::stream(s, indent + "  ", v.theta);
    s << indent << "set_color: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.set_color);
    s << indent << "r: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.r);
    s << indent << "g: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.g);
    s << indent << "b: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.b);
  }
};

} // namespace message_operations
} // namespace ros

#endif // HEBI_CPP_API_EXAMPLES_MESSAGE_BASEMOTIONGOAL_H