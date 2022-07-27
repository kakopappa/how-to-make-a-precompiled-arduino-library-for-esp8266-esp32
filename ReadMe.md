**Step 1:**

Create hello.cpp and hello.h and add the implementation.

Example files are in lib folder.

**Step 2:**

Make the archive file (.a) using xtensa-esp32-elf-gcc.exe for ESP32 and use xtensa-lx106-elf-gcc for ESP8266

xtensa-esp32-elf-gcc.exe -c hello.cpp -o libhello.o
xtensa-esp32-elf-ar.exe crf libhello.a libhello.o

Note: xtensa-esp32-elf-gcc.exe is located here if you have installed ESP32 in your arduino IDE. 
You may want to add this path to system env for easy access.
C:\Users\<USERNAME>\AppData\Local\Arduino15\packages\esp32\tools\xtensa-esp32s2-elf-gcc\gcc8_4_0-esp-2021r2-patch3\bin\

Now you should have a libhello.a in the path.

**Step 3:**

1. Make the library for Ardunio (arduino-helloworld-lib) and copy the header files (lib\hello.h) to library src folder (arduino-helloworld-lib\src). 
2. Copy the libhello.a to arduino-helloworld-lib\src\esp32 or arduino-helloworld-lib\src\esp8266 depending on which gcc you use to create the archive file.

**Step 4:**

Invoke the function from Ardunio sketch. example.ino

```
#include <hello.h> // hello.h header from our library  (arduino-helloworld-lib)

#define BAUD_RATE  9600

void setup() {
   Serial.begin(BAUD_RATE);
  
}

void loop() {
  // put your main code here, to run repeatedly:
   int result = add(1, 1); // Invokes the add function in libhello.a 
   Serial.println(result);
   delay(1000);
}
```









