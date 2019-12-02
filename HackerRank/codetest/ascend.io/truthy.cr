[
  true,
  false,
  0,
  -1,
  1,
  "",
  [] of Nil,
  {} of Nil => Nil,
  nil
].each do |value|
  if value
    puts "value #{value} was truthy"
  else
    puts "value #{value} was falsey"
  end
end
