### HAL_Delay()

SysTick 타이머를 이용하여 ms 단위의 딜레이를 주는 함수.

SysTick이 1ms 마다 인터럽트를 발생시키고, `uwTick`이라는 전역변수를 +1씩 증가시킨다.

```c
//HAL_Delay 함수
__weak void HAL_Delay(uint32_t Delay)
{
  uint32_t tickstart = HAL_GetTick(); //****얘를 알아보자****//
  uint32_t wait = Delay;

  /* Add a freq to guarantee minimum wait */
  if (wait < HAL_MAX_DELAY)
  {
    wait += (uint32_t)(uwTickFreq);
  }

  while((HAL_GetTick() - tickstart) < wait)
  {
  }
}
```

```c
__weak uint32_t HAL_GetTick(void)
{
  return uwTick; //uwTick을 가져온다.
}
```

`uwTick`은 `HAL_IncTick`에서 +1 된다.
```c
__weak void HAL_IncTick(void)
{
  uwTick += uwTickFreq;
}
```

`HAL_IncTick`은 `stm32f4xx_it.c`에 존재하는 `SysTick_Handler`로 부터 불려진다.

```c
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}
```

### HAL_GetTick()
uwTick을 가져오는 애

```c
/*
  * @brief Provides a tick value in millisecond.
  * @note This function is declared as __weak to be overwritten in case of other 
  *       implementations in user file.
  * @retval tick value
  */
__weak uint32_t HAL_GetTick(void)
{
  return uwTick;
}
```