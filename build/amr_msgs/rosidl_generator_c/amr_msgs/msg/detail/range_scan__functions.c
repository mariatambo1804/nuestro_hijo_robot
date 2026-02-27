// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from amr_msgs:msg/RangeScan.idl
// generated code does not contain a copyright notice
#include "amr_msgs/msg/detail/range_scan__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `ranges`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
amr_msgs__msg__RangeScan__init(amr_msgs__msg__RangeScan * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    amr_msgs__msg__RangeScan__fini(msg);
    return false;
  }
  // radiation_type
  // field_of_view
  // min_range
  // max_range
  // ranges
  if (!rosidl_runtime_c__float__Sequence__init(&msg->ranges, 0)) {
    amr_msgs__msg__RangeScan__fini(msg);
    return false;
  }
  return true;
}

void
amr_msgs__msg__RangeScan__fini(amr_msgs__msg__RangeScan * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // radiation_type
  // field_of_view
  // min_range
  // max_range
  // ranges
  rosidl_runtime_c__float__Sequence__fini(&msg->ranges);
}

bool
amr_msgs__msg__RangeScan__are_equal(const amr_msgs__msg__RangeScan * lhs, const amr_msgs__msg__RangeScan * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // radiation_type
  if (lhs->radiation_type != rhs->radiation_type) {
    return false;
  }
  // field_of_view
  if (lhs->field_of_view != rhs->field_of_view) {
    return false;
  }
  // min_range
  if (lhs->min_range != rhs->min_range) {
    return false;
  }
  // max_range
  if (lhs->max_range != rhs->max_range) {
    return false;
  }
  // ranges
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->ranges), &(rhs->ranges)))
  {
    return false;
  }
  return true;
}

bool
amr_msgs__msg__RangeScan__copy(
  const amr_msgs__msg__RangeScan * input,
  amr_msgs__msg__RangeScan * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // radiation_type
  output->radiation_type = input->radiation_type;
  // field_of_view
  output->field_of_view = input->field_of_view;
  // min_range
  output->min_range = input->min_range;
  // max_range
  output->max_range = input->max_range;
  // ranges
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->ranges), &(output->ranges)))
  {
    return false;
  }
  return true;
}

amr_msgs__msg__RangeScan *
amr_msgs__msg__RangeScan__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  amr_msgs__msg__RangeScan * msg = (amr_msgs__msg__RangeScan *)allocator.allocate(sizeof(amr_msgs__msg__RangeScan), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(amr_msgs__msg__RangeScan));
  bool success = amr_msgs__msg__RangeScan__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
amr_msgs__msg__RangeScan__destroy(amr_msgs__msg__RangeScan * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    amr_msgs__msg__RangeScan__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
amr_msgs__msg__RangeScan__Sequence__init(amr_msgs__msg__RangeScan__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  amr_msgs__msg__RangeScan * data = NULL;

  if (size) {
    data = (amr_msgs__msg__RangeScan *)allocator.zero_allocate(size, sizeof(amr_msgs__msg__RangeScan), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = amr_msgs__msg__RangeScan__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        amr_msgs__msg__RangeScan__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
amr_msgs__msg__RangeScan__Sequence__fini(amr_msgs__msg__RangeScan__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      amr_msgs__msg__RangeScan__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

amr_msgs__msg__RangeScan__Sequence *
amr_msgs__msg__RangeScan__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  amr_msgs__msg__RangeScan__Sequence * array = (amr_msgs__msg__RangeScan__Sequence *)allocator.allocate(sizeof(amr_msgs__msg__RangeScan__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = amr_msgs__msg__RangeScan__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
amr_msgs__msg__RangeScan__Sequence__destroy(amr_msgs__msg__RangeScan__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    amr_msgs__msg__RangeScan__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
amr_msgs__msg__RangeScan__Sequence__are_equal(const amr_msgs__msg__RangeScan__Sequence * lhs, const amr_msgs__msg__RangeScan__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!amr_msgs__msg__RangeScan__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
amr_msgs__msg__RangeScan__Sequence__copy(
  const amr_msgs__msg__RangeScan__Sequence * input,
  amr_msgs__msg__RangeScan__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(amr_msgs__msg__RangeScan);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    amr_msgs__msg__RangeScan * data =
      (amr_msgs__msg__RangeScan *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!amr_msgs__msg__RangeScan__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          amr_msgs__msg__RangeScan__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!amr_msgs__msg__RangeScan__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
