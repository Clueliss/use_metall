## Task

This is a scaffold for a CMake project that builds two executables, `write_data` and `read_data`. Your task is to extend it such that: 
- `write_data` stores some key-value pairs within a `boost::container::map`. Use the [metall allocator](https://github.com/dice-group/metall) to persist the stored pairs on disk. 
- `read_data` loads the `boost::container::map` which was persisted by `write_data` and prints the stored key-value pairs to stdout.

hint: It might be necessary to first create a metall segment with metall::create_only, before it can be opened for writing with metall::open_only. 

hint2: Have a look into the CMakeLists.txt. You need to include metall there.

## Build

This project must build on ubuntu 21.10 at least. 


To verify that everything builds and see the console output, run within this folder:
```
docker build .
# sudo docker build . ## if user is not in the docker group
```

Docker needs to be installed. If you are running windows, you can either use the linux subsystem, install Ubuntu 21.10 as dual boot or set up a ubuntu VM (e.g. with VirtualBox). 
