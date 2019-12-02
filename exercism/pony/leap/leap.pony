class Leap
  new create() => None
  fun apply(year: U32): Bool =>
    (
      (year % 400) == 0
    ) or (
      (
        (year % 4) == 0
      ) and not (
        (year % 100) == 0
      )
    )
