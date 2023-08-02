# BTT-Pi wiringPi Demo

### 简介

参考OrangePi-wiringOP为BTT-Pi移植的wiringPi，在BTT-Pi官方镜像上测试通过

[BTT-Pi官方文档及镜像]: https://github.com/bigtreetech/BTT-Pi

### 安装

下载此仓库并解压BTT-wiringPi.zip

cd到BTT-wiringPi

执行

```
./build clean
./build
```

当执行./build之后，出现如下内容

```
........
  25. orangepi800
  26. orangepizero2
  27. orangepizero2-lts
  28. orangepizero2-b
  29. orangepizero3
  30. orangepir1plus-lts
  31. orangepir1plus
Choice:
```

输入  26  并回车继续（即选择orangepizero2）

如果build 文件没有执行权限，需要执行

```
chmod +x ./build
```



### 参考

！！！！！！本程序更改自以下仓库！！！！！！

[OrangePi-wiringOP]: https://github.com/orangepi-xunlong/wiringOP

