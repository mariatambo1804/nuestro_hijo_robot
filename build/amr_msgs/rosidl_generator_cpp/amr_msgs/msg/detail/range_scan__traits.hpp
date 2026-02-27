// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from amr_msgs:msg/RangeScan.idl
// generated code does not contain a copyright notice

#ifndef AMR_MSGS__MSG__DETAIL__RANGE_SCAN__TRAITS_HPP_
#define AMR_MSGS__MSG__DETAIL__RANGE_SCAN__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "amr_msgs/msg/detail/range_scan__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace amr_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const RangeScan & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: radiation_type
  {
    out << "radiation_type: ";
    rosidl_generator_traits::value_to_yaml(msg.radiation_type, out);
    out << ", ";
  }

  // member: field_of_view
  {
    out << "field_of_view: ";
    rosidl_generator_traits::value_to_yaml(msg.field_of_view, out);
    out << ", ";
  }

  // member: min_range
  {
    out << "min_range: ";
    rosidl_generator_traits::value_to_yaml(msg.min_range, out);
    out << ", ";
  }

  // member: max_range
  {
    out << "max_range: ";
    rosidl_generator_traits::value_to_yaml(msg.max_range, out);
    out << ", ";
  }

  // member: ranges
  {
    if (msg.ranges.size() == 0) {
      out << "ranges: []";
    } else {
      out << "ranges: [";
      size_t pending_items = msg.ranges.size();
      for (auto item : msg.ranges) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RangeScan & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: radiation_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "radiation_type: ";
    rosidl_generator_traits::value_to_yaml(msg.radiation_type, out);
    out << "\n";
  }

  // member: field_of_view
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "field_of_view: ";
    rosidl_generator_traits::value_to_yaml(msg.field_of_view, out);
    out << "\n";
  }

  // member: min_range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "min_range: ";
    rosidl_generator_traits::value_to_yaml(msg.min_range, out);
    out << "\n";
  }

  // member: max_range
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_range: ";
    rosidl_generator_traits::value_to_yaml(msg.max_range, out);
    out << "\n";
  }

  // member: ranges
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.ranges.size() == 0) {
      out << "ranges: []\n";
    } else {
      out << "ranges:\n";
      for (auto item : msg.ranges) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RangeScan & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace amr_msgs

namespace rosidl_generator_traits
{

[[deprecated("use amr_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const amr_msgs::msg::RangeScan & msg,
  std::ostream & out, size_t indentation = 0)
{
  amr_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use amr_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const amr_msgs::msg::RangeScan & msg)
{
  return amr_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<amr_msgs::msg::RangeScan>()
{
  return "amr_msgs::msg::RangeScan";
}

template<>
inline const char * name<amr_msgs::msg::RangeScan>()
{
  return "amr_msgs/msg/RangeScan";
}

template<>
struct has_fixed_size<amr_msgs::msg::RangeScan>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<amr_msgs::msg::RangeScan>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<amr_msgs::msg::RangeScan>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AMR_MSGS__MSG__DETAIL__RANGE_SCAN__TRAITS_HPP_
