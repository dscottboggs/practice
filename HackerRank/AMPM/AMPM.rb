if $*.length == 0
  input = gets.chomp
else
  input = $*[0]
end
hour, minute, second_and_ampm = input.split(':')
second = second_and_ampm[/\d[2]/]
ampm = second_and_ampm[/AM|PM/]
puts "#{ampm == "AM"? hour : hour.to_i + 12}:#{minute}:#{second}"
