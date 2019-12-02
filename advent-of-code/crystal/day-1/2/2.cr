#!/usr/bin/env crystal
INPUT = {{ read_file "../input" }}

def fuel_for_component(weight)
  fuel = weight.to_i // 3 - 2
  if fuel <= 0
    0
  else
    fuel + fuel_for_component fuel
  end
end

puts INPUT.lines.map(&->fuel_for_component(String)).sum
