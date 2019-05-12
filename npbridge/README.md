# 平台

1. Linux (Ubuntu/CentOS/Windows WSL)
2. Windows（可能不太好用）

# 软件需求

1. Python 3.5 以及以上，包含Development Library
2. 使用pip3安装cython和PyTorch
3. 如果需要使用CUDA加速，安装相应的驱动和CuDNN（参见PyTorch的文档）
4. 编译环境（gcc或msvc）

# 构建和运行

1. Linux

    make -f Makefile.gcc
    ./main
  
2. Windows（可能不太好用，默认不维护）
首先启动Visual Studio的命令行编译，然后

    nmake -f Makefile.msvc main.exe
    ./main.exe

