#ifndef HTTPSERVER_SOCKETTASK_H
#define HTTPSERVER_SOCKETTASK_H
//------------------------------------------------------------------------------------
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

#include "UartDebug.h"
//#include "httpserver-socket.h"
//------------------------------------------------------------------------------------
//!
//extern void MX_LWIP_Init(void);

//osThreadId HttpServerSocketHandle;

//void CreateHttpServerSocketTask(void);

void StartHttpServerTask(void const * argument);


//------------------------------------------------------------------------------------
#endif // HTTPSERVER_SOCKETTASK_H
