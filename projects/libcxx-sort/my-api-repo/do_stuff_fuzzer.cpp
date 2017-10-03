// Copyright 2017 Marshall Clow. All Rights Reserved.
// Licensed under the Apache License, Version 2.0 (the "License");

#include <cassert>
#include "FuzzSort.h"

// See http://libfuzzer.info for details.
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  size_t res = FuzzSort(data, size);
  assert(res == 0);
  return 0;
}
