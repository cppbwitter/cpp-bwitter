CC = g++
CFLAGS = -lcurl
bwitter:
	$(CC) -o bwitter main.cpp $(CFLAGS)

argtest:
	$(CC) -o argtest argtest.cpp