cmake_minimum_required(VERSION 3.24)
project(test)

set(CMAKE_CXX_FLAGS "-fno-elide-constructors")

set(CMAKE_CXX_STANDARD 17)

add_executable(test main.cpp musor/sort.cpp musor/sort.h musor/calculator.cpp musor/calculator.h musor/lambda_t.cpp musor/lambda_t.h musor/Stack.cpp musor/Stack.h musor/Point.cpp musor/Point.h musor/operator_t.cpp musor/operator_t.h musor/associationt.cpp musor/associationt.h musor/Mycontainer.cpp musor/Mycontainer.h inheritance.cpp inheritance.h musor/shablon.cpp musor/shablon.h autoptr.cpp autoptr.h pattern/Singleton.cpp pattern/Singleton.h pattern/AbstractFactory.cpp pattern/AbstractFactory.h pattern/Factory.cpp pattern/Factory.h pattern/Prototype.cpp pattern/Prototype.h pattern/Builder.cpp pattern/Builder.h)

# target_link_libraries()

