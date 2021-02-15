# Butterfly Logging Library
  
Butterfly is another `c++` logging library.  

It's still in development.  

Butterfly is designed to be ergonomic and powerful, not extra-performant.  

## Platform & Requirements & Installation

This library uses `c++17` standard only. It is available for Linux, Windows and MacOS.  

Butterfly is developped to be used as a static library (not as a shared library or a header-only).

The provided makefile compiles the library for Linux systems only.
```
$ git clone https://github.com/limserhane/Butterfly.git
$ cd Butterfly/
$ make
```
Grab the `bin/libbutterfly.a` static library and the `include/butterfly/` include folder and add them to your project.  


## Features

* Global registry available to store `Logger`s
	* Default logger for less verbosity
	* Retrieve loggers from anywhere in the source code

* Several levels of records to caracterize their severity

* Custom format for log records with various flags
	* Time (also with custom representation)
	* Level
	* Tag
	* Location in source code (file, line, function)

* Multiple ways to write log records through `Wing`s
	* Easy to implement custom `Wing`s

* Can log one record through multiple `Wing`s with a `Net`
* Level filter on `Wing`s

* Thread safe decorator for `Logger`s
	* Easy to implement other decorators

## Upcoming features

* Optimization
	* Move semantic
	* String optimization (`string_litterals`, `string_view`s, ...)
	* Inlining, `constexpr`, ...

* More `Wing`s
	* Callback function
	* Colored console

## Documentation

Documentation is coming. (The source code is well commented, though)

## Usage

Examples to find in the `example/` folder.  
    
### Basic usage
 ```c++
	auto consoleLogger = CreateWing<ConsoleWing>("", Level::warning); // Will only write in the console records that have a warning or higher level

	auto fileLogger = CreateWing<FileWing>("", "log-basic-usage.txt"); // Will write in the "log-basic-usage.txt" file all records (no level specified)

	auto logger = CreateNet("", {consoleLogger, fileLogger}); // Will log both in the console logger and in the file logger

	logger->Error("Network", "Network service unavailable"); // I can use logger to Log

	SetDefaultLogger(logger); // Or I can set logger as the default logger ...

	Trace("Engine", "Engine initialization complete"); // ... and log
 ```
### Advanced usage
 ```c++
	auto consoleLogger = CreateWing<ConsoleWing>("main", Level::warning, PackageFormatter::CompletePattern); // "main" logger will Log in the console with a different pattern than the default

	auto networklogger = CreateNet("network", {consoleLogger, CreateWing<FileWing>("", "log-advanced-usage.txt")}); // "network" logger will Log both in the console and in the file (through a newly created logger)
	
	SetDefaultLogger(consoleLogger);

	// "main" logger is the default logger
	Trace("Engine", "Engine initialization complete"); // this is a trace so it won't Log through main

	// I can retrieve the "main" logger from anywhere
	Get("main")->Error("Engine", "Engine initialization failed"); // this is an error so it will Log through main
	
	// I can retrieve the "network" logger from anywhere
	Get("network")->Trace("Network", "Socket binded to port 80"); // this will print both it the file and in the console
	Get("network")->Error("Network", "Network service unavailable"); // this will print both it the file and in the console
 ```

### Thread safe usage
```c++
	// This logger is not safe to concurrent accesses
	auto unsafelogger = CreateWing<FileWing>("unsafe", "log-unsafe-thread-safe-usage.txt");

	// This logger can be safely accessed by concurrent threads
	auto safelogger = CreateSafeLogger("safe", 
		CreateWing<FileWing>("", "log-safe-thread-safe-usage.txt")
	);

	std::thread foothread(foo);
	std::thread barthread(bar);

	// Here foo() and bar() are concurrent; but the "logfile" logger will safely write in "bin/log.txt"

	foothread.join();
	barthread.join();
```

---   
## Nina sang :  

Butterfly logging library was named after one of the greatest songs in history,

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
