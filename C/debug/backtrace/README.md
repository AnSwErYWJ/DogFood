# Usage
## 编译:
```
$ make clean
$ make
```
## 显示函数名和行号
编译时需要加上`-g`
```
$ echo 0x123456 | addr2line -e bt -f
```
也可以直接打印，在编译时加上`-rdynamic`参数即可：
```
$ ./bt
```

# Tips
- 编译时不要做优化

# Reference
- [http://www.linuxidc.com/Linux/2012-11/73470.htm](http://www.linuxidc.com/Linux/2012-11/73470.htm)
- [http://www.linuxidc.com/Linux/2012-11/73470p2.htm](http://www.linuxidc.com/Linux/2012-11/73470p2.htm)
- [http://hutaow.com/blog/2013/10/15/dump-stack/](http://hutaow.com/blog/2013/10/15/dump-stack/)
