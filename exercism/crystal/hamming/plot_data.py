import matplotlib.pyplot as plot

class List(list):
    def __lshift__(self, value):
        self.append(value)
        return self

class Data:
    def __init__(self, line):
        count, types, mem, avg_time, mem_per_op, variance = line.split(',')
        self.count = int(count)
        self.mem = float(mem[0:-2]) if mem.endswith('M') else float(mem[0:-2]) * 1024
        self.avg_time = float(avg_time[0:-3]) if avg_time.endswith('ns') else float(avg_time[0:-3]) * 1000
        self.mem_per_op = float(mem_per_op[0:-3]) * 1024 if mem_per_op.endswith('kB') else float(mem_per_op[0:-2])
        self.types = types == "true"
        self.variance = float(variance)
    def __repr__(self):
        return f"<Data: count: {self.count}, mem: {self.mem}, avg_time:" +\
               f" {self.avg_time}, types: {self.types}, variance: {self.variance}>"

data = List()
with open('data') as data_file:
    data_file.readline() # skip the header line
    line = data_file.readline()
    while line:
        data << Data(line)
        line = data_file.readline()

iterations = [d.count for d in data if d.types]
# print(iterations)
for metric in ['mem', 'avg_time', 'variance', 'mem_per_op']:
    simple = [x.__dict__[metric] for x in data if not x.types]
    with_types = [x.__dict__[metric] for x in data if x.types]
    # print('with types:', with_types, 'simple:', simple, sep='\n')
    plot.plot(with_types,
              iterations,
              label=f'with types')
    plot.plot(simple,
              iterations,
              label=f'simple')
    plot.xlabel(metric)
    plot.ylabel('iterations')
    plot.title(f'benchmark {metric.replace("_", " ")}')
    plot.legend()
    plot.show()
