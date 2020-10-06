/*********************************************************************************************
* 文件：Infrared.h
* 作者：Lixm 2017.10.17
* 说明：可燃气体传感器驱动代码头文件  
* 修改：
* 注释：
*********************************************************************************************/

/*********************************************************************************************
* 宏条件编译
*********************************************************************************************/
#ifndef __MP_4_H__
#define __MP_4_H__

/*********************************************************************************************
* 头文件
*********************************************************************************************/
#include <ioCC2530.h>

/*********************************************************************************************
* 内部原型函数
*********************************************************************************************/
void combustiblegas_init(void);                          		//可燃气体传感器初始化
unsigned int get_combustiblegas_data(void);            			//获取可燃气体传感器状态

#endif /*__MP_4_H__*/

