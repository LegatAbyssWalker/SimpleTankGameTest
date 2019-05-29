cmake_minimum_required(VERSION 3.6)
project(SimpleTankGame CXX)

find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

add_executable(main ./Animation.cpp
./Bullet.cpp
./Coin.cpp
./Enemy.cpp
./FPSCounter.cpp
./Game.cpp
./Main.cpp
./Player.cpp
./PlaySound.cpp)

target_link_libraries(main sfml-graphics sfml-audio)

file(COPY res/ DESTINATION ${CMAKE_BINARY_DIR}/res)
