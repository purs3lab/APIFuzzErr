
# Using this Repo
This is a basic starter repo designed for writing LLVM passes to help Holistic Software Security Course.

## Installing LLVM

```
wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
sudo ./llvm.sh <version number>
```
We will be using LLVM 12 in our course. So, you should be installing version 12, i.e., `sudo ./llvm.sh 12`


## Building Passes
```
mkdir build
cd build
cmake ..
make
```

## Using the pass
