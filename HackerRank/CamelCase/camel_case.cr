ALL_UPCASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def from_camel(string : String)
  newversion = ""
  string.each_char_with_index do |char, index|
    if ALL_UPCASE.includes? char
      newversion += " " + char.downcase
    else
      newversion += char
    end
  end 
  newversion
end

from_camel "testStringInCamelCase"