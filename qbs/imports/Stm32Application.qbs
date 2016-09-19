import qbs

Stm32Product {
    type: "application"
    consoleApplication: true

    cpp.architecture: "arm"

    cpp.positionIndependentCode: false

    // Получаемый формат
    cpp.executableSuffix: ".elf"

    //  text   data	    bss	    dec	    hex	filename
    // 51300   2252	  15448	  69000	  10d88	CubeMX.elf
    //
    // DEC  = TEXT + DATA + BSS
    // TEXT - данные во Flash,
    // DATA - инициализированные данные в RAM,
    // BSS  - неинициализированные данные в RAM.

    //    text - shows the code and read-only data in your application (in decimal)
    //    data - shows the read-write data in your application (in decimal)
    //    bss - show the zero initialized ('bss' and 'common') data in your application (in decimal)
    //    dec - total of 'text' + 'data' + 'bss' (in decimal)
    //    hex - hexidecimal equivalent of 'dec'

    // ----------------------------------------------------------------------------------------------------------------
    // Дополнительный возможности
    //
    // C:\GCC\gcc-arm-none-eabi-5.3_2016q1\bin\arm-none-eabi-objcopy.exe -Oihex CubeMX.elf CubeMX.hex

    // https://manned.org/arm-none-eabi-size
    // C:\GCC\gcc-arm-none-eabi-5.3_2016q1\bin\arm-none-eabi-size        --format=berkeley CubeMX.elf

    // C:\GCC\gcc-arm-none-eabi-5.3_2016q1\bin\arm-none-eabi-objdump     -S CubeMX.elf > CubeMX.lss
    // ----------------------------------------------------------------------------------------------------------------

    /*
    // Команды для st-link

        set remote hardware-breakpoint-limit 6
        set remote hardware-watchpoint-limit 4
        monitor reset halt
        load
        monitor reset halt
        break main
        continue
    */

    cpp.toolchainPathPrefix: "C:/GCC/gcc-arm-none-eabi-5.3_2016q1/bin/"
    //cpp.toolchainPathPrefix: "/usr/bin/"

    /*
        — использовать короткие пути для проекта
        — на 64битной win надо использовать 64битный openocd
        — родные драйвера к stlink не должны быть установлены, только драйвера поставленные через Zadig для stlink
        — в архиве несколько gdb, нужный: qtcreator-gdb-7.7-mingw32_nt-6.1-i686\gdb-arm-none-eabi.exe

        Перед отладкой под виндой Обязательно прочесть и применить
        http://robocraft.ru/blog/ARM/653.html

        намек http://we.easyelectronics.ru/STM32/razrabotka-dlya-stm32f4discovery-s-pomoschyu-mbed-v-qtcreator.html
        https://yadi.sk/d/inoglwHOP5GHR

        Рабочий отладчик с поддержкой питона для Qt
        qtcreator-gdb-7.7-mingw32_nt-6.1-i686

        Qt Creator -> Инструменты -> Параметры -> Отладчик -> GDB, расширенные -> Использовать асинхронный режим для работы с программой.
        Нужно поставить эту галку, и креатор не будет вылетать при отладке! =)

    */

    cpp.compilerName:    "arm-none-eabi-gcc"
    cpp.cCompilerName:   "arm-none-eabi-gcc"
    cpp.cxxCompilerName: "arm-none-eabi-g++"

    cpp.assemblerName:   "arm-none-eabi-as"

    // Не включать. Сделает сам.
    //cpp.linkerName:      "arm-none-eabi-ld"
    cpp.linkerName:      "arm-none-eabi-gcc"

//    cpp.libraryPaths: "./lib"

//    cpp.staticLibraries: [
//        "CubeMX.a"
//    ]

    // Свойства компиляора для группы
    cpp.warningLevel: "all"

    cpp.commonCompilerFlags: [
        "-mthumb",
        "-mcpu=cortex-m4",
        "-mtune=cortex-m4",
        "-mfloat-abi=hard",
        // http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0489c/CIAHHAFG.html
        "-mfpu=fpv4-sp-d16",
        //"-mfpu=vfpv4",
        //VFPv4-D32, or VFPv4U-D32, for a thirty-two register implementation
        //VFPv4-D16, or VFPv4U-D16, for a sixteen register implementation.
        //-----------------
        // Оптимизация компиляции
        //http://habrahabr.ru/post/191058/
        "-fno-exceptions",
        "-fno-unwind-tables",
        "-fno-asynchronous-unwind-tables",
        // главные оптимизаторы
        "-ffunction-sections",
        "-fdata-sections",
//        "-fno-inline",
//        "-fno-builtin",
        //"-flto", // error: unrecognised debug output level "c-sections"
        //-----------------
        // -O1 (также носит обозначение -O, признанное устаревшим)
        // Мягкая оптимизация, некоторое увеличение времени компиляции, возможно ощутимое увеличение памяти для больших функций;
        // включены оптимизации, которые должны одновременно уменьшать общую занимаемую память и ускорять код.
        // -02
        // Включает практически все доступные оптимизации, не ухудшающие сильно один из двух показателей двоичного кода — память или скорость
        // — за счёт другого; не включает развертку циклов и автоматическое встраивание функций.
        // -O3
        // Наиболее «агрессивная» оптимизация, включаются развертку циклов и автоматическое встраивание функций.
        // -O0
        // Отключение оптимизаций, основная цель: высокая скорость компиляции и предсказуемость результатов отладки; эта опция задействована по умолчанию.
        // -Os  !!!
        // Оптимизация размера программы. Включаются те опции из набора -O2, которые обычно не увеличивают объём кода.
        // Также применяются некоторые другие оптимизации, направленные на снижение его объёма.
//        "-O0",
        //-----------------
        //"-specs=nosys.specs",  //or add syscalls.c
        //"-specs=nano.specs",
        //-----------------
        // Уровень 0 отключает генерацию отладочной информации.
        // Уровень 1 обеспечивает минимум отладочной информации,
        //           позволяющей просматривать стеки вызовов подпрограмм, которые вы не планировали отлаживать.
        //           Включаются описания функций и внешних переменных, но отсутствует информация о локальных переменных и номерах строк исходного кода.
        // Уровень 2 используется по умолчанию и добавляет к уровню 1 информацию о локальных переменных и номерах строк исходного кода.
        // Уровень 3 включает дополнительную информацию, например, определения макросов.
        // -ggdb (будет использован максимально выразительный доступный на данной платформе формат).
//         "-g3",
        //-----------------
        // Во-вторых, отладочная информация все же занимает дополнительное пространство в памяти
        // (темпы удешевления которой, впрочем, настолько высоки, что вряд ли можно оправдать пренебрежительное отношение
        // к генерации отладочной информации), которое вы можете захотеть сэкономить. Для этого существует ключ -s (от strip — удалить)
        //"-s",
        //-----------------
        //"-ffreestanding",
        //"-entry=Reset_Handler",
        //-----------------
        // Не использовать - увеличивает размер
        //"-fpack-struct",
        //-----------------
        //"-fno-builtin",
        //"-Wcpp",
        // Generate debug information
        "-g",
        //------------------
        //"-nostdlib",
        //"-nostartfiles",
        //"-ffreestanding",
        //------------------
    ]

    //gcc вполне позволяет использовать для программирования МК новый стандарт C++11
    cpp.cxxFlags: [ "-std=c++11" ]
    cpp.cFlags:   [ "-std=gnu99" ]

    cpp.linkerFlags:[
        "-mthumb",
        "-mcpu=cortex-m4",
        "-mtune=cortex-m4",
        "-mfloat-abi=hard",
        // http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0489c/CIAHHAFG.html
        "-mfpu=fpv4-sp-d16",
        //-----------------
        //! НЕ ВКЛЮЧАТЬ!!! init.c:(.text.__libc_init_array+0x38): undefined reference to `_init'
        // Do not link standard start files. We are providing our own start file *.s
        //"-nostartfiles",
        //"-nodefaultlibs",
        //"-nostdlib",
        //-----------------
        // Не для gcc
        //"-Xlinker -Map=target/target.map",
        //-----------------
        "-Wl,--gc-sections",
        "-static",
        //"-Wl,-Map",
        // сгенерировать карту памяти (linker memory map)
        "-Wl,-Map=CubeMX.map",
        // сгенерировать таблицу перекрестных ссылок (cross reference table, опция для линкера)
        "-Wl,-cref",
        //"-stdlib",
        //-----------------
//        "-specs=nosys.specs",  //or add syscalls.c
//        "-lnosys",
        //-----------------
//        "-specs=nano.specs",
        //-----------------
        // Подключает libgcc.a: Compiler helper library
        //"-lgcc",
        // Подключает libc.a: Standard C library (stdlib, stdio, string,…) (НЕ ПОДКЛЮЧАЕТСЯ!!!)
        // _sbrk, _write, _close, _fstat, _isatty, _lseek, _read
        // Без нее меньше памяти занимает
        //"-lc",
        // Подключает libm.a: Mathematical functions (log, sin,…)
        "-lm",
    ]

/*
    Rule {
        //id: hex
        //multiplex: true
        input: [ "application" ]
        //input: "elf"
//        Artifact {
//            //fileTags: ["hex"]
//            //filePath: FileInfo.baseName(input.filePath) + ".hex"
//        }
        Artifact {
           fileTags: ['elf']
           //filePath: project.name + '.elf'
           filePath: product.destinationDirectory+"/"+FileInfo.baseName(input.filePath)
        }
        prepare: {
//            var args = ["-O", "ihex", input.filePath, output.filePath];
//            var cmd = new Command("arm-none-eabi-objcopy", args);
//            cmd.description = "converting to hex: "+FileInfo.fileName(input.filePath);
//            //cmd.highlight = "linker";
//            cmd.highlight = "compiler";

//            return cmd;

            var args = [];
            args.push("-Oihex CubeMX.elf")

//            for (i in inputs["elf"])
//                        args.push(inputs["elf"][i].filePath);

            args.push('-Oihex');
            args.push(output.filePath);
            //args.push(product.destinationDirectory+"/"+FileInfo.baseName(input.filePath));

            //var compilerPath = "C:\ARM\gcc-arm-none-eabi-4_9_3\bin\arm-none-eabi-objcopy.exe"
            var objcopyPath = "C:/ARM/gcc-arm-none-eabi-4_9_3/bin/arm-none-eabi-objcopy.exe";

            var cmd = new Command(objcopyPath, args);
            cmd.description = '------------linking ' + project.name;
            cmd.highlight = 'linker';
            return cmd;


        }
    }
*/


    Rule {
        inputs: "elf"
        Artifact {
            fileTags: ["bin"]
            filePath: product.name + ".bin"
        }
        prepare: {
                var args = ["-O", "binary", input.filePath, output.filePath];
                var cmd = new Command(product.objcopyPath, args);
                cmd.description = "converting to bin";
                return cmd;
        }
    }

    Rule {
        inputs: "elf"
        Artifact {
            fileTags: ["hex"]
            filePath: product.name + ".hex"
        }
        prepare: {
            var args = ["-O", "ihex", input.filePath, output.filePath];
            var cmd = new Command(product.objcopyPath, args);
            cmd.description = "converting to hex";
            return cmd;
        }
    }


}
