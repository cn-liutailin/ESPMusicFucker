# 如何在学校安全地对爱听歌的同学实施制裁？

> 你需要 [ESPMusicFucker](https://github.com/cn-liutailin/ESPMusicFucker) ！
>

## 项目初衷

在学校，总有一些人喜欢听歌的 “高素质人才” 使用教室内的计算机，对班内同学进行噪声攻击。

> 噪音的规范用法是噪声，从生理学观点来看，凡是干扰人们休息、学习和工作以及对人们所要听的声音产生干扰的声音，即不需要的声音，统称为噪声。当噪声对人及周围环境造成不良影响时，就形成噪声污染。——摘自《百度百科》

但是，大多数同学对此是敢怒不敢言，无法使用舆论压力遏制他们，使得一些 “高素质人才” 得以继续为非作歹。对此，我们 “Keyboard Man” 绝不能袖手旁观，因此我们制作了正义的制裁武器 [ESPMusicFucker](https://github.com/cn-liutailin/ESPMusicFucker) ！

## 为什么不是……？

读者们看到这里可能会想，为什么不直接将计算机关闭？或者用手机对其进行远程控制。

第一，这么做就太不 geek 了。

第二，如果你直接将计算机关闭，你可能会被一些别有用心的人锁定，并被实施制裁和打击。

第三，如果你使用手机进行远程控制，你可能会违反一些 ~~监狱~~ 学校的《行为规范》，被发现后将会造成无法挽回的后果。

## 它的好处

### 机动性

由于ESP8266非常轻便，可迅速连接充电宝并按下按钮进行制裁。机动性对于实施制裁是很重要的，要知道在第二次世界大战中，法军因不重视机动作战学说，造成了战略上的严重失误，被纳粹德国的闪电战击溃。

### 便携性

400孔的面包板仅仅只有一张银行卡大小，便于携带。

### 性价比

一套设备的价格不超过￥20，仅仅相当于一杯奶茶的钱。

## 如何开始？

> 本项目需要配合 [FuckLCYBatch](https://github.com/Creeper23456/FuckLCYBatch) 来使用。
>
> 你应该自行阅读该项目文档。

### 购买必要的物品

高端的工具往往只需要简单的采购，以下为推荐购物单。

- ESP8266 NodeMCU 开发板
- 面包板 400孔
- 面包板线*3
- 微动开关 4角立式

### 安装必要的工具

- [Arduino IDE](https://www.arduino.cc/en/software)
- 串口驱动程序（根据购买开发板的串口芯片类型自行选择）。

### 接线

接线方式请参考 [接线原理图](https://github.com/cn-liutailin/ESPMusicFucker/blob/main/EspMusicFucker.png) 。

### 烧录

1. 打开 `Arduino IDE` ，选择 `文件` — `首选项` — `附加开发板管理器 ` ，填入`http://arduino.esp8266.com/stable/package_esp8266com_index.json`
2. 打开 `Arduino IDE` ，选择 `工具` — `开发板` — `开发板管理器 ` ，搜索并安装 `ESP8266` 。
3. 打开 `Arduino IDE` ，选择 `工具` — `开发板` — `开发板管理器 ` ，选择 `ESP8266` ，记得修改 `端口号` 。
4. 打开 `Arduino IDE` ，选择 `工具` — `管理库` — `库管理器 ` ，搜索并安装 `OneButton` 和 `WiFiManager`  。
5. 打开 GitHub ，下载 [esp_music_fucker](https://github.com/cn-liutailin/ESPMusicFucker/tree/main/esp_music_fucker) 文件夹，打开 `esp_music_fucker.ino` 文件。
6. 修改配置，点击 `上传` 。

## 自定义配置

> 根据注释自行修改 `esp_music_fucker.ino` 文件

```c
#include <HttpGet.h>
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>      //https://github.com/tzapu/WiFiManager
#include <OneButton.h>        //https://github.com/mathertel/OneButton
//引入库

OneButton button(D4, true);
//添加按钮

void click() {
//设定按钮单击函数
  gethttp_API("http://api.klpnb.cn/index.php?enable",80);
  //执行HttpGet
  Serial.println("单击");
  //串口输出
}

void doubleclick() {
//设定按钮双击函数
  gethttp_API("http://api.klpnb.cn/index.php?disable",80);
  //执行HttpGet
  Serial.println("双击");
  //串口输出
}

void setup() {
  Serial.begin(115200);
  //启动波特率115200

  WiFiManager wifiManager;
  //启动WiFi管理器

  //设置自定义IP
  wifiManager.setAPStaticIPConfig(IPAddress(6,6,6,6), IPAddress(6,6,6,6), IPAddress(255,255,255,0));

  wifiManager.autoConnect("EspMusicFucker");
  //设置自定义AP
    
  Serial.println("connected...yeey :)");
  //连接WIFI成功

  button.attachClick(click);
  //定义按钮单击

  button.attachDoubleClick(doubleclick);
  //定义按钮双击
}

void loop() {
  button.tick();
  //保持按钮函数运行
} 
```

## 结束

很感谢你能看到这里，希望本教程对你有用。
