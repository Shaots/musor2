cmake_minimum_required(VERSION 3.24)
project(test)

set(CMAKE_CXX_FLAGS "-fno-elide-constructors")

set(CMAKE_CXX_STANDARD 17)

add_executable(test main.cpp musor/sort.cpp  musor/calculator.cpp  musor/lambda_t.cpp musor/Stack.cpp  musor/Point.cpp  musor/operator_t.cpp  musor/associationt.cpp  musor/Mycontainer.cpp  inheritance.cpp  musor/shablon.cpp pattern/Singleton.cpp  pattern/AbstractFactory.cpp  pattern/Factory.cpp  pattern/Prototype.cpp  pattern/Builder.cpp)

# target_link_libraries()

