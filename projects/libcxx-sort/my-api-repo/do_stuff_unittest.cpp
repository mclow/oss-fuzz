// Copyright 2017 Marshall Clow. All Rights Reserved.
// Licensed under the Apache License, Version 2.0 (the "License");

#include <cassert>
#include <iostream>

#include "FuzzSort.h"

void TestFuzzSort(const char *str, size_t size) {
	const uint8_t *data = (const uint8_t *) str;
	size_t result = FuzzSort(data, size);
	assert(result == 0);
}

int main(int argc, char **argv) {
//	Test some simple inputs, verify the output.
	TestFuzzSort("", 0);
	TestFuzzSort("foo", 1);
	TestFuzzSort("omg", 2);
	TestFuzzSort("bar", 3);
}
