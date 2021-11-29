# Butterfly Logging Library
  
Butterfly is another `c++` logging library.  

Butterfly is designed to be ergonomic and powerful.  

<!-- The library is still in development. -->

## Platform & Requirements & Installation

This library is a standalone and uses `c++17` standard. It is available for Linux, Windows and MacOS.  

Butterfly is developped to be used as a static library.

---
To compile the library, CMake tool is required.

### Install library
```
$ git clone https://github.com/limserhane/Butterfly.git
$ cd Butterfly/
$ make install
$ make build
```
The static library and the include files can be found in the `build/` directory.

### Compile library only
```
$ git clone https://github.com/limserhane/Butterfly.git
$ cd Butterfly/
$ make generate-library
$ make build
```

### Compile library and examples
```
$ git clone https://github.com/limserhane/Butterfly.git
$ cd Butterfly/
$ make generate-all
$ make build
```

## Features

* Global registry available to store the created loggers
	* Default logger for less verbosity
	* Retrieve loggers from anywhere in the source code

* Multiple log targets
	* Console
	* Colored console
	* File

* Thread safe loggers

* Easy to implement custom log targets

* Several levels to caracterize logs severity

* Several patterns for log records

## Upcoming features

* Support for output operator `<<` and string format `"%d frames", frames`

* More log targets
	* Callback function
	* Buffered logger

* Custom patterns

* Performance optimization

* Shared library / Header only library

## Documentation

Documentation is coming. (The source code is well commented, though)

## Usage

### Basic usage
 ```c++
auto consoleLogger = create_wing<console_wing>("", level::all); // Will write in the console all records

auto fileLogger = create_wing<file_wing>("", "log-basic-usage.txt"); // Will write in the "log-basic-usage.txt" file all records (no level specified)

auto logger = create_net("", {consoleLogger, fileLogger}); // Will log both in the console logger and in the file logger

logger->error("Network", "Network service unavailable"); // I can use logger to log

set_default_logger(logger); // Or I can set logger as the default logger ...

info("Engine", "Engine initialization complete"); // ... and log

 ```

### Advanced usage
 ```c++
auto consoleLogger = create_wing<console_wing>("main", level::warning, pattern::complete); // "main" logger will log in the console with a different pattern than the default

auto networklogger = create_net("network", {consoleLogger, create_wing<file_wing>("", "log-advanced-usage.txt")}); // "network" logger will log both in the console and in the file (through a newly created logger)
	
set_default_logger(consoleLogger);

// "main" logger is the default logger
trace("Engine", "Engine initialization complete"); // this is a trace so it won't log through main

// I can retrieve the "main" logger from anywhere
get("main")->error("Engine", "Engine initialization failed"); // this is an error so it will log through main
	
// I can retrieve the "network" logger from anywhere
get("network")->trace("Network", "Socket binded to port 80"); // this will print both it the file and in the console
get("network")->error("Network", "Network service unavailable"); // this will print both it the file and in the console
 ```

### Thread safe usage
```c++
// This logger is not safe to concurrent accesses
auto unsafelogger = create_wing<file_wing>("unsafe", "log-unsafe-thread-safe-usage.txt");

// This logger can be safely accessed by concurrent threads
auto safelogger = create_safe_logger("safe", 
	create_wing<file_wing>("", "log-safe-thread-safe-usage.txt")
);

std::thread foothread(foo);
std::thread barthread(bar);

// Here foo() and bar() are logging through the loggers concurrently; but the "safe" logger will safely write in "bin/log.txt"

foothread.join();
barthread.join();
```

---   
# Butterfly x Nina Simone 

*Feelin' good*, interpretation by *Nina Simone*

> *. . .*
>
> *Butterflies all havin' fun, you know what I mean*  
>
> *Sleep in peace when day is done, that's what I mean*  
>
> *And this old world, is a new world*  
>
> *And a bold world for me*

![Picture of Nina Simone](https://www.numero.com/sites/default/files/images/article/homepage/full/nina-simone-fodder-on-my-wings-album-numero-magazine.jpg)
