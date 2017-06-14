cmake_minimum_required(VERSION 2.8.3)
project(rhydian_practice)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package(
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(rhydian_practice_node src/first_node.cpp)
add_executable(talker_node src/talker.cpp)
add_executable(listener_node src/listener.cpp)

target_link_libraries(rhydian_practice_node ${catkin_LIBRARIES})
target_link_libraries(talker_node ${catkin_LIBRARIES})
target_link_libraries(listener_node ${catkin_LIBRARIES})
