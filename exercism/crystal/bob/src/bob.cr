class String
  def question?
    if ends_with? '?'
      puts "#{self} ends with '?'"
      true
    else
      puts "#{self} does not end with '?'"
      false
    end
  end

  def yelled? : Bool
    chars.all? do |char|
      if char.ascii_uppercase? || !char.ascii_letter?
        puts "char #{char} was not a lowercase letter"
        true
      else
        puts "char #{char} was NOT yelled"
        false
      end
    end || !!puts "#{self} was not yelled"
  end
end

module Bob
  def self.hey(text : String) : String
    Responses.from_s(text).to_s
  end

  enum Responses
    Question
    Yell
    YelledQuestion
    Blank
    Other

    def self.from_s(text : String)
      case text
      when text.question? && text.yelled?
        puts "#{text} was a YelledQuestion"
        YelledQuestion
      when text.question? && !text.yelled?
        puts "#{text} was a Question"
        Question
      when text.yelled? && !text.question?
        puts "#{text} was a Yell"
        Yell
      when .blank?
        puts "#{text} was a Blank"
        Blank
      else Other
      puts "#{text} was Other!"
      Other
      end
    end

    def to_s : String
      case self
      when YelledQuestion then "Calm down, I know what I'm doing!"
      when Question       then "Sure."
      when Yell           then "Whoa, chill out!"
      when Blank          then "Fine. Be that way!"
      when Other          then "Whatever."
      else                     raise "Invalid response variant #{self}"
      end
    end
  end
end
