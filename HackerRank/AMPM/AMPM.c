#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <sysexits.h>
#define TIME_MAX_LEN 10
#define twelve_hour_format "%I:%M:%S%p"
#define twenty_four_hour_format "%H:%M:%S"

char *getInput() {
	char *input_str[TIME_MAX_LEN];
	if( fgets(*input_str, TIME_MAX_LEN+1, stdin) == NULL ) {
		fprintf(stderr,
				"got input \"%s\" from fgets\n",
				*input_str);
		exit(EX_USAGE);
	}
	input_str[strcspn(*input_str, "\n")] = 0;
	return input_str[0];
}

// to12 converts the given "time" to 12-hour, placing the result in 
// "twelve_time". It returns false and logs a message to stderr if there's a
// parsing error, true otherwise.
bool to12(char *time, char *twelve_time) {
	int hour, minute, second;
	char *end;
	hour = (int)strtol(time, &end, 10);
	if( *end != ':' ) {
		fprintf(stderr, "got invalid time delimiter %s", end);
		return false;
	}
	minute = (int)strtol(time + 3, &end, 10);
	if( *end != ':' ) {
		fprintf(stderr, "got invalid time delimiter %s", end);
		return false;
	}
	second = (int)strtol(time + 5, &end, 10);
	if( *end != '\0') {
		fprintf(stderr, "got invalid time delimiter %s", end);
		return false;
	}
	if( hour < 0 || hour > 23 ) {
		fprintf(stderr, "got invalid hour %d", hour);
		return false;
	}
	if( hour > 12 ) {
		sprintf(twelve_time, "%d:%d:%dPM", hour - 12, minute, second);
		return true;
	}
	sprintf(twelve_time, "%d:%d:%dAM", hour == 0? 12 : hour, minute, second);
	return true;
}

int main(int argc, char const *argv[]) {
	char *input_str[TIME_MAX_LEN];
	char output_str[TIME_MAX_LEN];
	// get input
	input_str[0] = getInput();
	to12(input_str[0], &output_str[0]);
	puts(output_str);
}
