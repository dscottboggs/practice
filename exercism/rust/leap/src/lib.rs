pub fn is_leap_year(year: u64) -> bool {
    if year % 400 == 0 {
        // Every year divisible by 400 is definitely a leap year
        return true;
    }
    return if year % 4 == 0 {
        // a year is a leap year if it is divisible by 4,
        year % 100 != 0 // unless it's divisible by 100
    } else {
        false // all other years are not
    };
}
