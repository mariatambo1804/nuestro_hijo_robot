// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from amr_msgs:msg/RangeScan.idl
// generated code does not contain a copyright notice

#ifndef AMR_MSGS__MSG__DETAIL__RANGE_SCAN__STRUCT_HPP_
#define AMR_MSGS__MSG__DETAIL__RANGE_SCAN__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__amr_msgs__msg__RangeScan __attribute__((deprecated))
#else
# define DEPRECATED__amr_msgs__msg__RangeScan __declspec(deprecated)
#endif

namespace amr_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RangeScan_
{
  using Type = RangeScan_<ContainerAllocator>;

  explicit RangeScan_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->radiation_type = 0;
      this->field_of_view = 0.0f;
      this->min_range = 0.0f;
      this->max_range = 0.0f;
    }
  }

  explicit RangeScan_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->radiation_type = 0;
      this->field_of_view = 0.0f;
      this->min_range = 0.0f;
      this->max_range = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _radiation_type_type =
    uint8_t;
  _radiation_type_type radiation_type;
  using _field_of_view_type =
    float;
  _field_of_view_type field_of_view;
  using _min_range_type =
    float;
  _min_range_type min_range;
  using _max_range_type =
    float;
  _max_range_type max_range;
  using _ranges_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _ranges_type ranges;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__radiation_type(
    const uint8_t & _arg)
  {
    this->radiation_type = _arg;
    return *this;
  }
  Type & set__field_of_view(
    const float & _arg)
  {
    this->field_of_view = _arg;
    return *this;
  }
  Type & set__min_range(
    const float & _arg)
  {
    this->min_range = _arg;
    return *this;
  }
  Type & set__max_range(
    const float & _arg)
  {
    this->max_range = _arg;
    return *this;
  }
  Type & set__ranges(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->ranges = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t ULTRASOUND =
    0u;
  static constexpr uint8_t INFRARED =
    1u;

  // pointer types
  using RawPtr =
    amr_msgs::msg::RangeScan_<ContainerAllocator> *;
  using ConstRawPtr =
    const amr_msgs::msg::RangeScan_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<amr_msgs::msg::RangeScan_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<amr_msgs::msg::RangeScan_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      amr_msgs::msg::RangeScan_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<amr_msgs::msg::RangeScan_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      amr_msgs::msg::RangeScan_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<amr_msgs::msg::RangeScan_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<amr_msgs::msg::RangeScan_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<amr_msgs::msg::RangeScan_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__amr_msgs__msg__RangeScan
    std::shared_ptr<amr_msgs::msg::RangeScan_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__amr_msgs__msg__RangeScan
    std::shared_ptr<amr_msgs::msg::RangeScan_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RangeScan_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->radiation_type != other.radiation_type) {
      return false;
    }
    if (this->field_of_view != other.field_of_view) {
      return false;
    }
    if (this->min_range != other.min_range) {
      return false;
    }
    if (this->max_range != other.max_range) {
      return false;
    }
    if (this->ranges != other.ranges) {
      return false;
    }
    return true;
  }
  bool operator!=(const RangeScan_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RangeScan_

// alias to use template instance with default allocator
using RangeScan =
  amr_msgs::msg::RangeScan_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RangeScan_<ContainerAllocator>::ULTRASOUND;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t RangeScan_<ContainerAllocator>::INFRARED;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace amr_msgs

#endif  // AMR_MSGS__MSG__DETAIL__RANGE_SCAN__STRUCT_HPP_
