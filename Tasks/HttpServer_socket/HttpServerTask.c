#include "HttpServerTask.h"

////------------------------------------------------------------------------------------
////!
//void CreateHttpServerSocketTask(void)
//{
//    /* definition and creation of StartHttpServerSocketTask */
//    osThreadDef(HttpServerSocketTask, StartHttpServerSocketTask, osPriorityLow, 0, 128);
//    HttpServerSocketHandle = osThreadCreate(osThread(HttpServerSocketTask), NULL);
//}
//------------------------------------------------------------------------------------
//!
void StartHttpServerTask(void const * argument)
{
    (void) argument;

    const char *testMessage="HttpServer";

    http_server_socket_init();

    for(;;)
    {
        sendToLog(testMessage);

        osDelay(200);
    }

}
