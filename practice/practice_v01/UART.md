### HAL_UART_RxCpltCallback()

UART Rx를 수신할 때마다 Interrupt를 주기 위해 `stm32f4xx_hal_uart.h`에 있는 아래 함수를 정의한다.

```c
__weak void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_RxCpltCallback could be implemented in the user file
   */
}
```


### HAL_UART_Receive_IT()

1byte char를 UART로 수신하도록 해주는 함수이다. (일회성)  
계속 수신받으려면 계속 호출해주어야함  


```c
/**
  * @brief  Receives an amount of data in non blocking mode.
  * @note   When UART parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         the received data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 available through pData.
  * @param  huart Pointer to a UART_HandleTypeDef structure that contains
  *               the configuration information for the specified UART module.
  * @param  pData Pointer to data buffer (u8 or u16 data elements).
  * @param  Size  Amount of data elements (u8 or u16) to be received.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size)
{
  /* Check that a Rx process is not already ongoing */
  if (huart->RxState == HAL_UART_STATE_READY)
  {
    if ((pData == NULL) || (Size == 0U))
    {
      return HAL_ERROR;
    }

    /* Set Reception type to Standard reception */
    huart->ReceptionType = HAL_UART_RECEPTION_STANDARD;

    return (UART_Start_Receive_IT(huart, pData, Size));
  }
  else
  {
    return HAL_BUSY;
  }
}
```

### HAL_UART_Transmit

UART Transmit 관련함수이다.
<details>
<summary> 정의 </summary>

```c
/**
  * @brief  Sends an amount of data in blocking mode.
  * @note   When UART parity is not enabled (PCE = 0), and Word Length is configured to 9 bits (M1-M0 = 01),
  *         the sent data is handled as a set of u16. In this case, Size must indicate the number
  *         of u16 provided through pData.
  * @param  huart Pointer to a UART_HandleTypeDef structure that contains
  *               the configuration information for the specified UART module.
  * @param  pData Pointer to data buffer (u8 or u16 data elements).
  * @param  Size  Amount of data elements (u8 or u16) to be sent
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  const uint8_t  *pdata8bits;
  const uint16_t *pdata16bits;
  uint32_t tickstart = 0U;
...
}
```

</details>

`uint8_t *pdata`는 바이트 단위 배열 주소를 요구한다.  

즉, `pdata`는 uint8_t type의 배열 주소여야한다.  


따라서 아래와 같은 예시에서,

```c
void Presenter_DispMonitorTimeWatch(watch_t watchData)
{
	char str[50];
	sprintf(str,"Time Watch : %02d:%02d:%02d.%03d\n", watchData.hour, watchData.min, watchData.sec, watchData.msec);
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 1000);
}
```

`str`은 이미 그 자체로 주소이지만(char 배열이지만), 바이트 단위의 배열주소여야 하기에  
`(uint8_t *)str`로 명시적 형변환(`casting`)을 해준다.

또한   `* @param  Size  Amount of data elements (u8 or u16) to be sent` 이므로 
`strlen(str)` 로 배열의 크기를 전달한다.

