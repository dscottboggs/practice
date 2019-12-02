#!/bin/ruby

require 'json'
require 'stringio'

# Complete the countApplesAndOranges function below.
def countApplesAndOranges(s, t, a, b, apples, oranges)
  applesHit, orangesHit = 0, 0
  apples.each do |apple|
    if s <= apple and apple <= t
      applesHit++
    end
  end
  oranges.each do |orange|
    if s <= orange and orange <= t
      orangesHit++
    end
  end
  puts applesHit, orangesHit
end

st = gets.rstrip.split

s = st[0].to_i

t = st[1].to_i

ab = gets.rstrip.split

a = ab[0].to_i

b = ab[1].to_i

mn = gets.rstrip.split

m = mn[0].to_i

n = mn[1].to_i

apples = gets.rstrip.split(' ').map(&:to_i)

oranges = gets.rstrip.split(' ').map(&:to_i)

countApplesAndOranges s, t, a, b, apples, oranges
