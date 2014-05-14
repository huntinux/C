Linux 动态链接库
===============
```
Linux下动态链接库一般是以.so结尾的文件。
这里学习一下怎么创建和使用动态链接库
```

生成动态链接库
--------------
```sh
gcc  test_a.c test_b.c -o libtest.so -fPIC -shared
注释： 
-fPIC : 生成位置无关代码 Position Independent Code
-shared : 生成动态链接库
```

使用动态链接库
--------------
```sh
gcc test.c -L. -ltest -o test
注释：
-L. : 表示在当前目录下搜寻库文件
-ltest: 链接 libtest.so
```

将动态链接库放入系统搜索路径
---------------------------
```sh
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
注释： 
这里把当前路径加入到系统搜索路径中
```

察看一个程序依赖哪些动态链接库
------------------------------
`ldd program`


