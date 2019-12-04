require "string_scanner"

File.open "../input" do |file|
  puts Program.new(file.gets_to_end).run
end

class NoFurtherOpcodes < Exception
  def initialize(text : StringScanner)
    super "no further opcodes found at offset #{text.offset}"
  end
end

class InvalidOpcode < Exception
  def initialize(code)
    super "Received invalid opcode " + code.to_s
  end
end

class StringScanner
  def next_int?
    scan_until /(\d+)/
    self[1]?.try &.to_i
  end

  def next_int
    next_int? || raise "No int found in #{self} at #{offset}"
  end
end

struct Operation
  enum Code
    Add      = 1
    Multiply
    STOP     = 99
  end
  property op : Code
  property data : Tuple(Int32, Int32)
  property location : Int32

  def initialize(@op : Code, left : Int32, right : Int32, @location : Int32)
    @data = {left, right}
  end

  def left
    data[0]
  end

  def right
    data[1]
  end

  def apply(to source : Array(Int32))
    case op
    when .add?      then source[location] = source[left] + source[right]
    when .multiply? then source[location] = source[left] * source[right]
    when .stop?     then return source
    else                 raise InvalidOpcode.new op
    end
    source
  end
end

struct Program
  @source : Array(Int32)
  property data : Array(Operation)

  def self.new(source : String)
    new StringScanner.new source
  end

  def initialize(source : StringScanner)
    @data = [] of Operation
    @source = [] of Int32
    while opcode = source.next_int?
      @source << opcode
    end
    @source[1] = 12
    @source[2] = 2
    parse
  end

  private def parse
    source = @source.dup
    while opcode = source.shift?
      case op = Operation::Code.new opcode
      when .add?, .multiply?
        data << Operation.new op, source.shift, source.shift, source.shift
      when .stop? then break
      else             raise InvalidOpcode.new opcode
      end
    end
  end

  def run
    while step = data.shift?
      @source = step.apply to: @source
    end
    @source.first
  end
end
