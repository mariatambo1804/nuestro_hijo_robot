// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from amr_msgs:msg/RangeScan.idl
// generated code does not contain a copyright notice

#ifndef AMR_MSGS__MSG__DETAIL__RANGE_SCAN__BUILDER_HPP_
#define AMR_MSGS__MSG__DETAIL__RANGE_SCAN__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "amr_msgs/msg/detail/range_scan__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace amr_msgs
{

namespace msg
{

namespace builder
{

class Init_RangeScan_ranges
{
public:
  explicit Init_RangeScan_ranges(::amr_msgs::msg::RangeScan & msg)
  : msg_(msg)
  {}
  ::amr_msgs::msg::RangeScan ranges(::amr_msgs::msg::RangeScan::_ranges_type arg)
  {
    msg_.ranges = std::move(arg);
    return std::move(msg_);
  }

private:
  ::amr_msgs::msg::RangeScan msg_;
};

class Init_RangeScan_max_range
{
public:
  explicit Init_RangeScan_max_range(::amr_msgs::msg::RangeScan & msg)
  : msg_(msg)
  {}
  Init_RangeScan_ranges max_range(::amr_msgs::msg::RangeScan::_max_range_type arg)
  {
    msg_.max_range = std::move(arg);
    return Init_RangeScan_ranges(msg_);
  }

private:
  ::amr_msgs::msg::RangeScan msg_;
};

class Init_RangeScan_min_range
{
public:
  explicit Init_RangeScan_min_range(::amr_msgs::msg::RangeScan & msg)
  : msg_(msg)
  {}
  Init_RangeScan_max_range min_range(::amr_msgs::msg::RangeScan::_min_range_type arg)
  {
    msg_.min_range = std::move(arg);
    return Init_RangeScan_max_range(msg_);
  }

private:
  ::amr_msgs::msg::RangeScan msg_;
};

class Init_RangeScan_field_of_view
{
public:
  explicit Init_RangeScan_field_of_view(::amr_msgs::msg::RangeScan & msg)
  : msg_(msg)
  {}
  Init_RangeScan_min_range field_of_view(::amr_msgs::msg::RangeScan::_field_of_view_type arg)
  {
    msg_.field_of_view = std::move(arg);
    return Init_RangeScan_min_range(msg_);
  }

private:
  ::amr_msgs::msg::RangeScan msg_;
};

class Init_RangeScan_radiation_type
{
public:
  explicit Init_RangeScan_radiation_type(::amr_msgs::msg::RangeScan & msg)
  : msg_(msg)
  {}
  Init_RangeScan_field_of_view radiation_type(::amr_msgs::msg::RangeScan::_radiation_type_type arg)
  {
    msg_.radiation_type = std::move(arg);
    return Init_RangeScan_field_of_view(msg_);
  }

private:
  ::amr_msgs::msg::RangeScan msg_;
};

class Init_RangeScan_header
{
public:
  Init_RangeScan_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RangeScan_radiation_type header(::amr_msgs::msg::RangeScan::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RangeScan_radiation_type(msg_);
  }

private:
  ::amr_msgs::msg::RangeScan msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::amr_msgs::msg::RangeScan>()
{
  return amr_msgs::msg::builder::Init_RangeScan_header();
}

}  // namespace amr_msgs

#endif  // AMR_MSGS__MSG__DETAIL__RANGE_SCAN__BUILDER_HPP_
