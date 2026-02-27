// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from amr_msgs:msg/RangeScan.idl
// generated code does not contain a copyright notice

#ifndef AMR_MSGS__MSG__DETAIL__RANGE_SCAN__STRUCT_H_
#define AMR_MSGS__MSG__DETAIL__RANGE_SCAN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'ULTRASOUND'.
/**
  * To represent fixed-distance (binary) rangers set min_range == max_range == distance of detection.
  * These sensors should follow REP 117 and output -Inf if the object is detected and +Inf otherwise.
  * Radiation type enum
 */
enum
{
  amr_msgs__msg__RangeScan__ULTRASOUND = 0
};

/// Constant 'INFRARED'.
enum
{
  amr_msgs__msg__RangeScan__INFRARED = 1
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'ranges'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/RangeScan in the package amr_msgs.
/**
  * Single scan from an array of range sensors that measure distance within an arc.
  * This message is not appropriate for laser scanners. Use LaserScan instead.
 */
typedef struct amr_msgs__msg__RangeScan
{
  /// Timestamp in the header is the acquisition time of the first ranger.
  std_msgs__msg__Header header;
  /// Type of radiation used by the sensor (ultrasound or infrared).
  uint8_t radiation_type;
  /// The width of the measurement arc. The object causing the reading
  /// may be anywhere within [-field_of_view / 2, field_of_view / 2].
  /// 0 rad corresponds to the x-axis of the sensor.
  float field_of_view;
  /// Minimum range value.
  float min_range;
  /// Maximum range value.
  float max_range;
  /// Range data. Out-of-range values should be discarded.
  rosidl_runtime_c__float__Sequence ranges;
} amr_msgs__msg__RangeScan;

// Struct for a sequence of amr_msgs__msg__RangeScan.
typedef struct amr_msgs__msg__RangeScan__Sequence
{
  amr_msgs__msg__RangeScan * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} amr_msgs__msg__RangeScan__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AMR_MSGS__MSG__DETAIL__RANGE_SCAN__STRUCT_H_
