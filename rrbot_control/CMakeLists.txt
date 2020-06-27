cmake_minimum_required(VERSION 2.8.3)
project(rrbot_control)

find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

catkin_package()

install(DIRECTORY config
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(actuator_interface src/actuator_interface.cpp)
target_link_libraries(actuator_interface ${catkin_LIBRARIES})
add_dependencies(actuator_interface actuator_interface_cpp)
