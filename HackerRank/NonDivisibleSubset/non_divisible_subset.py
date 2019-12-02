# Enter your code here. Read input from STDIN. Print output to STDOUT
nk = raw_input()
s = raw_input()
n = nk.split()[0]
k = nk.split()[1]
outset = []
inset = set(int(s.split()))
for i in inset:
	for j in inset:
		if((i//k+j//k)==k):
			outset.append(j)
			outset.append(i)
print(outset)
		
