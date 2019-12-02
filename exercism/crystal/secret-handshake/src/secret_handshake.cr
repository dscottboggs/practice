module SecretHandshake
  @[Flags]
  enum Step
    Wink
    DoubleBlink
    CloseYourEyes
    Jump
    Reversed

    def to_a
      array = Array(String).new initial_capacity: 5
      each do |value|
        next if value === Reversed
        array << value.to_s.underscore.gsub '_', ' '
      end
      array.reverse! if reversed?
      array
    end
  end

  extend self

  def commands(int : Int) : Array(String)
    Step.new(int).to_a
  end
end
