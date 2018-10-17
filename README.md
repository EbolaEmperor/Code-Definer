# Code-Definer

这个工具可以将您代码中的所有变量替换成若干个下划线

项目刚刚创建，欢迎大家帮忙找bug

目前已知的未解决bug：

1. STL中的奇怪变量类型无法识别

2. 函数中定义的传入参数识别可能会出锅

若主程序bug已经完全解决，后期将会用python制作一个简易的UI

### main.cpp

这是该项目中最重要的一个文件，是本工具的核心

若单独使用，需要先将其编译，编译时应该使用C++11或更高版本

编译后，打开cmd窗口，然后按以下方式调用

```
main.exe YourCode.cpp Output.cpp    (Windows cmd)
.\main YourCode.cpp Output.cpp      (Windows Power Shell)
./main YourCode.cpp Output.cpp      (Linux)
```
