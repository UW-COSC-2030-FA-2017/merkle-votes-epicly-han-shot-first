# Jared Spaulding
# 11/9/2017
# makefile for merkle tree project

output: vote.o
	g++ vote.o -o vote
	make clean

vote.o: vote.cpp
	g++ -c vote.cpp

# del only works for windows machines
# use rm for linux and mac
clean:
	del *.o output
