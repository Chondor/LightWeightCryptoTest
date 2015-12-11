
OBJS = driver.o Algorithm_RC5.o XTea.o Simon.o Speck.o
#OBJS = slim_driver.o Algorithm_RC5.o XTea.o Simon.o Speck.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

driver_run : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o driver_run

driver.o: driver.cpp Algorithm_RC5.h XTea.h Simon.h Speck.h
	$(CC) -std=c++11 $(CFLAGS) driver.cpp

#slim_driver.o: slim_driver.cpp Algorithm_RC5.h XTea.h Simon.h Speck.h
#	$(CC) -std=c++11 $(CFLAGS) slim_driver.cpp

Algorithm_RC5.o: Algorithm_RC5.h Algorithm_RC5.cpp ICrypto.h
	$(CC) $(CFLAGS) Algorithm_RC5.cpp

XTea.o: XTea.h XTea.cpp ICrypto.h
	$(CC) $(CFLAGS) XTea.cpp
	
Simon.o: Simon.cpp Simon.h ICrypto.h
	$(CC) $(CFLAGS) Simon.cpp
	
Speck.o: Speck.cpp Simon.h ICrypto.h
	$(CC) $(CFLAGS) Speck.cpp

clean:
	\rm *.o driver_run *.log *.csv

run: run_rc5_all run_xtea_all run_simon_all run_speck_all

run_2048000: 	
	./driver_run 1500 204800 R
	./driver_run 1500 204800 X
	./driver_run 1500 204800 SI
	./driver_run 1500 204800 SP

run_rc5:
	./driver_run 1500 204800 R

run_rc5_all:
	./driver_run 1500 800 R
	./driver_run 1500 1600 R
	./driver_run 1500 3200 R
	./driver_run 1500 6400 R
	./driver_run 1500 12800 R
	./driver_run 1500 25600 R
	./driver_run 1500 51200 R
	./driver_run 1500 102400 R
	./driver_run 1500 204800 R

run_xtea:
	./driver_run 1500 204800 X

run_xtea_all:
	./driver_run 1500 800 X
	./driver_run 1500 1600 X
	./driver_run 1500 3200 X
	./driver_run 1500 6400 X
	./driver_run 1500 12800 X
	./driver_run 1500 25600 X
	./driver_run 1500 51200 X
	./driver_run 1500 102400 X
	./driver_run 1500 204800 X

run_simon:
	./driver_run 1500 204800 SI

run_simon_all:
	./driver_run 1500 800 SI
	./driver_run 1500 1600 SI
	./driver_run 1500 3200 SI
	./driver_run 1500 6400 SI
	./driver_run 1500 12800 SI
	./driver_run 1500 25600 SI
	./driver_run 1500 51200 SI
	./driver_run 1500 102400 SI
	./driver_run 1500 204800 SI

run_speck:
	./driver_run 1500 204800 SP

run_speck_all:
	./driver_run 1500 800 SP
	./driver_run 1500 1600 SP
	./driver_run 1500 3200 SP
	./driver_run 1500 6400 SP
	./driver_run 1500 12800 SP
	./driver_run 1500 25600 SP
	./driver_run 1500 51200 SP
	./driver_run 1500 102400 SP
	./driver_run 1500 204800 SP

