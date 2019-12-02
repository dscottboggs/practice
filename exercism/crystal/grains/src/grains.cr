module Grains
  extend self

  def raise_out_of_range!(value : Int) : NoReturn
    raise ArgumentError.new "value must be between 1 and 64; got " + value.to_s
  end

  def square(value : Int32) : UInt64
    raise_out_of_range! value if 1 > value || value > 64
    1_u64 << (value - 1)
  end

  def total : UInt64
    (1..64).sum { |n| square n }
  end
end
