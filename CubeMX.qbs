import qbs
//import Stm32Product
import Stm32Application
//import Stm32Library
import qbs.FileInfo
import qbs.ModUtils

Stm32Application {
    type: "application"
    destinationDirectory: "./bin"
    buildDirectory: "./build"

    // Объявления defines для компилятора
    cpp.defines: [
        "STM32F407xx",
        "USE_HAL_DRIVER",
        //---------------------------------------
        //"STM32F4XX",
        //"STM32F40_41xxx",
        //---------------------------------------
        //"HSI_VALUE=168000000",
        //"HSE_VALUE=168000000",
        //---------------------------------------
        // Для БПФ
        "ARM_MATH_CM4",
        //---------------------------------------
        // Для FatFs
        "SDRAM_DEVICE_ADDR=0",
        "SDRAM_DEVICE_SIZE=1000 ",
        //---------------------------------------
        // Для подключения математического сопроцессора (use FPU)
//        "__VFP_FP__",
//        "__FPU_PRESENT=1U",
//        "__FPU_PRESENT=1",
//        "__TARGET_FPU_VFP=1",
        "__FPU_PRESENT = 1U",
//        "__FPU_USED = 1",
        //---------------------------------------
        // В CubeMX включается в проекте
        //"USE_FULL_ASSERT=1",
        //---------------------------------------
        // https://sites.google.com/site/stm32discovery/open-source-development-with-the-stm32-discovery/getting-newlib-to-work-with-stm32-and-code-sourcery-lite-eabi
        // для отладки
        "STDOUT_USART=1",
        "STDERR_USART=1",
        "STDIN_USART=1",
        //---------------------------------------
        // Для lwIP socket.h
        /** LWIP_TIMEVAL_PRIVATE: if you want to use the struct timeval provided
         * by your system, set this to 0 and include <sys/time.h> in cc.h */
        "LWIP_TIMEVAL_PRIVATE=0",
        // Для LWIP_HTTPD_CUSTOM_FILES
        //"FS_ROOT=адрес памяти   const struct fsdata_file *f; "
    ]

    cpp.includePaths: [
        //-----------------------------------------------------------------
        "./CubeMX/Inc/",
        //-----------------------------------------------------------------
        //"./CubeMX/Inc/USB_CustomHID",
        //"./CubeMX/Inc/LwIP",
        //-----------------------------------------------------------------
        "./CubeMX/Drivers/CMSIS/Device/ST/STM32F4xx/Include/",
        "./CubeMX/Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates",
        "./CubeMX/Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc",
        //-----------------------------------------------------------------
        "./CubeMX/Drivers/CMSIS/DSP_Lib/Source/",
        "./CubeMX/Drivers/CMSIS/DSP_Lib/Source/BasicMathFunctions/",
        "./CubeMX/Drivers/CMSIS/DSP_Lib/Source/CommonTables/",
        "./CubeMX/Drivers/CMSIS/DSP_Lib/Source/ComplexMathFunctions/",
        "./CubeMX/Drivers/CMSIS/DSP_Lib/Source/ControllerFunctions/",
        "./CubeMX/Drivers/CMSIS/DSP_Lib/Source/FastMathFunctions/",
        "./CubeMX/Drivers/CMSIS/DSP_Lib/Source/FilteringFunctions/",
        "./CubeMX/Drivers/CMSIS/DSP_Lib/Source/MatrixFunctions/",
        "./CubeMX/Drivers/CMSIS/DSP_Lib/Source/StatisticsFunctions/",
        "./CubeMX/Drivers/CMSIS/DSP_Lib/Source/SupportFunctions/",
        "./CubeMX/Drivers/CMSIS/DSP_Lib/Source/TransformFunctions/",
        //-----------------------------------------------------------------
        "./CubeMX/Drivers/CMSIS/Include/",
        //-----------------------------------------------------------------
        "./CubeMX/Drivers/STM32F4xx_HAL_Driver/Inc/",
        "./CubeMX/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy/",
        "./CubeMX/Drivers/STM32F4xx_HAL_Driver/Src/",
        //-----------------------------------------------------------------
//        "./CubeMX/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc/",
//        "./CubeMX/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Src/",
        "./CubeMX/Middlewares/ST/STM32_USB_Device_Library/Class/CustomHID/Inc/",
        "./CubeMX/Middlewares/ST/STM32_USB_Device_Library/Class/CustomHID/Src/",
        //-----------------------------------------------------------------
        "./CubeMX/Middlewares/ST/STM32_USB_Device_Library/Core/Inc/",
        "./CubeMX/Middlewares/ST/STM32_USB_Device_Library/Core/Src/",
        //-----------------------------------------------------------------
        "./CubeMX/Middlewares/ST/STM32_USB_Host_Library/Core/Inc/",
        "./CubeMX/Middlewares/ST/STM32_USB_Host_Library/Core/Src/",
        //-----------------------------------------------------------------
        "./CubeMX/Middlewares/ST/STM32_USB_Host_Library/Class/HID/Inc/",
        "./CubeMX/Middlewares/ST/STM32_USB_Host_Library/Class/HID/Src/",
        //-----------------------------------------------------------------
        "./CubeMX/Middlewares/Third_Party/FatFs/src/",
        "./CubeMX/Middlewares/Third_Party/FatFs/src/drivers",
        "./CubeMX/Middlewares/Third_Party/FatFs/src/option",
        //-----------------------------------------------------------------
        "./CubeMX/Middlewares/Third_Party/FreeRTOS/Source/include/",
        "./CubeMX/Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/",
        "./CubeMX/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/",
        "./CubeMX/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/",
        //-----------------------------------------------------------------
        "./CubeMX/Middlewares/Third_Party/LwIP/src/",
        "./CubeMX/Middlewares/Third_Party/LwIP/src/api/",
        "./CubeMX/Middlewares/Third_Party/LwIP/src/core/",
        "./CubeMX/Middlewares/Third_Party/LwIP/src/core/ipv4/",
        "./CubeMX/Middlewares/Third_Party/LwIP/src/core/snmp/",
        "./CubeMX/Middlewares/Third_Party/LwIP/src/include/",
        "./CubeMX/Middlewares/Third_Party/LwIP/src/include/ipv4/",
        "./CubeMX/Middlewares/Third_Party/LwIP/src/include/ipv4/lwip/",
        "./CubeMX/Middlewares/Third_Party/LwIP/src/include/lwip/",
        "./CubeMX/Middlewares/Third_Party/LwIP/src/include/netif/",
        "./CubeMX/Middlewares/Third_Party/LwIP/src/include/posix/",
        "./CubeMX/Middlewares/Third_Party/LwIP/src/include/posix/sys/",
        "./CubeMX/Middlewares/Third_Party/LwIP/src/netif/",
        "./CubeMX/Middlewares/Third_Party/LwIP/src/netif/ppp/",
        "./CubeMX/Middlewares/Third_Party/LwIP/system/",
        "./CubeMX/Middlewares/Third_Party/LwIP/system/arch/",
        "./CubeMX/Middlewares/Third_Party/LwIP/system/OS/",
        //-----------------------------------------------------------------
        "./CubeMX/Middlewares/Third_Party/LwIP/src/include/lwip/apps/",
        "./CubeMX/Middlewares/Third_Party/LwIP/src/apps/httpd/",
        //-----------------------------------------------------------------
        "./Syscalls/",
        //-----------------------------------------------------------------
        "./Tasks/",
        "./Tasks/FsData_custom/",
        "./Tasks/HttpServer_socket/",
        "./Tasks/Keyboard/",
        "./Tasks/LedIndicator/",
        "./Tasks/UartDebug/",
        //-----------------------------------------------------------------
        "./Tasks/USART_log/",
        "./Tasks/USB_DEVICE/",
        "./Tasks/ADC_BPF_analysis/",
        "./Tasks/UdpBroadcastServer/",
        "./Tasks/AdcTestOverUdp/",
        "./Tasks/FftTestOverUdp/",
        "./Tasks/Test_JSON/",
        //-----------------------------------------------------------------
        "./ExtLib/cJSON/",
        //-----------------------------------------------------------------
        "./ExtLib/jsmn/",
    ]

    //==========================================================================================
    // Варианты подмены системных функций _sbrk, _write, _close, _fstat, _isatty, _lseek, _read
    // Обычно реализованы в libc.a:
    // https://sites.google.com/site/stm32discovery/open-source-development-with-the-stm32-discovery/getting-newlib-to-work-with-stm32-and-code-sourcery-lite-eabi
    // для отладки задать номер UART порта для вывода
    // "STDOUT_USART=1",
    // "STDERR_USART=1",
    // "STDIN_USART=1",
    Group {
        name: "Syscalls"
        prefix: "./syscalls"
        files: [
            "/**",
            //"/newlib_stubs.c",
        ]

        // Исключить файлы из группы
        excludeFiles: [
            "/Temp/**",
        ]
    }

    //==========================================================================================
    Group {
        name: "CMSIS"

        prefix: "./CubeMX/Drivers/CMSIS"
        files: [
            "/Include/**",
            "/Device/ST/STM32F4xx/Include/**",
            //"/Device/ST/STM32F4xx/Include/stm32f4xx.h",
            //"/Device/ST/STM32F4xx/Include/stm32f407xx.h",
            //"/Device/ST/STM32F4xx/Include/system_stm32f4xx.h",
            "/Device/ST/STM32F4xx/Source/Templates/system_stm32f4xx.c",
            "/Device/ST/STM32F4xx/Source/Templates/gcc/startup_stm32f407xx.s",
//            "/Include/arm_common_tables.h",
//            "/Include/arm_const_structs.h",
//            "/Include/arm_math.h",
//            "/Include/core_cm4.h",
//            "/Include/core_cmFunc.h",
//            "/Include/core_cmInstr.h",
//            "/Include/core_cmSimd.h",
//
//            "/Include/cmsis_armcc.h",
//            "/Include/cmsis_gcc.h",
        ]

        // Исключить файлы из группы
        excludeFiles: [
            //"/CMSIS/RTOS/Template/cmsis_os.h",
        ]
    }

    //==========================================================================================

    Group {
        name: "CMSIS_DSP_Lib"

        prefix: "./CubeMX/Drivers/CMSIS/DSP_Lib/Source/"
        files: [
            "/**",
        ]

        // Исключить файлы из группы
        excludeFiles: [
            //"/CMSIS/RTOS/Template/cmsis_os.h",
        ]
    }

    //==========================================================================================

    Group {
        name: "STM32F4xx_HAL_Driver"
        prefix: "./CubeMX/Drivers/STM32F4xx_HAL_Driver"
        files: [
            "/Inc/**",
            "/Src/**",
//            "/Inc/Legacy/**",
//            "/Src/",
//            "/Src/",
//            "/Src/",
        ]

        // Исключить файлы из группы
        excludeFiles: [
            "/Src/stm32f4xx_hal_conf_template.h",
            "/Src/stm32f4xx_hal_msp_template.c",
            "/Src/stm32f4xx_hal_timebase_rtc_alarm_template.c",
            "/Src/stm32f4xx_hal_timebase_rtc_wakeup_template.c",
            "/Src/stm32f4xx_hal_timebase_tim_template.c",
        ]
    }

    //==========================================================================================
    Group {
        name: "FreeRTOS"
        prefix: "./CubeMX/Middlewares/Third_Party/FreeRTOS"
        files: [
            "/Source/croutine.c",
            "/Source/event_groups.c",
            "/Source/list.c",
            "/Source/queue.c",
            "/Source/tasks.c",
            "/Source/timers.c",
            //-------------------------------------
            "/Source/CMSIS_RTOS/**",
            "/Source/include/**",
            "/Source/portable/GCC/ARM_CM4F/**",
            "/Source/portable/MemMang/**",
            //-------------------------------------
            //"/Inc/FreeRTOSConfig.h",
            //-------------------------------------
        ]

        // Исключить файлы из группы
        excludeFiles: [
            "/Source/include/FreeRTOSConfig_template.h",
            //-------------------------------------
            // НЕ ЗАБЫТЬ ПОМЕНЯТЬ!
            // Веб сервер работает только на heap_3
            "/Source/portable/MemMang/heap_1.c",
            "/Source/portable/MemMang/heap_2.c",
            //"/Source/portable/MemMang/heap_3.c",
            "/Source/portable/MemMang/heap_4.c",
            "/Source/portable/MemMang/heap_5.c",
        ]
    }

    //==========================================================================================

    Group {
        name: "FatFs"
        prefix: "./CubeMX/Middlewares/Third_Party/FatFs/src/"
        files: [
            "/diskio.c",
            "/diskio.h",
            "/ff.c",
            "/ff.h",
            "/ff_gen_drv.c",
            "/ff_gen_drv.h",
            "/ffconf_template.h",
            "/integer.h",
            "/drivers/**",
            "/option/**",
        ]

        // Исключить файлы из группы
        excludeFiles: [
            "/drivers/sram_diskio.c",
            "/drivers/sram_diskio.h",
            "/drivers/usbh_diskio.c",
            "/drivers/usbh_diskio.h",
            "/option/ccsbcs.c",
            "/option/cc932.c",
            "/option/cc936.c",
            "/option/cc949.c",
            "/option/cc950.c",
            "/option/unicode.c",
        ]
    }

    //==========================================================================================

    Group {
        name: "LwIP"
        prefix: "./CubeMX/Middlewares/Third_Party/LwIP"
        files: [
            "/**",
        ]

        // Исключить файлы из группы
        excludeFiles: [
            // fsdata_custom.c
            // не подключать, чтоб не было переопределения
            "/src/apps/httpd/fsdata.c",
            //-------------------------------------
            //"/src/apps/httpd/fs.c",
        ]
    }

    //==========================================================================================
    /*
    Group {
        name: "cJSON"
        prefix: "./ExtLib/cJSON"
        files: [
            "/**",
        ]

        // Исключить файлы из группы
        excludeFiles: [
            "/tests/**",
            "/test.c",
        ]
    }
    */
    //==========================================================================================
    /*
    // https://bitbucket.org/zserge/jsmn/src
    Group {
        name: "jsmn"
        prefix: "./ExtLib/jsmn/"
        files: [
            "/**",
        ]

        // Исключить файлы из группы
        excludeFiles: [
            "/example/**",
            "/jsmn_test.c",
        ]
    }
    */
    //==========================================================================================
    /*
    Group {
        name: "Test_JSON"
        prefix: "./Tasks/Test_JSON"
        files: [
            "/**",
        ]

        // Исключить файлы из группы
        excludeFiles: [

        ]
    }
    */
    //==========================================================================================
    Group {
        name: "sources"
        prefix: "./CubeMX"
        files: [
            "/Inc/**",
            "/Src/**",            
        ]

        // Исключить файлы из группы
        excludeFiles: [
            "/Inc/Backup/**",
            "/Src/Backup/**",
//            //---------------------------------------------
//            "/Inc/USB_CustomHID/**",
//            "/Src/USB_CustomHID/**",
//            //---------------------------------------------
//            "/Inc/LwIP/**",
//            "/Src/LwIP/**",
//            //---------------------------------------------
//            "/Inc/adc.h",
//            "/Src/adc.c",
//            //---------------------------------------------
//            "/Inc/dma.h",
//            "/Src/dma.c",
//            //---------------------------------------------
        ]
    }    

    //==========================================================================================
    /*
    Group {
        name: "USB_CustomHID"
        prefix: "./CubeMX"
        files: [
            "/Middlewares/ST/STM32_USB_Device_Library/Core/Inc/**",
            "/Middlewares/ST/STM32_USB_Device_Library/Core/Src/**",
            //-------------------------------------------------------------------
            //"/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc/**",
            //"/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Src/**",
            //-------------------------------------------------------------------
            "/Middlewares/ST/STM32_USB_Device_Library/Class/CustomHID/Inc/**",
            "/Middlewares/ST/STM32_USB_Device_Library/Class/CustomHID/Src/**",
            //-------------------------------------------------------------------
            "/Inc/USB_CustomHID/**",
            "/Src/USB_CustomHID/**",
            //-------------------------------------------------------------------
            "/Tasks/USB_DEVICE/**"
        ]

        // Исключить файлы из группы
        excludeFiles: [
            "/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc/usbd_msc_storage_template.h",
            "/Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Src/usbd_msc_storage_template.c",
            //-------------------------------------------------------------------
            "/Middlewares/ST/STM32_USB_Device_Library/Class/CustomHID/Inc/usbd_customhid_if_template.h",
            "/Middlewares/ST/STM32_USB_Device_Library/Class/CustomHID/Src/usbd_customhid_if_template.c",
            //-------------------------------------------------------------------
            "/Middlewares/ST/STM32_USB_Device_Library/Core/Inc/usbd_conf_template.h",
            "/Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_conf_template.c",
            //-------------------------------------------------------------------
            //"/Tasks/USB_DEVICE"
        ]
    }
    */

    //==========================================================================================
    Group {
        name: "FsData_custom"
        prefix: "./Tasks/FsData_custom"
        files: [
            "/**",
        ]

        // Исключить файлы из группы
        excludeFiles: [
            "/fsdata_custom.c",
        ]
    }

    //==========================================================================================

    Group {
        name: "SdWorkerTask"
        prefix: "./Tasks/SdWorker"
        files: [
            "/**",
        ]

        // Исключить файлы из группы
        excludeFiles: [
        ]
    }

    //==========================================================================================

    Group {
        name: "UartDebugTask"
        prefix: "./Tasks/UartDebug"
        files: [
            "/**",
        ]

        // Исключить файлы из группы
        excludeFiles: [
            "/Temp/**",
        ]
    }

    //==========================================================================================
    Group {
        name: "LedIndicatorTask"
        prefix: "./Tasks/LedIndicator"
        files: [
            "/**",
        ]

        // Исключить файлы из группы
        excludeFiles: [
            "/Temp/**",
        ]
    }
    //==========================================================================================
    Group {
        name: "KeyboardTask"
        prefix: "./Tasks/Keyboard"
        files: [
            "/**",
        ]

        // Исключить файлы из группы
        excludeFiles: [
            "/Temp/**",
        ]
    }

    //==========================================================================================
    Group {
        name: "HttpServerTask"
        prefix: "./Tasks/HttpServer_socket"

        files: [
            "/**",
        ]

        // Исключить файлы из группы
        excludeFiles: [
            "/Temp/**",
//            "/httpserver-socket.h",
//            "/httpserver-socket.c",
        ]
    }

    //==========================================================================================
    /*
    Group {
        name: "AdcToUartTask"
        prefix: "./Tasks/AdcToUart"
        files: [
            "/**",
        ]

        // Исключить файлы из группы
        excludeFiles: [
//            "/AdcToUart.h"
//            "/AdcToUart.c"
        ]
    }
    */

    //==========================================================================================
    /*
    Group {
        name: "ADC_BPF_analysisTask"
        prefix: "./Tasks/ADC_BPF_analysis"

        files: [
            "../../../Inc/adc.h",
            "../../../Src/adc.c",
            "../../../Inc/dma.h",
            "../../../Src/dma.c",
            "/**",
        ]

        // Исключить файлы из группы
        excludeFiles: [
//            "/ADC_BPF_analysis.h",
//            "/ADC_BPF_analysis.c",
            "/tm_stm32f4_adc.h",
            "/tm_stm32f4_adc.c",
        ]
    }
    */
    //==========================================================================================
    /*
    Group {
        name: "UdpBroadcastServer"
        prefix: "./Tasks/UdpBroadcastServer"

        files: [
            "/**",
        ]

        // Исключить файлы из группы
        excludeFiles: [
            "/NotUsed/**",
            "/UdpBroadcastServer3.h",
            "/UdpBroadcastServer3.c",
        ]
    }
    */
    //==========================================================================================
    /*
    Group {
        name: "AdcTestOverUdp"
        prefix: "./Tasks/AdcTestOverUdp"

        files: [
            "/**",
        ]

        // Исключить файлы из группы
        excludeFiles: [
            //"/NotUsed/**",
        ]
    }
    */
    //==========================================================================================
    /*
    Group {
        name: "FftTestOverUdp"
        prefix: "./Tasks/FftTestOverUdp"

        files: [
            "/**",
        ]

        // Исключить файлы из группы
        excludeFiles: [
            //"/NotUsed/**",
        ]
    }
*/
    //==========================================================================================
    //особенно интересный момент: скрипты линковщика, описывают структуру бинарника, секции, и так далее
    cpp.linkerScripts: [
        "./ldscripts/STM32F407VE_FLASH.ld",
    ]
}
