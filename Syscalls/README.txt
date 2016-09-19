При попытке собрать проект линкер выдал несколько ошибок: 

undefined reference to _sbrk
undefined reference to _write
undefined reference to _close
undefined reference to _fstat
undefined reference to _isatty
undefined reference to _lseek
undefined reference to _read

Это связанно с тем, что newlib была сконфигурирована с ключом --disable-newlib-supplied-syscalls

Для решения этой проблемы в проект был включен файл syscalls.c с необходимыми функциями-"заглушками".
ИЛИ newlib_stubs.c
