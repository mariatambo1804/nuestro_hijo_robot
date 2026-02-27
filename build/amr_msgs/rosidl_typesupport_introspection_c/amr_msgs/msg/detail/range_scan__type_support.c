// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from amr_msgs:msg/RangeScan.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "amr_msgs/msg/detail/range_scan__rosidl_typesupport_introspection_c.h"
#include "amr_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "amr_msgs/msg/detail/range_scan__functions.h"
#include "amr_msgs/msg/detail/range_scan__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `ranges`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__RangeScan_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  amr_msgs__msg__RangeScan__init(message_memory);
}

void amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__RangeScan_fini_function(void * message_memory)
{
  amr_msgs__msg__RangeScan__fini(message_memory);
}

size_t amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__size_function__RangeScan__ranges(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__get_const_function__RangeScan__ranges(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__get_function__RangeScan__ranges(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__fetch_function__RangeScan__ranges(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__get_const_function__RangeScan__ranges(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__assign_function__RangeScan__ranges(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__get_function__RangeScan__ranges(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__resize_function__RangeScan__ranges(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__RangeScan_message_member_array[6] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(amr_msgs__msg__RangeScan, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "radiation_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(amr_msgs__msg__RangeScan, radiation_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "field_of_view",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(amr_msgs__msg__RangeScan, field_of_view),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "min_range",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(amr_msgs__msg__RangeScan, min_range),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "max_range",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(amr_msgs__msg__RangeScan, max_range),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "ranges",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(amr_msgs__msg__RangeScan, ranges),  // bytes offset in struct
    NULL,  // default value
    amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__size_function__RangeScan__ranges,  // size() function pointer
    amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__get_const_function__RangeScan__ranges,  // get_const(index) function pointer
    amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__get_function__RangeScan__ranges,  // get(index) function pointer
    amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__fetch_function__RangeScan__ranges,  // fetch(index, &value) function pointer
    amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__assign_function__RangeScan__ranges,  // assign(index, value) function pointer
    amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__resize_function__RangeScan__ranges  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__RangeScan_message_members = {
  "amr_msgs__msg",  // message namespace
  "RangeScan",  // message name
  6,  // number of fields
  sizeof(amr_msgs__msg__RangeScan),
  amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__RangeScan_message_member_array,  // message members
  amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__RangeScan_init_function,  // function to initialize message memory (memory has to be allocated)
  amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__RangeScan_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__RangeScan_message_type_support_handle = {
  0,
  &amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__RangeScan_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_amr_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, amr_msgs, msg, RangeScan)() {
  amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__RangeScan_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__RangeScan_message_type_support_handle.typesupport_identifier) {
    amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__RangeScan_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &amr_msgs__msg__RangeScan__rosidl_typesupport_introspection_c__RangeScan_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
