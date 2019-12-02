# Enter your code here. Read input from STDIN. Print output to STDOUT
import string

s = str(raw_input()).lower()
print(''.join(set(sorted(s))).strip())
print(string.ascii_lowercase)
#if (''.join(set(sorted(s.strip()))).find(string.ascii_lowercase) == -1):
#    print("pangram")
#else:
#    print("not pangram")
def getMinimal(str z):
	
