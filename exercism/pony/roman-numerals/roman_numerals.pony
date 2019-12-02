use "collections"

class Level
  let i: U8
  let v: U8
  let x: U8
  new create(i': U8, v': U8, x': U8) =>
    i = i'
    v = v'
    x = x'

class RomanNumerals
  let levels: Array[Level] val = [
    Level('I', 'V', 'X')
    Level('X', 'L', 'C')
    Level('C', 'D', 'M')
  ]
  fun from_roman(numeral: String): USize =>
    var number: USize = 0
    let array = numeral.array()
    for (index, char) in array.pairs() do
      let next = array(index + 1)
      let prev = array(index - 1)
      number = number + match char
                        | 'i' => match next
                                 | 'v' => 4
                                 | 'x' => 9
                                 else 1
                                 end
                        | 'v' => if prev == 'i' then 0 else 5 end
                        | 'x' => if prev == 'i' then
                                   0
                                 else
                                   match next
                                   | 'l' => 40
                                   | 'c' => 90
                                   else 10
                                   end
                                 end
                        | 'l' => if prev == 'x' then 0 else 50 end
                        | 'c' => if prev == 'x' then
                                   0
                                 else
                                   match next
                                   | 'd' => 400
                                   | 'm' => 900
                                   else 100
                                   end
                                 end
                        | 'd' => if prev == 'c' then 0 else 500 end
                        | 'm' => if prev == 'c' then 0 else 1000 end
                        else 0
                        end
    end
    number

  // A naive power implementation
  fun pow(number: USize, _power: USize): USize =>
    var out = number
    var power = _power
    while (power = power - 1) > 0 do
      out = out * out
    end
    out

  fun _calc_digit(digit: U8, level: U8): String =>
    if level > 2 then
      var str = ""
      for m in Range(USize(1), digit.usize()  * pow(10, (level - 3).usize())) do
        str = str + 'M'
      end
      return str
    else
      String.from_array(
        match digit
        | 1 => [levels(level).i]
        | 2 => [levels(level).i; levels(level).i]
        | 3 => [levels(level).i; levels(level).i; levels(level).i]
        | 4 => [levels(level).i; levels(level).v]
        | 5 => [levels(level).v]
        | 6 => [levels(level).v; levels(level).i]
        | 7 => [levels(level).v; levels(level).i; levels(level).i]
        | 8 => [levels(level).v; levels(level).i; levels(level).i; levels(level).i]
        | 9 => [levels(level).i; levels(level).x]
        else
          [as U8:]
        end
      )
    end
  
  fun to_roman(number: USize): String =>
    var numeral = ""
    for (index, rune) in number.string().array().pairs() do
      numeral = numeral + _calc_digit(rune.u8(), (numeral.size() - index - 1).u8())
    end
    numeral

  fun apply(number: USize): String => to_roman(number)
