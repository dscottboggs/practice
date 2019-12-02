module Hamming
  def self.distance(a, b)
    if a.size != b.size
      raise ArgumentError.new %<\
        the length of "#{a}" (#{a.size}) was not the same as "#{b}" \
        (#{b.size}).>
    end
    distance = 0
    a.each_char_with_index do |char, index|
      # puts "'#{char}' #{char != b[index] ? "equals" : "does not equal"}"
      distance += 1 if char != b[index]
    end
    distance
  end
end
