# RLZ

## Description

MySeqAnProject is a C++ application that demonstrates the use of the SeqAn3 library for genomic data compression and decompression using FM-index. The project includes a RLZ class for efficient pattern searching and reconstruction of genomic sequences.

## Features

- Build and query FM-index on genomic data
- Compress genomic data by searching patterns
- Decompress genomic data by reconstructing sequences

## Dependencies

- [CMake](https://cmake.org/) 3.10 or higher
- [SeqAn3](https://github.com/seqan/seqan3) library

## Getting Started

### Prerequisites

Ensure you have CMake and SeqAn3 installed on your system.

### Building the Project

1. Clone the repository:
```
git clone https://github.com/Dhruv-mak/rlz
cd MySeqAnProject
```
2. Create a build directory
```
mkdir build
cd build
```
3. Configure the project
```
cmake -DCMAKE_BUILD_TYPE=Release ..
```
You can also specify other build types such as Debug:
```
cmake -DCMAKE_BUILD_TYPE=Debug ..
```
4. Build the project
```
make
```

### Running the project

After building the project, an executable named rlz will be created in the build directory. Run it with:
```
./rlz [options] [args]
```

### Project Structure

```
rlz/
├── CMakeLists.txt
├── src/
│   ├── main.cpp
│   ├── rlz.h
│   └── rlz.cpp
├── build/
```

### License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/Dhruv-mak/rlz/blob/main/LICENSE) file for details

### Acknowledgements

- [SeqAn3](https://docs.seqan.de/seqan3/main_user/index.html) library for providing powerful tools for biological sequence analysis 
- [S. Kuruppu, S. J. Puglisi and J. Zobel, Relative Lempel-Ziv Compression of Genomes for Large-Scale Storage and Retrieval](http://dx.doi.org/10.1007/978-3-642-16321-0_20). Proc. 17th International Symposium on String Processing and Information Retrieval (SPIRE 2010) Lecture Notes in Computer Science, Volume 6393, (2010) pp. 201-206. 