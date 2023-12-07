# 使用cmake开发iar 8051工程

## 配置步骤

1. 新建一个基于cmake的空项目
2. 添加自定义工具链, ![img.png](img/img.png)
3. 配置cmake编译选项: `-G "Ninja Multi-Config" --toolchain iar-toolchain.cmake` ![img_1.png](img/img_1.png)
4. 修改iar-toolchain.cmake文件中的iar安装路径, 例如`set(TOOLKIT "D:/Program Files (x86)/iar1030/8051")`
5. 添加新的your_project_dir文件夹, 在根目录的CMakeLists.txt中添加`add_subdirectory(your_project_dir)`
6. 在your_project_dir文件夹中添加CMakeLists.txt, 参考hello-world的cmake文件
7. 刷新根目录的cmake, 开始编译即可

# 参考文档

[官方iar cmake教程](https://github.com/IARSystems/cmake-tutorial/blob/master/README.md)