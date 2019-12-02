
def get_input
  gets.chomp.to_i
  input = gets.chomp
  return input.split.map { |number| number.to_i }
end

def main
  pos = neg = zero = 0
  get_input.each { |number|
    if number > 0
      pos += 1
    elsif number == 0
      zero += 1
    else
      neg += 1
    end
  }
  puts "negative: #{neg}", "zero: #{zero}", "positive: #{pos}"
end

main
