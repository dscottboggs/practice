# Please implement your solution to gigasecond in this file
module Gigasecond
  GIGASECOND = 1e9.seconds

  def self.from(time : Time)
    time + GIGASECOND
  end
end
