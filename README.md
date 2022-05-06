## Flower STL

My STL-stuff implementation of
- std::vector - key elements (flower_vector)
- stack (flower_stack) 
- heap - key elements (flower_heap)

### Flower Stack
##### available functions
- push 
- pop
- get_top
- is_empty

### Flower Vector
##### available functions
- reserve
- shrink_to_fit
- push_back (multiple arguments)
- emplace_back
- clear
- erase at given position
- realloc

##### overloaded operators
- [ ]
- =
- ==
- <<

### Flower Heap

Max-Heap implementation

##### available functions
- insert (multiple arguments)
- extract_max
- heap_sort
- get_item
- search
- is_empty

### How to run

```
git clone https://github.com/M4yfl0w3r/flower-stl.git

cd flower-stl 

mkdir build 

cd build

cmake ..

make
```

To run specific test:
```
./vector_tst 
./heap_tst
./stack_tst
```

Or 
```
./Tests
```

to run everything. Tests were written using Google Test. CMake automatically link the library to the program.
