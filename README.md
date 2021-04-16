#  OmSU_1_course (2020-2021)
[![GitHub license](https://img.shields.io/github/license/ars-kalinichenko/OmSU_1_course?color=success&label=License)](https://github.com/ars-kalinichenko/OmSU_1_course/blob/master/LICENSE) [![Project Language](https://img.shields.io/github/languages/top/ars-kalinichenko/OmSU_1_course)](https://github.com/ars-kalinichenko/OmSU_1_course)

## About project:
🙋🏻  The project contains laboratory work, seminars, and individual homework assignments.

## Project structure
* Bakhta/individual_homework - Large individual works, which were given for 2 weeks - a month
* Bakhta/labs - Small assignments that prepare for individual assignments
* Backhta/seminars - Mainly on algorithms, data structures and more complex things

In each of the directories listed above, there are directories: **src** (stores the source code, as well as CMakeLists.txt for building the project), **include** (stores the header files).

## How do I run one of the subprojects (seminars, labs, ihws)?
In ```OmSU_1_course/CMakeLists.txt``` change this line:
```cmake
# set your path to subproject(seminars, labs, individual homeworks)
set(MAIN_DIR ${PROJECT_SOURCE_DIR}/Bakhta/seminars/seminar_9)
# or
set(MAIN_DIR ${PROJECT_SOURCE_DIR}/Bakhta/individual_homework/ihw_2_1)
```
If you are using clion, then copy the entire project, *"Add configuration"* -> *"Cmake Application"*. Other times google ```how to run cmake projects <your IDE>```.
