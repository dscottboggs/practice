#!/bin/ruby

require 'json'
require 'stringio'

def right_diagonal_sum(arrays)
    outsum = 0
    arrays.each_index do |index|
        outsum += arrays[index][index]
    end
    return outsum
end

def left_diagonal_sum(arrays)
    outsum = 0
    row = 0
    column = arrays.length - 1
    while row < arrays.length do
        puts "Sum is currently #{outsum}, at row #{row} and column #{column}, so adding #{arrays[row][column]}"
        theRow = arrays[row]
        puts "theRow[column] = #{theRow[column]}"
        outsum += theRow[column]
        column -= 1
        row    += 1
    end
    return outsum
end

# Complete the diagonalDifference function below.
def diagonalDifference(a)
    diff = right_diagonal_sum(a) - left_diagonal_sum(a)
    return diff.abs
end

fptr = File.open(ENV['OUTPUT_PATH'], 'w')

n = gets.to_i

a = Array.new(n)

n.times do |i|
    a[i] = gets.rstrip.split(' ').map(&:to_i)
end

result = diagonalDifference a

fptr.write result
fptr.write "\n"

fptr.close()
