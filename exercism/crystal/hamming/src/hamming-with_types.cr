module Hamming::WithTypes
  struct DnaSequence
    @seq : Slice(Neucleotide)

    def initialize(@seq); end

    enum Neucleotide : UInt8
      C; A; G; T

      def self.parse(chr : Char)
        {% begin %}
          case chr.upcase
            {% for c in @type.constants %}
              when '{{c.id}}' then {{c}}
            {% end %}
          else
            raise InvalidNeucleotide.new chr
          end
        {% end %}
      end

      def to_char
        {% begin %}
        case self
        {% for variant in @type.constants %}
        when {{variant}} then '{{variant.id}}'.ord.to_u8!
        {% end %}
        else raise "invalid enum vairant #{self}"
        end
        {% end %}
      end
    end
    include Indexable(Neucleotide)
    delegate :size, :unsafe_fetch, :each, to: @seq

    def self.from_s(str : String)
      data = Slice(Neucleotide).new str.size do |idx|
        Neucleotide.parse str[idx]
      end
      new data
    end

    def to_s
      String.new @seq.map &.to_char
    end

    def raise_for_invalid_compare
      raise ArgumentError.new "Hamming distance only applies to sequences of the same size."
    end

    def distance(to other : String)
      distance to: self.class.from_s(other)
    end

    def distance(to other : self) : UInt64
      raise_for_invalid_compare if size != other.size
      count = 0_u64
      each_with_index { |n, i| count += 1 unless other[i] == n }
      count
    end

    class InvalidNeucleotide < Exception
      def initialize(chr : Char)
        super "got invalid neucleotide character #{chr} -- only C, A, G, and T are valid."
      end
    end
  end

  def self.distance(a, b)
    DnaSequence.from_s(a).distance to: b
  end
end
