all: temperature_stats

temperature_stats: main.o temp_api.o getopt.o
	gcc -o temperature_stats main.o temp_api.o getopt.o

main.o: main.c temp_api.h getopt.h
	gcc -c -std=c99 -o main.o main.c

temp_api.o: temp_api.c
	gcc -c -std=c99 -o temp_api.o temp_api.c
	
getopt.o: getopt.c
	gcc -c -std=c99 -o getopt.o getopt.c

clean:
	del *.o
	del temperature_stats.exe