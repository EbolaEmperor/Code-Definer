# Code-Definer

这个工具可以将您代码中的所有变量替换成若干个下划线

项目刚刚创建，欢迎大家帮忙找bug

### 环境要求

python3，包含tkinter库

支持c++11或以上标准的g++编译器

### Main

这里有三个不同版本的代码，由三个不同的开发者维护，每个版本各有特色

- hwc版本：只将变量名替换成若干个下划线，其它保留。暂不支持带数字的变量名以及STL的变量类型。在变量名不带数字的情况下，该版本较为稳定

- lsq版本：将一切东西都替换成下划线，其中关键字在开头define成若干个下划线。有一些语法暂时无法识别，不保证转化后的代码能编译通过

所有版本的调用方式是相同的。若需单独使用，需要先编译main.cpp，然后按以下语法使用：

- Windows cmd

```
main.exe YourSource.cpp result.cpp
```

- Windows Power Shell

```
.\main YourSource.cpp result.cpp
```

- Linux

```
./main YourSource.cpp result.cpp
```