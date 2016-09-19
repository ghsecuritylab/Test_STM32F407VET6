#include "SdWorkerTask.h"

//------------------------------------------------------------------------------------
//!
void StartSdWorkerTask(void const * argument)
{    
    const char *testMessage="SdWorker";

    /*
    //##-0- Turn all LEDs off(red, green, orange and blue)
    HAL_GPIO_WritePin(GPIOG, (GPIO_PIN_10 | GPIO_PIN_6 | GPIO_PIN_7 |
    GPIO_PIN_12), GPIO_PIN_SET);
    //##-1- FatFS: Link the SD disk I/O driver ##########
    if(retSD == 0){
    // success: set the orange LED on
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_7, GPIO_PIN_RESET);
    //##-2- Register the file system object to the FatFs module ###
    if(f_mount(&SDFatFs, (TCHAR const*)SD_Path, 0) != FR_OK){
    // FatFs Initialization Error : set the red LED on
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_10, GPIO_PIN_RESET);
    while(1);
    } else {
    //##-3- Create a FAT file system (format) on the logical drive#
    // WARNING: Formatting the uSD card will delete all content on the device
    if(f_mkfs((TCHAR const*)SD_Path, 0, 0) != FR_OK){
    // FatFs Format Error : set the red LED on
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_10, GPIO_PIN_RESET);
    while(1);
    } else {
    //##-4- Create & Open a new text file object with write access#
    if(f_open(&MyFile, "Hello.txt", FA_CREATE_ALWAYS | FA_WRITE) !=
    FR_OK){
    // 'Hello.txt' file Open for write Error : set the red LED on
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_10, GPIO_PIN_RESET);
    while(1);
    } else {
    //##-5- Write data to the text file ####################
    res = f_write(&MyFile, wtext, sizeof(wtext), (void
    *)&byteswritten);
    if((byteswritten == 0) || (res != FR_OK)){
    // 'Hello.txt' file Write or EOF Error : set the red LED on
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_10, GPIO_PIN_RESET);
    while(1);
    } else {
    //##-6- Successful open/write : set the blue LED on
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_12, GPIO_PIN_RESET);
    f_close(&MyFile);
    //##-7- Open the text file object with read access #
    if(f_open(&MyFile, "Hello.txt", FA_READ) != FR_OK){
    // 'Hello.txt' file Open for read Error : set the red LED on
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_10, GPIO_PIN_RESET);
    while(1);
    } else {
    //##-8- Read data from the text file #########
    res = f_read(&MyFile, rtext, sizeof(wtext), &bytesread);
    if((strcmp(rtext,wtext)!=0)|| (res != FR_OK)){
    // 'Hello.txt' file Read or EOF Error : set the red LED on
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_10, GPIO_PIN_RESET);
    while(1);
    } else {
    // Successful read : set the green LED On
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);
    //##-9- Close the open text file ################
    f_close(&MyFile);
    }}}}}}}
    //##-10- Unlink the micro SD disk I/O driver #########
    FATFS_UnLinkDriver(SD_Path);
    */

    //const char *testMessage="SdWorkerTask";

    for(;;)
    {
        sendToLog(testMessage);

        osDelay(100);
    }
}
//------------------------------------------------------------------------------------
//!
