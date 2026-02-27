// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from amr_msgs:msg/PoseStamped.idl
// generated code does not contain a copyright notice

#ifndef AMR_MSGS__MSG__DETAIL__POSE_STAMPED__BUILDER_HPP_
#define AMR_MSGS__MSG__DETAIL__POSE_STAMPED__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "amr_msgs/msg/detail/pose_stamped__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace amr_msgs
{

namespace msg
{

namespace builder
{

class Init_PoseStamped_localized
{
public:
  explicit Init_PoseStamped_localized(::amr_msgs::msg::PoseStamped & msg)
  : msg_(msg)
  {}
  ::amr_msgs::msg::PoseStamped localized(::amr_msgs::msg::PoseStamped::_localized_type arg)
  {
    msg_.localized = std::move(arg);
    return std::move(msg_);
  }

private:
  ::amr_msgs::msg::PoseStamped msg_;
};

class Init_PoseStamped_pose
{
public:
  explicit Init_PoseStamped_pose(::amr_msgs::msg::PoseStamped & msg)
  : msg_(msg)
  {}
  Init_PoseStamped_localized pose(::amr_msgs::msg::PoseStamped::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_PoseStamped_localized(msg_);
  }

private:
  ::amr_msgs::msg::PoseStamped msg_;
};

class Init_PoseStamped_header
{
public:
  Init_PoseStamped_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseStamped_pose header(::amr_msgs::msg::PoseStamped::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PoseStamped_pose(msg_);
  }

private:
  ::amr_msgs::msg::PoseStamped msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::amr_msgs::msg::PoseStamped>()
{
  return amr_msgs::msg::builder::Init_PoseStamped_header();
}

}  // namespace amr_msgs

#endif  // AMR_MSGS__MSG__DETAIL__POSE_STAMPED__BUILDER_HPP_
