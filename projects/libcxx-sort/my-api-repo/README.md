Example of [OSS-Fuzz ideal integration](../../../docs/ideal_integration.md).

This directory contains an example software project that has most of the traits of [ideal](../../../docs/ideal_integration.md) support for fuzzing. 

## Files in my-api-repo
Imagine that these files reside in your project's repository:

* [FuzzSort.h](FuzzSort.h): and [FuzzSort.cpp](FuzzSort.cpp) implement the API we want to test/fuzz (`std::sort`, in this case)
* [do\_stuff\_unittest.cpp](do_stuff_unittest.cpp): is a unit test for `FuzzSort()`. Unit tests are not necessary for fuzzing, but are generally a good practice. 
* [do\_stuff\_fuzzer.cpp](do_stuff_fuzzer.cpp): is a [fuzz target](http://libfuzzer.info/#fuzz-target) for `FuzzSort()`.
* [do\_stuff\_test\_data](do_stuff_test_data): corpus directory for [do\_stuff\_fuzzer.cpp](do_stuff_fuzzer.cpp).
<!--
* [do\_stuff\_fuzzer.dict](do_stuff_fuzzer.dict): a [fuzzing dictionary file](https://github.com/google/oss-fuzz/blob/master/docs/new_project_guide.md#dictionaries) for `FuzzSort()`. Optional, but may improve fuzzing in many cases. 
-->
* [Makefile](Makefile): is a build file (the same can be done with other build systems):
  * accepts external compiler flags via `$CC`, `$CXX`, `$CFLAGS`, `$CXXFLAGS`
  * accepts external fuzzing engine via `$LIB_FUZZING_ENGINE`, by default uses [standalone\_fuzz\_target\_runner.cpp](standalone_fuzz_target_runner.cpp)
  * builds the fuzz target(s) and their corpus archive(s)
  * `make check` executes [do\_stuff\_fuzzer.cpp](do_stuff_fuzzer.cpp) on [`do_stuff_test_data/*`](do_stuff_test_data), thus ensures that the fuzz target is up to date and uses it as a regression test.
* [standalone\_fuzz\_target\_runner.cpp](standalone_fuzz_target_runner.cpp): is a simple standalone runnner for fuzz targets. You may use it to execute a fuzz target on given files w/o having to link in libFuzzer or other fuzzing engine.

## Files in OSS-Fuzz repository
* [oss-fuzz/projects/example](..)
  * [Dockerfile](../Dockerfile): sets up the build environment
  * [build.sh](../build.sh): builds the fuzz target(s). The smaller this file the better, most of the logic should be inside the project's build system).
  * [project.yaml](../project.yaml): short project description and contact info.

## Example bug
[Example bug report filed automatically](https://bugs.chromium.org/p/oss-fuzz/issues/detail?id=1562)


