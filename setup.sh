install python3
python -m pip install pyserial


git clone https://github.com/queezythegreat/arduino-cmake
install the stuff here: https://github.com/queezythegreat/arduino-cmake
Download the SDK at https://www.arduino.cc/en/main/software and update the path to it
 in arduino/CMakeLists.txt

To build arduino code:
- mkdir build
- cd build
- cmake .. && make upload
