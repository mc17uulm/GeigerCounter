# GeigerCounter

## Install

Clone repository in Arduino libraries folder:

````shell script
git clone git@github.com:mc17uulm/GeigerCounter.git
````

## Usage

### Arduino IDE
````c++
#include "./src/GeigerCounter.h"

GeigerCounter app;

void setup() {
  app.setup();
}

void loop() {
  app.loop();
}
````

