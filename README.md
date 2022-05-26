Статистика температуры - Консольное приложение.
=======================
Консольное приложение, которое
осуществляет считывание текстового файла csv, состоящего из
строк следующего формата:

YEAR;MONTH;DAY;HOUR;MINUTE;TEMPERATURE

dddd;mm;dd;hh;mm;temperature 

dddd - год 4 цифры

mm - месяц 2 цифры

dd - день 2 цифры

hh - часы 2 цифры

mm - минуты 2 цифры

temperature - целое число от -99 до 99

Приложение принимает параметры с аргументами в командной строке:
-	-h описание функционала приложения (список параметров);
-	-f <имя_файла> входной файл csv для обработки;
-	-m <mm> выводится статистика за указанный месяц (минимальная температура в текущем месяце, максимальная температура в текущем месяц, среднемесячная температура);
-	-y <yyyy> выводится статистика за указанный год (минимальная годовая температура, максимальная годовая температура, среднегодовая температура);
  
Описание файлов:
=======================
getopt.c - файл используемый для разбора параметров командной строки в стиле Unix/POSIX;
  
getopt.h - файл прототипов для getopt.c;
  
main.c - основной файл программы;
  
temp_api.c - файл описания функций программы;
  
temp_api.h - файл прототипов функций программы;
  
Makefile - файл инструкция для утилиты сборки mingw32-make;
  
  
Установка:
=======================
`cd <папка для проекта>`
  
`git clone https://github.com/sh1n0b1n0m0n0/IoT_temperature_proj.git`

Работа с приложением:
======================= 
`temperature_stats.exe -h`
  
![](https://github.com/sh1n0b1n0m0n0/IoT_temperature_stats/blob/master/6.png)
  
`temperature_stats.exe -f temperature_small.csv -m 01` - temperature_small.csv тестовый файл с ошибками;
  
![](https://github.com/sh1n0b1n0m0n0/IoT_temperature_stats/blob/master/2.png)
  
`temperature_stats.exe -f temperature_small.csv -y 2021`

![](https://github.com/sh1n0b1n0m0n0/IoT_temperature_stats/blob/master/3.png)
  
`temperature_stats.exe -f temperature_big.csv -m 01`
  
![](https://github.com/sh1n0b1n0m0n0/IoT_temperature_stats/blob/master/5.png)
  
`temperature_stats.exe -f temperature_big.csv -y 2021`

![](https://github.com/sh1n0b1n0m0n0/IoT_temperature_stats/blob/master/4.png)
  
Сборка Makefile:
======================= 
`cd temp_project`
  
`mingw32-make`
  
![](https://github.com/sh1n0b1n0m0n0/IoT_temperature_stats/blob/master/1.png)
