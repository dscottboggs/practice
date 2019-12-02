#!/usr/bin/env crystal
INPUT = {{ read_file "../input" }}

fuel = INPUT.lines.map do |component|
  component.to_i // 3 - 2
end.sum

puts fuel
