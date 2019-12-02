module ETL
  extend self

  def transform(input)
    data = {} of String => Int32
    input.each do |key, values|
      score_val = key.to_i
      values.each { |value| data[value.downcase] = score_val }
    end
    data
  end
end
