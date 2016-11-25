#include <stdio.h>
#include <thread>
#include <iostream>
#include <unistd.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define BLUE "\033[34m"

using namespace std;

int milliseconds;
int seconds;
int minutes;
int hours;
int days;

int ack(int m, int n) {
	if(m == 0)
		return n+1;
	if(n == 0)
		return ack(m-1, 1);

	return ack(m-1, ack(m, n-1) );
}

void count() {
	while(true) {
		milliseconds++;
		if(milliseconds >= 100) {
			seconds++;
			milliseconds = 0;
		}
		if(seconds >= 60) {
			minutes++;
			seconds = 0;
		}
		if(minutes >= 60) {
			hours++;
			minutes = 0;
		}
		if(hours >= 24) {
			days++;
			hours = 0;
		}
		usleep(10000);
		cout << BLUE << "\r" << days << ":" << hours << ":" << minutes << ":" << seconds << ":" << milliseconds << "                    " << RESET << flush;
	}
}

int main() {
	thread clock(count);
	for(int i = 3; i < 6; i++) {
		for(int j = 0; j < 6; j++) {
			cout << RED << "[" << i << "][" << j << "] = " << ack(i, j) << RESET << endl;
		}
	}

}