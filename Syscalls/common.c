﻿#include "common.h"
//------------------------------------------------------------------------------------
/*
void vPrintString( const portCHAR *pcString )
{
  // Запись строки в stdout, с использованием критической секции как
  // грубого метода взаимного исключения.
  taskENTER_CRITICAL();
  {
     printf( "%s", pcString );
     fflush( stdout );
  }
  taskEXIT_CRITICAL();

  // Разрешаем нажатием любой кнопки остановить приложение. Обычно
  // приложение использует для этого специальную комбинацию клавиш (типа
  // Alt+X), что также должно защитить доступ к клавиатурному вводу.
  if( kbhit() )
  {
     vTaskEndScheduler();
  }
}
*/
//------------------------------------------------------------------------------------
