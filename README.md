# Mindera Graduate Challenge

[![Build Status](https://travis-ci.org/jrfcabral/connected-component-labeling.svg?branch=master)](https://travis-ci.org/jrfcabral/connected-component-labeling)

This repository contains my implementation of the mindera adjacent cell challenge. The goal of the challenge is to develop a program which outputs the coordinates of every cell in each connected component in a matrix.

## Installation

The latest release of the executable, compatible with Linux and compiled under Ubuntu 18.04 is available in the "Releases" tab.

## Building and dependencies

This project depends on the Boost library. Under ubuntu the minimum required packages are libboost-dev and libboost-program-options-dev.

This project uses CMake as a compilation framework. I recommend that you build the project in a separate directory. An example of a possible compilation process is as follows:

```
git clone https://github.com/jrfcabral/connected-component-labeling
mkdir connected-component-labeling/build
cd connected-component-labeling/build
cmake ..
make
```

## Algorithms and usage

Two different, alternative algorithms are implemented in this project. The algorithm can be chosen using the ```--algorithm``` flag, choosing either ```one-pass``` or ```two-pass```. The differences between each algorithm are described below.

 The first is a simple iterative walk over the entire input. Whenever a element of a group who has not yet been assigned to an existing group is found, the algorithms performs a depth-first search on the cluster to which that group belongs and discovers all elements of the group.

The second algorithm is an implementation of the Rosenfeld algorithm for connected component labeling, widely used in the computer vision field. It iterates twice over the input. On the first pass it naively generates labels based only on the cell under observation and the cell immediately to the left and above. Each set so discovered is added to a disjoint set data structure. On the second pass sets which are connected are joined together and the label is updated. This implementation is much faster than the previous one at correctly labeling every single set, but slightly slower at enumerating the coordinates of all elements in each set.

## Tests and tooling
Tests to the implemented algorithms as well as the data handling are implemented in the test folder, using the Boost test framework. Tests are compiled into separate executables when compilation is performed. To run the tests, after compiling the program, run ```make test```.

This project uses Travis CI, which builds a docker image with all needed dependencies and performs compilation on every commit pushed to the repository. Additionally Travis runs the implemented tests. Additionally continuous deployment is enabled in the master branch. When a commit or pull request is merged into the master branch Travis will, in addition to building and running the tests, extract the generated executable and add it to the releases tab automatically.