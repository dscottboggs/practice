class HammingDistance
  new create() => None
  fun apply(one: String, two: String): USize? =>
    if one.size() != two.size() then error end
    var distance: USize = 0
    for (index, char) in one.array().pairs() do
      if char != two(index)? then
        distance = distance + 1
      end
    end
    distance
