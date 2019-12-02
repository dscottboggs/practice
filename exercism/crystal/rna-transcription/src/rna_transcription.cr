module RnaComplement
  def self.of_dna(text : String) : String
    String.build capacity: text.size do |builder|
      text.each_char do |neucleotide|
        builder << case neucleotide.upcase
        when 'G' then 'C'
        when 'C' then 'G'
        when 'T' then 'A'
        when 'A' then 'U'
        else          raise ArgumentError.new "invalid neucleotide #{neucleotide} in chain #{text}"
        end
      end
    end
  end
end
