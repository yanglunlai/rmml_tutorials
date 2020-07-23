cmake_minimum_required(VERSION 2.8.3)
project(rmml_tutorials)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)


catkin_package(

)


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(lasertest src/lasertest.cpp)
target_link_libraries(lasertest ${catkin_LIBRARIES})
add_dependencies(lasertest rmml_tutorials_gencpp)

