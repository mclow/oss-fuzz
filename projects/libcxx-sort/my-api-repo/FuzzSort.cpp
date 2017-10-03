// Copyright 2017 Google Inc. All Rights Reserved.
// Licensed under the Apache License, Version 2.0 (the "License");

// Implementation of "my_api".
#include "FuzzSort.h"

#include <algorithm>
#include <vector>

size_t FuzzSort(const uint8_t *data, size_t size)
{
  std::vector<uint8_t> working(data, data + size);
  std::sort(working.begin(), working.end());
  if (!std::is_sorted(working.begin(), working.end())) return 1;
// If we had C++14, we could use the four iterator version of is_permutation
//  if (!std::is_permutation(data, data + size, working.begin(), working.end())) return 2;
  if (!std::is_permutation(data, data + size, working.begin())) return 2;
  return 0;
}
