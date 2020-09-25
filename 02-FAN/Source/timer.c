/*********************************************************************************************
* �ļ���timer.c
* ���ߣ�Meixin 2017.09.15
* ˵������ʱ����������    
* �޸ģ�
* ע�ͣ�
*********************************************************************************************/

/*********************************************************************************************
* ͷ�ļ�
*********************************************************************************************/
#include "timer.h"

/*********************************************************************************************
* ���ƣ�xtal_init()
* ���ܣ�CC2530ʱ�ӳ�ʼ��
* ��������
* ���أ���
* �޸ģ�
* ע�ͣ�
*********************************************************************************************/
void xtal_init(void)
{
  CLKCONCMD &= ~0x40;                                           //ѡ��32MHz���ⲿ����
  while(CLKCONSTA & 0x40);                                      //���������������ȶ�
  CLKCONCMD &= ~0x07;                                           //ѡ��32MHϵͳʱ��
  CLKCONCMD &= ~0x38;                                           //ѡ��32MH��ʱ��ʱ��
}

/*********************************************************************************************
* ���ƣ�time1_init()
* ���ܣ���ʱ��1��ʼ��
* ��������
* ���أ���
* �޸ģ�
* ע�ͣ�
*********************************************************************************************/
void time1_init(void)
{
  T1CTL |= 0x06;                                                //8��Ƶ��ģģʽ����0������T1CC0
  T1CC0L = 0x40;                                                //��ʱ��1ͨ�� 0����/�Ƚ�ֵ��λ 
  T1CC0H = 0x9C;                                                //��ʱ��1ͨ�� 0����/�Ƚ�ֵ��λ   ����10ms��һ���ж�
  T1CCTL0 |= 0x44;                                              //��ʱ��1 ͨ0 ����/�ȽϿ���
  T1IE = 1;                                                     //�趨��ʱ��1�ж�ʹ��
  EA = 1;                                                       //�趨���ж�ʹ�� 
}