require "spec"

PERMITTED_EPSILON = 2

struct TestCase
  property bribes : Int32?
  property line : Array(Int32)

  def initialize(@bribes, @line); end

  def self.too_chaotic_case(line)
    new(nil, line)
  end
end

TestCases = {
  TestCase.new(3, [2, 1, 5, 3, 4]),
  TestCase.too_chaotic_case([2, 5, 1, 3, 4]),
  TestCase.too_chaotic_case([5, 1, 2, 3, 7, 8, 6, 4]),
  TestCase.new(7, [1, 2, 5, 3, 7, 8, 6, 4]),
}

describe ".minimum_bribes" do
  {% for test_case in TestCases %}
  context "when the positions are {{test_case}}" do
    it "responds as expected" do
      minimum_bribes({{test_case}}.line).should eq {{test_case}}.bribes
    end
  end
  {% end %}
end

describe ".bubble_sort_technique" do
  {% for test_case in TestCases %}
  context "when the positions are {{test_case}}" do
    it "responds as expected" do
      bubble_sort_technique({{test_case}}.line).should eq {{test_case}}.bribes
    end
  end
  {% end %}
end

def minimum_bribes(line)
  total_bribes = 0
  (line.size - 1).downto 0 do |line_position|
    original_position = line[line_position]
    puts "line #{line} at #{line_position} is person ##{original_position}"
    return nil if original_position - (line_position + 1) > PERMITTED_EPSILON
    {0, line[line_position]}.max.upto line_position do |bribe|
      total_bribes += 1 if line[bribe] > line[line_position]
    end
  end
  total_bribes
end

macro swap(first, second)
  swapped = true
  {{first.id}}, {{second.id}} = {{second.id}}, {{first.id}}
end

def bubble_sort_technique(line)
  swaps = 0
  swapped = false
  keep_sorting = true
  bribes = {} of Int32 => Int32

  line.each_index start: 0, count: line.size - 1 do
    line.each_index start: 0, count: line.size - 1 do |line_position|
      if line[line_position] > line[line_position + 1]
        swap line[line_position], line[line_position + 1]
        swaps += 1

        bribes[person = (line[line_position]-1)] = (bribes[person]? || 0) + 1
        return nil if bribes[person] > 2
      end
    end
    break unless swapped
    swapped = false
  end
  swaps
end
