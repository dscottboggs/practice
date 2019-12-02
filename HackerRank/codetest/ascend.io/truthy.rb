def voidfunc
end

[
  true,
  false,
  0,
  -1,
  1,
  "",
  [],
  {},
  nil,
  voidfunc(),
  undefined_value,
].each do |value|
  if value
    puts "value #{value} was truthy!"
  else
    puts "value #{value} was falsey!"
  end
end
