/*********************************************************************************************
* 文件：main.c
* 作者：Meixin 2017.09.25
* 说明：可燃气体传感器实验 习题    
*       模拟家居燃气安全检测，当燃气浓度达到一定阈值时系统向PC打印危险信息1S打印一次，未超阈值时3S一次安全信息，并打印燃气浓度采集值
* 修改：2017.11.08 chennian 将led文件替换为通用版驱动文件
*       2018.01.02 zhoucj   修改为串口一
* 注释：
*********************************************************************************************/

#define COMBUSTIBLEGAS_MAX      1000

/*********************************************************************************************
* 头文件
*********************************************************************************************/
#include <ioCC2530.h>
#include <stdio.h>
#include <string.h>
#include "clock.h"
#include "delay.h"
#include "mp-4.h"
#include "led.h"
#include "uart1.h"

/*********************************************************************************************
* 名称：main()
* 功能：逻辑代码
* 参数：无
* 返回：无
* 修改：修改LED灯相关的注释
* 注释：
*********************************************************************************************/
void main(void)
{
  unsigned int combustiblegas = 0;                              //存储可燃气体浓度变量
  char tx_buff[64];
  unsigned char num = 0;
  xtal_init();                                                  //系统时钟初始化     
  led_init();                                                   //LED初始化
  combustiblegas_init();                                        //可燃气体传感器初始化
  uart1_init(0x00,0x00);                                        //串口初始化
  
  while(1)
  {
    combustiblegas = get_combustiblegas_data();                 //获取可燃气体含量数据
    sprintf(tx_buff,"combustiblegas:%d ppm \r\n",combustiblegas);    //添加字符串数据到串口发送缓存
    uart1_send_string(tx_buff);                                  //串口打印
    memset(tx_buff,0,64);                                       //清空串口发送缓存
    if(combustiblegas > COMBUSTIBLEGAS_MAX){                    //判断可燃气体含量是否大于最大值
      D2 = ~D2;                                                 //翻转D2状态
      D1 = ~D1;													//翻转D1状态
      uart1_send_string("dangerous! \r\n");                      //串口打印
    }
    else{
      D2 = OFF;                                                 //熄灭D2灯
      D1 = OFF;													//熄灭D1灯
      num++;                                                    
      if(num >= 3){
        num = 0;
        uart1_send_string("normal! \r\n");                       //串口打印
      }
    }
    delay_s(1);                                                 //延时1s
  }
}
