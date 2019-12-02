require "spec"
require "benchmark"
require "../src/hamming-with_types"
require "../src/hamming"

def sequence(of length : Int32) : Hamming::WithTypes::DnaSequence
  Hamming::WithTypes::DnaSequence.new(Slice(Hamming::WithTypes::DnaSequence::Neucleotide).new size: length, read_only: true do
    Hamming::WithTypes::DnaSequence::Neucleotide.new Random::Secure
      .rand(Hamming::WithTypes::DnaSequence::Neucleotide::T.value + 1)
  end)
end
{% begin %}
SEQUENCES = {
  {% for len in (2..10).map { |i| 2 ** i } %}
    a_{{len}}: sequence(of: {{len}}).to_s,
    b_{{len}}: sequence(of: {{len}}).to_s,
  {% end %}
}
Benchmark.ips do |bench|
  {% for len in (2..10).map { |i| 2 ** i } %}
  bench.report "hamming distance on sequence of {{len}} neucleotides (with types)" do
    Hamming::WithTypes.distance(SEQUENCES[:a_{{len}}], SEQUENCES[:b_{{len}}])
  end
  bench.report "hamming distance on sequence of {{len}} neucleotides (simple)" do
    Hamming.distance(SEQUENCES[:a_{{len}}], SEQUENCES[:b_{{len}}])
  end
  {% end %}
end
{% debug %}
{% end %}
