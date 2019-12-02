class TimeRepr
  @hour : UInt8
  @minute : String
  @am_or_pm : String
  def initialize(@value : String)
    # expected input format /\d\d?:\d\d \w\w/ || 00:00 XM
    split = @value.split(':')
    if split.size < 2
      raise "invalid format. " + @value
    end
    @hour = split[0].to_u8
    split = split[1].split
    @minute = split[0]
    @am_or_pm = split[1]
    if @hour > 12 || @hour < 1
      raise "Invalid hour #{@hour}"
    end
    if @minute.to_u8 > 59
      raise "Invalid minute #{@minute}"
    end
  end

  def self.get_from_input
    if ARGV.size == 0
      # if the input arguments array is empty
      return TimeRepr.new gets.chomp
      # Request console input and trim the newline at the end.
    end
    # the input was specified as the first argument on the
    # command line
    return TimeRepr.new ARGV[0]
  end

  def to24time
    if @am_or_pm.upcase == "AM"
      return "#{@hour}:#{@minute}"
      # string ^^ interpolation puts variable's values in place of
      # "#{variable_name}"
      # could be written as
      # puts hour + ":" + minute
    elsif @am_or_pm.upcase == "PM"
      return "#{@hour.to_i + 12}:#{@minute}"
    else
      raise "syntax error"
    end
  end
end
