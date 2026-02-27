// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from amr_msgs:msg/PoseStamped.idl
// generated code does not contain a copyright notice

#ifndef AMR_MSGS__MSG__DETAIL__POSE_STAMPED__STRUCT_H_
#define AMR_MSGS__MSG__DETAIL__POSE_STAMPED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/PoseStamped in the package amr_msgs.
typedef struct amr_msgs__msg__PoseStamped
{
  std_msgs__msg__Header header;
  geometry_msgs__msg__Pose pose;
  bool localized;
} amr_msgs__msg__PoseStamped;

// Struct for a sequence of amr_msgs__msg__PoseStamped.
typedef struct amr_msgs__msg__PoseStamped__Sequence
{
  amr_msgs__msg__PoseStamped * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} amr_msgs__msg__PoseStamped__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AMR_MSGS__MSG__DETAIL__POSE_STAMPED__STRUCT_H_
