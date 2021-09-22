CC = g++ # swap for clang if you have no life
CFLAGS = -lcurl

# post_only include vars
SRC_FILES := $(wildcard *.cpp)
RO_SRC_FILES := $(filter-out post.cpp, $(SRC_FILES))
PO_SRC_FILES := $(filter-out read.cpp, $(SRC_FILES))

bwitter:
	$(CC) -o bwitter main.cpp $(CFLAGS)

bwitter_post_only:
	$(CC) -o bwitter_po main.cpp $(CFLAGS)

argtest:
	$(CC) -o argtest argtest.cpp
