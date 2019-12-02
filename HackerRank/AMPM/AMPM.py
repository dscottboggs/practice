#!/bin/python3
from datetime import datetime
_12_hour_time = r"%I:%M:%S%p"
_24_hour_time = r'%H:%M:%S'
to24hour = lambda time: time.strftime(_24_hour_time)
to12hour = lambda time: time.strftime(_12_hour_time)
from12hour = lambda tin: datetime.strptime(tin, _12_hour_time)
from24hour = lambda tin: datetime.strptime(tin, _24_hour_time)
def main():
	print(to24hour(from12hour(input("Time to be converted: "))))
if __name__ == '__main__':
	main()
