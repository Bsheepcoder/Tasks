# **关于VS code如何下载并配置C语言**（windows）

### 0x01  下载VS code

**1.**[**VS code官网**](https://code.visualstudio.com/) 

[![rq9RVe.png](https://s3.ax1x.com/2020/12/29/rq9RVe.png)](https://imgchr.com/i/rq9RVe)

**2**.点击后无需操作，等待下载弹窗

**3**.下载后找到安装包，打开

[![rq9WUH.png](https://s3.ax1x.com/2020/12/29/rq9WUH.png)](https://imgchr.com/i/rq9WUH)

### 0x02  安装VS code

**1.**按照下图流程操作

[<img src="https://s3.ax1x.com/2020/12/29/rq9f5d.png" alt="rq9f5d.png" style="zoom:150%;" />](https://imgchr.com/i/rq9f5d)

[<img src="https://s3.ax1x.com/2020/12/29/rq94PA.png" alt="rq94PA.png" style="zoom: 150%;" />](https://imgchr.com/i/rq94PA)

[<img src="https://s3.ax1x.com/2020/12/29/rq958I.png" alt="rq958I.png" style="zoom:150%;" />](https://imgchr.com/i/rq958I)

[<img src="https://s3.ax1x.com/2020/12/29/rq9oxP.png" alt="rq9oxP.png" style="zoom:150%;" />](https://imgchr.com/i/rq9oxP)

**2**.本人已经装过了，所以没有**自定义安装地址**

### 0x03  下载及安装MinGW

​    [**MinGW官网**]([**https://sourceforge.net/projects/mingw-w64/files/mingw-w64/mingw-w64-release/**](https://sourceforge.net/projects/mingw-w64/files/mingw-w64/mingw-w64-release/))    进入后一直翻，找到下图的位置

[![rq96KK.jpg](https://s3.ax1x.com/2020/12/29/rq96KK.jpg)](https://imgchr.com/i/rq96KK)

​    [**百度网盘**]([**https://pan.baidu.com/s/1g3BEDOh65r58OhwM7eMgeQ**](https://pan.baidu.com/s/1g3BEDOh65r58OhwM7eMgeQ))    **提取码：e42m**

​    下载解压即可，并找到并进入**bin文件夹**，记住路径

### 0x04  配置环境变量

**1.** 设置中找到 **编辑系统环境变量** ，或者如下图找到并单击

[<img src="https://s3.ax1x.com/2020/12/29/rq97Kf.png" alt="rq97Kf.png" style="zoom:150%;" />](https://imgchr.com/i/rq97Kf)

**2**.如下图提示依次操作

[![rq9LVg.png](https://s3.ax1x.com/2020/12/29/rq9LVg.png)](https://imgchr.com/i/rq9LVg)

[<img src="https://s3.ax1x.com/2020/12/29/rq9X5j.png" alt="rq9X5j.png" style="zoom:150%;" />](https://imgchr.com/i/rq9X5j)

**3**.找到Path变量并点击，再点击编辑

[<img src="https://s3.ax1x.com/2020/12/29/rq9vPs.png" alt="rq9vPs.png" style="zoom:150%;" />](https://imgchr.com/i/rq9vPs)

**4**.复制之前解压的mingw到bin的链接

[![rbloOe.jpg](https://s3.ax1x.com/2020/12/29/rbloOe.jpg)](https://imgchr.com/i/rbloOe)

[![rbl7eH.jpg](https://s3.ax1x.com/2020/12/29/rbl7eH.jpg)](https://imgchr.com/i/rbl7eH)

**5**.接下来一直点确定，直到窗口关闭

**6**.**点击 输入cmd 点击打开cmd，也可用快捷键win + R 输入cmd 打开**

<img src="https://s3.ax1x.com/2020/12/29/rq97Kf.png" alt="rq97Kf.png" style="zoom:150%;" />

[<img src="https://s3.ax1x.com/2020/12/29/rq9xGn.png" alt="rq9xGn.png" style="zoom:150%;" />](https://imgchr.com/i/rq9xGn)

**5**.测试计算机能否找到 gcc，有下方的输出表明配置正确，如果没有说明之前的配置有误，再去查看一下变量的地址、mingw的地址等。测试正确关闭即可。

[<img src="https://s3.ax1x.com/2020/12/29/rq9z2q.png" alt="rq9z2q.png" style="zoom:150%;" />](https://imgchr.com/i/rq9z2q)

### 0x05  设置VS Code

**1.** 打开vs code

[![rqC9MV.png](https://s3.ax1x.com/2020/12/29/rqC9MV.png)](https://imgchr.com/i/rqC9MV)



**2**.**输入chin，点击后，点安装。之后重启 vscode 你会发现界面变为中文**

[![rqCCrT.png](https://s3.ax1x.com/2020/12/29/rqCCrT.png)](https://imgchr.com/i/rqCCrT)

 **再次搜索C/C++，安装** 

[![rqC1de.png](https://s3.ax1x.com/2020/12/29/rqC1de.png)](https://imgchr.com/i/rqC1de)

 **再次搜索code runner，安装** 

[![rqCGid.png](https://s3.ax1x.com/2020/12/29/rqCGid.png)](https://imgchr.com/i/rqCGid)

**3**.**新建一个文件夹，并新建文件**

[<img src="https://s3.ax1x.com/2020/12/29/rqCJJA.png" alt="rqCJJA.png" style="zoom:150%;" />](https://imgchr.com/i/rqCJJA)

[<img src="https://s3.ax1x.com/2020/12/29/rqCUQP.png" alt="rqCUQP.png" style="zoom:150%;" />](https://imgchr.com/i/rqCUQP)

**4**.**写一段测试代码，(复制下方即可)**

```c
#include<stdio.h>
int main(){
    
    printf("hello world");
      
    return 0;
}
```

**5**.**运行在下方输出，输出正确即无误**

[![rqCdL8.png](https://s3.ax1x.com/2020/12/29/rqCdL8.png)](https://imgchr.com/i/rqCdL8)

### 0x06  重要问题解决

**1.Vscode一开始只能在输出看结果，我们要调整到终端看结果这样就可以输入了**

[![rqCBdg.png](https://s3.ax1x.com/2020/12/29/rqCBdg.png)](https://imgchr.com/i/rqCBdg)

**点击，然后下滑，直到找到下图这一项并点击**

[![rqCDoQ.png](https://s3.ax1x.com/2020/12/29/rqCDoQ.png)](https://imgchr.com/i/rqCDoQ)

**2.先复制下方代码，然后粘贴到{ }内的合适位置**

```c
"code-runner.runInTerminal": true,
```

**（这里容易出错，因为可能你设置过的话内容会和下图不同，多试几次不同位置。）**

[![rqCsij.png](https://s3.ax1x.com/2020/12/29/rqCsij.png)](https://imgchr.com/i/rqCsij)

**粘贴后关闭即可，下面运行刚才的代码，会发现程序在终端输出。**

**3.再写一个可以输入输出的代码如上法，测试一下**

```c
#include<stdio.h>
int main()
{
    int d, h, m;
    scanf("%d %d %d", &d, &h, &m);
    m = d * 24 * 60 + h * 60 + m;
    printf("这是中文%d",m);
    return 0;
}
```

**你会发现中文部分输出的是乱码**

[<img src="https://s3.ax1x.com/2020/12/29/rqCyJs.png" alt="rqCyJs.png" style="zoom:150%;" />](https://imgchr.com/i/rqCyJs)

**点击UTF-8**

[![rqCczq.png](https://s3.ax1x.com/2020/12/29/rqCczq.png)](https://imgchr.com/i/rqCczq)

找到GBK （中文编码）

[![rqC2Q0.png](https://s3.ax1x.com/2020/12/29/rqC2Q0.png)](https://imgchr.com/i/rqC2Q0)

**下滑找到点击**

**再次运行**

[![rqCWLT.png](https://s3.ax1x.com/2020/12/29/rqCWLT.png)](https://imgchr.com/i/rqCWLT)

**4.设置完毕，但是你下次打开此文件，代码中的中文还是会显示乱码。**

[<img src="https://s3.ax1x.com/2020/12/29/rqC4wF.png" alt="rqC4wF.png" style="zoom:150%;" />](https://imgchr.com/i/rqC4wF)

**将默认设置为GBK ，这样下次打开就是默认中文编码。**

**5.另外按 ctrl + shift + p 后，输入tasks，找到tasks.json文件**

**在下图位置，加划线那行代码，并且上一行尾要加逗号！！**

[![rqC7WR.jpg](https://s3.ax1x.com/2020/12/29/rqC7WR.jpg)](https://imgchr.com/i/rqC7WR)

```json
"-fexec-charset=GBK" //解决中文乱码 
```

**修改代码后记得ctrl + S 保存后，重启即可。**



## 注：

1.在调用函数库的时候可能会出现编辑器找不到的情况，需要尽可能多的定义

```c
#include <stdlib.h>
#include<stdio.h>
#include<time.h> 
```

例如在使用 time.h 时，需先写出stdlib.h

2.另外对编译的语法也有不同的要求，修改语法可以排除一些编译报错。
