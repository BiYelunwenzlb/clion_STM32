#include"sys.h"

int main(void)
{
	u32 t=0;
    u8 len;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	uart_init(115200);
	delay_init(84);
	LED_Init();
  while(1){
      if(USART_RX_STA&0x8000)
      {
          len=USART_RX_STA&0x3fff;//得到此次接收到的数据长度
          printf("\r\n您发送的消息为:\r\n");
          for(t=0;t<len;t++)
          {
              USART_SendData(USART1, USART_RX_BUF[t]);         //向串口1发送数据
              while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束
          }
          printf("\r\n\r\n");//插入换行
          USART_RX_STA=0;
      }
        printf("%s\r\n",USART_RX_BUF);
        PFout(9)=!PFout(9);
        PFout(10)=!PFout(10);
		delay_ms(5000);
		t++;
        printf("请输入你的数字\r\n");
        //scanf("%d",&t);
	}
}

