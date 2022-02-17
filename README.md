```cmake
# 遍历项目根目录下所有的 .cpp 文件
file (GLOB_RECURSE files *.cpp)
foreach (file ${files})
string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
add_executable (${exe} ${file})
message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()
```

> 添加头文件防止弹框闪退
> 
> #include<windows.h>
> 
> system("pause")


---


[Cmake, tasks, launch关系](https://blog.csdn.net/lovebasamessi/article/details/108716206)